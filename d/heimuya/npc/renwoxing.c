// renwoxing.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_bijian();

void create()
{
	set_name("������", ( { "ren woxing", "ren","woxing" }));
	set("title", BLU "������̽���"NOR );
	set("long", "ֻ����һ�ų��������ף���ɫѩ�ף����ް��Ѫɫ��üĿ���㣬������ߣ�һͷ�ڷ���������һϮ������\n");
	set("gender", "����");
	set("class", "scholar");
	set("age", 55);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 150);
	set("per", 27);
	set("int", 35);
	set("con", 100);
	set("dex", 100);

	set("max_qi", 500000);
	set("max_jing", 150000);
	set("neili", 5000000);
	set("max_neili", 3000);
	set("jiali", 7300);
	set("combat_exp", 90000000);
	set("score", 500000);

	set_skill("literate", 900);
	set_skill("force", 700);
	set_skill("dodge", 700);
	set_skill("unarmed", 700);
	set_skill("parry", 700);
	set_skill("sword", 700);
	set_skill("changquan", 700);
	set_skill("xixing-dafa", 700);
	set_skill("lingxu-bu", 700);
	set_skill("damo-jian", 700);
	set_skill("taiji-jian", 700);
	set_skill("huifeng-jian", 700);
	set_skill("taishan-jianfa", 700);
	set_skill("hengshan-jian", 700);
	set_skill("luoyan-jian", 700);
	set_skill("huashan-jianfa", 700);
	set_skill("songshan-jian", 700);

	map_skill("dodge", "lingxu-bu");
	map_skill("force", "xixing-dafa");
	map_skill("unarmed", "changquan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");

	set("inquiry", ([
                    "�Ƚ�" :  (: ask_bijian :),
                    "����" :  (: ask_bijian :),
                    "��ľ��" : "Ҫ�ú�ľ��Ϸ����ȿ�����Ľ�����\n",
	                ]) );
	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && visible(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if(!ob || environment(ob) != environment()) return;
	if( (ob->query("eff_qi")*100 / ob->query("max_qi") < 10)
	    && ob->query("neili") < 1
	    && random(10) == 0
	    && ob->query("gender") != "����"
		&& (ob->query_skill("xixing-dafa", 1) < 1)
		&& (ob->query_skill("beiming-shengong", 1) < 1)
		&& (ob->query_skill("huagong-dafa", 1) < 1))
	{
		command("heihei");
		command("say ���µ�״̬������⣬�������ʵ��̫�����ˡ�");
		command("say ��������һ���ڹ���ѧ����������������ơ�");
		command("say �������Ҳ����Ե���ҾͰ�������ѧ�������㣬����ȥ�о��о�����취���ưɣ�");
		message_vision(HIY"$N������$n���Ǵ󷨡�\n"NOR, this_object(), ob);
		ob->set_skill("xixing-dafa", 90);
	}
}

int ask_bijian()
{
	object obj, me = this_player(), ob = this_object();
	message_vision("$N����˵���������������Ұݼ�����ǰ�����������ָ�̡���\n
	               $nЦ���������ÿ������������Ҽ�į���ɶ�л��������\n", me, ob );
	message_vision("$N���������ҡ���\n
	               $n���˵�ͷ��˵��������ֻ��������Ľ�����������Ĺ�
	               �У���˵����Ҳδ����ʤ�����㡣��\n\n", me, ob);
	say(HIR"�����д��һ���������ֽ�������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵��������һ�С���\n");
		return 1;
	}
	command("enable sword taiji-jian");
	say(HIR"�����д��һ�������䵱��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword huifeng-jian");
	say(HIR"�����д��һ���������ҽ�������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword songshan-jian");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword taishan-jianfa");
	say(HIR"�����д��һ������̩ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword huashan-jianfa");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword luoyan-jian");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword hengshan-jian");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵����������û�����С���\n");
		return 1;
	}

	obj = new("/d/heimuya/obj/heimu-ling");
	obj -> move(me);
	say("������˵��������λ" + RANK_D->query_respect(me)+"�����Ҿ�����һ���ľ��ɡ���\n");
	return 1;
}
