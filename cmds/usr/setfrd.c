// pangzai��WLFY
// setfrd.c

#include <mudlib.h>
void create() { seteuid( getuid() ); }
#define MAX_FRIENDS     5
inherit F_CLEAN_UP;
int help();
int main(object me, string arg)
{

    object ob;
    int i;
    string term, *terms;
        mapping friends;
        friends = me->query("friends");
        if( !arg || arg=="" ) {
                write("��Ŀǰ�趨�ĺ����������£�\n");
                if( !mapp(friends) || !sizeof(friends) )
                        write("\tû���趨�κκ��ѡ�\n");
                else {
                        terms = keys(friends);
                        for(i=0; i<sizeof(terms); i++)
                                printf("%s  ", terms[i]); 
                        printf("\n");
                }
                return 1;
        }
      if( sscanf(arg, "%s", term)!=1 ) {
             term = arg;
     }
                if( strsrch(term, '/')!=-1 ){
                log_file("Bad_Man",sprintf("%s(%s) set <%s> in %s\n",me->short(1),query_ip_number(me),term,ctime(time()))); 

}

        
        if( arg && arg!="" ) {
                arg = lower_case(arg);
                ob = new(LOGIN_OB);
                ob->set("id", arg);
                if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) 
                {
                        if( mapp(friends) && undefinedp(friends[arg]) && sizeof(friends) >= MAX_FRIENDS )
                        return notify_fail("����ĺ���̫���ˣ������� unsetfrd ɾ�������ɡ�\n");
                        me->set("friends/" + arg, 1);
                        printf("���Ӻ��ѣ�%s  \n", arg);
                }
                else
                        return notify_fail("û�������ҡ�\n");
            return 1;
        }
        return 0;
}


