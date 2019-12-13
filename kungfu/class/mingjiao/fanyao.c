// FanYao.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_me();

void create()
{
    set_name("��ң", ({"fan yao","fan","yao",}));
	set("long",
        "����һλ�������е�ͷ�ӣ����ײ����ۡ�\n"
        "�����������߰˰˵�ȫ���˰̣���ֱ������������Ŀ�ˡ�\n"
	);

	set("title",HIG "����" HIR "������ʹ" NOR);
	set("level",11);
	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 38);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 3500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 5000000);
	set("score", 800000);

	set_skill("force", 250);
	set_skill("hunyuan-yiqi", 280);
	set_skill("dodge", 140);
	set_skill("shaolin-shenfa", 230);
	set_skill("unarmed", 270);
	set_skill("strike", 260);
	set_skill("unarmed", 200);
	set_skill("unarmed", 220);
	set_skill("parry", 210);
	set_skill("nianhua-zhi", 280);
	set_skill("sanhua-zhang", 280);
	set_skill("fengyun-shou", 210);
	set_skill("longzhua-gong", 210);
	set_skill("buddhism", 300);
	set_skill("literate", 180);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("unarmed", "fengyun-shou");
	map_skill("unarmed", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");

	set("inquiry", ([
        "����ʥ����"     : (: ask_me :)
	]));

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: prepare_skill("unarmed", "nianhua-zhi") :),
		(: prepare_skill("strike", "sanhua-zhang") :),
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
#include "fanyao.h"
