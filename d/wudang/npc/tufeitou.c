// tufeitou.c
inherit NPC;
void create()
{
    set_name("����ͷ", ({
 "tufei tou","bandit leader","tou" }) );
    set("gender", "����");
    set("age", 45);
    set("long",
        "��һ�����ɱ����һ�������ɷ��ģ��������������η��\n");
    set("combat_exp", 20000);
        set("shen", -300);
    set("attitude", "aggressive");
    set("apply/attack",  30);
    set("apply/defense", 30);
    set("chat_chance", 5);
    set("chat_msg", ({
        "����ͷ�ٺٵ���Ц��: ������ͱ����������ų�ȥ��!\n",
    }) );
    set_skill("sword", 30);
    set_skill("unarmed", 50);
    set_skill("parry", 50);
    set_skill("dodge", 50);
    setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
    add_money("silver", 10);
}
