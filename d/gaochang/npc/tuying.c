// Jay 5/23/96
inherit NPC;
void create()
{
        set_name("ͺӥ", ({ "tu ying", "ying", "tu" }) );
        set("race", "Ұ��");
        set("age", 3);
        set("dex", 1000);
        set("long", "һֻ�ȳ�ª���������ͺӥ��\n");
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "���", "צ��", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 130000);
        set_temp("apply/attack", 3);
        set_temp("apply/defense", 5);
        set_temp("apply/armor", 1);
        set("chat_chance", 10);
        set("chat_msg", ({
        "ͺӥ���¸¸¡��ؽ��˼�����\n",       
                  "ͺӥ��ɳ������Ծ�š�\n",
        }) );
        setup();
}
