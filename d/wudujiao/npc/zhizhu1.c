// by victori
inherit NPC;
#include "duchong.h"

#include <ansi.h>


string *first_name = ({"��", "����", "���", "����"});
string *name_words = ({ "֩��"});
void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        set_name(name,({"zhi zhu"}));
	set("race", "Ұ��");
        set("long", "һֻ������С����ͷ���Ե�С֩�롣\n");
	set("age", 100);
	set("attitude", "peaceful");

	set("max_jing", 600);
	set("max_qi", 800);

	set("str", 20);
	set("con", 50);

	set("limbs", ({ "ͷ��", "����", "����" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 80);
	set_temp("apply/damage", 80);

	set("combat_exp", 100000+random(40)*10000);
 
        set_weight(5000);
	setup();
}
