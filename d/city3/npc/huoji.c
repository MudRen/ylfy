//bye enter

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("���", ({ "huo ji","huo","ji"}));
        set("str", 20);
        set("gender", "����");
        set("age", 18);
        set("long", "���������м�������������ͦ�ڿ�ġ�\n");
        set("combat_exp", 2500);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/clone/cloth/necklace",
                "/d/city/obj/goldring",
                __DIR__"obj/ring",
                __DIR__"obj/haiyang",
        }));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

