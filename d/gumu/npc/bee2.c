// bee2.c  By csy 98/12
inherit NPC;
#include <ansi.h>
#include "bee2.h"
void create()
{
        set_name("���", ({ "yu feng", "bee","feng" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һֻ�ɰ�����䣬������С��Ů��ǰ�����ġ�\n");
        set("attitude", "peaceful");         

        set("str", 20);
        set("con", 30);

        set("limbs", ({  "����",  "���" , "ͷ��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 5000);

        set_temp("apply/attack", 35);
        set_temp("apply/damage", 23);
        set_temp("apply/armor", 24);

        setup();
}

void die()
{
        message_vision("\n$N����һ�»��䣬������ɢ��ʬ��ȫ�ޡ�\n", this_object()); 
        destruct(this_object());
}

