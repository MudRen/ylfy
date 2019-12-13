// made by lks

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include "ren.h"
void heal_ob();
void recover_ob();
int ask_me();

void create()
{
	set_name("任狂",( {"ren kuang","ren"}));
	set("nickname",HIY"武林孤子"NOR);
	set("gender","男性");
	set("int",30);
	set("con",30);
	set("str",130);
	set("dex",130);
	set("bac",40);
	set("yiqiguan_riyue",2);
	set("age",40);
	set("attitude","peaceful");
	set("combat_exp",6000000);
	set("kill",1000);
	set("long", "英俊潇洒,颇有大将风度。\n");
	set("max_qi", 2000000);
	set("jing", 1700000);
	set("max_jing", 1700000);
	set("jingli", 3000000);
	set("max_jingli", 100000);
	set("neili", 50000000);
	set("max_neili", 500000);
	set("jiali", 10000);
	set("combat_exp", 90000000);
	set("xyzx_sys/level", 1400);
	set_skill("literate",2320);
	set_skill("unarmed",2380);
	set_skill("parry",2380);
	set_skill("dodge",2380);
	set_skill("youran-bu",1380);
	set_skill("yudi-bian",1380);
	set_skill("whip",2380);
	set_skill("jieniu-dao",1380);
	set_skill("blade",2380);
	set_skill("throwing",2300);
	set_skill("sword",2600);
	set_skill("tianhe-jian",1300);
	set_skill("huaxue-shenzhen",1200);
	set_skill("yiqiguan-riyue",1380);
	set_skill("youren-jian",1380);
	set_skill("force",2380);
	set_skill("taoism",2340);
	map_skill("force","yiqiguan-riyue");
	map_skill("blade","jieniu-dao");
	map_skill("dodge","youran-bu");
	map_skill("throwing","youren-jian");
	map_skill("whip","yudi-bian");

	create_family("血河派",12,"弟子");
	setup();
	set("inquiry",([
                   "血河车" : (: ask_me :),
                   "che" : (: ask_me :),
	               ]));
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
	set("chat_chance", 2);
	set("chat_msg", (
	{
(: heal_ob :),
	}));
	set("chat_chance_combat", 30);
	set("chat_msg_combat", (
	{
(: exert_function, "zhibiao" :),
(: recover_ob :),
	}) );
}


void heal_ob()
{
	command("yun heal");
	command("yun heal");
	command("yun heal");
	command("yun recover");
	return;
}

void recover_ob()
{
	command("yun recover");
	return;
}

int ask_me()
{
	mapping fam;

	object me=this_player();

	fam=(mapping)me->query("family");

	if (!fam || fam["family_name"]!="血河派")
	{
		command("say 你与本派并无瓜葛，此话从何说起？");
		return 1;
	}

	if (!(present("xuehe che",environment(me))))
	{
		command("say 血河车已经被取走了。");
		return 1;
	}

	if (me->query("combat_exp")>8000000)
	{
		command("say 好吧，你把血河车开走吧。");
		me->set_temp("ask1",1);
		return 1;
	}
	else
	{
		command("say 你的经验不够，别把血河车给弄丢了。");
		return 1;
	}

}

