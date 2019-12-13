
#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_skills(string arg);
int do_join(string arg);
void create()
{
    set_name("������", ({ "zhang laosan", "zhang" }));
    set("title", "������СͷĿ");
    set("gender", "����");
    set("age", 44);
    set("str", 25);
    set("dex", 20);
    set("long", "����һ��������ͷ,һ˫С�۾��������⡣\n");
    set("combat_exp", 25000);
    set("score", 2000);
    set("shen_type", -1);
    set("attitude", "peaceful");
    set_skill("force", 50);
    set_skill("unarmed", 70);
    set_skill("dodge", 70);
    set_skill("parry", 70);
    set_skill("yixingbu", 40);
    set_skill("shenlong-bashi", 50);
    map_skill("parry", "shenlong-bashi");
    map_skill("dodge", "yixingbu");
    set_temp("apply/attack", 15);
    set_temp("apply/defense", 15);
    set_temp("apply/armor", 10);
    set_temp("apply/damage", 10);
    set("neili", 500); 
    set("max_neili", 500);
    set("jiali", 10);
        set("inquiry", ([
        "������" :  "\nһ�������벻���������̵�(join shenlongjiao).\n",
        "���" :  "\nһ�������벻���������̵�(join shenlongjiao).\n",
        "�鰲ͨ" :  "\n����Ƣ������,Ҫ�������Ĳźá�\n",
        "����" :  "\n����Ƣ������,Ҫ�������Ĳźá�\n",
        "�ں�" : "\n���겻��!�����ɸ�!��������!������ʥ!\n",
       ]) );
        set("chat_msg", ({
"�����������е�:������ѵ,ʱ������,�����˵�,���²���!\n",
"�����������е�:��־���Ŀɳɳ�,���������ޱ���!\n",
"�����������е�:��������������,���������ǰ˷�!\n",
"�����������е�:�˷����˳�Ӣ��,������ͬ���¹�!\n",
"�����������е�:���������ɸ�,��������!\n",
        }) );
    setup();
    carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
add_action("do_skills","skills");
add_action("do_skills","cha");
add_action("do_join","join");
}
int recognize_apprentice(object ob)
{
    if (!ob->query("shenlongjiao"))
    {
    message_vision("$Nҡ��ҡͷ��\n",this_object());
    command("tell "+ob->query("id")+"�����ز���ʶ������ʲôҪ�����أ� \n"); 
    return 0;
    }
    return 1;   
}
int do_skills(string arg)
{
   object ob ;
   ob = this_player () ;
    if( !arg || arg!="zhang" )
     return 0;
   if(wizardp(ob)) return 0;
  if (!ob->query("shenlongjiao"))
  {
   message_vision("$Nҡ��ҡͷ��\n",this_object());
   write("������˵��������ô�ܿ��ҵ��书�أ�\n");
   return 1;
  }
   command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �����Ṧ (dodge)                         - �����뻯  70/    \n"+
"  �����ڹ� (force)                         - �������  50/    \n"+
"  �����м� (parry)                         - �����뻯  70/    \n"+
"��������ʽ (shenlong-bashi)                - �������  50/    \n"+
"  ����ȭ�� (unarmed)                       - �����뻯  70/    \n"+
"�����β� (yixingbu)                        - �������  40/    \n");
return 1;
}
int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="shenlongjiao" )
    return notify_fail("��Ҫ����ʲô��֯��\n"); 
   if(ob->query("shenlongjiao")) 
    {
    message_vision(HIC "������˵�������Ѿ��������̵����ˡ�\n" NOR,this_player());
    return 1;
    }
   if ((int)ob->query("shen")>-1000)
        {
    message_vision(HIC "��������$N��ŭ����һ����Ͳ��Ǻ���!\n" NOR,this_player());
    set_leader(this_player());
    remove_call_out("kill_ob");
    call_out("kill_ob", 1, this_player()); 
    return 1;
    }
   if (ob->query("combat_exp")<20000)
        {
    message_vision(HIC "��������$Nҡͷ�������ʵս����̫�͡�\n" NOR,this_player());
    return 1;
    }
  if ( ob->query_skill("bibo-shengong",1)
    || ob->query_skill("hamagong",1)
    || ob->query_skill("huagong-dafa",1))
   {
    ob->set("shenlongjiao",1);
    command("tell "+this_player()->query("id")+" �����ھ��������̵�����.\n");
    return 1;   
   }
   else 
   {
   message_vision(HIC "��������$N��ŭ����һ����Ͳ��Ǻ���!\n" NOR,this_player());
    set_leader(this_player());
    remove_call_out("kill_ob");
    call_out("kill_ob", 1, this_player()); 
    return 1;
    }
}
