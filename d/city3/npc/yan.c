// tang.c ���ϰ� 
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
int redeem(string arg);
void create()
{
set_name("����", ({ "yan liu", "yan" }));	
set("title", "��Ǯ��ʹ����ĥ");	
	set("shen_type", 0);
	set("gender", "����");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long",
"���Ǹ����������ļһ\n");	
	set("no_get_from", 1);
        set("no_get", 1);	
        set("no_put", 1);
        set("dealer","dian/dang");       	
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);
	set("combat_exp", 50000);
	set("attitude", "friendly");
       set_weight(50000000);
       set("no_put",1);
	   set("sell_type", 3);
	
	setup();
	carry_object("/clone/cloth/changpao")->wear();
}
void init()
{
if (base_name(environment())!=this_object()->query("startroom")) return;      	
        add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
	add_action("do_redeem", "redeem");
	add_action("do_pawn", "pawn");
	add_action("do_check", "check");
	add_action("do_look_item", "look_item");
}
void die()
{
	message_vision("\n$N���ˡ�\n", this_object());
	destruct(this_object());
}
	
