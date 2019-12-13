

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
  string *dir;

//  if (!wizardp(me))    return notify_fail("��û��Ȩ��ʹ�����ָ�\n");

  dir = get_dir(DATA_DIR + "login/");
  remove_call_out("find_users");
  call_out ("find_users",0,0,dir);
  return 1;
}

void find_users(int i, string *dir)
{
  string *ppls, str, s;
  object ob;
  int j,k,last_time=0;
    mixed error;
  if (i==sizeof(dir)) return;
  write("Finding users: "+dir[i]+"\n");

            seteuid(ROOT_UID);
   ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
   for (j = 0; j < sizeof(ppls); j++) {
      reset_eval_cost();
      if (sscanf(ppls[j], "%s.o", str)==1) {
           last_time=0;
        for (k=0;k<7;k++){
            ob = new("/clone/user/login_back");
            s="/backdata/back"+sprintf("%d",k);
            ob->set_backdata_path(s);
            seteuid(str);
            ob->set("id", str);
           error=catch(ob->restore());
           if (error){
                destruct(ob);
                continue;
            }
            if (last_time > ob->query("last_on")){
                destruct(ob);
                continue;
            }
    last_time = ob->query("last_on");
write(s+"/user/"+dir[i]+"/"+str+".o  to "+DATA_DIR+"user/"+dir[i]+"/"+str+".o\n");
            seteuid(ROOT_UID);
            cp(s+"/user/"+dir[i]+"/"+str+".o",DATA_DIR+"user/"+dir[i]+"/"+str+".o");
         }
       }
    }
    i++;
  call_out ("find_users",0,i,dir);
}

int help(object me)
{
write(@HELP
ָ���ʽ�� restore

HELP
  );
    return 1;
}

