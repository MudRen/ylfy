// By zjb@ty 2002-5-16

#include <ansi.h>;
inherit NPC;
inherit F_DEALER;
void create()
{
    set_name("��٢", ({ "hua tuo", "hua", "tuo" }));
    set("title", "ҩ���ϰ�");
    set("gender", "����");
    set("long", "������ҽ���߳��ġ��������ġ���٢��\n");
    set("age", 65);
    set("int", 30);
    set("qi", 1000);
    set("max_qi", 1000);
    set("jing", 1000);
    set("max_jing", 1000);
    set("shen_type", 0);
    set("combat_exp", 500000);
    set("attitude", "heroism");
    set_skill("unarmed", 80);
    set_skill("dodge", 80);
    set_skill("parry", 60);
    set_temp("apply/attack", 70);
    set_temp("apply/defense", 70);
    set_temp("apply/damage", 50);
    


	set("vendor_goods", ({
		"/d/liandan/obj/chutou",
		"/d/liandan/obj/yaodai"
        }));
    setup();
    add_money("gold", 1);
    carry_object("/clone/cloth/changpao")->wear();
}


void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_sell", "sell");
}
