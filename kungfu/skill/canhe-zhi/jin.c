// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
#define JIN "��" HIY "��ս���" NOR "��"

inherit F_SSERVER;


string final(object me, object target, int damage);

int perform(object me, object target)
{
	int damage;
	string msg;

	int ap, dp, slv, clv,p;
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail(JIN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (objectp(me->query_temp("weapon")))
		return notify_fail("�������ֲ���ʹ��" JIN "��\n");

	if ((int)me->query_skill("canhe-zhi", 1) < 260)
		return notify_fail("��Ĳκ�ָ��Ϊ���ޣ�����ʩչ" JIN "��\n");

	if (me->query_skill_prepared("unarmed") != "canhe-zhi")
		return notify_fail("������û��׼��ʹ�òκ�ָ������ʩչ" JIN "��\n");

	if ((int)me->query("max_neili") < 2500)
		return notify_fail("���������Ϊ���㣬����ʩչ" JIN "��\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("�����������������ʩչ" JIN "��\n");

	if ((int)me->query_skill("shenyuan-gong", 1) < 180)
		return notify_fail("�����Ԫ�����̫ǳ��\n");

	if ((int)me->query_skill("douzhuan-xingyi", 1) < 180)
		return notify_fail("��Ķ�ת���ƻ��̫ǳ��\n");

	if (! living(target))
		return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "˫�ֺ�ʮ��΢΢һЦ���ĵ��黨֮�⡣ʳָ����ָ����һ������ʱһ����������������$n" HIY "Ϯȥ��\n" NOR;

	ap = me->query_skill("unarmed") + me->query("xyzx_sys/level") + me->query_skill("force") + me->query_skill("dodge");
	dp = target->query("xyzx_sys/level") + target->query_skill("force") + target->query_skill("parry");
	me->start_busy(3);

	if ((int)target->query_skill("martial-cognize", 1) >= 200 && random(5) == 1)
	{
		me->add("neili", -400);
		me->start_busy(4);
		msg += HIY "����$n" HIY "Ҳ����¶Ц�ݣ���������һ����˳�ƹ��ϣ��ٽ�$N" HIY "��ָ�����Ŵ�����\n" NOR;
	}
	else if (ap * 2 / 3 + random(ap) > dp)
	{
		damage = me->query_skill("unarmed") + me->query_skill("force")* me->query("con");
		me->add("neili", -400);
		target->receive_damage("jing", damage);
		target->receive_wound("jing", damage);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		msg += HIR "ֻ�������͡�һ����ָ������$n" HIR"��ǰ����һ��Ѫ��ģ���Ĵ󶴣�͸����롣\n" NOR;
	}
	else
	{
		me->add("neili", -200);
		me->start_busy(4);
		msg += CYN "$n" CYN "��$N" CYN "������ӿ�����������мܣ���æ����Ծ����\n" NOR;
	}
	message_vision(msg, me, target);
	damage = me->query_skill("canhe-zhi");
	slv = target->query_skill("liumai-shenjian");

	ap = me->query_skill("unarmed") + me->query_skill("dodge") + me->query_skill("force");
	dp = target->query_skill("dodge") + target->query_skill("parry") + me->query_skill("force");

	msg = HIW "\nֻ��$N" HIW "ʮָ��̯����ʱ�ƿ������죬���ɽ�����ָ�⼤���������$n" HIW "��ֱ��ȥ��\n" NOR;

	me->start_busy(3);

	if (slv >= 140
	        && random(5) == 0
	        && slv >= clv - 60 // ����κ�ָ�ȼ��������񽣵ȼ���60������ȡ������Ч��
	        &&! target->is_busy()
	        && target->query_skill_prepared("unarmed") == "liumai-shenjian")
	{
		msg += HIY "\n����$n" HIY "ббһָ�����ָ����磬�����ݺᣬ��Ȼ"
		       "���죬����$N" HIY "�Ľ���ȫ���ۻأ������Լ���ȥ��\n" NOR +
		       HIR "��������������һ�����죬���Ͼ�����һЩѪ�Σ�\n" NOR;

		me->receive_wound("qi", slv / 3 + random(slv / 4));
		p = (int)me->query("qi") * 100 / (int)me->query("max_qi");
		msg += "( $N" + eff_status_msg(p) + ")\n";

	}
	else if (ap * 2 / 3 + random(ap) > dp)
	{
		target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);

		msg +=HIR "\n��ʱֻ������������һ����$n����������������ʱ���ض���������һ��Ѫ�ꡣ\n" NOR;
	}
	else
	{
		msg += CYN "\n$n" CYN "��$N" CYN "������ӿ����æ����һԾ���𣬱ܿ�����һ����\n" NOR;
	}

	ap = me->query_skill("unarmed");
	dp = target->query_skill("force");

	if (slv >= 160
	        && random(8) == 0
	        && slv >= clv - 60  // ����κ�ָ�ȼ��������񽣵ȼ���60������ȡ������Ч��
	        &&! target->is_busy()
	        && target->query_skill_prepared("unarmed") == "liumai-shenjian")
	{
		msg += HIY "\n����$n" HIY "����Сָһ�죬һ�С����󽣡���ָ��͸��"
		       "�������ĵ�������Ѹ�٣��ٽ�$N" HIY "�����ƻأ�\n" NOR + HIR
		       "��������������һ�����죬���Ͼ�����һЩѪ�Σ�\n" NOR;

		me->receive_wound("qi", slv / 2 + random(slv / 4));
		p = (int)me->query("qi") * 100 / (int)me->query("max_qi");
		msg += "( $N" + eff_status_msg(p) + ")\n";

	}
	else if (ap * 2 / 3 + random(ap) > dp)
	{

		target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);

		msg +=HIR "\nֻ��$n" HIR "һ���Һ�����$N�Ľ���������Ҫ����Ѫ��ģ������Ѫ������ֹ��\n" NOR;

	}
	else
	{
		msg += CYN "\n$n" CYN "��$N" CYN "������ӿ����æ����һԾ���𣬱ܿ�����һ����\n" NOR;
	}

	ap = me->query_skill("unarmed");
	dp = target->query_skill("parry");

	if (slv >= 180
	        && random(10) == 0
	        && slv >= clv - 50  // ����κ�ָ�ȼ��������񽣵ȼ���50������ȡ������Ч��
	        &&! target->is_busy()
	        && target->query_skill_prepared("unarmed") == "liumai-shenjian")
	{
		msg += HIY "\n�ɵ���ʯ֮�䣬$n" HIY "��Ȼ���ƣ����ֶ�Ȼ̽������"
		       "ָ���г彣����$N" HIY "һ�����ǽ��κϽ����������Σ�\n" NOR
		       + HIR "��������������һ�����죬���Ͼ�����һЩѪ�Σ�\n" NOR;

		me->receive_wound("qi", slv / 2 + random(slv / 2));
		p = (int)me->query("qi") * 100 / (int)me->query("max_qi");
		msg += "( $N" + eff_status_msg(p) + ")\n";
		me->start_busy(6);

	}
	else if (ap * 2 / 3 + random(ap) > dp)
	{
		target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);

		msg +=HIR "\n$n" HIR "�����мܣ����ǲ��У�$N��" HIR "���ν�����͸����룬��Ѫ���䣬������ս��\n" NOR;
	}
	else
	{
		msg += CYN "\n$n" CYN "��$N" CYN "������ӿ����æ����һԾ���𣬱ܿ�����һ����\n" NOR;
	}
	me->add("neili", -400 - random(100));
	message_vision(msg, me, target);

	msg = HIW "\n��� $N" HIW "ʳָ�����ʩչ���κ�ָ�ľ�����ʽ��һ������Ϯ��$n����ǰѨλ��\n" NOR;

	ap = me->query_skill("force");
	dp =target->query_skill("force");

	if (ap / 2 + random(ap) > dp)
	{
		me->add("neili", -100);
		me->start_busy(2);
		damage =  me->query_skill("force");
		target->receive_damage("qi", damage*2);
		target->receive_wound("qi", damage*2);
		msg += HIR "$n" HIR "��ܲ�������ʱ���öپ�����������һʹ�����ﲻ��һ��\n" NOR;
	}
	else
	{
		me->add("neili",-40);
		msg += CYN "����$n" CYN "������$N" CYN "����·��������Ų������ʹ$N�Ĺ���û�������á�\n" NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);
	if ((int)me->query_skill("canhe-zhi", 1)> 350)
	{
		if (random(3)==0) target->start_busy(3);
		msg = MAG "$NĬ����Ԫ�񹦣�������������ָ��ƽƽ�������޻��εص���$n������Ѩ" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

		msg = YEL "$N�������ϣ�����΢�飬������֮���ţ�����˫��ʳָ����һ��������ָ��ͬʱϮ��$n" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

		msg = WHT "$N��������ָ������ָ��ϳ�һ�ɽ�����ֱ��$n��ȥ"NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

		msg =RED "$N�������֣���ָ���ǻ��ţ��ٻ���£ָ��ȭ����ʱ��������������Ľ�������" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

		msg = HIR "$Nָ��Ϭ������һ�����ν�������$n�������ڣ�$nֻ���ؿ�һʹ��ȫ��������к����" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
	return 1;
}