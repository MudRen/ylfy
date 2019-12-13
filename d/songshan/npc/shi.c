// shi.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("Ê·µÇ´ï", ({ "shi dengda", "dengda", "shi" }) );
	set("nickname", HIG"Ç§ÕÉËÉ"NOR);
	set("gender", "ÄÐÐÔ");
	set("class", "swordsman");
	set("age", 25);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 30);
	set("max_qi",1000);
	set("max_jing",800);
	set("combat_exp", 200000);
	set("shen_type", -1);

	set_skill("literate", 50);
	set_skill("unarmed", 80);
	set_skill("sword", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("songshan-jian", 120);
	set_skill("songyang-zhang", 120);
	set_skill("hanbing-zhenqi", 80);
	set_skill("lingxu-bu", 120);
	map_skill("unarmed", "songyang-zhang");
	map_skill("sword", "songshan-jian");
	map_skill("parry", "songshan-jian");
	map_skill("dodge", "lingxu-bu");
	map_skill("force", "hanbing-zhenqi");
	
	create_family("áÔÉ½ÅÉ", 14, "µÜ×Ó");
	set("chat_chance_combat", 60);
	
	setup();

	carry_object("d/songshan/obj/kuojian")->wield();
	carry_object("d/songshan/obj/yellow-cloth")->wear();
}

