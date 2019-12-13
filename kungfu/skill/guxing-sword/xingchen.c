#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
	string msg;
	if (!target ) target = offensive_target(me);
	if (!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「日毁星沉」只能在战斗中使用。\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if((int)me->query_skill("sword",1) < 500)
		return notify_fail("你的基本剑法的火候还不到家, 不能使用这一绝技 !\n");
	if((int)me->query_skill("guxing-sword",1) < 500)
		return notify_fail("你的孤星剑法的火候还不到家, 不能使用这一绝技 !\n");
	if( (int)me->query("neili") < 5000 )
		return notify_fail("你的真气不够！\n");
	if( (int)me->query("max_neili") < 5000 )
		return notify_fail("你的内力修为不够！\n");
	msg = YEL "\n$N威威一皱眉头，潇洒从容的使出孤星剑法中的最后杀招「日毁星沉」！\n" NOR;
	message_vision(msg, me);
	me->clean_up_enemy();
	ob = me->select_opponent();
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	me->add("neili",-5000);
	me->start_busy(random(3));
	return 1;
}
