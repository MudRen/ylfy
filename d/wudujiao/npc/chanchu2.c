// by victori
inherit NPC;
#include "duchong.h"
#include <ansi.h>

void create()
{
        set_name("ç�����",({"chan chu"}));
	set("race", "Ұ��");
        set("long", "һֻȭͷ��С�����������Ķ���󡡣\n");
	set("age", 1000);
	set("attitude", "peaceful");

	set("max_jing", 500);
	set("max_qi", 1000);
//           set("max_neili",1500);	
	set("neili",1000);

	set("str", 80);
	set("con", 50);

	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);
       set_skill("unarmed",180+random(200));
       set_skill("parry",180+random(200));
       set_skill("dodge",180+random(200));
       set_skill("force",180+random(200));

	set("combat_exp", 1000000+random(40)*100000);
        set_weight(5000);
	setup();
}
