// purge.c
#include <ansi.h>
int help(object me);
inherit F_CLEAN_UP;
int help(object me);
protected int do_purge_players(int day,object me);
int main(object me, string arg)
{
        string name, reason;
        int day;
        if( !arg ) return help(me);
        if( sscanf(arg, "%d", day) && day >= 0) return do_purge_players(day,me);
        if( sscanf(arg, "%s because %s", name, reason)!=2 )
                return help(me);
        if( me!=this_player(1)
        && wiz_level(me) < wiz_level(SECURITY_D->get_status(arg)) )
                return notify_fail("��û��Ȩ��ʹ�����ָ�\n");
        seteuid(getuid());
        if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__)<0 )
                return notify_fail("û����λʹ���ߡ�\n");
        rm(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        rm(DATA_DIR + "user/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        rm(DATA_DIR + "mail/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        write( "ʹ���� " + capitalize(name) + " ɾ�����ˡ�\n");
        log_file("static/PURGE", sprintf("[%s] %s purged %s because %s.\n",
                ctime(time())[0..15], geteuid(this_player(1)), name, reason));
        return 1;
}
protected int do_purge_players(int day,object me)
{
        int i, j, ppl_cnt, count;
        string *dir, *ppls, name;
        object ob;

        if( me!=this_player(1)
        && wiz_level(me) < wiz_level("(arch)") )
                return notify_fail("�����ʦ�ȼ�̫�ͣ�û��ʹ�����ָ���Ȩ����\n");
        if (day<60)     day=60;
        seteuid(getuid());
        message("system", RED"\n ������Ҵ��浵�У����Ժ�....\n", users());
        write("�����У�\n");
        count = 0;
        ppl_cnt = 0;
        dir = get_dir(DATA_DIR + "login/");
        for(i=0; i<sizeof(dir); i++) {
                reset_eval_cost();
                write(HIY+"----------------"+dir[i]+"-------------\n"+NOR);
                ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
                ppl_cnt += sizeof(ppls);
                for(j=0; j<sizeof(ppls); j++) {
                        if( sscanf(ppls[j], "%s.o", name)==1 ){
                                if( (string)SECURITY_D->get_status(name)!="(player)" ){
                                    write(BOLD+"�ų���ʦ"+name+"\n"+NOR);
                                        continue;
                                 }
                                if (ob=FINGER_D->acquire_login_ob(name)){
                                    if ( (time()-ob->query("last_on"))/86400<day){
                                        destruct(ob);
                                        continue; 
                                     }
                                    if (ob->query("combat_exp")>200000){
                                        printf("�ų������\t%-20s����:%10d\t%d��δ���ߡ�\n",ob->query("name")+"("+name+"):",ob->query("combat_exp"),(time()-ob->query("last_on"))/86400);
                                        destruct(ob);
                                        continue; 
                                      }
                                    destruct(ob);
                                 }
                                    rm(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
                                    rm(DATA_DIR + "user/" + dir[i] + "/" + ppls[j]);
                                    rm(DATA_DIR + "mail/" + dir[i] + "/" + ppls[j]);
                                    count ++;
                         }
                }
        }
        write("\n\nԭ���ܹ��� " + ppl_cnt + " λʹ���ߡ�\n");
        write( count + " ������ " + day + " ��δ���ߵ�ʹ���߱�������ˡ�\n");
        write("�����ܹ��� " + (ppl_cnt - count) + " λʹ���ߡ�\n");
        log_file("static/PURGE", sprintf("[%s] %s cleaned up %d characters who didn't login for more than %d days\n"
                "\t\tResulting statistics: %d characters remaining.\n",
                ctime(time())[0..15], geteuid(this_player(1)), count, day, ppl_cnt - count));
        return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ��purge [<δ��������>] | <ʹ��������> because <ԭ��>
���һ��ʹ���߻��������һ�������������ߵ�ʹ���ߡ�
HELP
        );
    return 1;
}

