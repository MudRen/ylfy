#define LAST_PAR "sorry"
#define THIS_PAR "sorrysf"
inherit NPC;

string give_cloth();
int qing_shen();
int chu_du();
int ask_mask(string str);	
int add_exp();
int give_gift();
int in_virtual_map();
int in_new_virtual_map();
int full_all();

void create()
{
	set_name(HIW"灵星"NOR, ({ "ling xing", "ling", "xing"}));
	set("title", HIY"小妖"NOR);
	set("nickname", HIB"映月精灵"NOR);	
    set("str", 37);
    set("gender", "女性");
    set("age", 14);
	set("per",30);
    set("long","这是一个漂亮的小姑娘，大大的眼睛里还透着丝丝的稚气。\n 她专门在这儿负责给予新人一些小小帮助。\n");
    set("combat_exp", 1500);
	set("no_get",1);
	set("end_boss",1);
	set("xyzx_sys/level", 3000000);
	set("str", 5000000);
    set("con", 5000000);
    set("int", 5000000);
    set("dex", 5000000);
	set("no_get", 1);
    set("max_qi", 5000000000);
    set("qi", 5000000000);
    set("max_jing", 5000000000);
    set("jing", 5000000000);
    set("neili", 3000000000);
    set("max_neili", 300000000);
    set("jingli", 3000000000);
    set("max_jingli", 300000000);
	set_temp("apply/attack",  12150);
    set_temp("apply/defense", 12130);
    set("combat_exp", 2100000000);
	set_skill("qimen-wuxing", 350000);
    set_skill("qufeng", 350000);
    set_skill("force", 350000);
    set_skill("king-of-dragon", 350000);	
    set_skill("dodge", 350000);
    set_skill("parry", 350000);
    set_skill("unarmed", 350000);
    set_skill("dragon", 350000);	
    set_skill("magic-old", 350000);	
    set_skill("spells", 350000);
    set_skill("magic", 350000);	
    map_skill("parry", "king-of-dragon");	
    map_skill("force", "king-of-dragon");           	
    map_skill("dodge", "king-of-dragon");           	
    map_skill("unarmed", "dragon");        	
    map_skill("spells", "magic-old"); 
    set("attitude", "friendly");
    set("inquiry", ([
		"新手试练场":(: in_new_virtual_map :),
		//"进入副本"  :(: in_virtual_map :),
		"衣服"      :(: give_cloth :),
		"清神"      :(: qing_shen :),	
		"除毒"      :(: chu_du :),
		"面具"      :(: ask_mask :),
		"状态回复"  :(: full_all :),
		//"新手礼物"      :(: give_gift :),
		"双倍经验"  :(: add_exp :),
		//"潜能银行"  :HIM"潜能银行....？？？有这个地方的嘛？我想想...我想想看啊.....\n...啊...对了...对了.....想起来了！好象就在上面的，一直往上走就到了啦....."
	]));
    
    setup();
	
	carry_object("/clone/cloth/female1-cloth")->wear();	
}

string give_cloth()
{
	object me,obj;
	me = this_player();
	
	if (me->query("gender")=="女性")
		obj=new("/clone/cloth/female1-cloth");
	else
		obj=new("/clone/cloth/cloth");
	
	obj->move(me);
	command("xixi");
	return "赶快穿上吧：）";
}

int ask_mask(string arg)	
{
	object me,obj;
	object zi;
	me = this_player();
	zi=this_object();
	
	if(present("mian ju", me) /*|| present("mian ju", environment())*/)
	{
		command("say 已经有了还想拿,你怎么如此贪得无厌呢?");
		return 1;
	}
	
	//只开放申请帐号至今不足30天的ID
	/*if ( me->query("xyhy_type")!=2 && time() - me->query("birthday",1) > 3600*24*30 )
	{
		command("say 老大不小的了,还只会饭来张口,衣来伸手,该学学独立生活了!");
		return 1;
	}
	else
	{*/
		message_vision(CYN "灵星微笑着拿出个面具，送了给$N \n" NOR,me);
		obj=new("/clone/misc/mask-new");
		obj->move(me);
		command("love");
		return 1;
	//}
}

int qing_shen()
{
	object me,ob;

	me = this_object();
	ob = this_player();

	//只开放申请帐号至今不足30天的ID
/*	if ( ob->query("xyhy_type")!=2 && time() - ob->query("birthday",1) > 3600*24*30 )
	{
		command("say 你已经不是新手了耶，还要我来照顾你的呀？\n");
		return 1;
	}*/

	ob->set("shen",0);
	message_vision(CYN "灵星笑嘻嘻的伸手朝$N一拂清脆道声：“好了啦！” \n" NOR,ob);
	return 1;
}

int chu_du()
{
	object me,ob;
	
	me = this_object();
	ob = this_player();

	//只开放申请帐号至今不足30天的ID
/*	if ( ob->query("xyhy_type")!=2 && time() - ob->query("birthday",1) > 3600*24*30 )
	{
		command("say 你已经不是新手了耶，还要我来照顾你的呀？\n");
		return 1;
	}*/

	ob->clear_condition();
	message_vision(CYN "灵星笑嘻嘻的伸手朝$N一拂清脆道声：“好了啦！” \n" NOR,ob);
	return 1;
}

int add_exp()
{
	object me, ob;
	string now_time, my_time;

	me = this_object();
	ob = this_player();
	now_time = CHINESE_D->chinese_time(11, ctime(time()));
	my_time = ob->query("get_exp_time");
	if ( !my_time ) my_time = "";
	if ( atoi(CHINESE_D->chinese_time(9,ctime(time()))) > 19 )
	{
		message_vision(HIW"每天20~24点均为双倍经验时间，现在正处于双倍经验时间段$N还是过一会再来领吧。\n"NOR,ob);
		return 1;
	}
	if ( my_time == now_time )
	{
		message_vision(HIW"$N今天的双倍经验时间似乎已经领完了的吧.....！\n"NOR,ob);
		return 1;
	}
	if ( ob->query("xy_huiyuan") )
	{
		ob->set("exp_jiacheng",time()+3600*2);
		//message("channel:chat", HIY"【镜花水月】："HIW+ob->query("name")+HIG" 领取两小时的双倍经验时间开始计时。\n"NOR,users() );
		message_vision(HIW"$N领取两小时的双倍经验时间开始计时.....！\n"NOR,ob);
		log_file("cmds/Add_exp", sprintf("%s(%s) 领取2小时双倍经验时间 on %s\n",ob->query("name"),ob->query("id"),CHINESE_D->chinese_time(5,ctime(time()))) );
	}
	else
	{
		ob->set("exp_jiacheng",time()+3600*1);
		//message("channel:chat", HIY"【镜花水月】："HIW+ob->query("name")+HIG" 领取一小时的双倍经验时间开始计时。\n"NOR,users() );
		message_vision(HIW"$N领取一小时的双倍经验时间开始计时.....！\n"NOR,ob);
		log_file("cmds/Add_exp", sprintf("%s(%s) 领取1小时双倍经验时间 on %s\n",ob->query("name"),ob->query("id"),CHINESE_D->chinese_time(5,ctime(time()))) );
	}
	ob->set("get_exp_time", now_time);
	return 1;
}

int give_gift()
{
	object me,obj;
	
	me = this_player();
	
	if ( me->query(THIS_PAR + "_pick") )
	{
		command("say 桌子上就有啦！\n\n");
		tell_object(me,HIW"你朝桌上一瞄，耶~！真的有个礼物包耶！你不由分说伸手就向礼物包抓去.....\n"NOR);
		tell_object(me,CYN "一个漂亮的人影突然出现在一阵烟雾之中。\n");
		tell_object(me,HIR "在你的手上轻轻一敲：每人只有一份礼物的哦~！\n");
		tell_object(me,CYN "只见一阵烟雾过後，那个漂亮的身影已经不见了。\n"NOR);
		return 1;
	}

	command("say 桌子上就有啦！\n\n");
	tell_object(me,HIW"你朝桌上一瞄，耶~！真的有个礼物包耶！你不由分说伸手就向礼物包抓去.....\n"NOR);
	
	obj = new("/d/city/obj/gift.c");
	obj->move(me);
	
	message_vision("$N从石桌上拿起一件礼物包。\n",me );
	
	//每次拣礼物，都将上次的参数消除，增加本次拿的参数。
	me->delete(LAST_PAR + "_pick");
	me->set(THIS_PAR + "_pick",1);
	me->start_busy(3);
	
	return 1;
}

int in_virtual_map()
{
	object me, ob, *teams;
	string place, place_link, tmp;
	int i, stop;

	me = this_player();
	stop = 0;

	if ( !stringp(place = me->query_temp("xyzx_team/name")) ) 
	{
		tell_object(me, "你还没有队伍，只有队伍才能进入副本。\n");
		return 1;
	}
	if ( !me->query_temp("xyzx_team/zhang") ) 
	{
		if ( VRM_SERVER->valid_place_name(place) )
		{
			tell_object(me, "你不是队长，只有队伍队长才能创建副本。\n");
			return 1;
		}
	}
	else
	{
		if ( VRM_SERVER->valid_place_name(place) )
		{
			teams = TEAMD->get_team_member(me);
			if ( me->query("vrm_in_busy") > time() )
			{
				message("party", HIR"【"HIM"副本精灵"HIR"】"HIW"由于队长上次副本任务失败，十五分钟内无法再创建副本。\n"NOR, teams);
				return 1;
			}
			if ( VRM_SERVER->make_check_user(me, 3))
			{
				message("party", HIM"【"HIG"副本精灵"HIM"】"HIW"由于队长 IP 线上已经创建了一个副本，无法再继续创建多一个副本。\n"NOR, teams);
				return 1;
			}
			tmp = HIW"由于队伍成员( "HIY;
			for ( i=0; i<sizeof(teams); i++ )
			{
				if ( objectp(teams[i]) )
				{
					if ( teams[i]->query("vrm_in_busy") > time() )
					{
						tmp += teams[i]->query("id") + " ";
						stop = 1;
					}
				}
			}
			tmp += HIW")上次副本任务失败，十五分钟内无法再进入副本，副本创建失败。\n";
			if ( stop )
			{
				message("party", HIR"【"HIM"副本精灵"HIR"】"+tmp+NOR, teams);
				return 1;
			}
			VRM_SERVER->make_check_user(me, 1);
			me->set("vrm_in_busy", time()+900);// 限制了 在副本外 解散队伍，创建副本
			//message("party", HBBLU+HIR"【"HIY"副本精灵"HIR"】"HIW"队伍["HIM+place+HIW"]创建了一个副本，开始进入寂静之森。\n"NOR, users());
			message("party", HBBLU+HIR"【"HIY"副本精灵"HIR"】"HIW"队伍["HIM+place+HIW"]创建了一个副本，开始进入寂静之森。\n"NOR, teams);
		}
	}
	place_link = sprintf("%s/%s/entry", VRM_SERVER, place);
	ob = find_object(place_link);
	if ( !ob ) ob = load_object(place_link);
	me->move(ob);
	return 1;
}

int in_new_virtual_map()
{
	object me, ob;
	string place;

	me = this_player();
	
	if ( me->query("xyzx_sys/level") < 100 )
	{
		place = sprintf("%s/new/entry", VRM_SERVER);
		ob = find_object(place);
		if ( !ob ) ob = load_object(place);
		me->move(ob);
	}
	else
		tell_object(me, "你在江湖中已是德高望重，不需要再进入新手副本了。\n");
	return 1;
}

// 新手恢复
int full_all()
{
	object me, ob;
	int max;
	
	me = this_object();
	ob = this_player();
	
	//只开放等级不大于1000级且年龄小于18岁的的ID
	if ( ob->query("xyhy_type")!=2 && ob->query("age") > 17 && ob->query("xyzx_sys/level") > 2000 )
	{
		command("say 你已经不是新手了耶，还要我来照顾你的呀？\n");
		return 1;
	}

	max = ob->query("max_jing");
	ob->receive_curing("jing", max);
	ob->receive_heal("jing", max);
	max = ob->query("max_qi");
	ob->receive_curing("qi", max);
	ob->receive_heal("qi", max);
	max = ob->query("max_neili");
	if ( ob->query("xyhy_type") == 2 )
		ob->set("neili", max*2);
	else
		ob->set("neili", max);
	max = ob->query("max_jingli");
	if ( ob->query("xyhy_type") == 2 )
		ob->set("jingli", max*2);
	else
		ob->set("jingli", max);
	ob->set("food", ob->max_food_capacity());
	ob->set("water", ob->max_water_capacity());
	message_vision(CYN "紫吟笑嘻嘻的伸手朝$N一拂清脆道声：“好了啦！” \n" NOR,ob);
	return 1;
}