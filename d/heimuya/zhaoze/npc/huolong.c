//huolong.c
inherit NPC;
void create()
{
        set_name("火龙", ({ "huo long", "long" }) );
        set("race", "野兽");
        set("age", 200000);
        set("long", "一只史前的庞然大物，它口喷火焰，气势凶凶，好象要一口把你吞下。\n");
        set("attitude", "aggressive");
        set("no_chang", 1);
        set("qi", 40000);
        set("max_qi", 40000);
        set("jing", 5000);
        set("max_jing", 5000);
        set("max_neili", 20000);
        set("jiali",3000);
        set("neili",2000000);
        set ("max_jingli",20000);
        set ("jingli",200000);
        set("str", 1000);
        set("dex", 580);
        set("int",3000);
        set("con",50000);
        set_skill("dodge", 10000);
        set("limbs", ({ "头部", "爪子","后脚","身体", "尾巴" }) );
        set("verbs", ({ "bite","hoof","claw","knock"}) );

        set("combat_exp", 100000000);

        set_temp("apply/attack", 850);
        set("apply/dodge", 800);
        set_temp("apply/damage", 800);
        set_temp("apply/armor", 100000);
        set_temp("apply/defence",800);
        setup();
}
void die()
{
        object ob;
        message_vision("$N惨嚎一声，浑身喷出巨大的火焰，身体一下就变成一堆灰烬！\n", this_object());
        ob = new(__DIR__"obj/huolongjin");
        ob->move(environment(this_object()));
        destruct(this_object());
}

