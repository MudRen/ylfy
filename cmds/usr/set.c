// ----/cmds/usr/set.c ----
// set.c
//    add color availability by ReyGod  in Dec. 1996
 
#define MAX_ENV_VARS    20
#include <ansi.h>
inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
    int i;
    string term, *terms, *wiz_only;
        mixed data;
        mapping env;
 
    wiz_only = ({"invisibility", "immortal"});
 
        if( me != this_player(1) ) return 0;
 
        env = me->query("env");
 
        if( !arg || arg=="" ) {
                if( !mapp(env) || !sizeof(env) )
                        write("��Ŀǰû���趨�κλ���������\n");
                else {
                        write("��Ŀǰ�趨�Ļ��������У�\n");
                        terms = keys(env);
                        for(i=0; i<sizeof(terms); i++)
						{
							if ( terms[i] != "myhp_show" )
								printf("%-20s  %O\n", terms[i], env[terms[i]]);
						}
                }
                return 1;
        }
 
        if( sscanf(arg, "%s %s", term, data)!=2 ) {
                term = arg;
                data = "YES";
        }
        
if( strsrch(term, '/')!=-1 ){   	
                log_file("Bad_Man",sprintf("%s(%s) set <%s> in %s\n",me->short(1),query_ip_number(me),term,ctime(time())));
                return notify_fail("û���������á�\n");
        }


        if( term && term!="" ) {
                if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
                        return notify_fail("����Ļ�������̫���ˣ������� unset ɾ�������ɡ�\n");
           sscanf(data, "%d", data);
        if (term=="msg_mout" || term=="msg_min"){
          if (!stringp(data)) return 0;
                data = replace_string(data, "$BLK$", BLK);
                data = replace_string(data, "$RED$", RED);
                data = replace_string(data, "$GRN$", GRN);
                data = replace_string(data, "$YEL$", YEL);
                data = replace_string(data, "$BLU$", BLU);
                data = replace_string(data, "$MAG$", MAG);
                data = replace_string(data, "$CYN$", CYN);
                data = replace_string(data, "$WHT$", WHT);
                data = replace_string(data, "$HIR$", HIR);
                data = replace_string(data, "$HIG$", HIG);
                data = replace_string(data, "$HIY$", HIY);
                data = replace_string(data, "$HIB$", HIB);
                data = replace_string(data, "$HIM$", HIM);
                data = replace_string(data, "$HIC$", HIC);
                data = replace_string(data, "$HIW$", HIW);
                data = replace_string(data, "$NOR$", NOR);
                data+= NOR;
        }
    me->set("env/" + term, data);
	if ( term != "myhp_show" )
		printf("�趨����������%s = %O%s\n", term, data,NOR);
         
      env = me->query("env");
    terms = keys(env);
    for(i=0; i<sizeof(terms); i++)
       if((wiz_level(me) == 0) && (member_array(terms[i], wiz_only) != -1))
              me->delete("env/"+terms[i]);
    return 1;
    }
    return help();
}
 
int help()
{
        write(@TEXT
ָ���ʽ��set <������> [<����ֵ>]
 
���ָ�������趨һЩ�������������Ӳ���ʱ����ʾ��Ŀǰ�趨�Ļ�����������ָ��
����ֵ�����ڶ�ֵΪ "YES"������ֵ��Ϊ�ַ������ɲ��� nick �仯��ɫ.
for example : set msg_min, msg_mout, msg_home , etc��no_combat_msg.
 
ȡ�������趨���� unset ָ�
 
�������Щ�������������趨����� help settings��
TEXT
        );
        return 1;
}


