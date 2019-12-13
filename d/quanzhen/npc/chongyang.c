inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
	set_name("王重阳", ( { "wang chongyang", "wang" }));
	set("nickname", HIC "中神通" NOR);
	set("long",
	    "他就是全真教开山祖师、中神通王重阳。\n"
	    "身穿一件青灰色道袍，背一口七星剑。\n"
	    "面色红润，看起来内功一定很高深。\n");
	set("gender", "男性");
	set("age", 70);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 80);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 2128000);
	set("max_jing", 1225000);
	set("neili", 2000000);
	set("max_neili", 1000000);
	set("jiali", 3100);
	set("combat_exp", 80000000);
	set("score", 500000);
	set("xyzx_sys/level", 1500);

	set_skill("force", 2900);
	set_skill("tiangang-zhengqi", 1100);
	set_skill("dodge", 2900);
	set_skill("qixing-huanwei", 1300);
	set_skill("unarmed", 2900);
	set_skill("kongming-quan", 1200);
	set_skill("parry", 2900);
	set_skill("sword", 2900);
	set_skill("quanzhen-jianfa", 1400);
	set_skill("xiantian-qigong", 1000);
	set_skill("qixing-array", 1500);
	set_skill("taoism", 2500);
	set_skill("literate", 2700);

	map_skill("force", "xiantian-qigong");
	map_skill("dodge", "qixing-huanwei");
	map_skill("unarmed", "kongming-quan");
	map_skill("parry", "quanzhen-jianfa");
	map_skill("sword", "quanzhen-jianfa");

	create_family("全真教", 1, "开山祖师");
	set("class", "taoist");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", (
	{
(: perform_action, "sword.qixing" :),
(: perform_action, "sword.jianzhen" :),
(: exert_function, "recover" :),
	}) );
	set("inquiry", ([
                    "九阴真经"  :HIM"九阴真经....？？这本书我送给我师弟保管了.....\n...如果你是<一代大侠>而且能找回来送给我的话.....我会帮你稍做整理....."
	                ]));
	setup();
	carry_object("/d/quanzhen/obj/qixingjian")->wield();
	carry_object("/d/quanzhen/obj/greenrobe")->wear();
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name")!="全真教" || (string)ob->query("class")!="sworder")
	{
		command("say 我全真乃是道家门派。");
		command("say " + RANK_D->query_respect(ob) + "若想拜我派需先入我道。");
		return;
	}
	if ((int)ob->query_skill("tiangang-zhengqi", 1) < 300)
	{
		command("say 我全真教乃内家武功，最重视内功心法。");
		command("say " + RANK_D->query_respect(ob) +
		        "是否还应该在天罡正气上多下点功夫？");
		return;
	}
	if ((int)ob->query("shen") < 100000)
	{
		command("say 学武之人，德义为先，功夫次之。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
		        "是否还做得不够？");
		return;
	}
	if (ob->query_int() < 60)
	{
		command("say 我全真教武功全从道中悟出。");
		command("say 要能达到炉火纯青之境，悟性低不得。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("chat 好！好！！好！！！");
	command("chat 希望" + RANK_D->query_respect(ob) + "你能够学到我全真教的真髓！！");
	command("chat* pat " + ob->query("id"));

	command("recruit " + ob->query("id"));
	ob->set("title",HIC"全真教重阳真人传人"NOR);
}


void init()
{
	object ob;
	::init();
	ob = this_player();
	/*        if ( (int)ob->query("shen") <-2000 && (string)ob->query("family/master_id") == "wang chongyang")
	        {
	                  command("chat "+ob->query("name")+"!你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
	                command("expell "+ ob->query("id"));
	                this_player()->set("title","全真教" + RED + "弃徒" NOR);

	        }*/
}


void do_kill(string arg)
{
	object me = this_player();
	object obj;

	if (!arg || !objectp(obj = present(arg, environment(me))))
		return;

	if (arg == "zhang sanfeng" || arg == "zhang")
		obj->kill_ob(me);
	else obj->fight_ob(me);

	me->fight_ob(obj);
}


int accept_fight(object ob)
{
	object me  = this_object();

	me->set("eff_qi", me->query("max_qi"));
	me->set("qi",     me->query("max_qi"));
	me->set("jing",   me->query("max_jing"));
	me->set("neili",  me->query("max_neili"));

	if ( me->is_fighting()) return 0;

	if ( !present(ob, environment()) ) return 0;

	remove_call_out("checking");
	call_out("checking", 1, me, ob);

	return 1;
}

int checking(object me, object ob)
{
	int my_max_qi, his_max_qi;

	if ( !present(ob, environment()) ) return 1;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if( me->is_fighting() )
	{
		if ( (int)me->query("qi")*100/my_max_qi <= 80 )
		{

			me->set("eff_qi", me->query("max_qi"));
			me->set("qi",     me->query("max_qi"));
			me->set("jing",   me->query("max_jing"));
			me->set("neili",  me->query("max_neili"));
		}
		if ( present(ob, environment()) )
			call_out("checking", 1, me, ob);
	}


	return 1;
}

int accept_object(object me, object ob)
{

	if ( (string) ob->query("id") =="jiuyin zhenjing1" )
	{
		message_vision("$N对$n说道：当年为了避免江湖动荡，而组织了华山论剑，由武功最高者获得《九阴真经》\n", this_object(),me);
		message_vision("$N对$n说道：这本武学关键之处，用梵语书写，如果修习方法不对，轻则武功尽废，重则立即毙命\n", this_object(),me);
		message_vision("$N对$n说道：你找到这半册经书，如果你能找到另外半册.........\n", this_object(),me);
		me->set_temp("tmark/jiuyin1", 1);
		return 1;
	}

	if ( (string) ob->query("id") =="jiuyin zhenjing2" )
	{
		if ((int)me->query_temp("tmark/jiuyin1") && me->query("shen") > 100000000 )
		{
			message_vision("$N对$n说道：稍等片刻，我将这2本秘籍重新整理成册......\n", this_object(),me);
			message_vision("$N对$n说道：修炼此武学切记不可心浮气躁!!!!!!!!!\n", this_object(),me);
			message_vision("$N对$n说道：好了，这本《九阴真经》我已重新整理完毕，现在送给你！！！\n", this_object(),me);
			message_vision("$N对$n说道：<我曾经在某地留下对于九阴真经的一点心得，如果有缘，可以去参悟一下！>\n", this_object(),me);
			message_vision("$N对$n说道：希望你以后不要用此武学滥杀无辜，我本已不想涉入江湖是非，你还是速速离去吧！\n", this_object(),me);
			ob = new("/clone/book/jiuyin.c");
			ob->move(this_player());
			return 1;
		}
		else
			message_vision("王重阳看了看$N送来的经书，说道：多谢了，此经书就暂时由我来保管吧！否则流入恶人之手..必将引起场江湖浩劫。\n",this_object(),me);
		return 1;
	}
	else
		return 0;
}