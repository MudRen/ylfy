// huo-chan.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(RED"ǧ����"NOR, ({ "huo chan", "chan" }) );
        set("race", "Ұ��");
        set("age", 100);
        set("long", "һֻ����ͦ�أ�ͨ�崿�죬���Ż��磬��������ֱ�е���ܡ�\n");
        set("attitude", "aggressive");
        
        set("str", 30);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("age", 50);
       
        set("chat_msg_combat", ({
                (: this_object(), "random_move" :),
                "��󸰺��ֱ�У�������������������������\n",
                "���ͻȻ���´�𣬵������硣\n"
        }) );
                
        set_temp("apply/attack", 45);
        set_temp("apply/damage", 30);
       set_temp("apply/armor", 5);

        setup();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                random(ob->query_kar() + ob->query_per()) < 30) {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }       
}
void die()
{
        object ob;
        message_vision("$N��һ���������ˣ�\n", this_object());
          ob = new("/d/mingjiao/npc/obj/si-huochan.c");
        ob->move(environment(this_object()));
        destruct(this_object());
}

