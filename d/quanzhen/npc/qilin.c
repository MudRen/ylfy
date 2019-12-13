// huo-chan.c

inherit NPC;

void create()
{
        set_name(HIR"������"NOR, ({ "qilin" }) );
        set("race", "Ұ��");
        set("age", 100);
        set("long", "һֻ����ͦ�أ�ͨ���Ƶ����롣\n");
        set("attitude", "aggressive");
        set("max_qi",9000);
        set("qi",9000);
        set("jing",3000);
        set("max_jing",3000);
        set("str", 300);
        set("cor", 200);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���" }) );
        set("verbs", ({ "bite", "claw" }) );

               
        set("chat_msg_combat", ({
                (: this_object(), "random_move" :),
                "������ͻȻ���������һ�ڴ��\n",
                  }) );
                
        set_temp("apply/attack", 300);
        set_temp("apply/damage", 300);
       set_temp("apply/armor", 250);

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
        message_vision("$N�ҽ�һ�������ˣ�\n", this_object());
        ob = new("d/quanzhen/obj/qilinjia.c");
        ob->move(environment(this_object()));
        destruct(this_object());
}

