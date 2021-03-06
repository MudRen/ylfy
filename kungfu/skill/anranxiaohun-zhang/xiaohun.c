// xiaohun.c 黯然消魂
// By Kayin @ CuteRabbit Studio 99-4-16 19:18 new
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("anranxiaohun-zhang",1);
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「黯然消魂」只能在战斗中使用。\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「黯然消魂」只能空手使用。\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("你的真气不够！\n");

	if(!me->query("couple/have_couple"))
		return notify_fail("你还没有所爱的人，无法体会深切思念一个人的感受。\n");

	if( (int)me->query_skill("anranxiaohun-zhang",1) < 300 )
		return notify_fail("你的黯然消魂掌火候不够，无法使用「黯然消魂」！\n");

	if( (int)me->query_skill("force",1) < 200 )
		return notify_fail("你的内功修为不够，无法使用「黯然消魂」！\n");
	weapon = me->query_temp("weapon");
	me->add_temp("apply/attack",extra*2);
	me->add_temp("apply/damage",extra);

	msg = HIM "$N心如止水，心中思念着$N的爱人，无意之中使出了"HIR"“黯然消魂”！\n" NOR;
	msg += HIM   "就似傍晚的遥烟，顿时天地间产生一丝苦涩！\n" NOR;
	message_vision(msg, me, target);
	msg = HIC  "\n   黯 \n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIY  "\n      然\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIW  "\n        消\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR  "\n          魂\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIB "\n             掌\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack",-extra*2);
	me->add_temp("apply/damage",-extra);

	if( me->query("shen") > 10000
	        && target->query("shen") < 10000 )
	{
		msg = HIG "\n$N怒视$n,大唱一声，打出最后的一掌！就似傍晚的遥烟，顿时天地间产生一丝苦涩！\n"NOR;
		if( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3 || random(me->query("unarmed")) > target->query("dodge")/3 )
		{

			msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
			target->receive_damage("qi",extra*3);
			target->receive_wound("qi",extra*3);

			if (!target->is_busy()) target->start_busy(3);
			message_vision(msg, me, target);
			COMBAT_D->report_status(target);
		}
		else
		{
			msg += HIY"可是$p急中生智，伏地翻滚而出，避过了这致命一击,躲了开去。\n" NOR;
			message_vision(msg, me, target);
		}
	}
	me->add("neili", -500);
	me->start_busy(3);

	return 1;
}

