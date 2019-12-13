// kuli.c 酷吏
inherit NPC;

void create()
{
    set_name("赵六", ({ "zhao liu", "liu", "zhao" }));
    set("title", "刑部酷吏");
    set("nickname", "水火棍");
    set("str", 37);
    set("gender", "男性");
    set("age", 35);
    set("long",
	    "他是刑部大堂里一名值班的小吏。官不大，可权力却不小\n");
    set("combat_exp", 1500);
    set("attitude", "friendly");
    set("inquiry", ([
        "自首" : "要自首先得交钱。",   //需要30两黄金
    ]));
    setup();
    carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
    object ob;

    ::init();
    if (interactive(ob = this_player()) && !is_fighting()) {
	remove_call_out("greeting");
	call_out("greeting", 1, ob);
    }
    add_action("do_betray","decide");
}
void greeting(object ob)
{
    if (!ob || environment(ob) != environment())
	return;
    switch(random(2)) {
	case 0 :
	    say("赵六笑眯眯地说道：这位" + RANK_D->query_respect(ob) +
		    "，快请进来歇口气吧。\n");
	    break;
	case 1 :
	    say("赵六说道：哟！这位" + RANK_D->query_respect(ob) + 
		    "您来了啊！您要清除您的判师记录吗？\n");
	    break;
    }
}
int accept_object(object who, object ob)
{
   /* if(get_system_config(DATA_CONFIG_DIR "system.h", "ALLOW_BETRAYER")==0)//->query("betrayer"))
    {
	tell_object(who, "赵六说道：朝廷已经下旨不能再清除判师记录了！\n");
	return 0;
    }*/

    if(! (int)who->query("betrayer"))
    {
	tell_object(who, "赵六说道：你已经没有判师记录了呀！\n");
	return 0;
    }

    if (ob->query("money_id") && ob->value() >= 1000000)
    {
	tell_object(who, "赵六笑眯眯地说到：好吧，每清除一次判师记录要减去15%的经验、并且各门功夫降两级。\n");
	tell_object(who, "你考虑清楚了就请作出决定吧。(decide)\n");
	who->set_temp("fee_paid",1);
	return 1;
    }
    else if (ob->query("money_id") && ob->value() < 1000000) 
    {
	tell_object(who, "赵六嘿嘿一笑，说道：给我这麽多钱？ 将来我可没法还你啊。\n");
	return 1;
    }
    return 0;
}

int do_betray()
{
    int i,ob_levl, level;
    object me;
    mapping skill_status;
    string *sname;

    me = this_player();

    if(! (int)me->query("betrayer"))
	return notify_fail("赵六说道：你已经没有判师记录了呀！\n");

    if( !me->query_temp("fee_paid") ) 
	return notify_fail("赵六冷冷地说道：不管叫我做什麽，您可得先付钱哪！\n");

    me->add("betrayer", -1);
    if ( skill_status = me->query_skills() )
    {
	sname  = keys(skill_status);
	for(i = 0; i < sizeof(skill_status); i++) 
	{
	    level = skill_status[sname[i]] - 2;
	    if(level <= 0)
		me->delete_skill(sname[i]);
	    else
		me->set_skill(sname[i], level);
	}
    }

    ob_levl = me->query("xyzx_sys/level");
    me->set("xyzx_sys/levup_exp",0);

   //实战经验损失3%
	me->add("combat_exp", -(int)me->query("combat_exp") / 20 * 3);
	//经验损失3%
	me->add("xyzx_sys/levup_exp", -(int)me->query("xyzx_sys/levup_exp") / 20 * 3);
				
	//等级损失
	if ( me->query("xyzx_sys/level") > 1 )
	{
		if ( me->query("xyzx_sys/level") > 0 && me->query("xyzx_sys/level") < 5 )
			me->add("xyzx_sys/level",-1);
		else
			me->add("xyzx_sys/level", -(int)me->query("xyzx_sys/level") / 5);
	}
    me->delete_temp("fee_paid");
    tell_object(me, "赵六笑眯眯地说到：好啦，判师记录清除了一次。\n");
    me->unconcious();
    return 1;
}