// animal: snake.c
// Jay 3/18/96

inherit NPC;

void create()
{
        set_name("���", ({ "bee", "yufeng" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "�����Ĵ��۷䣬С��Ů���ǣ��綾��\n");
        set("attitude", "peaceful");

        set("str", 20);
        set("cor", 30);

        set("limbs", ({  "����",  "���" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 1000);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 3);
        set_temp("apply/armor", 2);

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
//                        set_leader(ob);
        }
}

void die()
{
        message_vision("$N����һ�ƻ��䣬����һ�ţ�ʬ��ȫ�ޡ�\n", this_object());
        destruct(this_object());
}

int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("snake_poison",
                victim->query_condition("snake_poison") + 20);
        return 0;
}     

int query_autoload() { return 1; }