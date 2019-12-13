// renwoxing.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_bijian();

void create()
{
	set_name("任我行", ( { "ren woxing", "ren","woxing" }));
	set("title", BLU "日月神教教主"NOR );
	set("long", "只见他一张长长的脸孔，脸色雪白，更无半分血色，眉目清秀，身材甚高，一头黑发，穿的是一袭青衫。\n");
	set("gender", "男性");
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
                    "比剑" :  (: ask_bijian :),
                    "剑法" :  (: ask_bijian :),
                    "黑木令" : "要拿黑木令？老夫想先看看你的剑法！\n",
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
	    && ob->query("gender") != "无性"
		&& (ob->query_skill("xixing-dafa", 1) < 1)
		&& (ob->query_skill("beiming-shengong", 1) < 1)
		&& (ob->query_skill("huagong-dafa", 1) < 1))
	{
		command("heihei");
		command("say 阁下的状态真是糟糕，你的伤势实在太严重了。");
		command("say 但是我有一套内功绝学，可以治疗你的伤势。");
		command("say 咱们相见也是有缘，我就把这套武学传授于你，你拿去研究研究，想办法自疗吧！");
		message_vision(HIY"$N传授于$n吸星大法。\n"NOR, this_object(), ob);
		ob->set_skill("xixing-dafa", 90);
	}
}

int ask_bijian()
{
	object obj, me = this_player(), ob = this_object();
	message_vision("$N躬身说道：“晚辈今日有幸拜见任老前辈，还望多加指教。”\n
	               $n笑道：“不用客气，你来解我寂寞，可多谢你啦。”\n", me, ob );
	message_vision("$N道：“不敢。”\n
	               $n点了点头，说道：“我只想瞧瞧你的剑法，并非真的过
	               招，再说，我也未必能胜得了你。”\n\n", me, ob);
	say(HIR"任我行大喝一声：“少林剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才一招。”\n");
		return 1;
	}
	command("enable sword taiji-jian");
	say(HIR"任我行大喝一声：“武当剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才两招。”\n");
		return 1;
	}
	command("enable sword huifeng-jian");
	say(HIR"任我行大喝一声：“峨嵋剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才三招。”\n");
		return 1;
	}
	command("enable sword songshan-jian");
	say(HIR"任我行大喝一声：“嵩山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才四招。”\n");
		return 1;
	}
	command("enable sword taishan-jianfa");
	say(HIR"任我行大喝一声：“泰山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才五招。”\n");
		return 1;
	}
	command("enable sword huashan-jianfa");
	say(HIR"任我行大喝一声：“华山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才六招。”\n");
		return 1;
	}
	command("enable sword luoyan-jian");
	say(HIR"任我行大喝一声：“衡山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才七招。”\n");
		return 1;
	}
	command("enable sword hengshan-jian");
	say(HIR"任我行大喝一声：“恒山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“还是没过八招。”\n");
		return 1;
	}

	obj = new("/d/heimuya/obj/heimu-ling");
	obj -> move(me);
	say("任我行说道：“这位" + RANK_D->query_respect(me)+"不错，我就送你一块黑木令吧。”\n");
	return 1;
}
