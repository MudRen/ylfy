
#include <ansi.h>
inherit NPC;
inherit F_BANKER;
int ask_weiwang();
void create()
{
	set_name("Ǯ�ϱ�", ({"qian laoben", "qian", "laoben"}));
	set("title", "Ǯׯ�ϰ�");
	set("gender", "����");
	set("age", 34);
	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);
	set("qi", 500); 
	set("max_qi", 500);
	set("jing", 100);
	set("max_jing", 100);
	set("shen", 0);
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 5);
	set("chat_msg", ({
	"Ǯ�ϱ�˵�����ҽ�Ǯ�ϱ���������Ϊ���������ϱ�Ҳ���ˡ�\n",
	"Ǯ�ϱ�Ц��˵�����ڱ����Ǯ��Ϣ���ٰٷ�֮һ���͹���ֻ�ܴ�ɡ�\n",
	"Ǯ�ϱ�˵��ֻ�жԱ��ɵ����Ҳ���ô�������Ա���˰����ߺ�......\n",
	"Ǯ�ϱ�ͻȻ˵��: ������������Ҫ������ֵ�ߴ��кô�����\n",
        "Ǯ�ϱ�ͻȻ˵�����˷ֿ�һ��ʫ�����Ϻ�Ӣ����֪��\n",
	}));
        set("inquiry", ([
		"��Ϣ" :  "\n��Ҫ��Ϣ����ᣡ\n",
		"�½���" :  "\n����ܶ�����û��ô���ס�\n",
		"��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"����" :  "\nֻҪ��������ػᣬ��������и�λ����ѧ���ա�\n",
		"���" :  "\nֻҪ��������ػᣬ��������и�λ����ѧ���ա�\n",
                "����" :  (: ask_weiwang :),
                "��������" : (: ask_weiwang :),
       ]) );
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("gold", 5);
}
void init()
{
    if (base_name(environment())!=this_object()->query("startroom")) return;
	add_action("do_check", "check");
	add_action("do_check", "chazhang");
	add_action("do_convert", "convert");
	add_action("do_convert", "huan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
	add_action("do_join","join");
	delete_temp("busy");
}
int ask_weiwang()
{
command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
say("\nǮ�ϱ�˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
say("Ǯ�ϱ���˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
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
	message_vision(HIC "Ǯ�ϱ���$Nҡ��ҡͷ˵����Ľ�������ֵ̫�͡�\n" NOR,this_player());
  	return 1;
  	}
   if (ob->query("combat_exp")<20000)
        {
	message_vision(HIC "Ǯ�ϱ���$Nҡ��ҡͷ˵�����ʵս����̫�͡�\n" NOR,this_player());
  	return 1;
  	}
    if(ob->query("weiwang")<50)
    {
    ob->set("weiwang",50);
    message_vision(HIC "$N�Ľ�����������ˣ�\n" NOR,this_player());
    command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
    return 1;	
    }
    else message_vision(HIC "Ǯ�ϱ���$Nҡ��ҡͷ˵�����Ѿ������ػ��ˡ�\n" NOR,this_player());
    return 1;
}
