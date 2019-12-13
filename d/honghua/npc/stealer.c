// stealer.c
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
int do_buy_mu(string what);
void create()
{
	seteuid(getuid());
        set_name("��͵", ({"stealer"}));
	set("nickname", YEL"�ٱ���͵"NOR);
	set("gender", "����");
	set("long",
		"����һλ����ͨͨ������\n"
	);
	set("attitude", "peaceful");
	set_weight(240000);
	set("str", 31);
	set("con", 31);
	set("int", 31);
	set("dex", 31);
	set("kar", 100);
	set("food", 100000000);
	set("water", 100000000);
	set("qi", 300);
	set("max_qi", 300);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);
	set("shen", 10000);
	set("startroom","/d/city/guangchang");
	set("thief", 0);
	set("combat_exp", 8500000);
	set_skill("force", 40);
	set_skill("unarmed", 60);
	set_skill("dodge", 300);
	set_skill("parry", 50);
	set_skill("stealing", 500);
	set_skill("youlong-shenfa", 300);
	map_skill("dodge", "youlong-shenfa");
	set("chat_chance", 20);
	set("chat_msg", ({
			"��͵�ֹ������ϴ�ȥ����˳��ǣ�˼���ľͷ���...\n��͵�����̾�˿�����\n",
			"��͵���������˭Ҫ...����˭Ҫ�������?!...������û�˻�Ҫ�ģ��һ����Լ����Ű�...\n",
			(: random_move :)
	}) );
	set("vendor_goods", ({
		__DIR__"npc/daocao-ren",
		__DIR__"npc/mu-ren",
		__DIR__"npc/taomu-ren",
		__DIR__"npc/tong-ren",
	}));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && (int)ob->query("shen") < 0 )
		call_out("check", 0, ob);
	add_action("do_buy_mu", "buy");
	add_action("do_list", "list");
}
int do_buy_mu(string what)
{
	object ob, me = this_player();
	if ( do_buy(what) == 1 )
	{
		if ( what == "daocao ren" || what == "daocao"
		||   what == "mu ren"     || what == "mu"
		||   what == "taomu ren"  || what == "taomu"
		||   what == "tong ren"   || what == "tong" )
			if ( objectp(ob = present(what, me)) )
			{
				ob->set("title", me->query("name") + "��С����--����");
				ob->set_leader(me);
				ob->move(environment(me));
			}
		return 1;
	}
	return 0;
}
void check(object ob)
{
	mapping fam;
	if( !ob || environment(ob) != environment()
		|| ((fam = ob->query("family")) && fam["family_name"] == "�컨��")
	  ) return;
	switch( random(5) ) {
		case 0:
		       command("look " + ob->query("id"));
		       remove_call_out("stealing");
		       call_out("stealing",1,ob);
		       command("sigh "+ob->query("id"));
		       break;
		case 1:
		       command("look " + ob->query("id"));
		       remove_call_out("stealing");
		       call_out("stealing",1,ob);
		       command("xixi");
		       break;
		case 2:
		       command("look " + ob->query("id"));
		       remove_call_out("stealing");
		       call_out("stealing",1,ob);
		       command("duck");
		       break;
		case 3:
		       command("look " + ob->query("id"));
		       remove_call_out("stealing");
		       call_out("stealing",1,ob);
		       command("stuff");
		       break;
		case 4:
		       command("look " + ob->query("id"));
		       remove_call_out("stealing");
		       call_out("stealing",1,ob);
		       command("hi " + ob->query("id"));
		       break;
	}
	ob = this_object();
	if ( present("gold",ob) || present("silver",ob) || present("cash",ob) )
		call_out("put",1,ob);
	else
		if ( present("jingang zhao",ob) )
		{
			ob -> move("/d/city/dangpu");
			command ("sell zhao");
			call_out("put",1,ob);
		}
	return;
}
int stealing(object ob)
{
	if ( ob->present("jingang zhao",ob) )
		command("steal zhao from"+ob->query("id"));
	else
		command("steal gold from " + ob->query("id"));
	return 1;
}
int put(object ob)
{
	ob = this_object();
	ob -> move("/d/honghua/zongduo");
	command("west");
	command("put gold in xiang");
	command("put silver in xiang");
	command("put cash in xiang");
	ob -> move("/d/city/wumiao");
	command("east");
	set("chat_chance", 50);
	set("chat_msg", ({
			(: random_move :)
	}) );
	return 1;
}
