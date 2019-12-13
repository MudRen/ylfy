// zhu.c

inherit NPC;
inherit F_DEALER;

void create()
{

	set_name("ÖìÀÏ°å", ( {"zhu laoban","zhu","laoban" }));
	set("shop_id",( {"zhu laoban","zhu","laoban"}));
	set("shop_title","Öé±¦µêÀÏ°å");
	set("gender", "ÄÐÐÔ");
	set("combat_exp", 10000);
	set("age", 26);
	set("per", 14);
	set("attitude", "friendly");
	set("shen_type", 1);
	set_skill("unarmed", 10);

	set("vendor_goods", (
	{
		"d/gaoli/obj/feicui-neck",
		"d/gaoli/obj/huangjin-neck",
		"d/gaoli/obj/manao-neck",
		"d/gaoli/obj/baiyu-finger",
		"d/gaoli/obj/hupo-finger",
	}));
	setup();
	carry_object("/d/gaoli/obj/pao1")->wear();

	add_money("silver", 2);
}
void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}


