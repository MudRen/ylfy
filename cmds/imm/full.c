#include "/doc/help.h"
#include "ansi.h"
inherit F_CLEAN_UP;
int main(object me,string arg)
{
       int heal,heal1,neili;
       object ob;
       if (arg){
       ob = present(arg,environment(me));
       if(!ob)
       ob = LOGIN_D->find_body(arg);
       if(!ob)
       return notify_fail("û�������ҡ�\n");
       if(wiz_level(me) < wiz_level("(arch)")) {
       return notify_fail("�벻Ҫ�޹��޸�������ݣ�(help wizrules)");
       CHANNEL_D->do_channel(me,"wiz","���߻ָ���"+ob->query("name")+"("+ob->query("id")+")��״̬��\n");
       log_file("full_player",ob->query("id")+"is fulled by "+me->query("id"));}
       }
       else
       ob = me;
       
       heal = (int)ob->query("max_qi") - (int)ob->query("qi");
       heal1 = (int)ob->query("max_qi") - (int)ob->query("eff_qi");
        ob->add("eff_qi",heal1);
        ob->add("qi",heal);
       heal = (int)ob->query("max_jing") - (int)ob->query("jing");
       heal1 = (int)ob->query("max_jing") - (int)ob->query("eff_jing");
       neili = (int)ob->query("max_neili");
        ob->add("eff_jing",heal1);
        ob->add("jing",heal);
        ob->set("neili",neili*2);
		ob->set("jingli",ob->query("max_jingli")*2);
       heal = ob->max_water_capacity();
       heal1 = ob->max_food_capacity();
        ob->set("food",heal1);
        ob->set("water",heal);
        ob->clear_condition();
        ob->reincarnate();
tell_object(ob,"��ָ��ɹ���!!\n");
     return 1;
}
int help()
{
       write( @TEXT
ָ���ʽ��full
���ָ���������������
TEXT
       );
       return 1 ;
}


