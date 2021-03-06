// 全新的组队模式 By Wenwu on 2005.10.21

// 可组队的最小等级
#define MIN_TEAM_LEVEL 1
#include <liebiao.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	object *team, ob;
	string name, team_name, msg, id;
	float exp;
	int lvl, i;
	if ( me->is_busy() ) return notify_fail("你现在正忙着，还是先把手上的事情做完再说。\n");
	// 非会员不予离线练功
//	if ( !stringp(me->query("xy_huiyuan")) || !sscanf(me->query("xy_huiyuan"), "%*s年%*s月%*s日") )
//		return notify_fail(HIY"只有会员才能使用组队功能。\n"NOR);

	name = me->query_temp("xyzx_team/name");
	
	// 查询队伍信息
	if ( !arg )
	{
		if ( !stringp(name) ) return notify_fail("你目前还没有和人组队，无法查询队伍信息。\n");
		if ( !stringp(msg = TEAMD->more_team_list(me)) )
			return notify_fail("你目前还没有和人组队，无法查询队伍信息。\n");
		if ( msg == "" ) return notify_fail("你目前还没有和人组队，无法查询队伍信息。\n");
		
		write(msg);
		return 1;
	}

	// 创建队伍
	if ( sscanf(arg, "found %s", team_name) == 1 )
	{
		if ( stringp(name) ) 
			return notify_fail("你目前正处于组队中，只能先脱离了才能创建新的队伍。\n");

		i = strlen(team_name);

		if ( i < 4 ) return notify_fail("队伍名称最少要由两个中文汉字组成。\n");
		if ( i > 10 ) return notify_fail("队伍名称最多只能由五个中文汉字组成。\n");

		while ( i-- )
		{
			if ( team_name[i]<=' ' ) return notify_fail("队伍名称不能使用控制字元。\n");
			if ( i % 2 == 0 && !is_chinese(team_name[i..<0]) ) 
				return notify_fail("队伍名称必需是中文。\n");
		}

		exp = to_float(LEVUP_EXP)*me->query("xyzx_sys/level")+me->query("xyzx_sys/levup_exp")+me->query("combat_exp");
		lvl = to_int(exp / LEVUP_EXP);
              
		if ( lvl < MIN_TEAM_LEVEL )      
			return notify_fail("只有人物等级达到一级以上，或者实战经验达到"+LEVUP_EXP+"以上，才可以创建队伍。\n");
                 
		if ( !TEAMD->found_team(me, team_name) )
			return notify_fail("这个队伍名称已经有人用了，你无法再用这个名称创建队伍。\n");
	
		message_vision(HIG"$N成功创建了一支队伍："HIY+team_name+"\n"NOR, me);
		me->start_busy(3);
		return 1;
	}
	else
		if ( arg == "found" ) return notify_fail("创建队伍指令格式："HIY"team found 队伍名称\n"NOR);

	// 转让队长
	if ( sscanf(arg, "rang %s", id) == 1 )
	{
		if ( !stringp(name) ) return notify_fail("你现在并没有参加任何队伍。\n");
		if ( !me->query_temp("xyzx_team/zhang") ) return notify_fail("你现在并不是队长，无法进行队长转让。\n");
		if ( !objectp(ob = find_player(id)) ) return notify_fail("你想把队长转让给谁？\n");

		team = TEAMD->get_team_member(me);
		if ( member_array(ob, team) == -1 ) return notify_fail("你的队伍中并没有这个队员。\n");

		if ( ob == me ) return notify_fail("转让给自己？你这不是没事找事在瞎忙乎。\n");

		me->delete_temp("xyzx_team/zhang");
		ob->set_temp("xyzx_team/zhang", 1);
		//____________________更新IP检查参数____________________
		// 清除副本系统 IP 检查的相关参数
		VRM_SERVER->make_check_user(me, 2);
		// 增加副本系统 IP 检查的相关参数
		if ( !VRM_SERVER->valid_place_name(name) )
			VRM_SERVER->make_check_user(ob, 1);
		//________________________ End _________________________
		team = filter_array( users(), "team_listener", this_object(), name );
		message("party", HIY"【"+name+"】"HIW+me->query("name")+"("+me->query("id")+") "HIM"把队长之职转让给了 "HIW+ob->query("name")+"("+ob->query("id")+")"+HIM" 。\n"NOR, team);
		return 1;
	}
	
	// 把一个成员踢出队伍
	if ( sscanf(arg, "out %s", id) == 1 )
	{
		if ( !stringp(name) ) return notify_fail("你现在并没有参加任何队伍。\n");
		if ( !me->query_temp("xyzx_team/zhang") ) return notify_fail("只有队长才有权利踢人出队。\n");
		if ( !objectp(ob = find_player(id)) ) return notify_fail("你想把谁踢出队伍？\n");

		team = TEAMD->get_team_member(me);
		if ( member_array(ob, team) == -1 ) return notify_fail("队伍中并没有这个成员。\n");

		if ( ob == me )
		{
			message_vision("由于队长("HIY"$N"NOR")离队，队伍("HIY+name+NOR")解散了。\n", me);
			team = filter_array( users(), "team_listener", this_object(), name );
			message("party", HIY"【"+name+"】"HIM+"由于队长 "HIW+me->query("name")+"("+me->query("id")+") "HIM"离队，队伍解散了。\n"NOR, team);
		}
		else
			message_vision("$N把$n从队伍("HIY+name+NOR")中踢了出去。\n", me, ob);

		if ( !TEAMD->del_team_member(ob) ) return notify_fail("队伍中并没有这个成员。\n");

		return 1;
	}
	else if ( arg == "out" ) // 离开队伍
	{
		if ( me->query_temp("xyzx_team/zhang") )
		{
			 message_vision("$N将队伍("HIY+name+NOR")解散了。\n", me);
			 team = filter_array( users(), "team_listener", this_object(), name );
			 message("party", HIY"【"+name+"】"HIM+"队长 "HIW+me->query("name")+"("+me->query("id")+") "HIM"将队伍解散了。\n"NOR, team);
		}
		else if ( stringp(name) )
			message_vision("$N脱离了队伍("HIY+name+NOR")。\n", me);
		
		if ( !TEAMD->del_team_member(me) ) return notify_fail("你现在并没有参加任何队伍。\n");
		
		return 1;
	}

	// 屏蔽队伍共享分配奖励信息
	if ( arg == "block" )
	{
		if ( !stringp(name) ) return notify_fail("你现在并没有参加任何队伍。\n");
		if ( me->query_temp("xyzx_team/block") ) return notify_fail("你现在并没有接听队伍奖励共享分配的信息。\n");

		me->set_temp("xyzx_team/block", 1);
		write("你屏蔽了队伍奖励共享分配的信息。\n");
		return 1;
	}

	// 接听队伍共享分配奖励信息
	if ( arg == "listen" )
	{
		if ( !stringp(name) ) return notify_fail("你现在并没有参加任何队伍。\n");
		if ( !me->query_temp("xyzx_team/block") ) return notify_fail("你现在并没有屏蔽队伍奖励共享分配的信息。\n");

		me->delete_temp("xyzx_team/block");
		write("你开始接听队伍奖励共享分配的信息。\n");
		return 1;
	}

	// 邀请加入队伍
	if ( sscanf(arg, "yaoqing %s", id) == 1 )
	{
		if ( !stringp(name) ) return notify_fail("你现在连队伍都没，先要创建了队伍才能招收队员。\n");
		if ( !me->query_temp("xyzx_team/zhang") ) return notify_fail("只有队长才有权利招收成员。\n");
		if ( !objectp(ob = present(id, environment(me))) 
			|| !living(ob) 
			|| !ob->is_character() 
			|| ob==me )
			return notify_fail("你想邀请谁加入你的队伍？\n");

		if ( me->is_fighting() || ob->is_fighting() )
			return notify_fail("战斗状态中无法组队。\n");

		team = TEAMD->get_team_member(me);
		if ( member_array(ob, team) != -1 ) return notify_fail(ob->query("name")+"已经是你的队员了。\n");
		if ( ob->query_temp("xyzx_team/name") ) return notify_fail(ob->query("name")+"已经有队伍了。\n");
		if ( sizeof(team) > 9 ) return notify_fail("队伍已满。\n");

		if ( ob->query_temp("team_shenqing") == me->query("id") )
		{
			ob->delete_temp("team_shenqing");
			ob->delete_temp("team_yaoqing");

			if ( !TEAMD->add_team_member(me, ob) )
				message_vision("$N人物等级不足一级，实战经验也不到"+LEVUP_EXP+"，无法加入$n的队伍("HIY+name+NOR")。\n", ob, me);
			else
				message_vision("$N成功地加入了$n的队伍("HIY+name+NOR")。\n", ob, me);
		}
		else
		{
			ob->set_temp("team_yaoqing", me->query("id"));
			message_vision("$N邀请$n加入队伍("HIY+name+NOR")。\n", me, ob);
		}
		return 1;
	}
	else if ( arg == "yaoqing" ) return notify_fail("你想邀请谁加入你的队伍？\n");

	// 申请加入队伍
	if ( sscanf(arg, "jiaru %s", id) == 1 )
	{
		if ( !objectp(ob = present(id, environment(me))) 
			|| !living(ob) 
			|| !ob->is_character() 
			|| ob==me )
			return notify_fail("你想申请加入谁的队伍？\n");
		if ( !stringp(name = ob->query_temp("xyzx_team/name")) ) 
			return notify_fail("他(她)现在连自己都还没有队伍。\n");
		if ( !ob->query_temp("xyzx_team/zhang") ) return notify_fail("他(她)并不是队长，无法收取你入队。\n");
		if ( me->is_fighting() || ob->is_fighting() )
			return notify_fail("战斗状态中无法组队。\n");

		team = TEAMD->get_team_member(ob);
		if ( member_array(me, team) != -1 ) return notify_fail("你已经是这个队伍的队员了。\n");
		if ( me->query_temp("xyzx_team/name") ) 
			return notify_fail("你已经有队伍了，如想另加别的队伍先得脱离目前的队伍。\n");
		if ( sizeof(team) > 9 ) return notify_fail("队伍("HIY+ob->query_temp("xyzx_team/name")+NOR")已经满员了。\n");

		if ( me->query_temp("team_yaoqing") == ob->query("id") )
		{
			me->delete_temp("team_shenqing");
			me->delete_temp("team_yaoqing");

			if ( !TEAMD->add_team_member(ob, me) )
				message_vision("$N人物等级不足一级，实战经验也不到"+LEVUP_EXP+"，无法加入$n的队伍("HIY+name+NOR")。\n", me, ob);
			else
				message_vision("$N成功地加入了$n的队伍("HIY+name+NOR")。\n", me, ob);
		}
		else
		{
			me->set_temp("team_shenqing", ob->query("id"));
			message_vision("$N申请加入$n的队伍("HIY+name+NOR")。\n", me, ob);
		}
		return 1;
	}
	else if ( arg == "jiaru" ) return notify_fail("你想申请加入谁的队伍？\n");

	// 聊天
	if ( sscanf(arg, "talk %s", msg) == 1 )
	{
		if ( !stringp(name = me->query_temp("xyzx_team/name")) ) 
			return notify_fail("你现在并没有参加任何队伍。\n");

		team = filter_array( users(), "team_listener", this_object(), name );
		message("party", HIY"【"+name+"】"+me->query("name")+"("+me->query("id")+")"+HIW"："+ msg + "\n"NOR, team);
		return 1;
	} else if ( arg == "talk" )
	{
		if ( !stringp(name = me->query_temp("xyzx_team/name")) ) 
			return notify_fail("你现在并没有参加任何队伍。\n");

		team = filter_array( users(), "team_listener", this_object(), name );
		message("party", HIY"【"+name+"】"+me->query("name")+"("+me->query("id")+")"+HIW"：...\n"NOR, team);
		return 1;
	}

	// 改变分配模式
	if ( sscanf(arg, "change %s", msg) == 1 )
	{
		TEAMD->change_allot_type(me, msg);
		return 1;
	}

	help(me);
	return 1;
}

int team_listener(object ppl, string str)
{
	if ( !objectp(ppl) ) return 0;
	if ( !objectp(environment(ppl)) ) return 0;
	if ( wizardp(ppl) || ppl->query_temp("xyzx_team/name") == str )
		return 1;
	else
		return 0;
}

int help(object me)
{
write( @HELP
队伍指令使用方法:
------------------------------------------------------------------------
team found   <名称>    - 创建一个队伍，创建后自己是队长，可以邀请人入队。
team rang    <人物>    - 允许队伍领队把队长之职转让给队伍中的其他成员。
team yaoqing <人物>    - 让队长可以使用该指令邀请其他玩家加入其队伍。
team jiaru   <人物>    - 让你可以向一个队伍的队长申请入队。
team out     <人物>    - 队伍的队长可以把一个队员踢出队伍，如把自己踢出
                         则整个队伍被解散。
team out               - 离开队伍. 若下此指令的是领队, 则整个队伍会解散。
team talk    <讯息>    - 跟队伍里其他的人谈话, 可以用 tt <讯息> 替代。
team block             - 如果觉得队伍奖励共享分配的信息比较烦人，那么你
                         可以用这个指令把它屏蔽掉。
team listen            - 如果你已经屏蔽了队伍奖励共享分配的信息，而现在
                         又想重新接听队伍奖励共享分配信息那么你就可以用
                         这个指令来实现了。
team change <分配模式> - 更改分配模式。可支持的分配模式有：平均分配模式
                         (average) 和 按照等级比例分配的模式(level)。
直接下 team 指令时则会显示你目前是否有加入队伍及队员名单。
 
组队是[夕阳再现-炎龙封印]的一个特色系统:玩家组队之后,所有队员视为一体,除
了刷经验(fight)外，无论做任务(quest)、还是杀npc升级，队伍中的队员获得的奖
励都比单独完成要高出许多，具体能高多少是根据队伍内队员数目来决定的，相对
来说队伍成员越多所得奖励加成就越高，另外队伍所得奖励并不是简单地平均分配
的，而是根据队员经验高低按照经验高的多得、经验低的少取的原则来分配的。目
前每个队伍最多可以有10个成员，队伍每增加一个成员奖励加成就会高10%。
------------------------------------------------------------------------
HELP);
	return 1;
}
