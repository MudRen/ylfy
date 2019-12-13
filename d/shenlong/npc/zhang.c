
#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
int do_skills(string arg);
int do_join(string arg);
void create()
{
    set_name("�ŵ���", ({ "zhang danyue", "zhang"}));
    set("title", "�����̺���ʹ");
    set("long", "����һ�����´�,��ɫ���,���ӷ���,�ƺ��־��Ѽ�.\n" );
    set("gender", "����");
    set("age", 44);
    set("str", 35);
    set("dex", 20);
    set("max_qi",2000);
        set("qi",2000);
    set("max_jing",500);
        set("jing",500);
    set("combat_exp", 300000);
    set("score", 40000);
    set("shen_type", -1);
    set("attitude", "peaceful");
    set_skill("force", 80);
    set_skill("huagong-dafa", 80);
    set_skill("dodge", 100);
    set_skill("zhaixinggong", 85);
    set_skill("unarmed", 105);
    set_skill("chousui-zhang", 100);
    set_skill("shenlong-bashi", 100);
    set_skill("parry", 70);
    set_skill("staff", 70);
    set_skill("literate", 70);
    map_skill("force", "huagong-dafa");
    map_skill("dodge", "zhaixinggong");
    map_skill("unarmed", "chousui-zhang");
    map_skill("parry", "chousui-zhang");
    set_temp("apply/attack", 40);
    set_temp("apply/defense", 40);
    set_temp("apply/armor", 20);
    set_temp("apply/damage", 30);
    set("neili", 2000); 
    set("max_neili", 2000);
    set("jiali", 50);
        set("inquiry", ([
        "������" :  "һ�������벻���������̵�(join shenlongjiao).\n",
        "���" :  "һ�������벻���������̵�(join shenlongjiao).\n",
        "�鰲ͨ" :  "����Ƣ������,Ҫ�������Ĳźá�\n",
        "����" :  "����Ƣ������,Ҫ�������Ĳźá�\n",
        "�ں�" : "���겻��!�����ɸ�!��������!������ʥ!\n",
       ]) );
    setup();
    carry_object("/clone/cloth/cloth")->wear();
    add_money("silver", 10);
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
   write("�ŵ���˵��������ô�ܿ��ҵ��书�أ�\n");
   return 1;
  }
   command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 100/    \n"+
"  �����ڹ� (force)                         - �Ƿ��켫  80/    \n"+
"�������� (huagong-dafa)                  - �Ƿ��켫  80/    \n"+
"  ����д�� (literate)                      - ��Ȼ��ͨ  70/    \n"+
"  �����м� (parry)                         - �����뻯  70/    \n"+
"  �����ȷ� (staff)                         - �����뻯  70/    \n"+
"  ������ʽ (shenlong-bashi)                - ��ɲ� 100/    \n"+
"  ����ȭ�� (unarmed)                       - ��ɲ� 105/    \n"+
"�������Ʒ� (chousui-zhang)               - ��ɲ� 100/    \n"+
"��ժ�ǹ� (zhaixinggong)                    - �Ƿ��켫  85/    \n"+
"  �����ȷ� (staff)                         - ��ɲ� 100/    \n");
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
    message_vision(HIC "�ŵ���˵�������Ѿ��������̵����ˡ�\n" NOR,this_player());
    return 1;
    }
   if ((int)ob->query("shen")>-1000)
        {
    message_vision(HIC "�ŵ��¶�$N��ŭ�����������?һ����Ͳ��Ǻ���!\n" NOR,this_player());
    set_leader(this_player());
    remove_call_out("kill_ob");
    call_out("kill_ob", 1, this_player()); 
    return 1;
    }
   if (ob->query("combat_exp")<20000)
        {
    message_vision(HIC "�ŵ��¶�$Nҡͷ�������ʵս����̫�͡�\n" NOR,this_player());
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
   message_vision(HIC "�ŵ��¶�$N��ŭ�����������?һ����Ͳ��Ǻ���!\n" NOR,this_player());
    set_leader(this_player());
    remove_call_out("kill_ob");
    call_out("kill_ob", 1, this_player()); 
    return 1;
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
