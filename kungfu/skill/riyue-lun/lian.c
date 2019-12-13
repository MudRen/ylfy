
#include <ansi.h>
#include <weapon.h>
#include <combat.h>

#define LIAN "「" HIW "五轮连转" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string wp, msg;
	int i, count, attack_time;

	if (! target) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail(LIAN "只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "hammer")
		return notify_fail("你所使用的武器不对，难以施展" LIAN "。\n");

	if (me->query_skill_mapped("hammer") != "riyue-lun")
		return notify_fail("你没有激发日月轮法，难以施展" LIAN "。\n");

	if ((int)me->query_skill("riyue-lun", 1) < 300)
		return notify_fail("你日月轮法火候不足，难以施展" LIAN "。\n");

	if ((int)me->query_skill("force", 1) < 250)
		return notify_fail("你的内功火候不足，难以施展" LIAN "。\n");

	if ((int)me->query("max_neili") < 3000)
		return notify_fail("你的内力修为不足，难以施展" LIAN "。\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你现在的真气不足，难以施展" LIAN "。\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	wp = weapon->name();

	msg = HIY "$N" HIY "嗔目大喝，施展出日月轮法「" HIW "五轮连转"HIY "」神技，蓦地将手中" + wp + HIY "飞掷\n而出，幻作数道光芒，相互盘旋着压向$n" HIY "，招术煞为精奇！\n" NOR;
	message_vision(msg, me, target);

	count = me->query_skill("riyue-lun", 1) / 20;
	count += me->query_skill("longxiang", 1) / 20;
    attack_time = count/4;
	if(attack_time > 50) attack_time = 50;
	
	me->add_temp("apply/attack", count);
	me->add_temp("apply/damage", count);
    me->add_temp("lianzhao", attack_time);

	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
			break;

		if ( weapon->query("id") == "jin lun")
		{
			switch (i)
			{
			case 0:
				msg = WHT "突然间锡轮从日月金轮中分离开来，化作一道灰芒朝$n" WHT "砸去。\n" NOR;
				break;
			case 1:
				msg = HIR "突然间铁轮从日月金轮中分离开来，化作一道红芒朝$n" HIR "砸去。\n" NOR;
				break;
			case 2:
				msg = YEL "突然间铜轮从日月金轮中分离开来，化作一道黄芒朝$n" YEL "砸去。\n" NOR;
				break;
			case 3:
				msg = HIW "突然间银轮从日月金轮中分离开来，化作一道银芒朝$n" HIW "砸去。\n" NOR;
				break;
			default:
				msg = HIY "突然间金轮从日月金轮中分离开来，化作一道金芒朝$n" HIY "砸去。\n" NOR;
				break;
			}
			message_vision(msg, me, target);
			COMBAT_D->do_attack(me, target, weapon, 30);
		}
		else
			COMBAT_D->do_attack(me, target, weapon, 0);
	}
	me->add("neili", -100*attack_time);
	me->add_temp("apply/attack", -count);
	me->add_temp("apply/damage", -count );
	me->delete_temp("lianzhao");
	me->start_busy(3);
	return 1;
}


