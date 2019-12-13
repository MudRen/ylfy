// by victori
inherit NPC;
#include "duchong.h"
#include <ansi.h>


string *first_name = ({"百足", "千节", "大头", "金线"});
string *name_words = ({"蜈蚣"});
void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        set_name(name,({"wu gong"}));
	set("race", "野兽");
        set("long", "一条一尺多长，鬼头鬼脑的小蜈蚣。\n");
	set("age", 100);
	set("attitude", "peaceful");

	set("max_jing", 600);
	set("max_qi", 600);

	set("str", 30);
	set("con", 50);

	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/armor", 80);
	set_temp("apply/damage", 80);

	set("combat_exp", 100000+random(40)*10000);
 
        set_weight(5000);
	setup();
}
