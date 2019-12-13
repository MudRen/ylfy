// qiankun.c 一阳指 「一指乾坤」

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) || !living(target) )
		return notify_fail("「一指乾坤」只能在战斗中使用。\n");

	if((int)me->query_str() < 28)
		return notify_fail("你臂力不够,不能使用这一绝技!\n");
	
    if( objectp( me->query_temp("weapon")) )
		return notify_fail("只有空手才能施展「一指乾坤」。\n");
	
	if((int)me->query_skill("kumu-shengong",1) < 90)
		return notify_fail("你枯荣禅功的功力不够不能使用一指乾坤!\n");

	if((int)me->query_skill("sun-finger",1) < 90)
		return notify_fail("你的一阳指修为不够,目前还不能使用一指乾坤绝技!\n");

	if((int)me->query("max_neili") < 850)
		return notify_fail("你内力修为不够, 不能使用一指乾坤! \n");

	if((int)me->query("neili") < 200)
		return notify_fail("你内力现在不够, 不能使用一指乾坤! \n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

	msg = CYN "$N使出一阳指绝技「一指乾坤」，罩住$n的全身要穴, 企图使$n动弹不得。\n"NOR;

	if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/3 )
	{
		msg +=   "结果$n被$N攻了个措手不及! 一时不能动弹! \n";
		target->start_busy( (int)me->query_skill("yiyang-zhi",1) / 100 + 4);
		me->add("neili", -200);
	}
	else
	{
		msg += "可是$n看破了$N的企图，并没有上当。\n";
		me->start_busy(3);
		me->add("neili", -200);

	}
	message_vision(msg, me, target);

	return 1;
}
