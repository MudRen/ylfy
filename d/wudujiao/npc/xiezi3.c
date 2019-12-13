// by victori
inherit NPC;
#include "duchong.h"
#include <ansi.h>


void create()
{
        set_name("九尾蝎",({"xie zi"}));
	set("race", "野兽");
        set("long", "一条一丈来长，有九只尾蛰的大蝎子。\n");
	set("age", 10000);
	set("attitude", "peaceful");

	set("max_jing", 2500);
	set("max_qi", 2500);
	set("neili", 2000);
//           set("max_neili", 4000);	
	set("jiali", 200);

	set("str", 100);
	set("con", 50);

	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 200);
	set_temp("apply/defense", 350);
	set_temp("apply/armor", 200);
	add_temp("apply/damage", 100);
        set_skill("unarmed",200+random(580));
       set_skill("parry",200+random(580));
       set_skill("dodge",200+random(580));
       set_skill("force",200+random(580));
	set("combat_exp", 5000000+random(100)*100000);
 
 
        set_weight(5000);
	setup();
}
