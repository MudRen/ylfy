// ----/cmds/arch/checkall.c ----
inherit F_CLEAN_UP;
int help(object me);

int busy;

int main(object me, string arg)
{
    if (busy)
                return notify_fail(HIR "��������������ڽ��У�\n" NOR);
//        message("system", RED"\n ������Ҵ��浵�����Ժ�....\n" NOR, users());
    write("�����У�\n");
    rm("/log/bad_data");
    rm("/log/check_users");
    rm("/log/check_money");
    busy=1;
        call_out("checking",2);
        return 1;
}
int checking(int i)
{
        int j;
        string *dir, *ppls, *puls, name,arg;
        object ob,obj;

        seteuid(getuid());
        dir = get_dir(DATA_DIR + "login/");
        if (!i){
            i=0;
        }
        ob=new("/clone/misc/player");
        if ( i<sizeof(dir) ){
                reset_eval_cost();
                arg=dir[i];
                write("�������� -= "+arg+" =-\n");
                i++;
                ppls = get_dir(DATA_DIR + "login/" + arg + "/");
                puls = get_dir(DATA_DIR + "user/" + arg + "/");
                for(j=0; j<sizeof(ppls); j++) {
                        if( sscanf(ppls[j], "%s.o", name)==1 ){
                                if( (string)SECURITY_D->get_status(name)!="(player)" ){
                                    write(BOLD+"�ų���ʦ"+name+"\n"+NOR);
                                        continue;
                                }
                                if (file_size(DATA_DIR + "login/" + arg + "/"+ppls[j])<5 || file_size(DATA_DIR + "user/" + arg + "/"+puls[j])<5 ){
                                        log_file("bad_data",name+"\tis bad.\n");
                                        continue;
                                }
                                if (!ob->new_object(name)){
                                        log_file("bad_data",name+"\tis bad.\n");
                                        continue;
                                }
                                if (ob->query("id")!=name)
                                        log_file("bad_data",name+"\tisn't\t"+ob->query("id")+"\n");
                                  obj=present("thousand-gold",ob);
                                if (ob->query("combat_exp")>=50000000 || (int)ob->query("potential") - (int)ob->query("learned_points")>100000 || ob->query("max_neili")>150000 )
                                        log_file("check_users",sprintf("%10s(%s) ����:%10d,Ǳ��:%10d,����:%10d,����ʱ��:%d\n",ob->name(),name,ob->query("combat_exp"),(int)ob->query("potential") - (int)ob->query("learned_points"),ob->query("max_neili"),ob->query("mud_age")/86400));
                                
                        }
                  if  ( obj && obj->query_amount()>100)
                  log_file("check_money",sprintf("%10s(%s) ���Ͻ�Ʊ��:%d\n",ob->name(),name,obj->query_amount()));
                }
                destruct(ob);
                call_out("checking",1,i);
                return 1;
        }else{
//              message("system", BOLD"\n �������!\n" NOR, users());
                busy=0;
        }
        return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ��checkall

HELP
        );
    return 1;
}

