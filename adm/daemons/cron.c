// File：/adm/daemons/cron.c
// 自检系统

// 系统间隔 XYZX_REBOOT_TIME 小时重启
// #define XYZX_REBOOT_TIME 300
// 允许使用的最大内存 (Mb)
// #define CAN_USED_MAX_MEM 50

#define DEBUG 1
#define REBOOT_TIME 7

#include <ansi.h>
#include <net/daemons.h>

inherit F_DBASE;

static int LAST_HARD_DIS;
static int flag = 0;
static int line = 0;
static int reboot_time = 0;

void start_task();
void autosave();
void auto_clear();
void check_dns();
void check_nature();
void check_callouts();
void check_neicun();
void add_top();

int set_last_hard_dis();

void create()
{
	seteuid( ROOT_UID );
	set("channel_id", "守护精灵");
	CHANNEL_D->do_channel( this_object(), "sys", "守护精灵已经启动。\n"NOR);
	set_heart_beat(90);
	set_last_hard_dis();
}

int clean_up()
{
	return 1;
}

int query_last_hard_dis()
{
	return LAST_HARD_DIS;
}

int set_last_hard_dis()
{
	LAST_HARD_DIS = time();
	return flag;
}

private void heart_beat()
{
	object npc;
	int time, m, s;
	
	// 通告游戏主页地址
	//message("system",HIG"【"BRED+HIY"游戏精灵"NOR+HIG"】"HIW"："HBBLU"主页:"+get_system_config(DATA_CONFIG_DIR "system.h", "XYZX_WEB")+"\n"NOR,users());
	//message("system",HIG"【"BRED+HIY"游戏精灵"NOR+HIG"】"HIW"："HBBLU"论坛:"+get_system_config(DATA_CONFIG_DIR "system.h", "XYZX_BBS")+"\n"NOR,users());

	remove_call_out("start_task");
	call_out("start_task", 60);

	time = get_system_config(DATA_CONFIG_DIR "system.h", "REBOOT_TIME") * 3600 - uptime();
	m = time / 60;
	s = time % 60;

	if ( (int)uptime() / 3600 == get_system_config(DATA_CONFIG_DIR "system.h", "REBOOT_TIME") - 1 )
	{
		message("channel:chat",HIR"【系统精灵】"HIY"夕阳再现 之 [一代宗师] "HIW"距离重启时间还有 "HIY + m + " 分 "HIG + s +" 秒。\n"NOR, users());
	}

	if ( reboot_time == 0 && (int)uptime() / 3600 == get_system_config(DATA_CONFIG_DIR "system.h", "REBOOT_TIME") )
	{
		npc = new("/clone/npc/demogorgon");
		npc->move("/d/wizard/meeting");
		npc->start_shutdown();
		write_file("/log/static/LASTCRASH", "夕阳再现-风之纹章 自动重启于 " + ctime(time()) + "\n");
		reboot_time++;
	}
}

void start_task()
{
	mixed *local;	
	local = localtime(time());
	
	if ( !(local[1] % 7 ))
	{
		auto_clear();
		check_neicun();
	}
	
	if ( !(local[1] % 15 ))
	{
		// 检查CALLOUT
		if( LOGIN_D->get_madlock() != 1 )
			check_callouts();
    }
	
	if (local[1]==20 || local[1]==40 )
	{
		TASK_D->init_dynamic_quest();
		message("system",HIY"\n\n【"HIR"任务精灵"HIY"】-----"HIG"重新分布部分使命．．．．．\n\n" NOR,users());
	}
	
	if (flag==1)
	{
		TASK_D->init_dynamic_quest(1);
		flag=0;
		set_last_hard_dis();
		message("system",HIY"\n\n【"HIR"任务精灵"HIY"】-----"HIG"重新分布所有使命．．．．．\n\n" NOR,users());
	}
	
	if (local[1]==59 || ((int)time()-(int)query_last_hard_dis()) > 3720)
	{
		flag=1;
		CHANNEL_D->do_channel( this_object(), "sys", HIR "所有使命将在一分钟后重新分布！！！\n"NOR);
		//autosave();
	}
	
	if (local[1]==45 || local[1]==15 )
	{
		// check_dns();
		// check_nature();
		add_top();
	}
}

// 备份在线玩家的档案，针对win2000意外关机除错导致的档案错乱
void autosave()
{
	object *users;

	users = users();
	foreach(object ob in users)
	{
		if( !environment(ob) )
			continue;

		//创建根目录
		if ( file_size("/backtemp/") == -1 )
			mkdir("backtemp");

		if ( file_size("/backtemp/login/") == -1 )
			mkdir("/backtemp/login");

		if ( file_size("/backtemp/user/") == -1 )
			mkdir("/backtemp/user");
		
		if ( file_size("/backtemp/login/" + ob->query("id")[0..0] + "/") == -1 )
			mkdir("/backtemp/login/" + ob->query("id")[0..0]);
			
		cp((DATA_DIR+"/login/"+ob->query("id")[0..0]+"/"+ob->query("id")+".o"),("/backtemp/login/"+ob->query("id")[0..0]+"/"+ob->query("id")+".o"));

		if ( file_size("/backtemp/user/" + ob->query("id")[0..0] + "/") == -1 )
			mkdir("/backtemp/user/" + ob->query("id")[0..0]);
		
		cp((DATA_DIR+"/user/"+ob->query("id")[0..0]+"/"+ob->query("id")+".o"),("/backtemp/user/"+ob->query("id")[0..0]+"/"+ob->query("id")+".o"));
	}
	
	message("system",HIG"\n【"HIR"档案精灵"HIG"】"HIW"："HIY"在线数据备份完毕\n", users());
}

// 报告自动清除的变数
void auto_clear()
{
	string *msg;
	int i;

	CHANNEL_D->do_channel( this_object(), "sys",sprintf("系统自动清除 " + reclaim_objects() + " 个变数。"NOR));
	
	if(file_size("/data/caipiao/call")!=-1)
	{
		msg = explode(read_file("/data/caipiao/call"),"\n");
		for(i=0;i<sizeof(msg);i++)
		{
			if (msg[i] == "")
				break;

			message("channel:chat",HIW+msg[i]+NOR"\n",users());
		}
	}
}

// 检查DNS
void check_dns()
{
	mapping mud_list;
	mixed *muds;
	object dns;
	
	// dns not started, not our problem
	if(!dns = find_object(DNS_MASTER))
		return;
	
	mud_list = (mapping) DNS_MASTER->query_muds();
	muds=keys(mud_list);
	
	if(sizeof(muds)<= 1)
	{
		destruct(dns);
		call_other(DNS_MASTER,"???");
	}
	return;
}

// 检查NATURE
void check_nature()
{
	mixed *infos;
	object ob;
	int nature=0;
	
	infos = call_out_info();
	foreach(mixed info in infos)
	{
		if( "/"+sprintf("%O",info[0]) == NATURE_D )
			nature=1;
	}
	
	if(!nature)
	{
		if(ob=find_object(NATURE_D)) destruct(ob);
		call_other(NATURE_D,"???");
	}
	return;
}

// 监查CALLOUT的执行
void check_callouts()
{
	mixed *info;
	int i,f=0;
	string output;
	object *users, link_ob;
	
	info = call_out_info();
	for(i=0; i<sizeof(info); i++)
	{
		if(info[i][2]<info[f][2])
		{
			f=i;
		}
	}
	
	if(info[f][2] > -100)
	{
		CHANNEL_D->do_channel( this_object(), "sys", HIW"CALLOUT检测报告---"HIG"状态正常。\n"NOR);
		return;
	}
	
	users = users();
	
	if( flag!=2 )
	{
		flag = 2;
		message("system",HIB"\n【"HIG"守护精灵"HIB"】"HIW"："HIR"游戏出现故障，系统自动封闭时空。\n"NOR,users());
		output = sprintf("%-30O %-20s %d ",info[f][0], info[f][1],info[f][2]);
		log_file("CALLOUTS_ERR",output + ctime(time())+"\n");
		return;
	}
	else
		CHANNEL_D->do_channel( this_object(), "sys", HIW"CALLOUT检测报告---"HIG"状态正常。\n"NOR);
	
	message("system",HIR"\n【"HIG"系统精灵"HIR"】"HIW"：正在保存玩家数据中．．．\n"NOR, users());
	foreach(object user in users)
	{
		if( !environment(user) ) continue;
		user->save();
		
		link_ob = user->query_temp("link_ob");
		if( objectp(link_ob) )
			link_ob->save();
	}
	// 保存所有的守护进程的数据
	reset_eval_cost();
	// 禁止玩家继续登陆
	LOGIN_D->set_madlock(1);
	// if (find_object(DNS_MASTER)) DNS_MASTER->send_shutdown();
	log_file("static/MADLOCK",sprintf("系统因为故障自动封闭时空于%s\n",ctime(time())) );
	message("system",HIR"\n【"HIG"系统精灵"HIR"】"HIW"："HIY"．．．保存完毕，请大家静候巫师回来处理\n\n"NOR, users());
}

// 检测系统内存使用情况，负担过大自动重启释放内存
void check_neicun()
{
	object npc;

	if ( memory_info() > get_system_config(DATA_CONFIG_DIR "system.h", "CAN_USED_MAX_MEM") * 1048576 )
	{
		message("system",HIY"\n\n\n\n\n守护精灵："HIR"系统负担超出规划范围，系统将维护性当机重新启动。\n"+
		"　        游戏重启之前，不再另行通知。\n"NOR,users());
		/*if( find_object(DNS_MASTER) )
			DNS_MASTER->send_shutdown();
		NATURE_D->auto_shutdown(1);*/
		npc = new("/clone/npc/demogorgon");
		npc->move("/d/wizard/meeting");
		npc->start_shutdown();
		write_file("/log/static/LASTCRASH", "夕阳再现-风之纹章 因内存维护重启于 " + ctime(time()) + "\n");
	}
	else
		CHANNEL_D->do_channel( this_object(), "sys", HIY"内存检测报告---"HIG"状态正常\n"NOR);
}

//自动更新各种状态的排行
void add_top()
{
	"/cmds/bos/topadd-sys"->main();
	CHANNEL_D->do_channel( this_object(), "sys",sprintf(HIC"排行版自动更新完毕。\n"NOR));
}
