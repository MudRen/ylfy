// by victori
inherit NPC;
#include "duchong.h"
#include <ansi.h>


void create()
{
        set_name("����֩��",({"zhi zhu"}));
	set("race", "Ұ��");
        set("long", "һֻ�����С�����������Դ��Ĵ�֩�롣\n");
	set("age", 100);
	set("attitude", "peaceful");

	set("max_jing", 2500);
	set("max_qi", 2500);
	set("neili", 2000);
//           set("max_neili", 4000);	
	set("jiali", 300);

	set("str", 100);
	set("con", 50);

	set("limbs", ({ "ͷ��", "����", "����" }) );
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
