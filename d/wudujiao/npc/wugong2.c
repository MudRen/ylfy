// by victori
inherit NPC;
#include "duchong.h"
#include <ansi.h>

void create()
{
        set_name("金背蜈蚣",({"wu gong"}));
	set("race", "野兽");
        set("long", "一条一尺多长，鬼头鬼脑的小蜈蚣。\n");
	set("age", 100);
	set("attitude", "peaceful");

	set("max_jing", 1500);
	set("max_qi", 1500);
	set("jiali",50);
//           set("max_neili",1500);	
	set("neili",1500);

	set("str", 70);
	set("con", 50);

	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/armor", 150);
	set_temp("apply/damage", 100);
       set_skill("unarmed",180+random(300));
       set_skill("parry",180+random(300));
       set_skill("dodge",180+random(300));
       set_skill("force",180+random(300));

	set("combat_exp", 1000000+random(40)*100000);
       set_weight(5000);
	

	setup();
}
