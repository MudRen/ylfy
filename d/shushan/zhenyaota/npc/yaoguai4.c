//yaoguai.c by yushu@SHXY 2001.1
inherit NPC;
#include <ansi.h>
void create()
{
       set_name("妖怪", ({"yao guai", "guai"}));
       set("long", "镇妖塔里被关着的妖怪。\n");
       set("age", 32);
       set("attitude", "aggressive");
       set("str", 30);
       set("int", 30);
       set("per", 10);
       set("con", 30);
       set("combat_exp", 2100000000);
         set("max_jingli",10000000 );
         set("max_neili",10000000 );
         set("neili",10000000 );
         set("jingli",10000000 );
         set("jiali",2000 );
       set("max_qi", 10000000);
       set("max_jing", 10000000);
       set("neili", 10000000);
	   set("no_suck", 1);

         set_skill("shushan-force", 2000);
      set_skill("songhe-sword", 2000);
       set_skill("dodge", 2000);
       set_skill("literate", 2000);
       set_skill("sword", 2000);
       set_skill("force", 2000);
       set_skill("parry", 2000);
       set_skill("xiaoyaoyou", 2000);
       map_skill("dodge", "xiaoyaoyou");
          map_skill("parry", "songhe-sword");
          map_skill("sword", "songhe-sword");
       map_skill("force", "shushan-force");
       set("chat_chance_combat", 20);
       set("chat_msg_combat", ({
                (: perform_action, "sword", "chaofeng" :),
       }) );
       setup();
         carry_object("/clone/weapon/gangjian")->wield();
}
void die()
{
	object ob;
	
	if ( objectp(ob = query_temp("last_damage_from")))
	{
		ob->add("combat_exp", 10000);
		ob->add("potential", 10000);
		message("system", HIC"〖"HIW"镇妖塔传讯"HIC"〗"HIY+ob->query("name")+HIG"杀死[1;37m镇妖塔[1;32m里的妖怪，受到奖励！[2;37;0m\n"NOR,users());    
		tell_object (ob,"你赢得了"+chinese_number(10000)+"点经验"+chinese_number(10000)+"点潜能！\n");
	}
	::die();
}
