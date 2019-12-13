// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("С��", ({ "seller" }) );
	set("gender", "����" );
	set("age", 32);
	set("long",
		"���Ǹ�С����������������ʵʵ�������������Ƕ��ͱ��ˡ�\n");
	set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "friendly");
	set("vendor_goods", ({
		    "clone/cloth/stick",
		    "clone/cloth/shoes",
            "clone/food/bottle",
            "d/village/obj/egg",
	}) );
	setup();
        carry_object("clone/cloth/cloth")->wear();
	add_money("coin", 100);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

