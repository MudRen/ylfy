// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("С��", ({ "xiao fan", "seller", "fan" }) );
        set("gender", "����" );
        set("age", 32);
        set("long",
                "���Ǹ�С����������������ʵʵ�������������Ƕ��ͱ��ˡ�\n");
        set("shen_type", 1);
        set("combat_exp", 10000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "peaceful");
        set_skill("dodge",20);
        set_skill("unarmed",20);
        set("vendor_goods", ({
                "/d/dali/npc/obj/huotui",
                "/d/dali/npc/obj/hupi",
                "/d/dali/npc/obj/lace",
        }) );

        setup();
        carry_object("clone/cloth/cloth")->wear();
        add_money("coin", 100);
}

void init()
{
        ::init();
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}