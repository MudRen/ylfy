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
	"/clone/tzbox/jm-box",
	});
	
void create()
{
	int tsjndj;
	string weapon = "null";
	tsjndj = 30000 + random(10000);
	seteuid(getuid());
	
	set_name(WHT"丧尸王"NOR, ({"sangshi wang"}) );
    set("title", WHT "九幽怨灵" NOR);
    set("gender", "男性" );
    set("icon", "30004" );
    set("age", random(300)+200);
    set("long", "来自地狱的怨灵，浑身笼罩着一层邪恶之气。\n");
    set("attitude", "aggressive");
    set("class", "yuanling");
    set("str", 60);
    set("con", 60);
    set("int", 60);
    set("dex", 60);
    set("max_qi", 300000000);
	set("qi", 300000000);
    set("max_jing", 100000000);
	set("jing", 100000000);
    set("neili", 300000000);
    set("max_neili", 300000000);
	set("jingli", 300000000);
    set("max_jingli", 30000000);
	set("no_suck", 1);
    set("jiali", 100000);
	//set("end_boss", 1);
    set("env/wimpy", 5);
    set_temp("apply/attack",  550);
    set_temp("apply/defense", 530);
    set("combat_exp", 2100000000);
	set("xyzx_sys/level", 70000+random(100000));
	set("xyzx_sys/fanying", 200000+random(150000));
	set("xyzx_sys/jingzhun", 200000+random(150000));
	set("xyzx_sys/minjie", 200000+random(150000));
	set("xyzx_sys/lingxing", 200000+random(150000));
    set_skill("force", 100000); 
    set_skill("unarmed", 100000);
    set_skill("dodge", 100000);
    set_skill("parry", 100000);
	set_skill("sword", 100000);
	set_skill("blade", 100000);
    create_family("暗黑守护者", 3, "首领");
    set("chat_chance", 20);
	set("chat_msg", ({
		(: random_move :)
		}) ); 
    switch( random(2) ) {
	case 0:{
	set_skill("tianmo-jian", tsjndj);
    set_skill("tianmo-shengong", tsjndj); 
    set_skill("tianmo-zhang", tsjndj); 
    set_skill("shaolin-shenfa", tsjndj);
    map_skill("force", "tianmo-shengong");
    map_skill("unarmed","tianmo-zhang");
    map_skill("parry", "tianmo-jian");
    map_skill("sword", "tianmo-jian");
    map_skill("dodge", "shaolin-shenfa");
	weapon = "/clone/weapon/hanbing-jian";	
	}
	break;	
	case 1: {
	set_skill("tianmo-dao", tsjndj);
    set_skill("tianmo-shengong", tsjndj); 
    set_skill("tianmo-quan", tsjndj); 
    set_skill("shaolin-shenfa", tsjndj);
    map_skill("force", "tianmo-shengong");
    map_skill("unarmed","tianmo-quan");
    map_skill("parry", "tianmo-dao");
    map_skill("blade", "tianmo-dao");
    map_skill("dodge", "shaolin-shenfa");
	weapon = "/clone/weapon/hanbing-dao";	
	}
	break;	
	}
	set("weapon", weapon);	
	setup();
	if( weapon != "null" ) carry_object(weapon)->wield();
    carry_object("/clone/cloth/hanbing-jia")->wear();		
    add_money("gold", random(150));
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
	me->kill_ob(ob);
	command("follow "+ob->query("id"));
    // 只复制等级比自己高的玩家等级
	if ( ob->query("xyzx_sys/level") < me->query("xyzx_sys/level") ) return;
	// 获得玩家总等级
	level = ob->query("combat_exp")/LEVUP_EXP+ob->query("xyzx_sys/level");
	// 只复制最高等级玩家
	if ( me->query_temp("kill_ob_lvl") >= level ) return;
	// 防止重复复制同一人
	if ( objectp(get_ob=me->query_temp("fight_killer_id")) && get_ob==ob ) return;
	//__________________标记目前复制状况___________________
	me->set_temp("fight_killer_id", ob);
	me->set_temp("kill_ob_lvl", level);
	//______________________标记结束_______________________
	//__________________________等级相关参数拷贝_____________________________
	me->set("xyzx_sys/level", me->query("xyzx_sys/level")*11/10);
	//______________________________拷贝完成_________________________________
}

void die()
{
	object ob, me, corpse, baoshi, env;
	string room, name;
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
		m = random(100000);
		
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
		switch ( random(2))
		{
			case 0 : 
				baoshi->set("xyzx_item/pinji", 4);
				baoshi->set("name", YEL"★" + name);
				break;
			case 1 : 
				baoshi->set("xyzx_item/pinji", 5);
				baoshi->set("name", YEL"★★" + name);
				break;			
		}
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