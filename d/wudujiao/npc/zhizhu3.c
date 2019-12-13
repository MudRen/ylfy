// by victori
inherit NPC;
#include "duchong.h"
#include <ansi.h>


void create()
{
        set_name("人面蜘蛛",({"zhi zhu"}));
	set("race", "野兽");
        set("long", "一只面盆大小，长着人样脑袋的大蜘蛛。\n");
	set("age", 100);
	set("attitude", "peaceful");

	set("max_jing", 2500);
	set("max_qi", 2500);
	set("neili", 2000);
//           set("max_neili", 4000);	
	set("jiali", 300);

	set("str", 100);
	set("con", 50);

	set("limbs", ({ "头部", "身体", "长腿" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 300);
	set_temp("apply/defense", 300);
	set_temp("apply/armor", 300);
	add_temp("apply/damage", 200);
       set_skill("unarmed",200+random(580));
       set_skill("parry",200+random(580));
       set_skill("dodge",200+random(580));
       set_skill("force",200+random(580));
	set("combat_exp", 5000000+random(100)*100000);
 
        set_weight(5000);
	setup();
}
