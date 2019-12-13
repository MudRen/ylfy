// by victori 
inherit NPC;
#include "duchong.h"
#include <ansi.h>

void create()
{
        set_name("腾蛇",({"du she"}));
	set("race", "野兽");
        set("long", "一条十丈多长一人来粗的大蛇，据说腾蛇万年可以化龙飞去。\n");
	set("age", 10000);
	set("attitude", "peaceful");

	set("max_jing", 1500);
	set("max_qi", 1500);
//           set("max_neili", 4000);	
	set("jiali", 200);
	set("neili", 1000);

	set("str", 90);
	set("con", 50);

	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 300);
	set_temp("apply/defense", 200);
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
