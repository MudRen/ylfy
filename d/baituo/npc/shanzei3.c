//shanzei3.c
inherit NPC;
void create()
{
    set_name("ɽ��ͷ", ({ "shanzei tou","tou" }) );
    set("gender", "����" );
    set("age", 29);
    set("long", "���Ǹ���³��ɽ��ͷ��\n");
    set("attitude", "friendly");
    set("shen_type", -1);
    set("str", 24);
    set("int", 23);
    set("con", 24);
    set("dex", 23);
    set("max_qi", 200);
    set("max_jing", 200);
    set("neili", 100);
    set("max_neili", 100);
    set("combat_exp", 30000+random(5000));
    setup();
    add_money("silver", 11);
    carry_object("/d/baituo/obj/dadao")->wield();
}
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()))
        {
              command("say ���Ҵ�������");
                this_object()->kill_ob(ob);
        }
}
void die()
{
        object killer;
        if( objectp(killer = query_temp("last_damage_from")) )
                 killer->add_temp("��",10);
           ::die();
}
