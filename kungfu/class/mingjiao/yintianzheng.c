// YinTianZheng.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
    set_name("������", ({"yin tianzheng", "yin", "tianzheng", }));
	set("long",
        "����һλ��Ŀ����ͺ���ߣ���һ����ɫ���ۡ�\n"
        "����üʤѩ�������۽ǣ����ӹ���������ӥ�졣\n"
	);
                                                          
	set("title",HIG "����" HIW "��üӥ��" NOR);
	set("level",9);
	set("gender", "����");
	set("attitude", "peaceful");

	set("age", 72);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 900000);
	set("score", 1000000);

	set_skill("force", 280);
	set_skill("dodge", 220);
	set_skill("unarmed", 285);
	set_skill("parry", 220);
	set_skill("unarmed", 285);
//	set_skill("hand", 185);
	set_skill("literate", 160);
	set_skill("huntian-qigong", 280);
	set_skill("zhaixinggong", 220);
	set_skill("sougu", 285);
	set_skill("longzhua-gong", 240);

	map_skill("force", "huntian-qigong");
	map_skill("dodge", "zhaixinggong");
	map_skill("unarmed", "sougu");
	map_skill("parry", "longzhua-gong");

	prepare_skill("unarmed", "sougu");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("perform muyeyingyang") :),
	}) );

	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}
/*
void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}
*/
#include "fawang.h"
