// oldwomen.c �ϴ���

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("�ϴ���", ({ "old women", "old", "women" }) );
        set("gender", "Ů��" );
        set("age", 62);
	set("long",
                "���ǲ˳��ϰ壬������������Ŵ����������档\n");
        set("combat_exp", 120);
	set("attitude", "friendly");
        set("rank_info/respect", "�ϴ���");
	set("vendor_goods", ({
                __DIR__"obj/qingcai",
                "/d/city3/obj/dabaicai",
	}));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

