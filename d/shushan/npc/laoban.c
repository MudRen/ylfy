//����ɽ�ɡ�mhxy-yushu 2001/2
// lilong alter 2002.01.19
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
int redeem(string arg);
void create()
{
	set_name("���ϰ�", ({ "liu laoban", "liu", "laoban" }) );
	set("title", "�����ϰ�");
	set("shen_type", 0);
	set("gender", "����");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long",
		"��˵���ϰ����Ĵ��Ƽҵĺ����\n");
	set("no_get_from", 1);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);
	set("combat_exp", 50000);
	set("attitude", "friendly");
       set_weight(50000000);
       set("no_put",1);
set("no_get",1);
	
	setup();
	carry_object("/clone/cloth/cloth")->wear();
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
}
void die()
{
	message_vision("\n$N���ˡ�\n", this_object());
	destruct(this_object());
}
	


