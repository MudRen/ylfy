inherit NPC;
#include "duchong.h"
#include <ansi.h>


string *first_name = ({"五毒", "长螯", "双头", "花斑"});
string *name_words = ({"蝎子"});
void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        set_name(name,({"xie zi"}));
	set("race", "野兽");
        set("long", "一条半尺来长，鬼头鬼脑的小蝎子。\n");
	set("age", 100);
	set("attitude", "peaceful");

	set("max_jing", 600);
	set("max_qi", 700);

	set("str", 30);
	set("con", 50);

	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);

	set("combat_exp", 100000+random(40)*10000);
 
        set_weight(5000);
	setup();
}
