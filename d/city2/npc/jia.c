// jia.c ������ 
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
int ask_weiwang();
void create()
{
	set_name("������", ({ "jia laoliu", "jia" }));
	set("title", "�����ϰ�");
	set("shen_type", 1);
	set("gender", "����");
          set_max_encumbrance(1000000000);
	set("age", 35);
	set("long",
		"\n������ػ���ľ�û��ڣ�����������֮ʱ�����������ɣ�\n"+
		"�����ǲ���ɱ���췴��ֻ����˽©˰����û���ӵ�С���⣬\n"+
		"������������������׷ɱ��éʮ��Ҳ��˺���������\n");
	set("no_get_from", 1);
set("no_get", 1);	
set("no_put", 1);	
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
       set("no_die",1);
     set("no_put",1);
       set_weight(50000000);
	set_temp("apply/damage", 15);
	set("combat_exp", 50000);
	set("attitude", "friendly");
        set("dealer","dian/dang");
	set("chat_chance", 3);
	set("chat_msg", ({
	"��������Ȼ˵�������η�����ɶ�\n",
	"������˵: ������������Ҫ������ֵ�ߴ��кô�����\n",
        "������ͻȻ˵��: ������ǰ�ֵ��ڣ����е㽫�������\n",
	}));
        set("inquiry", ([
		"�½���" :  "\n����ܶ����ɲ����װ���\n",
		"��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"���" :  "\nֻҪ��������ػᣬ��������и�λ����ѧ���ա�\n",
                "���帴��" : "ȥ���׳��͹ײĵ���ϸ���ưɣ�\n",
                "����" :  (: ask_weiwang :),
                "��������" : (: ask_weiwang :),
       ]) );
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
        add_action("do_pawn", "pawn");
        add_action("do_redeem", "redeem");
        add_action("do_check", "check");
	add_action("do_join","join");
	add_action("do_look_item", "look_item");
}
void die()
{
	message_vision("\n$N��е����ֵ��ǻ����ұ���ģ�ͷһƫ�����ˡ�\n", this_object());
	destruct(this_object());
}
int ask_weiwang()
{
command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
say("\n������˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
say("��������˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
return 1;
}
int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="tiandihui" )
	return notify_fail("��Ҫ����ʲô��֯��\n"); 
   if (ob->query("weiwang")<20)
        {
	command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
	message_vision(HIC "��������$Nҡ��ҡͷ˵����Ľ�������ֵ̫�͡�\n" NOR,this_player());
  	return 1;
  	}
   if (ob->query("combat_exp")<20000)
        {
	message_vision(HIC "��������$Nҡ��ҡͷ˵�����ʵս����̫�͡�\n" NOR,this_player());
  	return 1;
  	}
    if(ob->query("weiwang")<50)
    {
    ob->set("weiwang",50);
    message_vision(HIC "$N�Ľ�����������ˣ�\n" NOR,this_player());
    command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
    return 1;	
    }
    else message_vision(HIC "��������$Nҡ��ҡͷ˵�����Ѿ������ػ��ˡ�\n" NOR,this_player());
    return 1;
}
