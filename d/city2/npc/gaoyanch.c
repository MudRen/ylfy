// gaoyanchao.c ���峬
#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int ask_weiwang();
int do_skills(string arg);
void create()
{
	set_name("���峬", ({ "gao yanchao", "gao", "yanchao" }));
	set("gender", "����");
	set("age", 32);
	set("str", 25);
	set("dex", 20);
	set("long", "��������ʮ��ͷ��ȴ�Ե��쳣������һ�Բ��������Ƕ�һվ��\n"
            "�����������ݡ�\n");
	set("combat_exp", 40000);
	set("score", 5000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("club", 80);
	set_skill("parry", 70);
	set_skill("literate", 50);
	set_skill("hunyuan-yiqi", 60);
	set_skill("shaolin-shenfa", 60);
	set_skill("zui-gun", 70);
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("club", "zui-gun");
	map_skill("parry", "zui-gun");
	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set_temp("apply/armor", 5);
	set_temp("apply/damage", 25);
	set("qi", 400);
	set("max_qi", 400);
	set("jing", 300);
	set("max_jing", 300);
	set("neili", 250); 
	set("max_neili", 250);
	set("jiali", 35);
        set("inquiry", ([
		"�½���" :  "\n����ܶ����ɲ����װ���\n",
		"��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"���" :  "\nֻҪ��������ػᣬ��������и�λ����ѧ���ա�\n",
                "���帴��" : "ȥ�ײĵ�������ϸ���ưɣ�\n",
                "����" : "�����£�\n",
                "�п�" : "�����£�\n",
                "����" :  (: ask_weiwang :),
                "��������" : (: ask_weiwang :),
       ]) );
	setup();
        carry_object("/d/shaolin/obj/qimeigun")->wield();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("gold", 1);
}
int ask_weiwang()
{
command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
say("\n���峬˵�������������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
say("���峬��˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
return 1;
}
void init()
{
::init();
add_action("do_skills","skills");
add_action("do_skills","cha");
add_action("do_join","join");
}
int recognize_apprentice(object ob)
{
    if (ob->query("weiwang")<50)
    {
    message_vision("$Nҡ��ҡͷ��\n",this_object());
    command("tell "+ob->query("id")+" ������ػ�����Ҳ��̡�\n"); 
    return 0;
    }
	return 1;
}
int do_skills(string arg)
{
   object ob ;
   ob = this_player () ;
    if( !arg || arg!="gao" )
     return 0;
   if(wizardp(ob))    return 0;
  if (ob->query("weiwang")<50)
  {
   message_vision("$Nҡ��ҡͷ��\n",this_object());
   command("tell "+ob->query("id")+" ������ػ���Ӳ��ܲ쿴��\n"); 
   return 1;
   }
   command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �������� (club)                          - �Ƿ��켫  80/    \n"+
"  �����Ṧ (dodge)                         - �����뻯  70/    \n"+
"  �����ڹ� (force)                         - �����뻯  70/    \n"+
"����Ԫһ���� (hunyuan-yiqi)                - ����似  60/    \n"+
"  ����д�� (literate)                      - �������  50/    \n"+
"  �����м� (parry)                         - �����뻯  70/    \n"+
"�������� (shaolin-shenfa)                - ����似  60/    \n"+
"  ����ȭ�� (unarmed)                       - �����뻯  70/    \n"+
"��������� (zui-gun)                       - �����뻯  70/    \n");
return 1;
}
int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="tiandihui" )
	return notify_fail("��Ҫ����ʲô��֯��\n"); 
   if (ob->query("weiwang")<20)
        {
	command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
	message_vision(HIC "���峬��$Nҡ��ҡͷ˵����Ľ�������ֵ̫�͡�\n" NOR,this_player());
	return 1;
  	}
   if (ob->query("combat_exp")<20000)
        {
	message_vision(HIC "���峬��$Nҡ��ҡͷ˵�����ʵս����̫�͡�\n" NOR,this_player());
  	return 1;
  	}
   if(ob->query("weiwang")<50)
   {
    ob->set("weiwang",50);
    message_vision(HIC "$N�Ľ�����������ˣ�\n" NOR,this_player());
    command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
    return 1;	
   }
   else message_vision(HIC "���峬��$Nҡ��ҡͷ˵�����Ѿ������ػ��ˡ�\n" NOR,this_player());
   return 1;
}
int prevent_learn(object me, string skill)
{
    if (me->query("weiwang")<50)  return 1;
    else return 0;
}
