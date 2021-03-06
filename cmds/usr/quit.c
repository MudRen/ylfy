// ----/cmds/usr/quit.c ----
//完善tomud协议quit列表(下线的行囊、人物、who列表的更新)
#include <dbase.h>
#include <command.h>
#include <ansi.h>
#include <liebiao.h>
// #define HTTP_D "/adm/daemons/httpd"

inherit F_DBASE;
inherit F_CLEAN_UP;

int do_rmdata(object ob, object me);

void create() 
{
	seteuid(getuid());
	set("channel_id", "离线指令");
}

string online_time(int t)
{
	int h, m, s;
	
	s = t % 60;
	t /= 60;
	m = t % 60;
	t /= 60;
	h = t ;
        
        return sprintf("本次联线时间%d:%d",m,s);
}

int main(object me, object target, string arg)	
{
	int exp,online;
	object link_ob;
	string ip_num,msg;
	
	if ( !objectp(me) ) return 0;
	// 限制特殊情况下不能离开游戏
	if( LOGIN_D->get_madlock() == 1 )  return notify_fail(HIY"时空已封闭，任何人都无法离开这个世界。\n"NOR);
	if ( !wizardp(me) )
	{
		if ( me->query_condition("killer") ) 
		{
			set_heart_beat(1);
			return notify_fail(HIR"你目前正被官府下令通缉，想潜逃么？\n"NOR);
		}
		/*if ( (me->query_temp("pker_starttime")+3600*me->query_temp("pker_time")) > me->query("mud_age") )
		{
			set_heart_beat(1);
			return notify_fail("你刚杀了人，暂时还无法离开游戏。\n");
		}*/
	}
	
	if( interactive(me) )
	{
		if ( me->is_busy() )
		{
			if( !me->query_temp("suicide") )
				return notify_fail("上一个动作未完成！\n");
			else
			{
				CHANNEL_D->do_channel(this_object(),"rumor",HIG""+me->query("name") + "终于想通了，放弃自杀了。 :)");
				tell_object( me,MAG "\n\n你决定要放弃自杀，太好了，那下次再来吧！\n\n\n" NOR);
			}
		}
		
		if ( me->is_fighting() ) return notify_fail("战斗中只能逃跑，不能退出游戏！\n");
	}
	
	// We might be called on a link_dead player, so check this.
	link_ob = me->query_temp("link_ob");
	
	if( link_ob )
	{
		// Are we possessing in others body ?
		if( link_ob->is_character() )
		{
			write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}
		
		if( !living(me) )
		{
			write("什麽？\n");
			return 0;
		}
		
		if( !wizardp(me) )
		{
			foreach (object ob in all_inventory(me))
			{
				if ( ob && !ob->query_autoload() && !ob->query("xyzx_save_item") )
					DROP_CMD->do_drop(me, ob, 1);
			}
			// 注册不及半小时退出游戏删除帐号以减轻系统负担
			if ( time() - me->query("birthday",1) < 1800 )
			{
				// 自主退出游戏
				if ( interactive(me) )
				{
					write(HIY"您刚注册帐号不及半小时，如果您现在离开游戏为了减轻系统负担将删除您的帐号"HIW"["HIR"Y"HIY"/"HIG"N"HIW"]"HIY"：\n"NOR);
					input_to("rmdata_exit", 1, link_ob, me);
					return 1;
				}
			}
			if ( !interactive(me) && time() - me->query("birthday",1) < 3600 )
			{ // 注册不足一小时的因断线等因数退出游戏删除帐号
				do_rmdata(link_ob, me);
				return 1;
			}
		}
		
		online=time()-link_ob->query("online_time");
		link_ob->set("last_on", time());
		if ( query_ip_name(me) )
			link_ob->set("last_from", query_ip_name(me));
		else
			link_ob->set("last_from", me->query_temp("last_ip_name"));
		exp=me->query("combat_exp")-link_ob->query("combat_exp");
		link_ob->set("combat_exp", me->query("combat_exp"));
		
		if ( !(wizardp(me) && me->query("env/invisibility") == 10) )
			link_ob->save();
		
		destruct(link_ob);
	}
	else
	{
		link_ob = new(LOGIN_OB);
		link_ob->set("id", me->query("id"));

		if( !link_ob->restore() )
		{
			destruct(link_ob);
        	return 0;
		}

		// 注册不及半小时退出游戏删除帐号以减轻系统负担
		if ( !wizardp(me) )
		{
			if ( time() - me->query("birthday",1) < 1800 )
			{
				// 自主退出游戏
				if ( interactive(me) )
				{
					write(HIY"您刚注册帐号不及半小时，如果您现在离开游戏为了减轻系统负担将删除您的帐号"HIW"["HIR"Y"HIY"/"HIG"N"HIW"]"HIY"：\n"NOR);
					input_to("rmdata_exit", 1, link_ob, me);
					return 1;
				}
			}
			if ( !interactive(me) && time() - me->query("birthday",1) < 3600 )
			{ // 注册不足一小时的因断线等因数退出游戏删除帐号
				do_rmdata(link_ob, me);
				return 1;
			}

			if ( query_ip_name(me) ) // 记录IP
				link_ob->set("last_from", query_ip_name(me));
			else // 断线目前无 IP ，记录这次登录时的 IP
				link_ob->set("last_from", me->query_temp("last_ip_name"));

			link_ob->save();
		}

		destruct(link_ob);
	}

	//if ( in_input(me) ) /*remove_input_to(me)*/;
	
	write("欢迎下次再来！\n");
	//message("system", me->query("name") + "离开游戏。\n", environment(me), me);
	
	ip_num = query_ip_number(me);
	
	if (!ip_num)
		msg=me->query("name")+"("+me->query("id")+")"+HIR+"断线时间过长"+HIW+",自动离开游戏了。";
	else
		msg=me->query("name")+"("+me->query("id")+")("+query_ip_number(me)+")离开游戏了。";
	
	msg+=online_time(online);
	
	if (exp!=0)
		msg+=sprintf("，经验增加"+HIR+"%d"+NOR+WHT+"点。",exp);
	else
		msg+="。";
	
	CHANNEL_D->do_channel(this_object(), "sys",msg);

    reclaim_objects();
	
	if ( !wizardp(me) )
	{
		if ( sscanf(base_name(environment(me)), "/u/%*s") 
			|| sscanf(base_name(environment(me)), "/d/automap/%*s") 
			|| sscanf(base_name(environment(me)), "/d/migong/%*s") 
			|| environment(me)->query("no_login")
			|| clonep(environment(me))
			|| virtualp(environment(me)) )
		{
			me->delete("startroom");
		}
		else
			me->set("startroom", base_name(environment(me)));

		me->set("quit_time",time());
	}
	else me->set("startroom", base_name(environment(me)));
	// 清除技能熟练度
	//me->delete_learned();
	//me->delete("exp_jiacheng");
	me->save();
	
	if(!me->query("xieyi/zmud"))
	{
		tell_object(me,CLEAN2);
		tell_object(me,CLEAN0);
		tell_object(me,CLEAN1);
                /*
		if ( !me->query("env/myhp_show") )
			tell_object(me, ALERT("您使用的登陆器(客户端)版本过低，请到论坛下载最新版本的客户端。$$$$"
		"新版本客户端新增的功能具体如下：$$"
		"㈠、鼠标左键双击人物、物品栏里的图标可打开物品属性框。(如您是游戏管理员可以直接通过界面修改物品属性)$$"
		"㈡、点击环境变量按钮，可以直接打开环境变量设置框，里面有各环境变量用途的详细说明。$$"
		"㈢、增加精神、气血、精力、内力、食物、饮水六种状态条，有了它你再也不用经常靠输入hp来查看状态了。$$"
		"㈣、点击地图按钮可以打开地图对话框，您可以通过按钮操作直接去一些常去的地方，你也可以查看当前地图。$$"
		"㈤、点击问题申报按钮打开帖子发送框，你可以通过这里把你发现的问题或者好的建议直接发送给游戏管理员。$$"
		"㈥、修改了客户端免注册就可以使用全部的功能。$$"
		"㈦、修正了原来大窗口文字过多换行的问题，现在可以完全按服务器发送来的信息格式进行显示。(美观多了，呵呵)$$"
		"㈧、修改了原来点who列表自己的图标查看QQ资料没反应的问题，现在点自己的图标查看QQ资料会打开QQ资料设置框。$$"
		"㈨、修正了聊天窗口不会自动滚屏的问题。修改who列表在客户端处理刷新。$$"
		"㈩、修正了点击任务栏图标有时会导致窗口和图标同时消失的问题。(当时出现这问题只能用任务管理器来结束进程。汗)"));
               */
	}
	
	// 发送数据到数据库服务器
	// DATAD->send_database(me);
	destruct(me);
    //HTTP_D->make_who();
    return 1;
}

int rmdata_exit(string arg, object ob, object me)
{
	if ( strsrch(arg,"Y") != -1 || strsrch(arg,"y") != -1 )
		do_rmdata(ob, me);
	else
		write(HIG"\n您决定重新回到游戏了。\n"NOR);

	return 1;
}

int do_rmdata(object ob, object me)
{
	if ( !objectp(ob)) return 0;
	if ( !objectp(me)) return 0;

	CHANNEL_D->do_channel(this_object(), "sys", HBRED+HIY+me->query("name")+"("+me->query("id")+")"+HIW"删档离开游戏 From "+query_ip_number(me)+"\n"NOR);
	log_file("static/quit_rm",sprintf("%s 删档离开游戏 On %s\n",me->name(1)+"("+me->query("id")+")", CHINESE_D->chinese_time(7,ctime(time()))) );
	rm( ob->query_save_file() + __SAVE_EXTENSION__ );
	rm( me->query_save_file() + __SAVE_EXTENSION__ );	
	write(HIR"\n您决定离开游戏，您的帐号已被删除。\n"NOR);
	message("system", me->query("name") + "离开游戏。\n", environment(me), me);
	delete_item_data(me);
	me->set_temp("no_auto_items", 1);
	me->set_temp("no_end_save", 1);
	destruct(ob);
	destruct(me);
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : quit
当你想暂时离开时, 可利用此一指令。
HELP
    );
    return 1;
}