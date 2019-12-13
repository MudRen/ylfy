#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
	string msg;
	int damage, p;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) || !living(target) )
		return notify_fail("������������ֻ����ս����ʹ�á�\n");

	if( objectp( me->query_temp("weapon")) )
		return notify_fail("ֻ�п��ֲ���ʩչ��������������\n");

	if( (int)me->query_skill("yiyang-zhi", 1) < 100 || (int)me->query_str() < 25)
		return notify_fail("���еĹ��򻹲�����죬����ʹ�á�������������\n");

	if(me->query_skill("kumu-shengong", 1) <320)
		return notify_fail("�������ڵ��ڹ���Ϊ��ʹ������������������\n");

	if (me->query_skill_mapped("force") != "kumu-shengong" )
		return notify_fail("����ʹ�õ��ڹ����ԡ�\n");

    if ( me->query_skill_mapped("unarmed") != "yiyang-zhi" )
        return notify_fail("�������޷�ʹ�á��������������й�����\n");

	if (me->query_skill_mapped("parry") != "yiyang-zhi")
		return notify_fail("����ʹ�õ��мܲ��ԡ�\n");
	if( (int)me->query("neili") < 1200 )
		return notify_fail("���������Ϊ̫��������ʹ�á�������������\n");

	if( (int)me->query("neili") < 800 )
		return notify_fail("�������������\n");

	if (me->query("yd_2") && (target->query_skill_mapped("force")=="hamagong" || target->query_skill_mapped("unarmed") == "hamagong"))
	{
		msg = YEL "\n$N����$n��������ָ��һʽ���������������ֻ������������ָ��ֱϮ$n�ؿڣ�\n" NOR;
		if (random(me->query_skill("unarmed")) > target->query_skill("dodge") /4 )
		{
			me->start_busy(1);
			target->start_busy(1);
			damage = (int)me->query_skill("yiyang-zhi", 1) + me->query_skill("unarmed");
			damage = (int)me->query_skill("kurong-changong", 1) +damage;
			damage = random(damage)+150;
			target->receive_damage("qi", damage);
			target->receive_wound("qi", damage/2);
			me->add("neili", -300);
			p = (int)target->query("qi")*100/(int)target->query("max_qi");
			msg += HIR "$nһ��֮�£���Ϊʧɫ���������ƺ������Լ��Ŀ��ǣ�\n"NOR;
			msg += damage_msg(damage, "����");
			msg += "( $n"+eff_status_msg(p)+" )\n";
		}
		else
		{
			me->start_busy(3);
			me->add("neili", -200);
			msg += HIY"$p���ⷴ�ֵ�Ѩ�ƺ����Ǹ�󡹦�Ŀ��ǣ�ʶ��������Σ��֮��һ�������ţ��������һ�������ѵĶ����һ�С�\n"NOR;
		}
	}
	else
	{
		msg = YEL "\n$N������ָ��һʽ������������������������������죬һ�ɴ���������ֱϮ$n�ؿڣ�\n" NOR;
		if (random(me->query_skill("unarmed")) > target->query_skill("parry") / 4)
		{
			me->start_busy(1);
			target->start_busy(2);
			damage = (int)me->query_skill("yiyang-zhi", 1);
			//              damage = (int)me->query_skill("qiantian-yiyang", 1) +damage;
			damage = (int)me->query_skill("kurong-changong", 1) +damage;
			damage = damage + random(damage/2);
			target->receive_damage("qi", damage);
			target->receive_wound("qi", damage/3);
			me->add("neili", -(damage/2));
			p = (int)target->query("qi")*100/(int)target->query("max_qi");
			msg += damage_msg(damage, "����");
			msg += "( $n"+eff_status_msg(p)+" )\n";
			if(me->query_skill("yiyang-zhi", 1) > 150)
				call_out("perform2", 0, me, target);
		}
		else
		{
			me->start_busy(3);
			me->add("neili", -100);
			msg += HIY"����$pһ�����Ʒ���ԶԶ�Ķ��˿�ȥ��\n"NOR;
		}
	}
	message_vision(msg, me, target);
	return 1;
}

int perform2(object me, object target)
{
	string msg;

	if (!me || !target) return 0;
	if(!living(target))
		return notify_fail("�����Ѿ�������ս���ˡ�\n");

	if( (int)me->query("neili", 1) < 600 )
		return notify_fail("���Ҫ�ٳ��ڶ�ָ��ȴ�����Լ������������ˣ�\n");

	msg = YEL "\n����$N̤ǰһ�������ڶ�ָ���յ���$n��ǰ������Ѩ������Ѩ�������֮�\n"NOR;
	if (random(me->query_skill("unarmed")) > target->query_skill("dodge") / 4)
	{
		msg += HIR "���һָ���У�$nֻ����ȫ������ͨ���������������ܸ��ӣ�\n"NOR;
		me->start_busy(1);
		target->start_busy(me->query_skill("force",1)/30);
		me->add("neili", -(me->query_skill("force",1)/2));
		if((int)me->query_skill("yiyang-zhi", 1) > 200)
			call_out("perform3", 0, me, target);
	}
	else
	{
		me->start_busy(3);
		me->add("neili", -150);
		target->add("neili", -50);
		msg += HIY"\n$p�ۿ����޿ɱƣ���Ҳһָ��ȥ������ָ��������$p˳�����˿�ȥ��\n" NOR;
	}
	message_vision(msg, me, target);
	return 1;
}

int perform3(object me, object target)
{
	int skill;
	string msg;
	skill = (int)me->query_skill("yiyang-zhi", 1);
	skill = skill/10;

	if(!living(target))
		return notify_fail("�����Ѿ�������ս���ˡ�\n");

	if( (int)me->query("neili", 1) < 400 )
		return notify_fail("���Ҫ�ٳ�����ָ��ȴ�����Լ������������ˣ�\n");

	msg = YEL "\n������$Nһ��ָ�����ε�����Դ���������ͬʱ͸��$n���������Ϲ�Ѩ����ά�����Ѩ����������Ѩ����������Ѩ������������Ѩ��\n"NOR;
	if (random(me->query_skill("unarmed")) > target->query_skill("dodge") / 4)
	{
		me->add("neili", -200);
		msg += HIR "$nֻ�������澭��������ϢΪ֮һ����ȫ��������Ȼ�᲻�����ˣ�\n" NOR;
		target->add_temp("apply/attack", -100);
		target->add_temp("apply/dodge", -100);
		target->add_temp("apply/parry", -100);
		target->add("neili", -500);
		call_out("back", 3 + skill, target);
	}
	else
	{
		me->start_busy(target->query_skill("force",1)/30);
		me->add("neili", -300);
		target->start_busy(2);
		msg += HIY"\n$p��Ϣδ������$Pָ��������������æ��Ծ�����ߣ��Ǳ��رܿ���\n" NOR;
	}
	message_vision(msg, me, target);
	return 1;
}

void back(object target)
{
	if (!target) return;
	target->add_temp("apply/attack", 100);
	target->add_temp("apply/dodge", 100);
	target->add_temp("apply/parry", 100);
}
