// yangguo.c ���
// By Kayin @ CuteRabbit Studio 99-4-16 21:10 new
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_skills(string arg);
int do_kill(object me, object dest);
void create()
{
	set_name("���", ({ "yang guo", "yang" }));
	set("nickname", HIG "������" NOR);
	set("gender", "����");
	set("age", 30);
	set("int",30);
	set("con",30);
	set("str", 30);
	set("dex", 30);
	set("long", "����һλ�ߴ�����ӣ���ò���㡣\n"+
	"һֻ����տ���Ҳ�����Ƕ���һ�ۣ�������ˣ�\n"+
	"��Ȼ�ڲ�ס�����˵ķ�ɡ�\n");
	set("combat_exp", 5000000);
	set("score", 10000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("sword", 350);
	set_skill("force", 400);
	set_skill("unarmed", 400);
	set_skill("dodge", 350);
	set_skill("parry", 350);
	set_skill("anranxiaohun-zhang",400);
	set_skill("quanzhen-jianfa", 350);
	set_skill("xiantian-qigong", 400);
	set_skill("xianyun-bufa",350);
	map_skill("sword", "quanzhen-jianfa");
	map_skill("force", "xiantian-qigong");
	map_skill("parry", "anranxiaohun-zhang");
	map_skill("unarmed","anranxiaohun-zhang");
	map_skill("dodge", "xianyun-bufa");

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 40);
	set_temp("apply/damage", 100);
	set("neili", 5000); 
	set("max_neili", 5000);
	set("jiali", 100);
        set("inquiry", ([
                "С��Ů" : "������С���\n",
       ]) );
       create_family("��Ĺ��", 3, "����");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("gold", 2);
}

void init()
{
::init();
add_action("do_skills","skills");
add_action("do_skills","cha");
}

int recognize_apprentice(object ob)
{
    if (ob->query("shen")<50000) 
    {
    message_vision("$Nҡ��ҡͷ˵����������ۺ����Ǻܺ�ѽ��\n",this_object());
    return 0;
	}
    if(!ob->query("couple/have_couple"))
    {
command("tell "+ob->query("id")+" �Բ����㻹û���������ˣ��Ҳ��ܽ��㡣\n"); 
	return 0;
}
    return 1;	
}
int do_skills(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="yang" )
     return 0;
  if (ob->query("shen")<50000)
  {
   message_vision("$Nҡ��ҡͷ˵����������۲���ô�ðɣ�\n",this_object());
   return 1;
   }
   command("tell "+ob->query("id")+" �����е��书���£�\n"+
"����Ȼ������ (anranxiaohun-zhang)          - ��ɲ� 400/    0\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 350/    0\n"+    
"  �����ڹ� (force)                         - ��ɲ� 400/    0\n"+
"  ����ȭ�� (unarmed)                       - ��ɲ� 400/    0\n"+
"  �����м� (parry)                         - ��ɲ� 350/    0\n"+
"��ȫ�潣�� (quanzhen-jianfa)               - ��ɲ� 350/    0\n"+
"  �������� (sword)                         - ��ɲ� 350/    0\n"+
"  ������ (xiantian-qigong)                 - ��ɲ� 400/    0\n"+
"�����Ʋ��� (xianyun-bufa)                  - ��ɲ� 350/    0\n");
return 1;
}

int do_kill(object me, object dest)
{
	if( objectp(dest) && present(dest, environment(me))
		 && !environment(me)->query("no_fight"))
	{
		message_vision(HIR "$N��$n˵������һ��а�ɸ��־�������"
			+RANK_D->query_rude(dest)+"����������\n" NOR, me, dest);
		me->set_leader(dest);
		me->kill_ob(dest);
		dest->fight_ob(me);

		call_out("checking", 0,  me, dest);
	}
	else  
		call_out("waiting", 1, me, dest);
	
	return 1;
}
