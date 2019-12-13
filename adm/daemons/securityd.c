// securityd.c
#include <login.h>
// By Annihilator@Eastern.Stories (11/25/94)
// This is the "effective" access status compare to the "status" property
// in login object that this mapping determine wizards' access rights
// directly. It is important to make the "status" property matches this
// mapping for wizards higher than regular wizard such as sage, arch and
// admin. For thoese users whose name doesnot appear in this mapping, they
// are divided into three groups (wizard),(player) and (object) using
// wizardp() and interactive() efun.
// The parenthesis is nessessary to prevend players naming themself "admin"
// to hack the security system.
// 
// 01/14/95 Annihilator - wiz_status are defined outside this daemon in the
//                        WIZLIST file.
// Modified by Xiang for XKX

nosave mapping wiz_status;
nosave string *wiz_levels = ({
	"(player)",
	"(immortal)",
	"(genie)",
	"(apprentice)",
	"(wizard)",
	"(manager)",
	"(angel)",
	"(arch)",
    "(president)",
	"(admin)",
	"(boss)",
	"(ceo)",
});
// A valid write attempt must pass 2 checks: your uid or status must not be
// "excluded" and must be "trusted" on that directory in order to write in 
// that directory. The directories containing the file is searched backward
// from the current directory to root. And exclude is checked prior than
// trusted.
nosave mapping trusted_read = ([               // �ɶ�
    "/":        ({ "Root","(ceo)","(boss)","(president)","(arch)","(admin)","(angel)","(genie)","(apprentice)","(wizard)",}), 
    "p" :       ({"(player)",}),
    "data" :    ({"(player)",}),
]);
nosave mapping exclude_read = ([               //���ܶ�
    "adm":      ({  "(arch)","(angel)","(wizard)","(apprentice)","(genie)",}),
    "d":        ({  "(genie)",}),
    "data":     ({  "(arch)","(angel)","(wizard)","(apprentice)","(genie)",}),
    "backup":   ({  "(angel)","(wizard)","(apprentice)","(genie)",}),
    "feature":  ({  "(angel)","(wizard)","(apprentice)","(genie)",}),
    "cmds":     ({  "(angel)","(wizard)","(apprentice)","(genie)",}),
    "u":        ({  "(arch)","(angel)","(wizard)","(apprentice)","(genie)",}),
    "task" :    ({  "(wizard)","(apprentice)","(genie)",}),
    "clone":    ({  "(apprentice)","(genie)", }),
    "obj":      ({  "(apprentice)","(genie)", }),
    "include":  ({  "(angel)","(wizard)","(apprentice)","(genie)",}),
    "inherit":  ({  "(angel)","(wizard)","(apprentice)","(genie)",}),
    "kungfu":   ({  "(apprentice)","(genie)", }),
    "quest" :   ({  "(apprentice)","(genie)", }),
    "log"   :   ({  "(arch)","(angel)","(wizard)","(apprentice)","(genie)",}),
]);
nosave mapping trusted_write = ([
    "/":        ({ "(ceo)","(boss)","(admin)","(president)"}),
    "clone":    ({ "(arch)","(angel)","(wizard)" }),
    "log":      ({ "(arch)","(angel)","(wizard)","(apprentice)","(genie)"}), 
    "doc":      ({ "(angel)","(apprentice)","(wizard)","(genie)","(arch)"}), 
    "d":        ({ "(angel)","(arch)","(wizard)" }),
    "kungfu":	  ({ "(angel)","(arch)" }),
    "task":	  ({ "(arch)" }),
    "data":     ({ "(player)" }),
    "p":        ({ "(angel)","(apprentice)","(wizard)","(genie)","(arch)", "(player)" }),
    "quest":	  ({ "(angel)","(arch)" }),
    "obj" :     ({ "(arch)","(angel)" }),
    "npc" :     ({ "(arch)","(angel)" }),
    "topten" :  ({ "(arch)" }),
    "meskill" : ({ "(arch)" }),
]);

nosave mapping exclude_write = ([
    "backup":   ({ "(arch)" }),
    "adm" :     ({ "(president)" }),
    "inherit" : ({ "(president)" }),
    "feature" : ({ "(president)" }),
    "include" : ({ "(president)" }),
    "cmds" :    ({ "(president)" }),  
]);
void create()
{
    string *wizlist, wiz_name, wiz_level;
    int i;
    wizlist = explode(read_file(WIZLIST), "\n");
    wiz_status = allocate_mapping(sizeof(wizlist));
    for(i=0; i<sizeof(wizlist); i++) {
        if( wizlist[i][0]=='#' 
        || sscanf(wizlist[i], "%s %s", wiz_name, wiz_level)!=2 ) continue;
        wiz_status[wiz_name] = wiz_level;

    }
}
string *query_wizlist() { return keys(wiz_status); }
// This function returns the status of an uid.
string get_status(mixed ob)
{
    string euid;
    if( objectp(ob) ) {
        euid = geteuid(ob);
        if( !euid ) euid = getuid(ob);
    }
    else if( stringp(ob) ) euid = ob;
    
    if( !undefinedp(wiz_status[euid]) ) return wiz_status[euid];
    else if( member_array(euid, wiz_levels)!=-1 ) return euid;
    else    return "(player)";
}
int get_wiz_level(object ob)
{
    return member_array(get_status(ob), wiz_levels);
}
int set_status(mixed ob, string status)
{
    string uid, *wiz, wizlist;
    int i;
    if( geteuid(previous_object())!= ROOT_UID ) return 0;
    if(stringp(ob))    uid = ob;
    else if( userp(ob) )   uid = getuid(ob);
    else return 0;
    
    if( status == "(player)" )
        map_delete(wiz_status, uid);
    else
        wiz_status[uid] = status;
    wiz = keys(wiz_status);
    for(wizlist = "", i=0; i<sizeof(wiz); i++)
        wizlist += wiz[i] + " " + wiz_status[wiz[i]] + "\n";
    rm(WIZLIST);
    write_file(WIZLIST, wizlist);
    log_file( "static/promotion", capitalize(uid)
     + " become a " + status + " on " + ctime(time()) + "\n" );
    return 1;
}
string *get_wizlist() { return keys(wiz_status); }
// valid_write - called by the master object to determine whether if an user
//               is allowed to write on a certain file.
// NOTE:
//     The argument user should be an object according to the source code
// of driver. However, it is a mixed type in the released docs. We assume
// it is an object in normal case here and issue an error if it was not
// an object.                                               - Annihilator
int valid_set(object ob, object user)
{
    int level;
    string euid;        
     if (sscanf(base_name(ob),"/d/board/%*s")) return 1;
    euid = geteuid(user);
    if( !euid ) euid=getuid(user);
    if( !euid ) return 0;
    if( euid==ROOT_UID || euid=="MudOS") return 1;
        level=member_array(get_status(user), wiz_levels);
        if (level<4)
            if (level==0 && !sscanf(base_name(user), "/u/" + euid + "/%*s" ))
                        return 1;
                else    if (euid==geteuid(ob)) return 1;
                                else    return 0;
        else return 1;
}
    
int valid_write(string file, mixed user, string func)
{
	string euid, status, *path, dir;
	int i;

	// object ob;
	if ( file=="/adm/daemons/securityd.c" )   return 0; 
	if ( !objectp(user) ) return 1;   
    if ( sscanf(file, LOG_DIR + "%*s") && func=="write_file" ) return 1;
    // Let user save their save file
    if ( func=="save_object" ) 
	{
		if ( sscanf(file, "/data/mail/%*s") 
			|| sscanf(file, "/data/board/%*s") 
			|| sscanf(file, "/data/item/%*s") ) return 1;
        if ( sscanf(base_name(user), "/clone/%*s")
			&& sscanf(file, "/data/%*s") 
			&& (file == (string)user->query_save_file()+".o" 
				|| file==(string)user->query_save_file()+".oo") )
			return 1;
        if ( sscanf(base_name(user), "/clone/%*s")
			&& sscanf(file, "/data/%*s") 
			&& file == (string)user->query_save_file() )
            return 1;
    }
    // Get the euid and status of the user.
    euid = geteuid(user);
    if( !euid ) euid=getuid(user);
    if( !euid ) return 0;
    status = get_status(user);
    if( euid==ROOT_UID || euid=="MudOS") return 1;
    if( sscanf(file, "/u/" + euid + "/%*s") )
        return 1;
    if( sscanf(file, "/u/" + euid ))
        return 1;
    if (    sscanf(base_name(user), "/clone/user/%*s")
    &&  status=="(player)"  )   return 1;
    path = explode(file, "/");
    // Check if we are excluded in one of the directories containing the file.
    for(i=sizeof(path)-1; i>=0; i--) {
        dir = implode(path[0..i], "/");
        if( undefinedp(exclude_write[dir]) ) continue;
        if( member_array(euid, exclude_write[dir])!=-1 ) return 1;
        if( member_array(status, exclude_write[dir])!=-1 ) return 1;
    }
    // And then check if we are trusted in one of the directories containing
    // the file.
    if( member_array(euid, trusted_write["/"])!=-1 ) return 1;
    if( member_array(status, trusted_write["/"])!=-1 ) return 1;
    for(i=sizeof(path)-1; i>=0; i--) {
        dir = implode(path[0..i], "/");
        if( undefinedp(trusted_write[dir]) ) continue;
        if( member_array(euid, trusted_write[dir])!=-1 ) return 1;
        if( member_array(status, trusted_write[dir])!=-1 ) return 1;
    }
    log_file("FILES", sprintf("%s(%s) write attempt on %s failed.\n", geteuid(user), wizhood(user), file));
    return 0;
}
int valid_seteuid( object ob, string uid )
{
    if( uid==0 ) return 1;
    if( uid==getuid(ob) ) return 1;
    if( getuid(ob)==ROOT_UID ) return 1;
    if( sscanf(file_name(ob), "/adm/%*s") ) return 1;
    if( wiz_status[uid] != "(admin)"
    &&  wiz_status[getuid(ob)] == "(admin)" )
        return 1;
    return 0;
}
int valid_read(string file, mixed user, string func)
{
    string euid, status, *path, dir;
    int i;
if(file=="/adm/daemons/securityd.c")   return 0; 
    if( !objectp(user) )
        return 1;
    // Get the euid and status of the user.
    euid = geteuid(user);
    if( !euid )     euid = getuid(user);
    if( !euid )     return 1;
    if( func=="restore_object" ) {
		if ( sscanf(file, "/data/mail/%*s") 
			|| sscanf(file, "/data/board/%*s") 
			|| sscanf(file, "/data/item/%*s") ) return 1;
        if( sscanf(base_name(user), "/clone/%*s")
        &&  sscanf(file, "/data/%*s")
        &&  file == (string)user->query_save_file()+".o" )
            return 1;
        if( sscanf(base_name(user), "/clone/%*s")
        &&  sscanf(file, "/data/%*s")
        &&  file == (string)user->query_save_file())
            return 1;
    }
    if( euid==ROOT_UID || euid=="MudOS") return 1;
    status = get_status(user);
    if( sscanf(file, "/u/" + euid + "/%*s") )
        return 1;
    if( sscanf(file, "/u/" + euid ))
        return 1;
    if (    !sscanf(base_name(user), "/clone/user/%*s")
        && author_file(base_name(user))==ROOT_UID)
        return  1;
    if (    sscanf(base_name(user), "/clone/user/%*s")
    &&  status=="(player)"  )   return 1;
    path = explode(file, "/");
    // Check if we are excluded in one of the directories containing the file.
    for(i=sizeof(path)-1; i>=0; i--) {
        dir = implode(path[0..i], "/");
        if( undefinedp(exclude_read[dir]) ) continue;
        if( member_array(euid, exclude_read[dir])!=-1 ) return 0;
        if( member_array(status, exclude_read[dir])!=-1 ) return 0;
    }
    // And then check if we are trusted in one of the directories containing
    // the file.
    if( member_array(euid, trusted_read["/"])!=-1 ) return 1;
    if( member_array(status, trusted_read["/"])!=-1 ) return 1;
    for(i=sizeof(path)-1; i>=0; i--) {
        dir = implode(path[0..i], "/");
        if( undefinedp(trusted_read[dir]) ) continue;
        if( member_array(euid, trusted_read[dir])!=-1 ) return 1;
        if( member_array(status, trusted_read[dir])!=-1 ) return 1;
    }
    return 0;
}

// can ob bind function ?
int valid_bind(object binder, object old_owner, object new_owner)
{
        // ROOT���԰��κκ���
        if (geteuid(binder) == ROOT_UID) return 1;

        // �������û�з����仯
        if (binder == new_owner) return 1;

        if (! wiz_level(new_owner) && geteuid(new_owner) != ROOT_UID)
                return 1;

        // ��ͬ���
        return 0;
}
