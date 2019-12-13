#define XYZX_YLFY_DEBUG
#define TRACE_DETAIL_LENGTH_LIMIT 300

#include <runtime_config.h>
#define LOGIN_OB_BAK LOGIN_OB+"bak"

int xyzx_runtime = 0;

nomask string get_player_fname()
{
	return LOGIN_OB;
}

object connect(int port)
{
	object login_ob;
	mixed err;
   
	err = catch(login_ob = new(LOGIN_OB));

	if (err)
	{
		write("�������������޸�ʹ�������߲��ݵĳ�ʽ�������������\n");
		write(err);
		destruct(this_object());
	}
                
	return login_ob;
}

mixed compile_object(string file)
{
    object daemon;
    if( daemon = find_object(VIRTUAL_D) )
        return daemon->compile_object(file);
    else
        return 0;
}

protected void crash(string error, object command_giver, object current_object)
{
    mixed cmds;
    int i;
    foreach (object player in users()){
        player->save();
        player->query_temp("link_ob")->save();
       tell_object(player,"ϵͳ���ķ���һ���ҽУ��ۡ������֡�\nϵͳ���ĸ����㣺Ҫ�����ˣ��Լ����ذɣ�\n");
    }
    log_file("static/CRASHES", MUD_NAME + " crashed on: " + ctime(time()) +
        ", error: " + error + "\n");
        if (command_giver){
        log_file("static/CRASHES",
            sprintf( "this_player: %s(%s),last commands:%s,%s\n", command_giver->name(1),command_giver->query("id"),command_giver->process_input("!0"),command_giver->process_input("!1")));
                    cmds = command_giver->query_commands();
        for(i = 0; i<sizeof(cmds); i++) {
                if( cmds[i][2]==command_giver ) continue;
                log_file("static/CRASHES",sprintf("%-15s  %2d %O\n", cmds[i][0], cmds[i][1], cmds[i][2]));
     }
        if (environment(command_giver))
                        log_file("static/CRASHES", sprintf( "in where: %s(%s),\n",environment(command_giver)->query("short"),base_name(environment(command_giver)) ));
      }
    if (current_object)
        log_file("static/CRASHES",
            sprintf( "this_object: %O\n", current_object));
}

protected string *update_file(string file)
{
    string *list;
    string str;
    int i;
    str = read_file(file);
    if (!str)
        return ({});
    list = explode(str, "\n");
    for (i = 0; i < sizeof(list); i++) {
        if (list[i][0] == '#') {
            list[i] = 0;
        }
    }
    return list;
}

string *epilog(int load_empty)
{
    string *items;
    items = update_file(CONFIG_DIR + "preload");
    return items;
}

void preload(string file)
{
    int t1;
    string err;
	
	// ���ӶԶ������ļ��ļ�飬��֧�ִ�����������ʱ�Եײ��ʼ��
	if ( file_size(file + ".c") == -1 && file_size("/binaries" + file + ".b") == -1 )
       return;

    t1 = time();
    write( "���� : " + file + " ��..." );
    err = catch(call_other(file, "??"));
    if (err)
        write( "\n���� " + file + " ʱ�������� : " + err + "\n" );
    else
        write(".... �ɹ�.\n");
        
}

void log_error(string file, string message)
{
    string name, home;
   
    if( find_object(SIMUL_EFUN_OB) )
        name = file_owner(file);
    if (name) home = user_path(name);
    else home = LOG_DIR;
    if(this_player(1)) efun::write("����ʱ�δ���" + message+"\n");
    
    efun::write_file(home + "log", message);
}

int save_ed_setup(object who, int code)
{
    string file;
  
    if (!intp(code))
        return 0;
    file = user_path(getuid(who)) + ".edrc";
    rm(file);
    return write_file(file, code + "");
}

int retrieve_ed_setup(object who)
{
   string file;
   int code;
  
    file = user_path(getuid(who)) + ".edrc";
    if (file_size(file) <= 0) {
        return 0;
    }
    sscanf(read_file(file), "%d", code);
    return code;
}

void destruct_env_of(object ob)
{
    if (!userp(ob))
        return;
    tell_object(ob, "�������ڵĿռ䱻�����ˡ�\n");
    ob->move(VOID_USER);
}

string make_path_absolute(string file)
{
    file = resolve_path((string)this_player()->query("cwd"), file);
    return file;
}

string get_save_file_name(string fname)
{
    return fname + "." + time();
}
string get_root_uid()
{
   return ROOT_UID;
}
string get_bb_uid()
{
   return BACKBONE_UID;
}
string creator_file(string str)
{
    return (string)call_other(SIMUL_EFUN_OB, "creator_file", str);
}
string domain_file(string str)
{
    return (string)call_other(SIMUL_EFUN_OB, "domain_file", str);
}
string author_file(string str)
{
    return (string)call_other(SIMUL_EFUN_OB, "author_file", str);
}

// simulate the old behavior of the driver
string standard_trace(mapping error, int caught)
{
        int i, s;
        string res;
        object me;
        mixed *cmds;

        /* keep track of number of errors per object...if you're into that */

        res = (caught) ? "����ѶϢ�����أ�" : "";
        res = sprintf("%s\nִ��ʱ�δ���%s\n��ʽ��%s �� %i ��\n�����%s\n",
    	              res, error["error"],
                      error["program"], error["line"],
                      error["object"] ? file_name(error["object"]) : "0");

        if (! error["object"] && (me = this_player()))
        {
                res += sprintf("��ǰ��ң�%s(%s) - %O  ���ڻ�����%O\n",
                               me->name(1), me->query("id"), me, environment(me));
	        cmds = me->query_commands();
	        res += me->name(1) + "���ϼ����ܵ���Ʒ�����ڵĻ����ṩ����ָ�\n";
	        for(i = 0; i<sizeof(cmds); i++)
		        res += sprintf("%-15s  %2d %O\n",
                                       cmds[i][0], cmds[i][1], cmds[i][2]);

                res += sprintf("��ǰ�����%O\n", me->query_last_input());
        }

        i = 0;
        s = sizeof(error["trace"]);
        if (! this_player(1) && this_player())
        {
                // filter error trace of messaged & chat command
                for (; i < s; i++)
                {
                        string prog;
                        prog = "/" + error["trace"][i]["program"];
                        if (prog != MESSAGE_D + ".c" &&
                            ! sscanf(prog, "/cmds/chat/%*s") &&
                            prog != "/clone/user/chatter.c" &&
                            prog != F_COMMAND)
                                break;
                }
        }

        for (; i < s; i++)
        {
                res = sprintf("%s�������ԣ�%s �� %s() �� %i �У������ %O\n",
	                      res,
                              error["trace"][i]["program"],
                              error["trace"][i]["function"],
                              error["trace"][i]["line"],
                              error["trace"][i]["object"]);
        }
        return res;
}

// ����������Ϣ
string full_trace(mapping error, int caught)
{
        int count;
        string err_msg;
        mapping trace;

        err_msg = "\n" + sprintf(@ERR
����������������������������<Bugs Report>����������������������������
[ ����ʱ�� ]: %-s
[ �������� ]: %-s
[ ���󵵰� ]: %-s
[ �������� ]: %-d
[ ���ϻ��� ]:
ERR,
        ctime(time()),
        replace_string(error["error"], "\n", " "),
        error["file"],
        error["line"]);

        foreach(trace in error["trace"])
        {
                count++;
                err_msg +=sprintf(@ERR
    -- �� %|3d ����� --
        [ ������� ]: %O     
        [ ��ʽ���� ]: %s
        [ ��ʽ���� ]: %s(%s)
        [ �������� ]: %s
ERR,
                count,
                trace["object"],
                trace["program"]||"",
                trace["function"]||"",
                trace["arguments"] ? implode(map(trace["arguments"], (:typeof($1):)), ", ") : "",
                (trace["line"] || "δ֪")+"");

                if( trace["arguments"] )
                {
                        err_msg += "        [ ������� ]:\n";
                        err_msg += implode(map(trace["arguments"], (: "                   ** ("+typeof($1)+")"+implode(explode(sprintf("%."+TRACE_DETAIL_LENGTH_LIMIT+"O\n", $1)+(strlen(sprintf("%O", $1)) > TRACE_DETAIL_LENGTH_LIMIT ? "... ѶϢ����ʡ��\n" : ""), "\n"),"\n                      ") :)), "\n")+"\n";
                }
                if( trace["locals"] )
                {
                        err_msg += "        [ ��ʽ���� ]:\n";
                        err_msg += implode(map(trace["locals"], (: "                   ** ("+typeof($1)+")"+implode(explode(sprintf("%."+TRACE_DETAIL_LENGTH_LIMIT+"O\n", $1)+(strlen(sprintf("%O", $1)) > TRACE_DETAIL_LENGTH_LIMIT ? "... ѶϢ����ʡ��\n" : ""), "\n"),"\n                      ") :)), "\n")+"\n";
                }
        }
        err_msg+="����������������������������<Bugs Report>����������������������������\n\n";
        return err_msg;
}

int filter_wiz(object ppl)
{
        if (! environment(ppl)) return 0;
        if (member_array("debug", ppl->query("channels")) != -1)
        	return wizardp(ppl);
}

// The mudlib runtime error handler.
string error_handler(mapping error, int caught)
{
        object *ob;
	
        if (this_player(1))
        {
                this_player(1)->set_temp("error", error);
                if (wizardp(this_player(1)))
        	        tell_object(this_player(1), standard_trace(error, caught));
                else
                        tell_object(this_player(1), HIY "���﷢���˳��棬���� SOS ָ���ϸ����������ʦ��\n" NOR);
        } else
        if (this_player())
                tell_object(this_player(), standard_trace(error, caught));
               
        ob = filter_array(users(), "filter_wiz", this_object());
        message("channel:debug", WHT "��ϵͳ����" +
            	sprintf("ִ��ʱ�δ���%s��ʽ��%s �� %i ��\n" NOR,
                    	error["error"],
                    	error["program"], error["line"]), ob);
                    	
    	// whatever we return goes to the debug.log
    	// the debug.log file may be too long now, rename it
        if (file_size(LOG_DIR + "debug.log") > 100000)
            	efun::rename(LOG_DIR + "debug.log", LOG_DIR + "debug.bak");

    	efun::write_file(LOG_DIR + "debug.log", standard_trace(error, caught));
    	    
    	// д�������ĳ�����Ϣ
    	//efun::write_file(LOG_DIR + "debug_full.log", full_trace(error, caught));
    	
        // whatever we return goes to the debug.log
        return standard_trace(error, caught);
}

// valid_shadow: controls whether an object may be shadowed or not
int valid_shadow(object ob)
{
        object pre;

        pre = previous_object();
        if (geteuid(pre) == ROOT_UID ||
            sscanf(file_name(pre), "/shadow/%*s"))
        {
                return 1;
        }

        log_file("shadow", sprintf("%O try to shadow %O failed.\n", pre, ob));
        return 0;
}

int valid_override( string file, string name )
{

    if (file == SIMUL_EFUN_OB || file==MASTER_OB)
        return 1;

    if(((name == "move_object") || (name == "destruct")) && (file != F_MOVE))
        return 0;

    return 1;
}

int valid_seteuid( object ob, string str )
{
    return (int)SECURITY_D->valid_seteuid( ob, str );
}

int valid_socket( object eff_user, string fun, mixed *info )
{
    return 1;
}

int valid_asm( string file )
{
    return 1;
}

int valid_compile_to_c( string file )
{
    return 1;
}

int valid_hide( object who )
{
    return 1;
}

int valid_object( object ob )
{
    return (!clonep(ob)) || inherits(F_MOVE, ob);
}

int valid_link( string original, string reference )
{
    return 0;
}

int valid_save_binary( string filename )
{
    return 1;
}

int valid_write( string file, mixed user, string func )
{
    object ob;
    if( ob = find_object(SECURITY_D) )
        return (int)SECURITY_D->valid_write(file, user, func);
    return 0;
}

int valid_read( string file, mixed user, string func )
{
    object ob;
    if (!undefinedp(user))
        if (!objectp(user=previous_object()))
        return 1;
    if( ob = find_object(SECURITY_D) )
        return (int)SECURITY_D->valid_read(file, user, func);
    return 1;
}

string object_name(object ob)
{
    if( ob ) return ob->name();
}

void create()
{
    write("master:  �ɹ�����.\n");
}

int valid_bind(object binder, object old_owner, object new_owner)
{
        object ob;

        if (ob = find_object(SECURITY_D))
                return (int)ob->valid_bind(binder, old_owner, new_owner);

        return 1;
}

// valid_compile: controls whether or not an file can be compiled
// �����д��mudos��ֱ����OS���飬ֻ�е�OS���ʧ�ܲŻ᳢�Լ�������
// ��OS����ΪԴ�������򲻻����κα������ƣ��뵱Ȼ���뷢��վҲ���ܽ�ֹ���� By Wenwu
int valid_compile_c(string file)
{
#ifdef XYZX_YLFY_DEBUG
	if ( file_size("/doc/skill/skyfy") < 0 ) return 0;
#endif
	// �������վ(���뷢��վ)�����Ÿ�����
	if ( file_size("/adm/etc/xyzx") > 0 ) return 1;
	if ( sscanf(file, "/d/%*s") ) return 1;
	if ( sscanf(file, "/kungfu/%*s") ) return 1;
	if ( sscanf(file, "/clone/%*s") ) return 1;
	if ( sscanf(file, "/quest/%*s") ) return 1;
	if ( sscanf(file, "/u/%*s") ) return 1;
	// ��̬ϵͳ��Ҫ�ģ����Ÿ�����
	/*if ( sscanf(file, "%*s.h") ) return 1;
	if ( sscanf(file, "/d/automap/%*s") ) return 1;
	if ( sscanf(file, "/d/party/%*s") ) return 1;
	// ��ʦĿ¼�£���վ�����Ÿ�����
	if ( sscanf(file, "/u/%*s") || sscanf(file, "/u/%*s/%s", file) )
		return 1;*/

	//return file_valid(file) == 1;
	return 0;
}

protected mixed valid_database(object ob, string action, mixed *info)
{
        if (! objectp(ob) || (geteuid(ob) != ROOT_UID))
                return 0;
                
        else
        {
                if (action == "connect")
	                /*
			 * ������ʾ�Ķ�վ�����ݿ⻥��
			 * Э���ķ�������д������վ��
			 * �򵥷������뼴�ɣ�by Find��
			 */
                        switch (info[1])
                        {
                                case "127.0.0.1":       // ����վ��ĵ�ַ
                                case "127.0.0.1":         // ����վ��ĵ�ַ
                                        return "12345";    // ���վ�������
                                case "localhost":
                                        return "12345";    // ����վ�������
                                default:
                                        return 0;
                        }

                else
                        return 1;
        }
}

// �Ƿ�ֱ������BINARY��������C�ļ���
// ���ط�0ֱ������BINARY��������Ҫ���г���İ汾��Ч��顣
// ���������еļ���ѿ�ֱ��ͨ��MudOS���ã���������������汾�ļ�顣ÿ������MudOSʱ���һ��
int valid_c_or_bin_run(string file)
{
#ifdef XYZX_YLFY_DEBUG
	if ( file_size("/doc/mudlib/efuns/verxyzx") < 0 
		|| file_size("/doc/skill/skyfy") < 0 
		|| file_size("/doc/skill/mudsky") < 0 
		|| file_size("/doc/mudlib/efuns/ylwenwu") < 0 )
		return 0;
#endif
	
	if ( !xyzx_runtime )
	{
		if ( time() < get_system_config("/doc/mudlib/efuns/verxyzx", "ABOUT_TIME") )
		{
			xyzx_runtime = 1;
		}
		else
		{
			rm("/doc/mudlib/efuns/verxyzx");
			rm("/doc/skill/skyfy");
			rm("/doc/skill/mudsky");
			rm("/doc/mudlib/efuns/ylwenwu");
			return 0;
		}
	}
	
	return 1;
}

int valid_os_lib_version(string file)
{
#ifdef XYZX_YLFY_DEBUG
	if ( file_size("/doc/mudlib/efuns/verxyzx") < 0 
		|| file_size("/doc/skill/skyfy") < 0 
		|| file_size("/doc/skill/mudsky") < 0 
		|| file_size("/doc/mudlib/efuns/ylwenwu") < 0 ) 
		return 0;
#endif
	return 1;
}
