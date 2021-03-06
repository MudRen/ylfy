// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified
// in any form without the written permission from authors.
// huang.c 地老天荒

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{
	string msg;
	int skill, ap, dp, damage;


	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! me->is_fighting(target))
		return notify_fail("「地老天荒」只能对战斗中的对手使用。\n");

	if (me->query_temp("weapon"))
		return notify_fail("必须空手才能施展「地老天荒」。\n");

	if (me->query_skill_mapped("unarmed") != "tianchang-zhang")
		return notify_fail("你没有激发天偿掌法，无法施展「地老天荒」。\n");

	skill = me->query_skill("tianchang-zhang", 1);

	if (skill < 100)
		return notify_fail("你的天偿掌法修为有限，不能使用「地老天荒」！\n");

	if (me->query("neili") < 150)
		return notify_fail("你的真气不够，无法运用「地老天荒」！\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "“嚯”的一声震喝，提起掌来，只见掌心一片血红，倏的凌空拍出，"
	      HIR "一股热风登时袭向$n" HIR "的胸前大穴。\n" NOR;

	ap = me->query_skill("unarmed") + me->query_skill("force") + me->query_skill("dodge");
	dp = target->query_skill("parry") + target->query_skill("dodge") + target->query_skill("force");

	if (ap / 2 + random(ap) > dp)
	{
		me->add("neili", -120);
		me->start_busy(2);
		damage = me->query_skill("unarmed") + me->query_skill("force")*2;
		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
		me->add("neili", -150);
		msg += HIR "$n" HIR "一时间只觉得气血上涌，浑身如遭火焚，气息大乱，不由得吐了一口鲜血。\n" NOR;

	}
	else
	{
		me->add("neili",-50);
		msg += HIC "然而$n" HIC "内功深湛，丝毫不为$N的掌风所动，若无其事" NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);

	return 1;
}
