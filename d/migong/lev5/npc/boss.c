#include <ansi.h>
inherit NPC;

string *random_item = ({	
	"/clone/tzbox/jm-box",
	"/clone/tzbox/sx-box",
	"/clone/map/obj/longwen-chijin",
	"/clone/tzbox/qf-box",
	"/clone/gem/gem",
	});

void create()
{
	int tsjndj;
	string weapon = "null";
	tsjndj = 10000 + random(5000);
	seteuid(getuid());
	
	set_name("黑衣人", ({ "heiyi ren", "heiyi", "boss" }));
    set("long", "各大门派私下派到眠龙洞寻找宝物的弟子，由于是私下活动，所以看到他的人都是一个字『死』。\n");
    set("title", "神秘人");
    set("gender", "男性" );
    set("icon", "30005" );
    set("age", random(30)+20);   
    set("attitude", "aggressive");
    set("class", "lvlin");
    set("str", 200);
    set("con", 200);
    set("int", 200);
    set("dex", 200);
    set("max_qi", 200000000);
	set("qi", 200000000);
    set("max_jing", 30000000);
	set("jing", 30000000);
    set("neili", 300000000);
    set("max_neili", 300000000);
	set("jingli", 300000000);
    set("max_jingli", 300000000);
	set("no_suck",1);
    set("jiali", 50000);
	set("end_boss", 1);
    set("env/wimpy", 10);
    set_temp("apply/attack",  800);
    set_temp("apply/defense", 600);
    set("combat_exp", 2100000000);
	set("xyzx_sys/level", 30000+random(50000));
	set("xyzx_sys/fanying", 100000+random(50000));
	set("xyzx_sys/jingzhun", 100000+random(50000));
	set("xyzx_sys/minjie", 100000+random(50000));
	set("xyzx_sys/lingxing", 100000+random(50000));
    set_skill("force", 20000); 
    set_skill("parry", 20000);
    set_skill("dodge", 20000);
    set_skill("unarmed", 20000);
	set_skill("sword", 20000);
	set_skill("blade", 20000);
	set_skill("club", 20000);
	set_skill("hammer", 20000);
	set_skill("staff", 20000);
	set_skill("whip", 20000);
    create_family("眠龙洞寻宝者", 3, "首领");
    set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :)
		}) );
    switch( random(16) ) {
	case 0:
	set_skill("douzhuan-xingyi", tsjndj);
    set_skill("guiyuan-tunafa", tsjndj);
    set_skill("tiezhang-zhangfa", tsjndj);
    set_skill("wuming-jianfa", tsjndj); 
    set_skill("shaolin-shenfa", tsjndj);
    map_skill("force", "guiyuan-tunafa");
    map_skill("unarmed","tiezhang-zhangfa");
    map_skill("parry", "douzhuan-xingyi");
    map_skill("sword", "wuming-jianfa");
    map_skill("dodge", "shaolin-shenfa");	
	weapon = "/clone/weapon/yuenv";	
	break;	
	case 1: 
	set_skill("taiji-shengong", tsjndj);
    set_skill("taiji-quan", tsjndj);
    set_skill("taiji-jian", tsjndj);
    set_skill("tiyunzong", tsjndj);
    map_skill("force", "taiji-shengong");
    map_skill("unarmed","taiji-quan");
    map_skill("parry", "taiji-jian");
    map_skill("sword", "taiji-jian");
    map_skill("dodge", "tiyunzong");
	weapon = "/clone/weapon/hanbing-jian";	
	break;	
	case 2: 
	set_skill("linji-zhuang", tsjndj);
    set_skill("jinding-zhang", tsjndj);
    set_skill("huifeng-jian", tsjndj);
    set_skill("zhutian-bu", tsjndj);
    set_skill("yugalism", tsjndj);
    map_skill("dodge", "zhutian-bu");
    map_skill("parry", "huifeng-jian");
    map_skill("sword", "huifeng-jian");
    map_skill("force", "linji-zhuang");
    map_skill("unarmed","jinding-zhang");
	weapon = "/clone/weapon/hanbing-jian";
	break;
	case 3: 
	set_skill("yunlong-xinfa", tsjndj);
    set_skill("yunlong-shengong", tsjndj);
    set_skill("yunlong-jian", tsjndj);
    set_skill("yunlong-shenfa", tsjndj);
    map_skill("dodge", "yunlong-shenfa");
    map_skill("force", "yunlong-shengong");
    map_skill("unarmed", "houquan");
    map_skill("parry", "yunlong-jian");
    map_skill("sword", "yunlong-jian");
	weapon = "/clone/weapon/hanbing-jian";
	break;	
	case 4: 
	set_skill("jueqing-zhang", tsjndj);
	set_skill("mingyu-shengong", tsjndj);
	set_skill("yifeng-jian", tsjndj);
    set_skill("yihua-jiemu", tsjndj);
	map_skill("force", "mingyu-shengong");
	map_skill("unarmed", "jueqing-zhang");
	map_skill("dodge", "yihua-jiemu");
	map_skill("parry", "mingyu-shengong");
    map_skill("sword","yifeng-jian");
	weapon = "/clone/weapon/hanbing-jian";
	break;	
	case 5:
	set_skill("hamagong", tsjndj);
    set_skill("chanchu-bufa", tsjndj);
    set_skill("training", tsjndj);
    set_skill("lingshe-zhangfa", tsjndj);
    map_skill("force", "hamagong");
    map_skill("dodge", "chanchu-bufa");
    map_skill("unarmed", "hamagong");
    map_skill("parry", "lingshe-zhangfa");
    map_skill("staff", "lingshe-zhangfa");
	weapon = "/clone/weapon/gangzhang";
	break;	
	case 6:
	set_skill("xiaoyaoyou", tsjndj);
    set_skill("huntian-qigong", tsjndj);
    set_skill("xianglong-zhang", tsjndj);
    set_skill("dagou-bang", tsjndj);
    map_skill("force", "huntian-qigong");
    map_skill("unarmed", "xianglong-zhang");
    map_skill("dodge", "xiaoyaoyou");
    map_skill("parry", "xianglong-zhang");
    map_skill("club", "dagou-bang");
	weapon = "/clone/weapon/tiegun";
	break;	
	case 7:
	set_skill("wuxing-dun", tsjndj);
    set_skill("shayi", tsjndj);
    set_skill("shayi-xinfa", tsjndj);
    set_skill("shiren-jianfa", tsjndj);
    set_skill("ninjitsu", tsjndj);
    set_skill("ittouryu", tsjndj);
    set_skill("enmeiryu", tsjndj);
    map_skill("blade", "ittouryu");
    map_skill("force", "shayi-xinfa");
    map_skill("dodge", "wuxing-dun");
    map_skill("parry", "shiren-jianfa");
    map_skill("unarmed", "enmeiryu");
	weapon = "/clone/weapon/hanbing-dao";
	break;	
	case 8:
	set_skill("xuanhualiu-quanfa", tsjndj);
    set_skill("feitian-yujianliu", tsjndj);
    set_skill("wuxing-dun", tsjndj);
    set_skill("shayi-xinfa", tsjndj);
    set_skill("shayi", tsjndj);
    map_skill("force", "shayi-xinfa");
    map_skill("parry", "feitian-yujianliu");
    map_skill("blade", "feitian-yujianliu");
    map_skill("dodge", "wuxing-dun");
    map_skill("unarmed", "xuanhualiu-quanfa");
	weapon = "/clone/weapon/hanbing-dao";
	break;	
	case 9:
	set_skill("yunv-shenfa", tsjndj);
    set_skill("xuantie-jianfa", tsjndj);
    set_skill("anranxiaohun-zhang", tsjndj);	
    set_skill("yunv-xinfa", tsjndj);     
    map_skill("force", "yunv-xinfa");        	
    map_skill("sword","xuantie-jianfa");
    map_skill("dodge", "yunv-shenfa");
    map_skill("parry", "xuantie-jianfa");        	
    map_skill("unarmed", "anranxiaohun-zhang"); 
	weapon = "/clone/weapon/hanbing-jian";
	break;	
	case 10:
    set_skill("liuyang-zhang", tsjndj);
    set_skill("tianyu-qijian", tsjndj);
    set_skill("yueying-wubu", tsjndj);
    set_skill("bahuang-gong", tsjndj);
    map_skill("force", "bahuang-gong");
    map_skill("dodge", "yueying-wubu");
    map_skill("unarmed", "liuyang-zhang");
    map_skill("parry", "liuyang-zhang");
    map_skill("sword","tianyu-qijian");
	weapon = "/clone/weapon/hanbing-jian";
	break;	
	case 11:
    set_skill("longxiang", tsjndj);
    set_skill("shenkong-xing", tsjndj);
    set_skill("yujiamu-quan", tsjndj);
    set_skill("mizong-xinfa", tsjndj);
    set_skill("hammer", tsjndj);
    set_skill("riyue-lun", tsjndj);
    map_skill("force", "longxiang");
    map_skill("dodge", "shenkong-xing");
    map_skill("unarmed", "yujiamu-quan");
    map_skill("parry", "riyue-lun");
    map_skill("hammer", "riyue-lun");
	weapon = "/clone/weapon/hammer";
	break;	
	case 12:
    set_skill("jiuyang-shengong", tsjndj);
    set_skill("qiankundanuoyi", tsjndj);
    set_skill("qishang-quan", tsjndj);
    set_skill("wuxue-shenfa", tsjndj);
    set_skill("shenghuo-ling", tsjndj);
	map_skill("force", "jiuyang-shengong");
    map_skill("dodge", "wuxue-shenfa");
    map_skill("unarmed", "qishang-quan");
	map_skill("sword", "shenghuo-ling");
    map_skill("parry","qiankundanuoyi");
	weapon = "/clone/weapon/hanbing-jian";
	break;	
	case 13:
    set_skill("qimen-wuxing", tsjndj);
    set_skill("yijing-force", tsjndj);
    set_skill("lingyunbu", tsjndj);
    set_skill("cuixin-zhang", tsjndj);
    set_skill("tianxin-blade", tsjndj);
    map_skill("force", "yijing-force");
    map_skill("dodge", "lingyunbu");
    map_skill("parry", "cuixin-zhang");
    map_skill("unarmed", "cuixin-zhang");
    map_skill("blade", "tianxin-blade");
	weapon = "/clone/weapon/hanbing-dao";
	break;
	case 14:
    set_skill("luoying-zhang", tsjndj);
    set_skill("yuxiao-jianfa", tsjndj);
	set_skill("bibo-shengong", tsjndj);
    set_skill("xuanfeng-tui", tsjndj);
	set_skill("anying-fuxiang", tsjndj);
    set_skill("qimen-wuxing", tsjndj);
    map_skill("force", "bibo-shengong");
    map_skill("unarmed", "xuanfeng-tui");
    map_skill("dodge", "anying-fuxiang");
    map_skill("parry", "luoying-shenjian");
    map_skill("sword", "yuxiao-jianfa");	
	weapon = "/clone/weapon/hanbing-jian";
	break;
    case 15:
    set_skill("snow-zhang", tsjndj);
    set_skill("xueshan-jianfa", tsjndj);
	set_skill("snowstep", tsjndj);
    set_skill("bingxue-xinfa", tsjndj);	
    map_skill("force", "bingxue-xinfa");
    map_skill("unarmed", "snow-zhang");
    map_skill("dodge", "snowstep");
    map_skill("parry", "xueshan-jianfa");
    map_skill("sword", "xueshan-jianfa");	
	weapon = "/clone/weapon/hanbing-jian";
	break;	
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
	//if ( ob->query("xyzx_sys/level") < 5000 ) return;
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
	me->set("xyzx_sys/level", me->query("xyzx_sys/level") + ob->query("xyzx_sys/level") );
	me->set("xyzx_sys/jingzhun", me->query("xyzx_sys/jingzhun") + ob->query("xyzx_sys/jingzhun") );
	me->set("xyzx_sys/minjie", me->query("xyzx_sys/minjie") + ob->query("xyzx_sys/minjie") );
	me->set("xyzx_sys/lingxing", me->query("xyzx_sys/lingxing") + ob->query("xyzx_sys/lingxing") );
	me->set("xyzx_sys/fanying", me->query("xyzx_sys/fanying") + ob->query("xyzx_sys/fanying") );
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

	if ( objectp(me) && objectp(ob) && random(100) < 10 )
	{
		baoshi = new(random_item[random(sizeof(random_item))]);
		message("party", HIW"【"+room+"】"+HIM"听说 "HIG+me->name(1)+HIM" 在 "+ob->name(1)+HIM" 尸体上发现了 "+baoshi->name(1)+HIM"。\n"NOR,users() );	
		baoshi->move(corpse);
	}

	COMBAT_D->announce(ob, "dead");
	destruct(ob);
	return;
}