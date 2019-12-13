//����ɽ�ɡ�mhxy-yushu 2001/2
// lilong alter 2002.01.19
inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("���ϰ�", ( {"wang laoban", "laoban"}));
	set("age", 42);
	set("gender", "����");
	set("long","�ӻ��̵��ϰ壬Ц���еĿ����㡣\n");
	set("title", "�ӻ����ϰ�");
	set("attitude", "friendly");
	set("combat_exp", 10000);
	set("shen_type", 1);
	set("max_neili", 200);
	set("neili", 200);
	set("jiali", 5);
	set_skill("unarmed", 30);
	set_skill("dodge", 40);
	set_skill("parry", 30);
	set("vendor_goods", (
	{
		"/d/shushan/obj/shoe",
		"/d/shushan/obj/longwenpifeng",
		"/d/shushan/obj/shenxue",
	}));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	object ob,owner;
	string nature;
	nature=NATURE_D->room_event_fun();
	owner=this_object();
	::init();
	if (base_name(environment())!=query("startroom")) return;
	if (interactive(ob = this_player()) && !is_fighting())
	{
		if(nature!="event_dawn"
		        && nature!="event_night"
		        && nature!="event_midnight")
		{
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
		else owner->command("zzz "+owner->query("id"));
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2))
	{
	case 0 :
		say("���ϰ�Ц���е�˵������λ" + RANK_D->query_respect(ob) +
		    "�����������Ķ��������ʵ��\n");
		break;
	case 1 :
		say("���ϰ�˵����Ӵ����λ" + RANK_D->query_respect(ob) +
		    "�����˰�������Ķ����Ų���Ƿ��\n");
		break;
	}
}

