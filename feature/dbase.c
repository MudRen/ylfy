//dbase.c
//增加兼容等级制升级算法 

#include <dbase.h>
inherit F_TREEMAP;

mapping dbase;
nosave mapping tmp_dbase;
nosave int exp_times = 1;
// The default_ob provides the default values of the dbase. It is set to
// be master copy of an object.
nosave mixed default_ob;

int get_levelup_exp();

mixed query_default_object()
{
	return default_ob;
}

void set_default_object(mixed ob)
{
	if( !geteuid() ) seteuid(getuid());

	default_ob = ob;
	ob->add("no_clean_up", 1);
}

mixed set(string prop, mixed data)
{
    if( !mapp(dbase) ) dbase = ([]);
    if( strsrch(prop, '/')!=-1 )
        return _set( dbase, explode(prop, "/"), data );
    return dbase[prop] = data;
}

varargs mixed query(string prop, int raw)
{
	mixed data;
	object ob;
	
	if( !mapp(dbase) )
		return 0;

	if ( prop == "combat_exp" && origin() != "local" ) 
	{
		ob = previous_object();
		if ( ob )
		{
			if ( sscanf(base_name(ob), "%*skungfu/skill/%*s") )
			{
				return (get_levelup_exp()/2*query("xyzx_sys/level"));
			}
			else if ( ob != this_object() )
				return get_levelup_exp();
		}

		/*tell_object(this_object(), "呼叫程式："+origin()+"\n");*/
	}
	
	if( undefinedp(dbase[prop]) && (strsrch(prop, '/')!=-1) ) 
		data = _query(dbase, explode(prop, "/"));
	else 
		data = dbase[prop];

	if( undefinedp(data) && default_ob ) data = default_ob->query(prop, 1);

	if( raw ) return data;

	return evaluate( data, this_object() );
}

int delete(string prop)
{
	if( !mapp(dbase) )
		return 0;
	
	if( strsrch(prop, '/')!=-1 )
		return _delete(dbase, explode(prop, "/"));
	else
	{
		map_delete(dbase, prop);
		return 1;
	}
}

varargs mixed add(string prop, mixed data, int team)
{
	mixed old;
	string hy;
	int levup_exp = 0, new_data = 0;
	int lvlupexp;
	
	if( !mapp(dbase) || !(old = query(prop, 1)) ) return set(prop, data);
	if( functionp(old) ) error("dbase: add() - called on a function type property.\n");
	// 团队奖励共享分配
	if ( !team && TEAMD->query_team_share(this_object(), prop) )
	{
		TEAMD->team_add(this_object(), prop, data);
		return 1;
	}
	// 经验翻倍系统
	if ( prop == "combat_exp" )
	{
		if ( stringp(hy = query("xy_huiyuan")) && query("xyhy_type") == 2)
		{
			if ( sscanf(hy, "%*s年%*s月%*s日") )
			{
				if ( intp(data) && data > 0 )
				{
					data = data * XYZX_SYS_EXP_NUM;
				}
			}
		}
		else if ( intp(data) && data > 0 )
		{
			data = data * exp_times;
		}
	}
	//自动升级
	switch (prop)
	{
		case "combat_exp":
			if ((new_data = old + data) >= LEVUP_EXP_START )
			{
				set("xyzx_sys/levup_exp", new_data - LEVUP_EXP_START + query("xyzx_sys/levup_exp", 1));
				set("combat_exp", LEVUP_EXP_START);
				// 等级提升
				lvlupexp = get_levelup_exp();
				if ( (levup_exp = query("xyzx_sys/levup_exp",1)) >= lvlupexp )
				{
					set("xyzx_sys/levup_exp", levup_exp - lvlupexp);
					//检查数据使之在设计范围内
					if ( query("xyzx_sys/levup_exp",1) > lvlupexp )
						set("xyzx_sys/levup_exp",lvlupexp);
					//等级提升
					set("xyzx_sys/level", query("xyzx_sys/level",1) + LEVEL_UP_NUM);
					//自动提升的级数
					set("xyzx_sys/auto_levup", query("xyzx_sys/auto_levup",1) + LEVEL_UP_NUM);
					//传送升级信息给目标
					tell_object(this_object(), HIG"你的"HIM"『 等 级 』"HIG"提升了！\n" NOR);
				}
			}
			else
				return set(prop, old + data);
			break;
		default:return set(prop, old + data);
	}
}

mapping query_entire_dbase()
{
    return dbase;
}

mixed set_temp(string prop, mixed data)
{
    if( !mapp(tmp_dbase) ) tmp_dbase = ([]);
    if( strsrch(prop, '/')!=-1 )
        return _set( tmp_dbase, explode(prop, "/"), data );
    return tmp_dbase[prop] = data;
}

varargs mixed query_temp(string prop, int raw)
{
    mixed data;

    if( !mapp(tmp_dbase) ) return 0;

    if( undefinedp(tmp_dbase[prop]) && strsrch(prop, '/') != -1 ) 
		data = _query(tmp_dbase, explode(prop, "/"));
    else
        data = tmp_dbase[prop];
    
	if( functionp(data) && !raw )
        return (*data)( this_object() );
    else 
        return data;
}
int delete_temp(string prop)
{
    if( !mapp(tmp_dbase) ) return 0;
    if( strsrch(prop, '/')!=-1 )
        return _delete(tmp_dbase, explode(prop, "/"));
    else {
        map_delete(tmp_dbase, prop);
        return 1;
    }
}

mixed add_temp(string prop, mixed data)
{
    mixed old;
    if( !mapp(tmp_dbase) || !(old = query_temp(prop, 1)) )
        return set_temp(prop, data);
    if( functionp(old) )
        error("dbase: add_temp() - called on a function type property.\n");
    return set_temp(prop, old + data);
}

mapping query_entire_temp_dbase()
{
    return tmp_dbase;
}

int query_exp_times()
{
	if ( stringp(query("xy_huiyuan")) 
		&& query("xyhy_type") == 2 )
		return XYZX_SYS_EXP_NUM;

	return exp_times;
}

void set_exp_times()
{
	object me;

	me = this_object();

	// 设置双倍奖励
	if ( time() < me->query("exp_jiacheng") 
		|| (me->query("xy_huiyuan") 
			//&& me->query("xyhy_type")  //普通会员也可以享受晚上的系统双倍了2015.10.6
			&& atoi(CHINESE_D->chinese_time(9,ctime(time()))) > 19) )
	{
		if ( interactive(me) )
			me->add("biguan_is_online", 1); // 离线时间增加加速
		exp_times = XYZX_SYS_EXP_NUM; // 设置双倍标识
	}
	else
		exp_times = 1;
}

int get_levelup_exp()
{
	object me = this_object();
	int lvl = me->query("xyzx_sys/level");
	int lvlupexp = (lvl + 1) * LEVUP_EXP;
	if ( 9223372036854775800 / LEVUP_EXP <= lvl ) 
		return 9223372036854775800;
	return lvlupexp;
}