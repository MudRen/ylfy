// niu.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIY"�ϻ�ţ"NOR, ({ "huang niu", "niu" }) );
        set("race", "Ұ��");
        set("long", "һͷƤ����ͷ���ݵ�û����ϻ�ţ��\n");
        set("attitude", "peaceful");
        set("str", 30);
        set("cor", 30);
        set("limbs", ({ "��", "����", "ǰ��", "���" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("age", 5);
        set_temp("apply/attack", 5);
        set_temp("apply/damage", 3);
        set_temp("apply/armor", 5);

        setup(); 
        set("chat_chance", 10);
        set("chat_msg", ({
                "�ϻ�ţ��ͷֱ�У����裡�裡�裡�裡�裡��\n",
        } ) );                 
}


