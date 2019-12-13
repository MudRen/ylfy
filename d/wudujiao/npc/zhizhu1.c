// by victori
inherit NPC;
#include "duchong.h"

#include <ansi.h>


string *first_name = ({"毒", "长腿", "大肚", "花斑"});
string *name_words = ({ "蜘蛛"});
void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        set_name(name,({"zhi zhu"}));
	set("race", "野兽");
        set("long", "一只鸡蛋大小，鬼头鬼脑的小蜘蛛。\n");
	set("age", 100);
	set("attitude", "peaceful");

	set("max_jing", 600);
	set("max_qi", 800);

	set("str", 20);
	set("con", 50);

	set("limbs", ({ "头部", "身体", "长腿" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 80);
	set_temp("apply/damage", 80);

	set("combat_exp", 100000+random(40)*10000);
 
        set_weight(5000);
	setup();
}
