// by victori
inherit NPC;
#include "duchong.h"
#include <ansi.h>
// #include "init.h"
#define A_TIME 10
string *first_name = ({"�嶾", "����", "���", "����"});
string *name_words = ({"���"});
void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        set_name(name,({"chan chu"}));
	set("race", "Ұ��");
        set("long", "һֻȭͷ��С����ͷ���Ե�С��󡡣\n");
	set("age", 100);
	set("attitude", "peaceful");

	set("max_jing", 200);
	set("max_qi", 800);

	set("str", 40);
	set("con", 50);

	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 40);

	set("combat_exp", 100000+random(40)*10000);
 
        set_weight(5000);
	setup();
}
