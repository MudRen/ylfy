// ji.c ����Ȼ

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("����Ȼ", ({ "ji yanran", "ji" }));	
	set("title", "���Ʋ�Ů");	
	set("shen_type", 0);	
	set("gender", "Ů��");	
	set("age", 23);	
	set("long", "���ϲ�Ů��\n");	
	set("no_get", 1);
	set("no_put", 1);
	set("per", 30);
	set("max_neili", 300000);
	set("neili", 300000);
	set("max_jingli", 60000);
	set("jingli", 60000);
	set_skill("unarmed", 3000);
	set_skill("force", 3000);
	set_skill("parry", 3000);
	set_skill("dodge", 3000);
	set("combat_exp", 0);	
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/city/obj/sleepbag",	
		"/clone/drug/jinchuang",	
		"/clone/drug/yangjing",	
		}));
	
	setup();
	carry_object("/d/city/npc/cloth/zi-dress.c")->wear();	
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
