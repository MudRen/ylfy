//fumo by greenwc
//fomo by yushu修改
//lilong alter 2002.01.08
#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int i,j,e,damage,damagea;

	if ( !target ) target = offensive_target(me);
	if ( !target
		|| !target->is_character()
		|| target->is_corpse()
		|| target==me)
		return notify_fail("你要攻击谁？\n");
	if ( !me->is_fighting(target) ) return notify_fail("你们没有在打架！\n");
	if ( playerp(me) && me->query("family/family_name") != "蜀山派" ) return notify_fail("不是蜀山的不能用「御剑伏魔」！\n");
	if ( (int)me->query("max_neili") < 20000 ) return notify_fail("你的内力修为太差。\n");
	if ( (int)me->query("neili") < 20000 ) return notify_fail("你的内力不足！\n");
	if ( (int)me->query("jing") < 100 ) return notify_fail("你的精神不足，没法子施用外功！\n");
	if ( !(weapon = me->query_temp("weapon")) ) return notify_fail("你必须手持剑才能使用剑法。\n");
	if ( (int)me->query_skill("shushan-force", 1) < 900 ) return notify_fail("你的蜀山心法等级不够，不能使用这一招！\n");
	if ( me->query_skill_mapped("force") != "shushan-force" ) return notify_fail("没有蜀山心法无法驾驭剑气。\n");

	i = (int)me->query_skill("sword", 1);
	if ( i < 1500 ) return notify_fail("你的基本剑法级别还不够，使用这一招会有困难！\n");
	i = (int)me->query_skill("yujianshu", 1);
	j = (int)target->query_skill("dodge", 1);
	e = i + j;
	if ( i < 1500 )
		return notify_fail("你的御剑术级别还不够，使用这一招会有困难！\n");

	me->delete("env/brief_message");
	target->delete("env/brief_message");
	//message_vision(HIC"\n$N口中默念御剑口诀，手中"+weapon->name()+NOR+HIC"顿时间霞光四射，一招「御剑伏魔」直斩$n！\n\n"NOR,me,target);
	message_vision(HIC"\n$N口中默念御剑口诀，手中长剑顿时间霞光四射，一招「御剑伏魔」直斩$n！\n\n"NOR,me,target);
	
	if ( random(e) > j )
	{       
		damage = i+random((int) me->query("max_neili"))/30;
		damagea = i+random((int) me->query("max_neili"))/50;
		target->receive_damage("qi", damage, me);
		target->receive_damage("jing", damagea, me);
		target->receive_wound("qi", damage/10, me);
		me->receive_damage("jing", 10000);
		me->receive_damage("qi", 10000);
		me->receive_wound("qi", 1000);
		me->add("neili", -10000);
		COMBAT_D->report_status(target);
		
		if ( !target->is_fighting(me) ) 
		{
			if ( living(target) )
			{
				if( playerp(target) ) target->fight_ob(me);
				else target->kill_ob(me);
			}
		}
	}

	target->start_busy(random(3)+1);
	me->start_busy(random(3)+1);
	return 1;
}
