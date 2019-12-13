#include <ansi.h>
inherit NPC;
int ask_gao();
void create()
{
    set_name("�޸�����", ( { "wugen daozhang", "wugen","daozhang" }) );
    set("title", "�����̳���ʹ");
    set("gender", "����" );
    set("age", 55);
    set("long",
          "���Ǹ���ʮ����ĺ������,��ò����,�����Դ�ɱ����\n"
         );
    set("int", 30);
    set("str", 25);
    set("con", 25);
    set("dex", 25);
    set("qi", 2000);
    set("max_qi", 2000);
    set("jing", 500);
    set("max_jing", 500);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 100);
    set("combat_exp", 250000);
    set("score", 15000);
    set_temp("apply/attack", 60);
    set_temp("apply/defense", 60);
    set_temp("apply/damage", 40);
    set_skill("unarmed",90);
    set_skill("huashan-zhangfa", 90);
    set_skill("force", 90);
    set_skill("zixia-shengong", 80);
    set_skill("dodge", 90);
    set_skill("parry", 90);
    set_skill("sword", 100);
    set_skill("huashan-jianfa", 90);
    set_skill("huashan-shenfa",80);
    set_skill("literate", 80);
    map_skill("force", "zixia-shengong");
    map_skill("unarmed", "huashan-zhangfa");
    map_skill("dodge", "huashan-shenfa");
    map_skill("parry", "huashan-jianfa");
    map_skill("sword", "huashan-jianfa");
       set("inquiry", ([
        "������" :  "\nһ�������벻���������̵�(join shenlongjiao).\n",
        "�鰲ͨ" :  "\n����Ƣ������,Ҫ�������Ĳźá�\n",
        "����" :  "\n����Ƣ������,Ҫ�������Ĳźá�\n",
        "���" :  "\nһ�������벻���������̵�(join shenlongjiao).\n",
        "�ں�" : "\n���겻��!�����ɸ�!��������!������ʥ!\n",
    ]));
    setup();
        carry_object("/clone/weapon/duanjian")->wield();
		carry_object("/clone/cloth/cloth")->wear();
    add_money("silver",10);
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
    if( !arg || (arg!="wugen"&&arg!="daozhang"))
     return 0;
   if(wizardp(ob)) return 0;
  if (!ob->query("shenlongjiao"))
  {
   message_vision("$Nҡ��ҡͷ��\n",this_object());
   write("�޸�����˵��������ô�ܿ��ҵ��书�أ�\n");
   return 1;
  }
   command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �����Ṧ (dodge)                         - һ����ʦ  90/    \n"+
"  �����ڹ� (force)                         - һ����ʦ  90/    \n"+
"����ɽ�Ʒ� (huashan-zhangfa)               - һ����ʦ  90/    \n"+
"����ɽ���� (huashan-jianfa)                - һ����ʦ  90/    \n"+
"����ɽ�� (huashan-shenfa)                - �Ƿ��켫  80/    \n"+
"  ����д�� (literate)                      - ������˫  80/    \n"+
"  �����м� (parry)                         - һ����ʦ  90/    \n"+
"  �������� (sword)                         - ��ɲ� 100/    \n"+
"  ����ȭ�� (unarmed)                       - һ����ʦ  90/    \n"+
"����ϼ�� (zixia-shengong)                - �Ƿ��켫  80/    \n");
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
    message_vision(HIC "�޸�����˵�������Ѿ��������̵����ˡ�\n" NOR,this_player());
    return 1;
    }
   if ((int)ob->query("shen")>-1000)
        {
    message_vision(HIC "�޸�������$N��ŭ�����������?һ����Ͳ��Ǻ���!\n" NOR,this_player());
    set_leader(this_player());
    remove_call_out("kill_ob");
    call_out("kill_ob", 1, this_player()); 
    return 1;
    }
   if (ob->query("combat_exp")<20000)
        {
    message_vision(HIC "�޸�������$Nҡͷ�������ʵս����̫�͡�\n" NOR,this_player());
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
   message_vision(HIC "�޸�������$N��ŭ�����������?һ����Ͳ��Ǻ���!\n" NOR,this_player());
    set_leader(this_player());
    remove_call_out("kill_ob");
    call_out("kill_ob", 1, this_player()); 
    return 1;
    }
}
void init()
{
    object ob;
    ::init();
add_action("do_skills","skills");
add_action("do_skills","cha");
add_action("do_join","join");
    if( interactive(ob = this_player()) && !is_fighting() ) {
        remove_call_out("greeting");
        call_out("greeting", 50, ob);
    }
}
void greeting(object ob)
{
    object obj;
        if( !ob || environment(ob) != environment() ) return;
        if (interactive(ob))
        {
    if (obj = present("usedgao", ob))          
       set("combat_exp",100000);
       set("qi",100);
       set("jing",100);
    }
    return;
}
