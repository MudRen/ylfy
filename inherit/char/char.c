//生物核心程序

#include <action.h>
#include <ansi.h>
#include <command.h>
#include <condition.h>
#include <dbase.h>
#include <move.h>
#include <name.h>
#include <skill.h>
#include <team.h>
#include <user.h>
#include <liebiao.h>

inherit F_ACTION;
inherit F_ALIAS;
inherit F_APPRENTICE;
inherit F_ATTACK;
inherit F_ATTRIBUTE;
inherit F_COMMAND;
inherit F_CONDITION;
inherit F_DAMAGE;
inherit F_DBASE;
inherit F_EDIT;
inherit F_FINANCE;
inherit F_MESSAGE;
inherit F_MORE;
inherit F_MOVE;
inherit F_NAME;
inherit F_SKILL;
inherit F_TEAM;
inherit F_SUIT;    //套装

//Use a tick with longer period than heart beat to save cpu's work
nosave int tick;
nosave int baishi = 0;
nosave int save_times = 0;
nosave int use_skill_busy = 0;
nosave int all_lvl_set_flap = 0; // 为1时表示NPC的经验已经转换成属性值了

string tribar_graph(int, int, int, string);
int query_use_skill_busy();
int set_use_skill_busy(int num);

void create()
{
	//so LOGIN_D can export uid to us
	seteuid(0);
}

//Use this function to identify if an object is a character.
int is_character() { return 1; }

// setup: used to configure attributes that aren't known by this_object()
//at create() time such as living_name (and so can't be done in create()).
void setup()
{
	mapping my;
	int lvl, level;
	seteuid(getuid(this_object()));
	set_heart_beat(1);
	tick = 5 + random(10);
	enable_player();
	CHAR_D->setup_char(this_object());
	if ( !userp(this_object()) && 0 == all_lvl_set_flap )
	{
		set("breakup", 1);
		set("xy_huiyuan", "2101年3月3日");
		// NPC设置，版本升级至完全等级制时
		my = query_entire_dbase();		
		if(my["combat_exp"] > 0 ) //2015.12.20 添加，防止出现 exp<0的情况
		lvl = to_int(sqrt(to_float(my["combat_exp"]/(LEVUP_EXP/2)))); // 经验可转换的等级数
        this_object()->set("combat_exp", 0);
        this_object()->set("xyzx_sys/levup_exp", 0);
        level = this_object()->add("xyzx_sys/level", lvl);		
		//upnum = level * LEVUP_SHUXD_NUM_ONE;
		//upnum /= 5;
		this_object()->add("xyzx_sys/jingzhun", level);
		this_object()->add("xyzx_sys/lingxing", level);
		this_object()->add("xyzx_sys/minjie", level);
		this_object()->add("xyzx_sys/fanying", level);
		this_object()->set("xyzx_sys/property_set", 1);	
		all_lvl_set_flap = 1;
	}
	
}

void heart_beat()
{
	int cnd_flag, wimpy_ratio;
	mapping my;
	object me, ob, room, downroom, killer;
	string fightroom;

	me = this_object();
	
	if ( !objectp(room=environment()) )
	{
		if ( !playerp(me) && clonep(me) )
			destruct(me);
		return;
	}

	if ( playerp(me) )
	{
		save_times++;
		if ( save_times > 300 )
		{
			save_times = 0;
			me->save();
			tell_object(me, HIY"【"+HBBLU+HIC"存盘精灵"NOR+HIY"】："+HIG+"档案储存完毕\n"NOR);
		}

		me->degression_cmds_block();
	}
	
	my = query_entire_dbase();
	
	//内伤
	if ( my["eff_qi"] < 0 || my["eff_jing"] < 0 )
	{
		remove_all_enemy();//死亡清除所有战斗记录
		
		if ( stringp(fightroom = room->query("fight_room")) )
		if ( !downroom = find_object(fightroom) )
			downroom = load_object(fightroom);
		
		//擂台比武败方
		if( objectp(downroom) && objectp(killer = query_temp("last_damage_from")) )
		{
			//如果打擂台不是被玩家杀死的则真正死亡
			if (!playerp(killer))
			{
				die();
				return;
			}
			
			message_vision("$N飞起一脚，把$n踢下擂台！\n",killer,me);
			set("no_get",1);
			set("no_get_from",1);
			set_temp("temp_no_die",1);//设置擂台战败踢下来不会死亡
			me->remove_all_killer();
			me->delete_temp("last_damage_from");
			
			if ( me->query("eff_qi") < 0 )
				me->set("eff_qi",0);
			
			if ( me->query("eff_jing") < 0 )
				me->set("eff_jing",0);
			
			all_inventory(room)->remove_killer(me);//清除擂台上的Pk记录
			me->move(downroom);
			message("vision","只听见一声惨嚎，"+me->name()+"从擂台上重重的摔了下来！\n",downroom);
			CHANNEL_D->do_channel(killer,"rumor",me->name()+"被"+killer->name()+"一脚踢下了擂台！\n"NOR);
			unconcious();
			return;
		}
		
		die();
		return;
	}
	
	//If we're dying or falling unconcious?
	if( my["qi"] < 0 || my["jing"] < 0 )
	{
		remove_all_enemy();
		
		if ( stringp(fightroom = room->query("fight_room")) )
		if ( !downroom = find_object(fightroom) )
			downroom = load_object(fightroom);
		
		if( objectp(downroom) && objectp(killer = query_temp("last_damage_from")) )
		{
			if (!playerp(killer))
			{
				if( !living(me) )
					die();
				else
					unconcious();
				
				return;
			}
			
			message_vision("$N飞起一脚，把$n踢下擂台！\n",killer,me);
			set("no_get",1);
			set("no_get_from",1);
			set_temp("temp_no_die",1);//设置擂台战败踢下来不会死亡
			
			if ( me->query("qi") < 0 )
				me->set("qi",0);
			
			if ( me->query("jing") < 0 )
				me->set("jing",0);

			me->remove_all_killer();
			all_inventory(room)->remove_killer(me);
			me->move(downroom);
			message("vision","只听见一声惨嚎，"+me->name()+"从擂台上重重的摔了下来！\n",downroom);
			CHANNEL_D->do_channel(killer,"rumor",me->name()+"被"+killer->name()+"一脚踢下了擂台！\n"NOR);
			unconcious();
			return;
		}
		
		if( !living(me) )
			die();
		else
			unconcious();
		return;
	}

	if ( playerp(me) )
	{
		// 设置离线挂机时间只能同等于实际在线的时间
		if ( interactive(me) )
			me->add("biguan_is_online", 1);
		else if ( me->query("biguan_is_online") > 0 )
			me->add("biguan_is_online", -1);
		// 设置双倍奖励
		me->set_exp_times();
	}

	// 减少技能使用busy
	if ( query_use_skill_busy() > 0 ) use_skill_busy--;
	
	//Do attack if we are fighting.
	if( is_busy() )
	{
		//有Busy则随心跳减少Busy时间
		continue_action();
		//We don't want heart beat be halt eventually, so return here.
		if ( !me->is_fighting() && me->query("env/myhp_show") && !me->query("xieyi/zmud") )
			tell_object(me, my_hp(me));
		return;
	}
	else
	{
		//战斗中当精气百分比小于设置的逃跑系数时则找机会逃跑
		if( is_fighting() && intp(wimpy_ratio = (int)query("env/wimpy")) && wimpy_ratio > 0
			&&	( my["qi"] * 100 / my["max_qi"] <= wimpy_ratio || my["jing"] * 100 / my["max_jing"] <= wimpy_ratio) )
			{
                         GO_CMD->do_flee(me);
		         
                        }
		//Do attack or clean up enemy if we have fleed.
		attack();
		// 清除自动外功标志，表示运用完成
		// this_object()->delete_temp("xyzx_auto_skill_perform");
	}
	
	//NPC自主动作
	if ( !playerp(me) && living(me)) 
	{
		if ( !me->heal_self() ) me->chat();
	}

    //chat() may do anything -- include destruct(this_object())
    if( !me ) return;
	if( tick--  )
	{
		if ( !me->is_fighting() && me->query("env/myhp_show") && !me->query("xieyi/zmud") )
			tell_object(me, my_hp(me));
		return;
	}
	else
		tick = 5 + random(10);
	
	if ( me->query_condition("killer") || !room->query("freeze") /*中毒表现 */|| me->query("no_get") )
		cnd_flag = update_condition();
	
	//If we are compeletely in peace, turn off heart beat.
	// heal_up() must be called prior to other two to make sure it is called
	// because the && operator is lazy :P
	
	if( ((cnd_flag & CND_NO_HEAL_UP) || !heal_up()) && !is_fighting() && !interactive(me))
	{
		ob = first_inventory(room);
		while( ob && !interactive(ob) )
			ob = next_inventory(ob);
		if( !ob )
		{
			if ( !me->query_condition("killer") ) 
				set_heart_beat(0);
		}
	}
	if( !interactive(me) ) return;
    //heal_up();//减少饮食和恢复气血
	if ( baishi % 2 == 1 )
	{
		baishi = 0;
		me->delete_temp("pended");
	}

	baishi++;
	// Make us a bit older. Only player's update_age is defined.
	// Note: update_age() is no need to be called every heart_beat, it
	// remember how much time has passed since last call.
	
		me->update_age(); //更新玩家年龄
		if(query_idle(me) > IDLE_TIMEOUT)// && !wizardp(me))
			me->user_dump(DUMP_IDLE); //发呆处理
}

int visible(object ob)
{
	int lvl, invis;
	
	if ( ob == this_object() )
		return 1;
	
	lvl = wiz_level(this_object());
	
	if( ob->is_ghost() )
	{
		if( is_ghost() )
			return 1;
		
		if ( !userp(this_object()) )
			return 1;
		
		if( query_temp("apply/astral_vision") )
			return 1;
		
		if ( lvl > 2 )
			return 1;
		else
			return 0;
	}
	
	if ( lvl <= wiz_level(ob) )
	{
		if ( !query_temp("apply/shade_vision") && ob->query_temp("apply/shade_vision") && ob->is_fighting() )
		{
			if ( !userp(this_object()) )
				return 1;
			else
				return 0;
		}
		
		if ( wizardp(ob) )
			invis = (int)ob->query("env/invisibility");
		else
			invis = 0;
		
		if( invis > lvl )
			return 0;
	}
	else
		return 1;
	
	return 1;
}

int command( string str )
{
        return efun::command(str);
}

// Tomud状态条函数
string tribar_graph(int val, int eff, int max, string color)
{
	string bar_string = "■■■■■■■■■■";
	string blank_string = "□□□□□□□□□□";
	string none_string = "※※※※※※※※※※";
	if ( max < 1 ) max = 1;
	return color + bar_string[0..(val*10/max)*2-1] + ((eff > val) ? blank_string[(val*10/max)*2..(eff*10/max)*2-1] : "") + ((max > eff) ? none_string[(eff*10/max)*2..19] : "");
}

int query_use_skill_busy()
{
	return use_skill_busy;
}

int set_use_skill_busy(int num)
{
	if ( num < 0 ) num = 0;
	
	use_skill_busy = num;

	return use_skill_busy;
}