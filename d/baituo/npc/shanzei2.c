//shanzei2.c
inherit NPC;
void create()
{
    set_name("山贼", ({ "shan zei","shan","zei" }) );
    set("gender", "男性" );
    set("age", 20);
    set("long", "这是个面目可憎的山贼。\n");
    set("attitude", "friendly");
    set("shen_type", -1);
    set("str", 21);
    set("int", 21);
    set("con", 22);
    set("dex", 21);
    set("max_qi", 200);
    set("max_jing", 200);
    set("neili", 80);
    set("max_neili", 80);
    set("combat_exp", 10000+random(5000));
    setup();
    add_money("silver", 5);
    carry_object("/d/baituo/obj/dadao")->wield();
}
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()))
        {
        this_object()->kill_ob(ob);
    }
}
void die()
{
        object killer;
        if( objectp(killer = query_temp("last_damage_from")) )
                 killer->add_temp("金花",1);
           ::die();
}
