// waiter.c

inherit NPC;

int ask_key();

void create()
{
	set_name("��С��", ({ "xiao er", "xiao", "xiaoer", "waiter" }) );
	set("gender", "����" );
       set("icon","30001");
	set("age", 22);
	set("long",
		"��λ��С��������������ţ�������û����Ǯ��һ����\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("inquiry", ([
		"rumors" : "�ϴ�һ����ë������������������ֹ��Ĵ�˵��ֻ�ð���������������������Ҳ����䵭�ˡ�",
		"��ë����": "������¥�ϵ������",
		"�һ���": "��˵��������ôһ��С��������ס��һ����ħ��",
		"Կ��": (: ask_key :),
		"����" : "�����ݵ�������",
		"����" : "�����ݵĶ��ϱߣ������ݶ���ȥ�ҡ�",
		"����" : "�����ݵĶ��ϱߡ�",
		"������" : "�ں�������ɽ�����������������ߵ���",
		"�䵱��" : "�ں������ڣ����������������߰ɡ�",
		"������" : "����ɽ���ߣ�����������ȥ�ҡ�",
		"����" : "������ɽ���ߣ������������ߡ�",
		"����Ľ��" : "�ڹ��������أ�ȥ�������ҿ��ɡ�",
		"����ׯ" : "��̫�����ϣ������������ߡ�",
		"ؤ��" : "����Ǹ�����ѽ��",
		"������" : "��ңԶ������һֱ�����߰ɡ�",
		"��Ĺ" : "������ɽ�������������������ϰɡ�",
		"����ɽ" : "�����������������ϰɡ�",
		"����" : "�ڴ��ε��ϱߣ�����Ҫ�����������ߡ�",
		"��ɽ" : "���������ڣ������ݳ������߿��Ե��",
	]) );
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
"��С������˵���������µ�һ�����ɾ������֡���\n",
"��С������Ҵ�ķָ, ���������µ�һ��ô, ��Ȼ��ؤ���ˡ���\n",
"��С��С��˵���������µ�һ��, ���˳�ħ�̵����̡���\n",
"��С��������ʣ����䵱ɽ, ����ɽ, ��������, ����һ����? ��\n",
"��С��̾Ϣ�������������, �������, ��֪��Ĺһ�ɿ��д��ˡ���\n",
"��С��ŭ���, �������£�����ɱ���ǰ����޶������ɡ���\n",
"��С��Ц������˵��������ǰ�������⵽����, ���������˴������ʵۡ���\n",
"��С������һЦ, ��������˵�һ���������ҩʦ������κ�, �ֻص��ˡ���\n",
"��С��ָ��ָ���Ϸ�, ������Ц��������ʲô������, ��Ҫʲô���������\n",
        }) );

}

void init()
{	
	object ob;

	::init();
	if (base_name(environment()) != query("startroom")) return;
	if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if (!present(ob, environment())) return;
	say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
		+ "�����������\n");
}

int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 400) 
	{
		tell_object(who, "��С��һ��������������˵������л���ϣ��͹�����¥ЪϢ��\n");
		who->set_temp("rent_paid",1);
		return 1;
	}
	return 0;
}

void relay_emote(object me,string arg)
{
	command(arg+" "+me->query("id"));
}

int ask_key()
{
	object ob=this_player();

	if (!present("kezhan key",ob)) {
		say("С�����˵�˵���͹���ϲ��ס�������ǿ�̫���ˡ�Կ�׸�����\n" );
		new("d/nio/obj/key")->move(ob);
	}
	else say("С��������˵������ô�����ˣ��ղŲ��������ߵ���\n");
	return 1;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("С����æ��$N��Ҿ�������ҿ�����ʵ�ˣ��͹����ͱ�����Ѱ�����ˡ���\n", ob);
	message_vision("$N�������ĵ�ù����ʵ���²����֡���\n", ob);
}

void unconcious()
{
	say( "С����һ�������Ҳ����ˣ������Ӱ࣡��\n");
	say( "�����¥����������һ��С������˵����û���⣬�����Ұɡ���\n");
	say( "ǰһ��С��������ֵ��뿪�ˡ�\n");
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
}

void die()
{
	unconcious();
}
