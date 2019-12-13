#include <ansi.h>
inherit NPC;

string *random_item = ({	
	"/clone/map/weapon/axe",
	"/clone/map/weapon/blade",
	"/clone/map/weapon/club",
	"/clone/map/weapon/hammer",
	"/clone/map/weapon/spear",
	"/clone/map/weapon/staff",
	"/clone/map/weapon/whip",
	"/clone/map/weapon/sword",
	"/clone/map/armor/boot",
	"/clone/map/armor/cloth",
	"/clone/map/armor/hand",
	"/clone/map/armor/head",
	"/clone/map/armor/neck",
	"/clone/map/armor/ring",
	"/clone/map/armor/shield",
	"/clone/map/armor/surcoat",
	"/clone/map/armor/waist",
	"/clone/map/armor/wrists",
	"/clone/map/armor/armor",
	"/clone/map/armor/pants",
	});

string *random_item2 = ({
	"/clone/tzbox/qf-box",
	"/clone/tzbox/sx-box",
	//"/clone/tzbox/jm-box",
	"/clone/tzbox/rf-box",
	"/clone/map/obj/longwen-chijin",
	});

void create()
{
	string weapon = "null";
	seteuid(getuid());
	
	set_name(HIM"贼盗王"NOR, ({"zeidao wang", "wang", "boss"}) );
    set("title", HIC "绿林霸主" NOR);
    set("gender", "男性" );
    set("icon", "30005" );
    set("age", random(30)+20);
    set("long", "迷雾森林的贼盗首领，有着一身不凡的武艺，穷凶恶极手下罕有十合之将。\n");
    set("attitude", "aggressive");
    set("class", "lvlin");
    set("str", 100);
    set("con", 100);
    set("int", 100);
    set("dex", 100);
    set("max_qi", 30000000 + random(60000000));
	set("qi", 30000000 + random(60000000));
    set("max_jing", 10000000+ random(20000000));
	set("jing", 10000000+ random(20000000));
    set("neili", 500000000);
    set("max_neili", 50000000);
	set("jingli", 100000);
    set("max_jingli", 100000);
	set("no_suck",1);
    set("jiali", 20000 + random(50000));
	set("end_boss", 1);
    set("env/wimpy", 10);
    set_temp("apply/attack",  500);
    set_temp("apply/defense", 300);
    set("combat_exp", 2100000000);
	set("xyzx_sys/level", 50000 + random(30000));
	set("xyzx_sys/fanying", 200000);
	set("xyzx_sys/jingzhun", 200000);
	set("xyzx_sys/minjie", 200000);
	set("xyzx_sys/lingxing", 200000);
    set_skill("force", 30000); 
    set_skill("unarmed", 30000);
    set_skill("dodge", 30000);
    set_skill("parry", 30000);
	set_skill("sword", 30000);
	set_skill("blade", 30000);
    create_family("绿林暴风盟", 3, "首领");
    set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :)
		}) );
    switch( random(2) ) {
	case 0:{
	set_skill("douzhuan-xingyi", 10000);
    set_skill("guiyuan-tunafa", 10000); 
    set_skill("tiezhang-zhangfa", 5000+random(5000)); 
    set_skill("wuming-jianfa", 5000+random(5000)); 
    set_skill("shaolin-shenfa", 10000);
    map_skill("force", "guiyuan-tunafa");
    map_skill("unarmed","tiezhang-zhangfa");
    map_skill("parry", "douzhuan-xingyi");
    map_skill("sword", "wuming-jianfa");
    map_skill("dodge", "shaolin-shenfa");
	weapon = "/clone/weapon/yuenv";	
	}
	break;	
	case 1: {
	set_skill("douzhuan-xingyi", 10000);
    set_skill("guiyuan-tunafa", 10000); 
    set_skill("liumai-shenjian", 5000+random(5000)); 
    set_skill("badao", 5000+random(5000)); 
    set_skill("shaolin-shenfa", 10000);
    map_skill("force", "guiyuan-tunafa");
    map_skill("unarmed","liumai-shenjian");
    map_skill("parry", "douzhuan-xingyi");
    map_skill("blade", "badao");
    map_skill("dodge", "shaolin-shenfa");
	weapon = "/clone/weapon/longya";
	}
	break;
    default: // others      BUG!!!
    set("long","武功设置错误，BUG！！！");	
	}
	set("weapon", weapon);	
	setup();
	if( weapon != "null" ) carry_object(weapon)->wield();
    carry_object("/clone/cloth/hanbing-jia")->wear();
    add_money("gold", random(1000));
}

int just_kill(object guai,object player)
{
    int kar = player->query("kar");
    int kill=0;
	if(random(kar) >= random(40))
	{
	guai->command("haha");
	guai->command("say 你运气不错，老子现在心情不错，赶紧滚吧！！！");
	}
	else
	{
	guai->command("say 算你小子倒霉，老子现在心情不好，正想找个人砍，你就送上门了！");
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
	if ( ob->query("xyzx_sys/level") < me->query("xyzx_sys/level") ) return;
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
	//me->set("xyzx_sys/level", me->query("xyzx_sys/level")*11/10);
	//______________________________拷贝完成_________________________________
}

void die()
{
	object ob, me, corpse, baoshi, env;
	string room, name;
	int m, my_level;

	ob = this_object();
    my_level = ob->query("xyzx_sys/level", 1);
	if ( !objectp(env=environment(ob)) 
		|| !stringp(room=env->query("short")) ) 
	{
		::die();
		return;
	}

	if ( ob->query_temp("last_damage_from") )
	{
		me = ob->query_temp("last_damage_from");
		m = my_level*(100+random(200));
		
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

	if ( objectp(me) && objectp(ob) && random(100) > 70 )
	{
		baoshi = new(random_item[random(sizeof(random_item))]);
		name = baoshi->name(1);
		baoshi->set("xyzx_item/pinji", 4);
		baoshi->set("name", YEL"★" + name);  
		 message("party", HIW"【"+room+"】"+HIM"听说 "HIG+me->name(1)+HIM" 在 "+ob->name(1)+HIM" 尸体上发现了"HIW+baoshi->name(1)+"("+baoshi->query("id")+")。\n"NOR,users() );	
		baoshi->move(corpse);
	}
	else if ( random(100) < 5 )
		    {
			baoshi = new(random_item2[random(sizeof(random_item2))]);
             message("party", HIW"【"+room+"】"+HIM"听说 "HIG+me->name(1)+HIM" 在 "+ob->name(1)+HIM" 尸体上发现了"HIW+baoshi->name(1)+"("+baoshi->query("id")+")。\n"NOR,users() );				
			baoshi->move(corpse);
		}

	COMBAT_D->announce(ob, "dead");
	destruct(ob);
	return;
}
