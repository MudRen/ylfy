// by victori
inherit NPC;
#include "duchong.h"
#include <ansi.h>
// #include "init.h"
#define A_TIME 10
string *first_name = ({"五毒", "巨眼", "大肚", "花斑"});
string *name_words = ({"蟾蜍"});
void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        set_name(name,({"chan chu"}));
	set("race", "野兽");
        set("long", "一只拳头大小，鬼头鬼脑的小蛤蟆。\n");
	set("age", 100);
	set("attitude", "peaceful");

	set("max_jing", 200);
	set("max_qi", 800);

	set("str", 40);
	set("con", 50);

	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 40);

	set("combat_exp", 100000+random(40)*10000);
 
        set_weight(5000);
	setup();
}
