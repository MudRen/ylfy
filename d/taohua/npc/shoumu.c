// shoumu.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("��Ĺ��ū", ( { "shoumu jianu", "jianu" }) );
	set("long",
	    "����һ��ר�ſ���Ĺ�ص����ˡ�\n");
	set("attitude", "heroism");
	set("vendetta_mark", "authority");
	set("pursuer", 1);
	set("str", 27);
	set("cor", 26);
	set("cps", 25);
	set("combat_exp", 100000);
	set("chat_chance_combat", 15);
	set("chat_msg_combat", (
	{
		"��Ĺ�˺ȵ�����ô�ĵ��ӣ����Ҷ�ĹѨ�еĶ�����\n",
		"��Ĺ�˺ȵ���Ҫ�õ���֪�����ǰ������Ƥ���ɣ�\n"
	}) );
	set_skill("luoying-shenjian",40);
	set_skill("sword", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	map_skill("sword","luoying-shenjian");
	map_skill("parry","luoying-shenjian");
	add_temp("apply/attack", 50);
	add_temp("apply/defense", 50);
	add_temp("apply/damage", 50);
	add_temp("apply/armor", 50);
	setup();
	carry_object("/kungfu/class/taohua/obj/cloth");
	carry_object("/clone/weapon/changjian")->wield();
}
