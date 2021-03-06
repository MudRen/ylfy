// tie@fengyun

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, i, v, attack_time;
	object weapon;
	
	if ( !target ) target = offensive_target(me);
	if ( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("铁掌降龙只能对战斗中的对手使用。\n"); 
	if ( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「铁掌降龙」只能空手使用。\n");		
	if ( (int)me->query_skill("tiezhang-zhangfa", 1) < 500 )
		return notify_fail("你的铁掌掌法不够娴熟，不能用铁掌降龙。\n");
	
	if( me->query_skill_mapped("unarmed") != "tiezhang-zhangfa" )
	    return notify_fail("你没有用铁掌掌法。\n");
	if ( (int)me->query_skill("guiyuan-tunafa", 1) < 900 )
	    return notify_fail("你的归元吐纳法不够娴熟，不能使用铁掌降龙。\n");

	extra = me->query_skill("tiezhang-zhangfa", 1) / 50;

	if ( (int)me->query("neili", 1) < extra * 100 )
		return notify_fail("你现在内力不足，不能使用！\n");	
	
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra*2);
	
	msg = HIY"\n$N运起［归元吐纳法］，同时使出［铁掌降龙］一阵一阵的掌力，如潮水般的击向$n！\n\n" NOR;
	message_vision(msg, me, target);
	msg = HIW "第一层掌力，．．．．\n" NOR;
	v = 1;
	attack_time = extra;
	if ( attack_time > 50) attack_time = 50;
	message_vision(msg, me, target);

	for ( i=0; i<attack_time; i++ )
	{
		if ( i>4 && !(i%5) )
		{
			v++;
			msg = HIC "$N身形突转，又是连续五掌拍出第"+chinese_number(v)+"层掌力！\n" NOR;
			message_vision(msg, me, target);
		}
		COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra*2);
	me->add("neili", - 100 * extra);
	return 1;
}
