inherit NPC;
#include "duchong.h"
#include <ansi.h>


string *first_name = ({"�嶾", "����", "˫ͷ", "����"});
string *name_words = ({"Ы��"});
void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        set_name(name,({"xie zi"}));
	set("race", "Ұ��");
        set("long", "һ�������������ͷ���Ե�СЫ�ӡ�\n");
	set("age", 100);
	set("attitude", "peaceful");

	set("max_jing", 600);
	set("max_qi", 700);

	set("str", 30);
	set("con", 50);

	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);

	set("combat_exp", 100000+random(40)*10000);
 
        set_weight(5000);
	setup();
}
