// tufei2.c

inherit NPC;

void create()
{
	set_name("����", ({ "tufei","bandit","fei" }) );
	set("gender", "����");
	set("age", 20);
	set("long",
		"��һ��������⪬һ�������ɷ��ģ��������������η��\n");
	set("combat_exp", 5000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack", 10);
	set("apply/defense", 10);

//	set("chat_chance", 30);
//	set("chat_msg", ({
//		"����һ����: ��ɽ���ҿ������������ԣ���Ҫ�Ӵ˹���������·�� !\n",
//	}) );

	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

	setup();
        carry_object("/clone/cloth/cloth")->wear();
	add_money("gold", 2);
}
