// tufei1.c
inherit NPC;
void create()
{
    set_name("����", ({
 "tufei","bandit","fei" }) );
    set("gender", "����");
    set("age", 30);
    set("long",
        "��һ��������⪬һ�������ɷ��ģ��������������η��\n");
    set("combat_exp", 10000);
        set("shen", -100);
    set("attitude", "aggressive");
    set("apply/attack", 20);
    set("apply/defense", 20);
    set("chat_chance", 30);
    set("chat_msg", ({
        "����һ����: ��ɽ���ҿ������������ԣ���Ҫ�Ӵ˹���������·�� !\n",
    }) );
    set_skill("unarmed", 40);
    set_skill("sword", 20);
    set_skill("parry", 40);
    set_skill("dodge", 40);
    setup();
        carry_object("/clone/weapon/duanjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
    add_money("silver", 1);
}