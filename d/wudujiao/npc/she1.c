// by victori
inherit NPC;
#include "duchong.h"
#include <ansi.h>


string *first_name = ({ "��Ƥ", "����", "�Ľ�", "����"});
string *name_words = ({ "��"});
void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        set_name(name,({"du she"}));
	set("race", "Ұ��");
        set("long", "һ��һ�߶೤����ͷ���Ե�С�ߡ�\n");
	set("age", 100);
	set("attitude", "peaceful");

	set("max_jing", 200);
	set("max_qi", 300);

	set("str", 20);
	set("con", 50);

	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/armor", 80);
	set_temp("apply/damage", 80);

	set("combat_exp", 100000+random(40)*10000);
        set_weight(5000);
	setup();
}
