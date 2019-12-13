
#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_skills(string arg);
int do_join(string arg);
void create()
{
    set_name("½����", ({ "lu gaoxuan", "lu" ,"gaoxuan"}));
    set("title", "�����̾�ʦ");
    set("nickname",HIC "�������" NOR);
    set("long", "����ͥ����,������Բ,��ò��ΪӢ��.\nȻ���������,ǡ����̼����ɱ��֮��һ��.\n" );
    set("gender", "����");
    set("age", 37);
    set("str", 35);
    set("dex", 20);
    set("max_qi",2000);
        set("qi",2000);
    set("max_jing",500);
        set("jing",500);
    set("combat_exp", 300000);

    set("shen_type", -1);
    set("attitude", "peaceful");
    set_skill("force", 150);
    set_skill("unarmed", 100);
    set_skill("staff", 100);
    set_skill("sword", 100);
    set_skill("parry", 100);
    set_skill("dodge", 100);
    set_skill("hamagong", 90);
    set_skill("yixingbu", 90);
    set_skill("shenlong-bashi", 100);
    set_skill("shedao-qigong", 80);
    set_skill("hamagong", 90);
    set_skill("shexing-diaoshou", 80);
    set_skill("tianshan-zhang", 80);
    map_skill("dodge", "yixingbu");
    map_skill("force", "hamagong");
    map_skill("sword", "shedao-qigong");
    map_skill("unarmed", "shexing-diaoshou");
    map_skill("parry", "shexing-diaoshou");
    map_skill("staff", "tianshan-zhang");
    set_temp("apply/attack", 60);
    set_temp("apply/defense", 60);
    set_temp("apply/armor", 30);
    set_temp("apply/damage", 60);
    set("neili", 2000); 
    set("max_neili", 2000);
    set("jiali", 75);
        set("inquiry", ([
        "������" :  "һ�������벻���������̵�(join shenlongjiao).\n",
        "���" :  "һ�������벻���������̵�(join shenlongjiao).\n",
        "�鰲ͨ" :  "����Ƣ������,Ҫ�������Ĳźá�\n",
        "����" :  "����Ƣ������,Ҫ�������Ĳźá�\n",
        "�ں�" : "���겻��!�����ɸ�!��������!������ʥ!\n",
       ]) );
       
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: command("wield sword") :),
        (: perform_action, "sword.chang" :),
        (: perform_action, "sword.chang2" :),
        (: perform_action, "sword.chang3" :),
        
    }) );


    setup();
    carry_object("/clone/cloth/cloth")->wear();
    carry_object("/d/city/obj/changjian");
    add_money("silver", 10);
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
    if( !arg || arg!="pang" )
     return 0;
   if(wizardp(ob)) return 0;
  if (!ob->query("shenlongjiao"))
  {
   message_vision("$Nҡ��ҡͷ��\n",this_object());
   write("½����˵��������ô�ܿ��ҵ��书�أ�\n");
   return 1;
  }
   command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 100/    \n"+
"  �����ڹ� (force)                         - ��ɲ� 150/    \n"+
"  �����м� (parry)                         - ��ɲ� 100/    \n"+
"���ߵ��湦 (shedao-qigong)                 - �Ƿ��켫  80/    \n"+
"  ������ʽ (shenlong-bashi)                - ��ɲ� 100/    \n"+
"  �������� (sword)                         - ��ɲ� 100/    \n"+
"  �����ȷ� (staff)                         - ��ɲ� 100/    \n"+
"  ����ȭ�� (unarmed)                       - ��ɲ� 100/    \n"+
"����󡹦 (hamagong)                        - һ����ʦ  90/    \n"+
"�����ε��� (shexing-diaoshou)              - �Ƿ��켫  80/    \n"+
"����ɽ�ȷ� (tianshan-zhang)                - �Ƿ��켫  80/    \n"+
"�����β� (yixingbu)                        - һ����ʦ  90/    \n");
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
    message_vision(HIC "½����˵�������Ѿ��������̵����ˡ�\n" NOR,this_player());
    return 1;
    }
   if ((int)ob->query("shen")>-1000)
        {
    message_vision(HIC "½������$N��ŭ�����������?һ����Ͳ��Ǻ���!\n" NOR,this_player());
    set_leader(this_player());
    remove_call_out("kill_ob");
    call_out("kill_ob", 1, this_player()); 
    return 1;
    }
   if (ob->query("combat_exp")<20000)
        {
    message_vision(HIC "½������$Nҡͷ�������ʵս����̫�͡�\n" NOR,this_player());
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
   message_vision(HIC "½������$N��ŭ�����������?һ����Ͳ��Ǻ���!\n" NOR,this_player());
    set_leader(this_player());
    remove_call_out("kill_ob");
    call_out("kill_ob", 1, this_player()); 
    return 1;
    }
}
