// mujiang.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("ľ��", ({ "mu jiang", "mu", "jiang" }) );
	set("gender", "����" );
	set("age", 32);
	set("long",
		"��λľ��������ͷ��������Ϊ��������ע����������̧��ͷ��΢Ц��һ�¡�\n");
	set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"d/xiangyang/obj/mujian",
		"d/xiangyang/obj/mudao",
        "d/xiangyang/obj/mugun",
	}) );
	setup();
        carry_object("/clone/cloth/cloth")->wear();
	add_money("coin", 100);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

