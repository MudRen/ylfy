// xuanfeng.c  旋风浮影

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「旋风浮影」只能在战斗中使用。\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「旋风浮影」开始时不能拿着兵器！\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够！\n");

	if( (int)me->query_skill("bibo-shengong",1) < 50 )
		return notify_fail("你的碧波神功不够！\n");

	if( (int)me->query_skill("luoying-zhang",1) < 500 || me->query_skill("xuanfeng-tui",1) < 500)
		return notify_fail("你的腿掌功夫还不到家，无法使用狂风绝技！\n");

	msg =  HIC"$N使出桃花岛绝技「旋风浮影」，掌腿齐出、步步紧逼！\n" NOR;
	message_vision(msg, me, target);
	msg =  HIB  "$N聚力于左掌，右腿一脚跟着踢出！" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIM  "人影中，$N翻身而起，左掌大力得挥向$n！" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIY  "$N见$n门户大开，暗运内力，双腿连环踢向$n！" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = CYN  "$N越战越勇，周围骤起一阵旋风，使得$n看不清方向！" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIG"$N如星光乍现，右掌略带悠然之色轻拍$n！" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR"$N长啸一声，面如赤发，忽然转到$n身后，反手又是一掌！" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add("neili", -500);
	me->start_busy(4);

	return 1;
}

