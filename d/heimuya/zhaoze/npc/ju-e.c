//ju-e.c
inherit NPC;
void create()
{
        set_name("����", ({ "ju e", "e" }) );
        set("race", "Ұ��");
        set("age", 200000);
        set("long", "һֻ��Ȼ������������,����Ҫһ�ڰ������¡�\n");
        set("attitude", "aggressive");
        set("no_chang", 1);
        set("qi", 40000);
        set("max_qi", 40000);
        set("jing", 5000);
        set("max_jing", 5000);
        set("max_neili", 20000);
        set("jiali",2000);
        set("neili",2000000);
        set ("max_jingli",20000);
        set ("jingli",200000);
        set("str", 860);
        set("dex", 580);
        set("int",3000);
        set("con",50000);
        set_skill("dodge", 5000);
        set_skill("parry", 5000);
        set("limbs", ({ "ͷ��", "צ��","���","����", "β��" }) );
        set("verbs", ({ "bite","hoof","claw","knock"}) );

        set("combat_exp", 10000000);
        set("chat_chance", 3);
        set("chat_msg", ({
        (: random_move :)
        }) );
        set_temp("apply/attack", 850);
        set("apply/dodge", 800);
        set_temp("apply/damage", 800);
        set_temp("apply/armor", 20000);
        set_temp("apply/defence",800);
        setup();
}

void die()
{
        object ob;
        message_vision("$N�Һ�һ�������ˣ�\n", this_object());
        ob = new(__DIR__"obj/epi");
        ob->move(environment(this_object()));
        destruct(this_object());
}

