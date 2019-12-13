// zhuziliu.c

#include <ansi.h>
inherit NPC;
void create()
{
	set_name("朱子柳", ({"zhu ziliu", "zhu", "ziliu"}));
	set("gender", "男性");
	set("age", 55);
	set("long", "一灯大师的四大弟子之一。\n");
 	set("attitude", "peaceful");
	
	set("per", 17);
	set("str", 40);
	set("int", 20);
	set("con", 30);
	set("dex", 25);

	set("qi", 3500);
	set("max_qi", 3500);
	set("eff_jingli", 4000);
	set("max_jing", 3500);
	set("neili", 45000);
	set("max_neili", 4500);
	set("inquiry",([
//                   "守城": (:give_job:),	
//                   "完成": (:task_ok:),	
		]));
	
	set("combat_exp", 9000000);
     	set_skill("force", 170);
	set_skill("yiyang-zhi", 170);
	set_skill("jinyu-quan", 170);
	set_skill("dodge", 1700);
	set_skill("parry", 170);
       set_skill("unarmed",800);
	
	map_skill("unarmed", "yiyang-zhi");
	map_skill("parry", "yiyang-zhi");
	reincarnate();
	setup();
   	carry_object("clone/weapon/gangjian")->wield();
	carry_object("clone/armor/tiejia")->wear();	
	
}
