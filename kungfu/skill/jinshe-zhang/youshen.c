#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「"+HIY"金蛇游身"NOR+"」只能对战斗中的对手使用。\n");


	if( (int)me->query_skill("jinshe-zhang", 1) < 500 )
		return notify_fail("你的金蛇游身掌不够熟练，不会使用「"+HIY"金蛇游身"NOR+"」。\n");

	if( (int)me->query("max_neili") < 50000 )
		return notify_fail("你的内力修为还不够高。\n");

	if( (int)me->query("neili") < 150000 )
		return notify_fail("你的内力不够了。\n");

	if( me->query_temp("weapon"))
		return notify_fail("你先放下手中的武器再说吧？！\n");

	msg = HIY "	$N的身体突然变得柔软,身形漂浮不定,前摇后摆飞絮般围着$n旋转起来,\n$n只觉头晕脑涨到处都是$N的身影,朦胧中见得一金色蛇形气劲袭向自己要害部位。\n"NOR;

	if( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3)
	{
		me->start_busy(3);
		target->start_busy(3+random(1));

		damage = (int)me->query_skill("unarmed")*2+(int)me->query_skill("force");
		damage = damage + random(damage);

		target->receive_damage("jing", damage);
		target->receive_wound("jing", damage);
		me->add("neili", -damage-200);
		msg += HIR"$n匆忙中急欲闪避已然不及,只觉胸口剧痛如遭雷击,五脏六腑翻腾移位，身形跌飞丈余洒下漫天鲜血！！！\n"NOR;
		message_vision(msg, me, target );
		COMBAT_D->report_status(target);		
		return 1;

	}
	else
	{
		me->start_busy(3);
		me->add("neili",-200);
		msg += CYN"$n不及细想,提气纵身急急飘起,但觉脚底一凉鞋底已然全部削去,$n不由得吓出一身冷汗。\n"NOR;
	}
	message_vision(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}


