// monkey.c 

inherit NPC;

void create()
{
	set_name("�����", ({ "ma hou","monkey"}) );
        set("race", "Ұ��");
	set("age", 8);
	set("long",
		"��ֻ�����ڲ�ͣ���������£�����ʱ�����ζ�ؿм��������ҡ�\n");
     
        set("limbs", ({ "ͷ��", "����", "צ��", "β��" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 500);
        set("shen_type", -1);
	set("attitude", "peaceful");
	set("chat_chance", 20);
        set("chat_msg", ({
                        "����ﲻͣ���������£�����ʱ�����ζ�ؿм��������ҡ�\n",
                        (: random_move :),
           }));setup();
}
