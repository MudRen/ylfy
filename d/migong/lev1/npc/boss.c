#include <ansi.h>
inherit NPC;

string *random_item = ({
	"/clone/gem/gem",
	"/clone/gem/robe",
	"/clone/tzbox/sx-box",
	"/clone/tzbox/jm-box",
	"/clone/map/obj/longwen-chijin",
	"/clone/tzbox/qf-box",
	});

void create()
{
	seteuid(getuid());
	
	set_name("黑衣人", ({ "heiyi ren", "heiyi", "boss" }));
    set("long", "各大门派私下派到眠龙洞寻找宝物的弟子，由于是私下活动，所以看到他的人都是一个字『死』。\n");
    set("title", "神秘人");
    set("gender", "男性" );
    set("icon", "30005" );
    set("age", random(30)+20);   
    set("attitude", "aggressive");
    set("class", "lvlin");
    set("str", 90);
    set("con", 90);
    set("int", 90);
    set("dex", 90);
    set("max_qi", 100000000);
	set("qi", 100000000);
    set("max_jing", 50000000);
	set("jing", 50000000);
    set("neili", 300000000);
    set("max_neili", 300000000);
	set("jingli", 300000000);
    set("max_jingli", 300000000);
	set("no_suck",1);
    set("jiali", 50000);
	set("end_boss", 1);
    set("env/wimpy", 50);
    set_temp("apply/attack",  5000);
    set_temp("apply/defense", 3000);
    set("combat_exp", 2100000000);
	set("xyzx_sys/level", 5000);
	set("xyzx_sys/fanying", 60000);
	set("xyzx_sys/jingzhun", 60000);
	set("xyzx_sys/minjie", 60000);
	set("xyzx_sys/lingxing", 60000);
    set_skill("force", 15750);
    set_skill("unarmed", 15900);
    set_skill("dodge", 15800);
    set_skill("parry", 15940);
    set_skill("staff", 15000);
    set_skill("hamagong", 5980);
    set_skill("chanchu-bufa",5870);
    set_skill("training",5500);	
    set_skill("shexing-diaoshou",5800);
    set_skill("lingshe-zhangfa",5000);
    map_skill("force", "hamagong");
    map_skill("dodge", "chanchu-bufa");
    map_skill("unarmed", "hamagong");
    map_skill("parry", "lingshe-zhangfa");
    map_skill("staff", "lingshe-zhangfa");
    create_family("眠龙洞寻宝者", 3, "首领");
    set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :)
		}) );
    
	setup();
    
	carry_object("/clone/weapon/gangzhang")->wield();
    carry_object("/clone/cloth/cloth")->wear();
    add_money("gold", random(1000));
}

int just_kill(object guai,object player)
{
    int kar = player->query("kar");
    int kill=0;
	if(random(kar) >= random(30))
	{
	guai->command("haha");
	guai->command("say 你运气不错，老子现在不想动手！！！");
	}
	else
	{
	guai->command("say 你的运气到头了，老子现在心情不好，想找个人砍！");
	    kill=1;
	}	
    if(kill==1)
    {
	if(!objectp(guai)||!objectp(player))
	    return 1;
	if(environment(guai) != environment(player))
	    return 1;
	guai->kill_ob(player);
	player->fight_ob(guai);
    }
    return 1;
}

void init()
{
	object ob, me, get_ob;
	int level;
    
	me = this_object();
    ob = this_player();

	// 怪物必须是可以动作的，并只针对玩家
	if ( !objectp(ob) || !living(me) || !playerp(ob) ) return;
	// 见面就杀
	call_out("just_kill",1,me,ob);
	// command("follow "+ob->query("id"));
    // 只复制>5000级玩家状态
	if ( ob->query("xyzx_sys/level") < 5000 ) return;
	// 获得玩家总等级
	level = ob->query("xyzx_sys/level");
	// 只复制最高等级玩家
	if ( me->query_temp("kill_ob_lvl") >= level ) return;
	// 防止重复复制同一人
	if ( objectp(get_ob=me->query_temp("fight_killer_id")) && get_ob==ob ) return;
	//__________________标记目前复制状况___________________
	me->set_temp("fight_killer_id", ob);
	me->set_temp("kill_ob_lvl", level);
	//______________________标记结束_______________________
	//__________________________等级相关参数拷贝_____________________________
	me->set("xyzx_sys/level", ob->query("xyzx_sys/level") * 12 / 10);
	me->set("xyzx_sys/jingzhun", ob->query("xyzx_sys/jingzhun") * 12 / 10);
	me->set("xyzx_sys/minjie", ob->query("xyzx_sys/minjie") * 12 / 10);
	me->set("xyzx_sys/lingxing", ob->query("xyzx_sys/lingxing") * 12 / 10);
	me->set("xyzx_sys/fanying", ob->query("xyzx_sys/fanying") * 12 / 10);
	//______________________________拷贝完成_________________________________
}

void die()
{
	object ob, me, corpse, baoshi, env;
	string room;
	int m;

	ob = this_object();

	if ( !objectp(env=environment(ob)) 
		|| !stringp(room=env->query("short")) ) 
	{
		::die();
		return;
	}

	if ( ob->query_temp("last_damage_from") )
	{
		me = ob->query_temp("last_damage_from");
		m = random(50000);
		
		if ( interactive(me) )
		{
			message_vision(HIG"\n你杀死了 "+ob->name(1)+HIG" ，奖励了 "HIM+(m*me->query_exp_times())+HIG" 点经验和 "HIY+(m/10)+HIG" 潜能。\n"NOR, me);
			message("party", HIW"【"+room+"】"+HIG+me->name(1)+HIM" 杀死了 "+ob->name(1)+HIM" ，奖励了 "HIC+(me->query_exp_times()*m)+HIM" 点经验和 "HIY+(m/10)+HIM" 潜能。\n"NOR,users() );	
			me->add("combat_exp",m);
			me->add("potential",m / 10);
		}
	}
	
	if ( objectp(corpse = CHAR_D->make_corpse(ob, me)) )
		corpse->move(environment(ob));

	if ( objectp(me) && objectp(ob) && random(100) < 20 )
	{
		baoshi = new(random_item[random(sizeof(random_item))]);
		message("party", HIW"【"+room+"】"+HIM"听说 "HIG+me->name(1)+HIM" 在 "+ob->name(1)+HIM" 尸体上发现了 "+baoshi->name(1)+HIM"。\n"NOR,users() );	
		baoshi->move(corpse);
	}

	COMBAT_D->announce(ob, "dead");
	destruct(ob);
	return;
}