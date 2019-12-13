//来去若无形 wuying.c
// by godzilla 99.03.06

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon,ob;
	int skill;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「分身无影」只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("「分身无影」必须用剑才能施展。\n");

	if( (int)me->query_skill("wuying-jian", 1) < 150 )
		return notify_fail("你的「少林无影剑」不够娴熟，不会使用「分身无影」。\n");

	if( (int)me->query("neili") < 300  )
		return notify_fail("你的内力不够。\n");

	skill = me->query_skill("wuying-jian");
	msg = HIG "$N身行突变，瞬间犹如分出无数身影闪电般的向$n攻去！\n"NOR;
	message_vision(msg, me, target);

	me->add("neili", -200);

	me->clean_up_enemy();
	ob = me->select_opponent();
	msg = HIR"来字决！\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	msg = HIY"去字决！\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);
	msg = HIG"若字决！\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	msg = HIB"无字决！\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	msg = HIW"形字决！\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}
