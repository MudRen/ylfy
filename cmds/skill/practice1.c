// ----/cmds/skill/practice.c ----

// practice.c   	

int help(object me);

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object where = environment(me);
	string skillname, skill_name;
	int skill, skill_basic, skill_add, addtime, is_int, times;
	
	seteuid(getuid());
	
	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");
	
	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");
	
	if( environment(me)->query("no_fight") )
		return notify_fail("这里是是非之地，不可久留，别练功了，快走吧！\n");

	if( me->is_fighting() )
		return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	if ( me->query("neili") < 0 )
	{
		me->set("neili", 0);
		return notify_fail("你的内力不足。\n");
	}

	//if( !arg ) 
		//return help(me);
	if( !arg ) return (__DIR__"enable")->main(me, arg);

        if ( (sscanf(arg, "%s %d", arg, times)!=2 ))
                return notify_fail("指令格式：practice|lian <技能种类> <次数>\n");

        if ( times < 1 || times > 3)
               return notify_fail("练习次数必须大于一次，但不能超过三次。\n"); 
        if( !arg ) return help(me);

        if( !stringp(skillname = me->query_skill_mapped(arg))|| arg=="parry" )
                return notify_fail("你只能练习用 enable 指定的特殊技能。\n");
	
	if( !stringp(skillname = me->query_skill_mapped(arg)) || arg == "parry" )
		return notify_fail("你只能练习用 enable 指定的特殊技能。\n");

	skill_basic = me->query_skill(arg, 1);
	skill = me->query_skill(skillname, 1);
	skill_add = (skill_basic+skill)/4;
	is_int = me->query("int");
	is_int *= 20;
	skill_add += is_int;
	
	if( skill < 1 )
		return notify_fail("你好像还没有学过这项技能吧？最好先去请教别人。\n");
	
	if( skill_basic < 1 )
		return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。\n");
	
	if( skill_basic <= skill )
		return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");
	
	notify_fail("你试着练习" + to_chinese(skillname) + "，但是并没有任何进步。\n");
	
	if( SKILL_D(skillname)->practice_skill(me) )
	{
		if ( me->query_exp_times() > 1 ) addtime = 2;
		else addtime = 1;
		if (skill >= SKILL_D(skillname)->practice_level())
			me->improve_skill(skillname, times*(skill_add/5 +1)*addtime, skill_basic > skill? 0: 1);
		else
			me->improve_skill(skillname, times*(skill_add/5 +1)*addtime);//原是除5 2004.8.17 by wenwu

		if(!me->query("env/block_lian_msg") && skill_name = SKILL_D(skillname)->query_skill_name(skill))
			printf(HIW"你试着练习" + to_chinese(skillname) + "，对「%s」这一招似乎有些心得。\n"NOR, skill_name);
		else
			printf(HIW"你试着练习" + to_chinese(skillname) + "，似乎有些心得。\n"NOR);
		
		//write( HIY "你的" + to_chinese(skillname) + "进步了！\n" NOR);
		return 1;
	}
	else 
		return 0;
}

int help(object me)
{
        write(@TEXT
指令格式：practice|lian <技能种类> <次数>
这个指令让你练习某个种类的技能，这个技能必须是经过 enable 的专业技能。
如果你对这方面的基本技能够高，可以经由练习直接升级，而且升级的上限只跟
你基本技能的等级有关，换句话说，勤加练习是使你的所学「青出于蓝胜于蓝」
的唯一途径，当然，在这之前你必须从实际运用中获得足够的经验以提升你的基
本技能。
TEXT
        );
        return 1;
}

