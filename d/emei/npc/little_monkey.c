// little_monkey.c

inherit NPC;

void create()
{
	set_name("С��",({ "little monkey", "monkey"}) );
        set("race", "Ұ��");
        set("age", 7);
        set("long", "����һֻ��Ƥ��С���ӣ�����������ȴϲ��ģ��������\n");
        set("limbs", ({ "ͷ��", "����", "צ��", "β��" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 50);
	set("shen_type", -1);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
        set("attitude", "peaceful");
        set("chat_chance", 20);
        set("chat_msg", ({
                        "С��֨֨�Ľ��ţ���ʱ�Ķ���������\n",
                        (: random_move :),
                        }));
        setup();
}
