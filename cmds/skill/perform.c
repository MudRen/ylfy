inherit F_CLEAN_UP;
#include <liebiao.h>
int main(object me, string arg)
{
	object weapon;
	mapping smap;
	string martial, skill;
	
	seteuid(getuid());
	smap = me->query_skill_map();
	if( !arg )
		return notify_fail("你要用外功做什麽？\n");

	if ( me->query("neili") < 0 )
	{
		me->set("neili", 0);
		return notify_fail("你的内力不足。\n");
	}

	if ( me->is_busy() )
		return notify_fail("( 你上一个动作还没有完成，不能施用技能绝招。)\n");
	
	if ( playerp(me) && !me->query("xy_huiyuan") && me->query("age") > 17 )
		return notify_fail(HIY"只有会员才能施用技能绝招。\n"NOR);

	if ( me->query_use_skill_busy() )
		return notify_fail("你的真气尚未回转，暂时不能施用技能绝招。\n");
	
	if( me->query_condition("no_perform") )
		return notify_fail("( 你气息不匀，暂时不能施用外功。)\n");
	
	if (sscanf(arg, "%s.%s", martial, arg) != 2)
        {
		if (weapon = me->query_temp("weapon"))
			martial = weapon->query("skill_type");
		else
			martial = "unarmed";
	}
	
	if( stringp(skill = me->query_skill_mapped(martial)) )
	{
		if (file_size(SKILL_D(skill)->perform_action_file(arg)+".c") > 0 || file_size("/binaries" + SKILL_D(skill)->perform_action_file(arg)+".b") > 0)
		{
			notify_fail("你所使用的外功中没有这种功能。\n");
			
			if( SKILL_D(skill)->perform_action(me, arg) )
			{
				if( random(120) < (int)me->query_skill(skill) )
					me->improve_skill(skill, 1, 1);
				if ( playerp(me) )
				{
					// 设置技能绝招使用冷冻延迟时间
					if ( me->is_busy() && !me->query_use_skill_busy() )
						me->set_use_skill_busy(random(3));
					// 当出外功没busy时增加busy避免出现BUG
					if ( !me->is_busy() && skill != "shedao-qigong" )
						me->start_busy(1+random(3));
				}
				
				return 1;
			}
			else if( SKILL_D(martial)->perform_action(me, arg) )
			{
				if( random(120) < (int)me->query_skill(martial, 1) )
					me->improve_skill(martial, 1, 1);
				if ( playerp(me) )
				{
					// 设置技能绝招使用冷冻延迟时间
					if ( me->is_busy() && !me->query_use_skill_busy() )
						me->set_use_skill_busy(random(3));
					// 当出外功没busy时增加busy避免出现BUG
					if ( !me->is_busy() && martial != "shedao-qigong" )
						me->start_busy(1+random(3));
				}
				
				return 1;
			}
			
			return 0;
		}
	}

	if( sscanf(arg, "%s.%s", martial, arg)!=2 )
	{
		
		if( weapon = me->query_temp("secondary_weapon") )
			martial = weapon->query("skill_type");
		else
			martial = "unarmed";
	}
	
	if( stringp(skill = me->query_skill_mapped(martial)) )
	{
		notify_fail("你所使用的外功中没有这种功能。\n");
		
		if( SKILL_D(skill)->perform_action(me, arg) )
		{
			if( random(120) < (int)me->query_skill(skill) )
				me->improve_skill(skill, 1, 1);
			if ( playerp(me) )
			{
				// 设置技能绝招使用冷冻延迟时间
				if ( me->is_busy() && !me->query_use_skill_busy() )
					me->set_use_skill_busy(random(3));
				// 当出外功没busy时增加busy避免出现BUG
				if ( !me->is_busy() && skill != "shedao-qigong" )
					me->start_busy(1+random(3));
			}
			
			return 1;
		}
		else if( SKILL_D(martial)->perform_action(me, arg) )
		{
			if( random(120) < (int)me->query_skill(martial, 1) )
				me->improve_skill(martial, 1, 1);
			if ( playerp(me) )
			{
				// 设置技能绝招使用冷冻延迟时间
				if ( me->is_busy() && !me->query_use_skill_busy() )
					me->set_use_skill_busy(random(3));
				// 当出外功没busy时增加busy避免出现BUG
				if ( !me->is_busy() && martial != "shedao-qigong" )
					me->start_busy(1+random(3));
			}
			
			return 1;
		}
		
		return 0;
	}
	
	return notify_fail("你请先用 enable 指令选择你要使用的外功。\n");
}

int help (object me)
{
        write(@HELP
指令格式：perfrom [<武功种类>.]<招式名称> [<施用对象>]
如果你所学的外功(拳脚、剑法、刀法....)有一些特殊的攻击方式或招式，可以
用这个指令来使用，你必须先用 enable 指令指定你使用的武功，不指定武功种
类时，空手的外功是指你的拳脚功夫，使用武器时则是兵刃的武功。
若是你的外功中有种类不同，但是招式名称相同的，或者不属於拳脚跟武器技能
的武功(如轻功)，可以用 <武功>.<招式>  的方式指定，如：
perform taiji-jian.chan
or
perform chan
换句话说，只要是 enable 中的武功有特殊招式的，都可以用这个指令使用。
HELP
        );
        return 1;
}
