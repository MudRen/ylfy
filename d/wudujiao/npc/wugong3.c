// by victori
inherit NPC;
#include "duchong.h"
#include <ansi.h>

void create()
{
        set_name("��ɽ����",({"wu gong"}));
	set("race", "Ұ��");
        set("long", "һ������೤������һ˫���ľ綾��򼡣\n");
	set("age", 10000);
	set("attitude", "peaceful");

	set("max_jing", 2500);
	set("max_qi", 2500);
	set("neili", 2000);
//           set("max_neili", 4000);	
	set("neili", 2000);
	set("jiali", 200);

	set("str", 40);
	set("con", 50);

	set("limbs", ({ "ͷ��", "����", "β��" }) );
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
