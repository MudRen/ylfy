// pingwei.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("ƽ��", ({ "ping wei", "wei" ,"ping"}));
	set("gender", "����");
	set("title", HIC"������̫��"NOR);
	set("age", 26);
	set("per", 16);
	set("long", "һ�����ֺ��ӣ��������ͣ���ϧ�Ǹ�̫�ࡣ\n");

	set("combat_exp", 3000);
	set("shen_type", 0);

	set_skill("unarmed", 10);
	set_skill("blade", 10);
	set_skill("parry", 10);
	set_skill("dodge", 10);
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	set("chat_chance", 10);
	set("chat_msg", ({
	      (: random_move :),
	}));

	setup();
	add_money("silver", random(10));
	carry_object("d/huanggong/obj/taijianfu")->wear();
}
	
