// 团队系统 By Wenwu

// 预分配内存给映射
// #define FORE_MAPPING_MEM 15
// 可组队的最小等级
#define MIN_TEAM_LEVEL 1
// 团队奖励加成十分之TEAM_LIST_ADD
#define TEAM_LIST_ADD 1
// 每个队伍允许的最大成员数
#define MAX_TEAM_MEMBER 10

#include <ansi.h>

inherit F_DBASE;

// 团队映射
static mapping user_team = ([]);
// 队伍分配类型
static mapping team_allot_type = ([]);
// 可共享分配的奖励项目
static string *team_share = ({"combat_exp", "potential"});
// 可共享分配奖励项目的对应中文
static mapping team_share_chinese = ([
	"combat_exp" : "实战经验",
	"potential"  : "潜能"
	]);
// 可更改的分配模式类型
static mapping team_allot_type_chinese = ([ 
	"average" : "平均分配",
	"level"   : "等级比例"
	]);
// 正延迟倒计时退出副本的玩家队列
nosave object *exit_duplicate_user = ({});

// 内部使用函数
int team_listener(object ppl, string str); // 接收队伍信息的对象集合
void remove(); // 析构函数
int is_change_allot_type(string type); // 是否支持更改队伍分配模式
// 外部使用函数
int found_team(object ob, string name); // 创建队伍
int add_team_member(object me, object ob); //增加成员
int del_team_member(object ob); // 删除成员
string more_team_list(object ob); // 查看队伍信息
int team_add(object ob, string prop, mixed data); // 团队共享分配、加成
int change_allot_type(object ob, string type); // 更改队伍分配模式
// 公用函数
int query_team_share(object ob, string prop); // 是否允许共享分配
object *get_team_member(mixed ob); // 获取一个队伍所有成员
string get_allot_type(string name); // 取得队伍分配模式，并转换成中文显示
int check_team_vip(mixed ob); // 检查队伍中是否全是会员。
object get_team_leader(mixed ob); // 取得队伍中的队长

void create()
{
	seteuid( ROOT_UID );
	set("channel_id","团队系统");
	CHANNEL_D->do_channel( this_object(), "sys", HIM"团队系统已经启动。\n"NOR);
	set_heart_beat(150);
}

// 创建一个队伍
int found_team(object ob, string name)
{
	//float exp;
	int lvl;

	if ( !name ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !interactive(ob) ) return 0;
	if ( !mapp(user_team) ) return 0;
	if ( user_team[name] ) return 0;
	if ( ob->query_temp("xyzx_team/name") ) return 0;
	
	/*exp = to_float(LEVUP_EXP) * ob->query("xyzx_sys/level") + 
		ob->query("xyzx_sys/levup_exp") + ob->query("combat_exp");
	lvl = to_int(exp / LEVUP_EXP);*/
	lvl = ob->query("xyzx_sys/level");

	if ( lvl < MIN_TEAM_LEVEL ) return 0;

	// 在正式创建队伍时我们预先申请一段内存
	// 这样效率会比较高，而不用总是动态分配占用Cpu
	// if ( !sizeof(user_team) )
		// user_team = allocate_mapping( FORE_MAPPING_MEM );
	// 增加一个队伍映射
	user_team[name] = ({ ob });
	// 设置人物队伍状态参数
	/////////////////////////////////////////////////////////
	ob->set_temp("xyzx_team/name", name); // 队伍名称
	ob->set_temp("xyzx_team/zhang", 1); // 队长标志
	ob->set_temp("xyzx_team/lvl", lvl); // 总的等级
	ob->set_temp("xyzx_team/max_lvl", lvl); // 所有成员等级和
	/////////////////////////////////////////////////////////
	//message("party", HIY"【镜花水月】"HIW+ob->query("name")+"("+ob->query("id")+")"HIM" 创建了一支队伍: "HIG+name+HIM" 。\n"NOR, users());
	tell_room(environment(ob), HIY"【镜花水月】"HIW+ob->query("name")+"("+ob->query("id")+")"HIM" 创建了一支队伍: "HIG+name+HIM" 。\n"NOR);
	change_allot_type(ob, "average"); // 默认分配模式为：平均分配
	return 1;
}

// 增加一个队伍成员
int add_team_member(object me, object ob)
{
	string name, type;
	object *team_user;
	//float exp;
	int i, lvl, team_size;

	if ( !objectp(me) || !objectp(ob) ) return 0;
	if ( !interactive(me) || !interactive(ob) ) return 0;
	if ( !mapp(user_team) ) return 0;
	if ( !sizeof(user_team) ) return 0;
	if ( ob->query_temp("xyzx_team/name") ) return 0;
	if ( !me->query_temp("xyzx_team/zhang") ) return 0;

	// 取得队伍名称
	name = me->query_temp("xyzx_team/name");
	
	if ( !arrayp(user_team[name]) ) return 0;

	/*exp = to_float(LEVUP_EXP) * ob->query("xyzx_sys/level") + 
		ob->query("xyzx_sys/levup_exp") + ob->query("combat_exp");
	lvl = to_int(exp / LEVUP_EXP);*/
	lvl = ob->query("xyzx_sys/level");

	if ( lvl < MIN_TEAM_LEVEL ) return 0;

	// 增加成员入队
	/////////////////////////////////////////////////////////
	team_user = user_team[name];
	team_size = sizeof(team_user);

	if ( team_size >= MAX_TEAM_MEMBER ) return 0;

	team_user += ({ ob });
	user_team[name] = team_user;
	/////////////////////////////////////////////////////////
	// 更新各成员队伍状态参数
	/////////////////////////////////////////////////////////
	ob->set_temp("xyzx_team/name", name); // 队伍名称
	ob->set_temp("xyzx_team/lvl", lvl); // 总的等级
	team_size = sizeof(team_user);
	for ( i = 0, lvl = 0; i < team_size; i++ )
	{
		if ( objectp(team_user[i]) )
			lvl += team_user[i]->query_temp("xyzx_team/lvl"); // 取得所有成员等级和
	}
	for ( i = 0; i < team_size; i++ )
	{
		if ( objectp(team_user[i]) )
			team_user[i]->set_temp("xyzx_team/max_lvl", lvl); // 所有成员等级和
	}
	/////////////////////////////////////////////////////////
	team_user = filter_array( users(), "team_listener", this_object(), name );
	if ( !check_team_vip(me) ) 
	{ // 队伍中全是免费会员，变更分配模式为：平均
		change_allot_type(me, "average");
		type = get_allot_type(name);
		message("party", HIY"【"+name+"】"HIW"由于队伍中都是普通玩家，分配模式强制更改为："HIC+type+HIW""NOR, team_user);
	}
	type = get_allot_type(name);
	message("party", HIY"【"+name+"】"HIM"新成员 "HIW+ob->query("name")+"("+ob->query("id")+")"+HIM" 加入了队伍，目前队伍分配模式为："HIC+type+HIM"。\n"NOR, team_user);
	return 1;
}

// 删除一个队伍成员
int del_team_member(object ob)
{
	string name, type;
	object *team_user, room, leader, *show_user;
	int i, lvl, team_size, duizhang, flag, del_ip;

	if ( !objectp(ob) ) return 0;
	if ( !mapp(user_team) ) return 0;
	if ( !sizeof(user_team) ) return 0;
	if ( !stringp(name = ob->query_temp("xyzx_team/name")) ) return 0;
	if ( !arrayp(user_team[name]) ) return 0;

	team_user = user_team[name];

	if ( member_array(ob, team_user) == -1 ) return 0;

	name = ob->query_temp("xyzx_team/name");
	duizhang = ob->query_temp("xyzx_team/zhang");

	switch ( duizhang )
	{
		// 如果是队长离开队伍则整个队伍被解散
		/////////////////////////////////////////////////////////////////////
		case 1:
				map_delete(user_team, name);
				map_delete(team_allot_type, name);
				team_size = sizeof(team_user);
				flag = 0;
				del_ip = 0;
				for ( i = 0; i < team_size; i++ )
				{
					if ( objectp(team_user[i]) )
					{
						// 副本里的成员移动到武庙，三小时内禁止再进入副本
						if ( !VRM_SERVER->valid_place_name(name) )
						{
							// 清除副本系统 IP 检查的相关参数
							if ( !del_ip )
							{
								VRM_SERVER->make_check_user(ob, 2);
								del_ip = 1;
							}
							// 所有队员退出副本
							if ( virtualp(environment(team_user[i])) )
							{
								if ( !flag )
								{
									show_user = filter_array(users(), "team_listener", this_object(), name);
									message("party", HIM"【"HIG"副本精灵"HIM"】"HIW"队伍 "HIC+name+HIW" 开始退出副本。\n"NOR, show_user);
									flag = 1;
								}
								if ( !wizardp(team_user[i]) && virtualp(environment(ob)) )
									team_user[i]->set("vrm_in_busy", time() + 900);
								room = find_object("/d/city/wumiao");
								if ( !room ) room = load_object("/d/city/wumiao");
								// 战斗和busy中无法立即退出副本
								//_____________________________________________________________________
								if ( !team_user[i]->is_fighting() && !team_user[i]->is_busy() )
								{
									tell_object(team_user[i], "你开始离开副本。\n");
									team_user[i]->move(room);
								}
								else
								{ // 放入队列，延迟处理
									if ( !arrayp(exit_duplicate_user) ) exit_duplicate_user = ({ });
									if ( member_array(team_user[i], exit_duplicate_user) == -1 )
										exit_duplicate_user += ({ team_user[i] });
								}
							}
							//______________________________________________________________________
						}
						team_user[i]->delete_temp("xyzx_team");
					}
				}
				// 删除副本地图
				VRM_SERVER->delete_team_place(name);
				break;
		/////////////////////////////////////////////////////////////////////
		default:
				ob->delete_temp("xyzx_team"); // 清除个人组队状态参数
				// 从团队中删除一个成员，并重新更新所有成员相关状态参数
				/////////////////////////////////////////////////////////////////////////////////
				team_user -= ({ ob });
				user_team[name] = team_user;
				team_size = sizeof(team_user);
				for ( i = 0, lvl = 0; i < team_size; i++ )
				{
					if ( objectp(team_user[i]) )
						lvl += team_user[i]->query_temp("xyzx_team/lvl"); // 取得所有成员等级和
				}
				for ( i = 0; i < team_size; i++ )
				{
					if ( objectp(team_user[i]) )
						team_user[i]->set_temp("xyzx_team/max_lvl", lvl); // 所有成员等级和
				}
				// 退出副本
				if ( !VRM_SERVER->valid_place_name(name) && virtualp(environment(ob)) )
				{
					show_user = filter_array(users(), "team_listener", this_object(), name);
					message("party", HIM"【"HIG"副本精灵"HIM"】"HIW"队伍 "HIC+name+HIW" 成员 "HIY+ob->name(1)+HIW" 开始退出副本。\n"NOR, show_user);
					if ( !wizardp(ob) )
						ob->set("vrm_in_busy", time()+1800);
					room = find_object("/d/city/wumiao");
					if ( !room ) room = load_object("/d/city/wumiao");
					// 战斗和busy中无法立即退出副本
					//_____________________________________________________________________
					if ( !ob->is_fighting() && !ob->is_busy() ) 
					{
						tell_object(ob, "你开始离开副本。\n");
						ob->move(room);
					}
					else
					{ // 放入队列，延迟处理
						if ( !arrayp(exit_duplicate_user) ) exit_duplicate_user = ({ });
						if ( member_array(ob, exit_duplicate_user) == -1 )
							exit_duplicate_user += ({ ob });
					}
					//______________________________________________________________________
				}
				/////////////////////////////////////////////////////////////////////////////////
	}
	
	team_user = filter_array( users(), "team_listener", this_object(), name );
	message("party", HIY"【"+name+"】"HIM"成员 "HIW+ob->query("name")+"("+ob->query("id")+")"+HIM" 退出了队伍。\n"NOR, team_user);
	if ( !duizhang )
	{ // 队员离开队伍，检查分配模式
		if ( !check_team_vip(name) ) 
		{ // 队伍中全是免费会员，变更分配模式为：平均
			if ( leader = get_team_leader(name) )
			{ // 获得队长
				change_allot_type(leader, "average"); // 改变分配模式为：平均
				type = get_allot_type(name);
				message("party", HIY"【"+name+"】"HIW"由于队伍中都是免费会员，分配模式强制更改为："HIC+type+HIW""NOR, team_user);
			}
		}
	}
	return 1;
}

// 查看队伍成员
string more_team_list(object ob)
{
	string msg, str, name, arg, type;
	object *team_user, room;
	int i, lvl, max_lvl, team_size;

	msg = "";

	if ( !objectp(ob) ) return msg;
	if ( !interactive(ob) ) return msg;
	if ( !objectp(environment(ob)) ) return msg;
	if ( !mapp(user_team) ) return msg;
	if ( !sizeof(user_team) ) return msg;
	if ( !stringp(name = ob->query_temp("xyzx_team/name")) ) return msg;
	if ( !arrayp(user_team[name]) ) return msg;
	
	type = get_allot_type(name);
	team_user = user_team[name];
	team_size = sizeof(team_user);

	msg = sprintf(HIY"〖%s〗"NOR"队伍信息：成员 "HIG"%s"NOR" 人，团队共享资源获取翻倍 "HIY"%s"NOR" 。\n"NOR, 
		name, sprintf(HIG"%d"NOR" / "HIY"%d"NOR, team_size, MAX_TEAM_MEMBER), sprintf("%d %s", check_team_vip(ob)?((team_size-1)*10+100):100, "%") );
	msg += "------------------------------------------------------------------------------\n";
	msg += sprintf("%-8s%-30s %-12s %-4s %-8s %-12s\n", " ", "成员名称", "获取分成", "信息", "分配模式", "所处位置");
	msg += "------------------------------------------------------------------------------\n";

	for ( i = 0; i < team_size; i++ )
	{
		lvl = team_user[i]->query_temp("xyzx_team/lvl");
		max_lvl = team_user[i]->query_temp("xyzx_team/max_lvl");
		name = team_user[i]->query("name")+"("+team_user[i]->query("id")+")";
		if ( type == team_allot_type_chinese["average"] )
			str = sprintf(GRN"%-5d"NOR"/"YEL"%-6d"NOR, 1, team_size);
		else
			str = sprintf(GRN"%-5d"NOR"/"YEL"%-6d"NOR, lvl, max_lvl);
		if ( !objectp(room = environment(team_user[i])) ) continue;
		if ( team_user[i]->query_temp("xyzx_team/block") )
			arg = HIR"拒绝"NOR;
		else
			arg = HIG"接听"NOR;
		if ( team_user[i]->query_temp("xyzx_team/zhang") )
			msg += sprintf("%-8s%-30s %-12s %-4s %-8s %-12s\n", HIY"【队长】"NOR, name, str, arg, HIC+type+NOR, room->query("short"));
		else
			msg += sprintf("%-8s%-30s %-12s %-4s %-8s %-12s\n", HIG"【队员】"NOR, name, str, arg, HIC+type+NOR, room->query("short"));
	}

	msg += "------------------------------------------------------------------------------\n";
	return msg;
}

// 团队奖励加成：根据团队人数加成奖励。
int team_add(object ob, string prop, mixed data)
{
	object *team_user, room, env;
	string name;
	int i, lvl, max_lvl, team_size, v, vv;

	if ( !stringp(prop) || !intp(data) )
	{
		ob->add(prop, data, 1);
		return 1;
	}
	if ( !objectp(ob) )
	{
		ob->add(prop, data, 1);
		return 1;
	}
	if ( data < 1 )
	{
		ob->add(prop, data, 1);
		return 1;
	}
	if ( !objectp(room = environment(ob)) )
	{
		ob->add(prop, data, 1);
		return 1;
	}
	if ( room->query("no_fight") )
	{
		ob->add(prop, data, 1);
		return 1;
	}
	if ( !mapp(user_team) )
	{
		ob->add(prop, data, 1);
		return 1;
	}
	if ( !sizeof(user_team) )
	{
		ob->add(prop, data, 1);
		return 1;
	}
	if ( !stringp(name = ob->query_temp("xyzx_team/name")) )
	{
		ob->add(prop, data, 1);
		return 1;
	}
	if ( !arrayp(team_user=user_team[name]) )
	{
		ob->add(prop, data, 1);
		return 1;
	}
	
	team_size = sizeof(team_user);
	if ( check_team_vip(ob) ) // 队伍中有会员则有加成
		v = (10 + TEAM_LIST_ADD * (team_size - 1)) * data / 10;
	else // 否则无加成
		v = data;

	for ( i = 0; i < team_size; i++ )
	{
		if ( mapp(team_allot_type) && team_allot_type[name]=="average" )
		{
			// 平均分配模式
			vv = v/team_size;
		}
		else
		{
			lvl = team_user[i]->query_temp("xyzx_team/lvl");
			max_lvl = team_user[i]->query_temp("xyzx_team/max_lvl");
		//	vv = atoi(count(count(v,"*",lvl), "/", max_lvl));
			vv = v * lvl / max_lvl;

		}
		
		if ( vv < 1 ) continue;
		if ( !objectp(env = environment(team_user[i])) ) continue;
		if ( (virtualp(room) && !virtualp(env))
			|| (!virtualp(room) && virtualp(env)) )
			continue;
		if ( (domain_file(base_name(room))=="party" && domain_file(base_name(env))!="party") 
			|| (domain_file(base_name(env))=="party" && domain_file(base_name(room))!="party") )
			continue;
		if ( domain_file(base_name(room)) != domain_file(base_name(env)) )
			continue;
		// 不允许战斗的地方不分经验
		if ( env->query("no_fight") ) continue;
		// 杀人犯不分经验
		if ( team_user[i]->query_condition("killer") ) continue;
		// 免费会员不分经验
		// if ( !team_user[i]->query("xyhy_type") ) continue;
		//不在同一个房间不分经验
	    if(environment(ob) != env) continue;
		//不参与战斗不分经验
	    if(ob->is_fighting() && !team_user[i]->is_fighting()) continue;
		//队员对刷不分经验
	     if(ob->is_fighting(team_user[i]) || team_user[i]->is_fighting(ob)) continue;

		team_user[i]->add(prop, vv, 1);
		// 不在战斗中则发送信息
	//	if ( !team_user[i]->is_fighting() )
	//	{
			// 如没设置屏蔽该消息，则发送之
			if ( !team_user[i]->query_temp("xyzx_team/block") )
			{
				if ( prop == "combat_exp" ) vv *= team_user[i]->query_exp_times();
				tell_object(team_user[i], "『队伍』：你获得了 "+vv+" 点"+team_share_chinese[prop]+"。\n");
			}
	//	}
	}

	return 1;
}

// 是否允许共享分配
int query_team_share(object ob, string prop)
{
	if ( !objectp(ob) ) return 0;
	if ( !ob->query_temp("xyzx_team/name") ) return 0;
	if ( !stringp(prop) ) return 0;
	if ( !arrayp(team_share) ) return 0;
	if ( member_array(prop, team_share) == -1 ) return 0;

	return 1;
}

// 获取一个团队所有成员
object *get_team_member(mixed ob)
{
	object *team_member;
	string name;

	team_member = ({});

	if ( objectp(ob) )
	{ // 传入参数是object
		if ( !interactive(ob) ) return team_member;
		if ( !stringp(name = ob->query_temp("xyzx_team/name")) ) return team_member;
		if ( !objectp(environment(ob)) ) return team_member;
	} 
	else if ( stringp(ob) ) // 传入参数是string
		name = ob;
	else 
		return team_member;
	if ( !mapp(user_team) ) return team_member;
	if ( !sizeof(user_team) ) return team_member;
	if ( !arrayp(team_member = user_team[name]) ) return ({});

	return team_member;
}

// 筛选函数
int team_listener(object ppl, string str)
{
	if ( !objectp(ppl) ) return 0;
	if ( !objectp(environment(ppl)) ) return 0;
	if ( wizardp(ppl) || ppl->query_temp("xyzx_team/name") == str )
		return 1;
	else
		return 0;
}

// 析构函数
void remove()
{
	string *teams;
	object *team_objs;
	int i, j;

	if ( mapp(user_team) && sizeof(user_team) )
	{
		teams = keys(user_team);
		for ( i=0; i<sizeof(teams); i++ )
		{
			if ( arrayp(team_objs = user_team[teams[i]]) && sizeof(team_objs) )
			{
				for ( j=0; j<sizeof(team_objs); j++ )
				{
					del_team_member(team_objs[j]);
				}
			}
			//message("party", HIR"【"HIM"队伍精灵"HIR"】："HIW"团队进程更新重置，队伍("HIY+teams[i]+HIW")已被自动解散。\n"NOR, users());
			message("party", HIR"【"HIM"队伍精灵"HIR"】："HIW"团队进程更新重置，队伍("HIY+teams[i]+HIW")已被自动解散。\n"NOR, teams);
		}
	}

	team_allot_type = ([]);
}

// 改变队伍分配模式
int change_allot_type(object ob, string type)
{
	object *team_user;
	string team_name, *is_type, get_type;
	int i;

	if ( !mapp(team_allot_type) ) team_allot_type=([]);
	if ( !objectp(ob) || !objectp(environment(ob)) ) return 0;
	if ( !stringp(team_name=ob->query_temp("xyzx_team/name")) )
	{
		tell_object(ob, "你还没有队伍。\n");
		return 0;
	}
	if ( !ob->query_temp("xyzx_team/zhang") )
	{
		tell_object(ob, "只有队长才能改变队伍分配模式。\n");
		return 0;
	}

	is_type = keys(team_allot_type_chinese);

	if ( !arrayp(is_type) || !sizeof(is_type) )
	{
		tell_object(ob, "目前游戏不支持改变队伍分配模式。\n");
		return 0;
	}
	if ( member_array(type, is_type) == -1 ) 
	{
		get_type = "";
		for ( i=0; i<sizeof(is_type); i++ )
		{
			get_type += HIY+team_allot_type_chinese[is_type[i]];
			get_type += "("HIG+is_type[i]+HIY")";
			if ( i < sizeof(is_type)-1 ) get_type += "、";
		}
		tell_object(ob, "目前游戏支持的队伍分配模式只有："+get_type+"。\n"NOR);
		return 0;
	}
	if ( team_allot_type[team_name] == type )
	{
		tell_object(ob, "你队伍目前的分配模式已为("HIY+team_allot_type_chinese[type]+NOR")，不需要再重新设定。\n");
		return 0;
	}
	if ( !check_team_vip(ob) && type=="level" )
	{
		tell_object(ob, "你的队伍中目前都是免费会员，分配模式只能为："+team_allot_type_chinese["average"]+"。\n"NOR);
		return 0;
	}
	
	team_allot_type[team_name] = type;
	team_user = filter_array( users(), "team_listener", this_object(), team_name );
	message("party", HIY"【"+team_name+"】"HIM"队长 "HIC+ob->query("name")+"("+ob->query("id")+")"+HIM" 更改队伍分配模式为："HIG
		+team_allot_type_chinese[type]+HIM"。\n"NOR, team_user);
	return 1;
}

// 是否支持更改队伍模式
int is_change_allot_type(string type)
{
	string *is_type;

	is_type = keys(team_allot_type_chinese);

	if ( !arrayp(is_type) || !sizeof(is_type) ) return 0;
	if ( member_array(type, is_type) == -1 ) return 0;

	return 1;
}

// 取得队伍分配模式，并转换成中文显示
string get_allot_type(string name)
{
	string type;

	if ( !mapp(team_allot_type) ) team_allot_type=([]);
	if ( !stringp(type=team_allot_type[name]) ) 
	{
		team_allot_type[name]="level";
		type="level";
	}

	if ( !is_change_allot_type(type) ) type = "等级比例";
	else type = team_allot_type_chinese[type];

	return type;
}

// 检查队伍中是否有会员，是返回 1，否则返回 0。
int check_team_vip(mixed ob)
{
	object *team_user;
	int i, max;

	if ( !arrayp(team_user=get_team_member(ob)) ) return 0;
	if ( !(max=sizeof(team_user)) ) return 0;
	for ( i=0; i<max; i++ )
	{
		if ( !objectp(team_user[i]) ) continue;
		if ( team_user[i]->query("xy_huiyuan") ) return 1; //xyhy_type
	}

	return 0;
}

// 获取队伍中的队长
object get_team_leader(mixed ob)
{
	object *team_user;
	int i, max;

	if ( !arrayp(team_user=get_team_member(ob)) ) return 0;
	if ( !(max=sizeof(team_user)) ) return 0;
	for ( i=0; i<max; i++ )
	{
		if ( !objectp(team_user[i]) ) continue;
		if ( team_user[i]->query_temp("xyzx_team/zhang") ) return team_user[i];
	}

	return 0;
}

private void heart_beat()
{
	object env;
	int i, max;

	if ( !arrayp(exit_duplicate_user) ) exit_duplicate_user = ({ });
	if ( !(max = sizeof(exit_duplicate_user)) ) return;

	for ( i=0; i<max; i++ )
	{
		if ( !objectp(exit_duplicate_user[i]) ) continue;
		if ( !objectp(env = environment(exit_duplicate_user[i])) ) continue;
		if ( !virtualp(env) ) continue;
		if ( exit_duplicate_user[i]->is_fighting() ) continue;
		if ( exit_duplicate_user[i]->is_busy() ) continue;

		tell_object(exit_duplicate_user[i], "你开始离开副本。\n");
		exit_duplicate_user[i]->move("/d/city/wumiao");
		exit_duplicate_user[i] = 0;
	}

	exit_duplicate_user -= ({ 0 });
}

mapping check_team_all()
{
	return user_team;
}

mapping check_team_type()
{
	return team_allot_type;
}
