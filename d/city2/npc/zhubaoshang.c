// seller.c
inherit NPC;
inherit "/feature/baoshi.c";

void create()
{
    set_name("金银花", ({ "jin yinhua", "jin" }) );
    set("gender", "女性" );
    set("age", 32);
    set("long",
        "金万财的小女，据说金家世代做着珠宝生意，收藏有不少的金银珠宝。\n" +
		"作为金家最小的她更是倍得娇宠，从小就穿金戴银，人也长得漂亮，年轻时\n" +
		"不知迷倒多少少家公子，你看现在虽徐娘半老仍是风韵犹存,隔壁钱老本对她追得可紧呢。\n");
	set("shen_type", 1);
	set("combat_exp", 300);
	set("str", 17);
	set("dex", 20);
	set("con", 17);
	set("int", 22);
    set("attitude", "peaceful");
    setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("coin", 100);
}

void init()
{
	if (base_name(environment())!=this_object()->query("startroom"))
		return;
	
	add_action("do_cun", "cun");
	add_action("do_qu", "qu");
	add_action("do_chaxun", "chaxun");
}

void die()
{
	message_vision("\n$N死了。\n", this_object());
	destruct(this_object());
}
