// lingxi.c ��Ϭһָ

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h"

int perform(object me, object target)
{
	string msg;
	object weapon;
	int damage, p;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��Ϭһָֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("tanzhi-shentong", 1) < 100 )
		return notify_fail("��ĵ�ָ��ͨ������죬�޷�ʹ����Ϭһָ��\n");

	weapon = me->query_temp("weapon");
	if (weapon) return notify_fail("��Ϭһָ�����ʹ�á�\n");

	if ( (int)me->query("neili") < 1000)
		return notify_fail("��������������޷�ʹ����Ϭһָ��\n");

	msg = CYN "$N˫��һǰһ�󣬻����������ָͻ��һ��������������һ�ɣ������С�������ֱϮ$nǰ�ء�\n";

	damage = me->query_skill("tanzhi-shentong", 1) + me->query_skill("force") * me->query("con");
	damage += random(damage);
	if (random(me->query("xyzx_sys/level")) > random(target->query("xyzx_sys/level"))) 
	{
		msg += "$n�������������ۡ���һ������ָ������ǰ�أ�\n";
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage / 3, me);
		p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
		if ( p < 30 && target->query("neili") < me->query("max_neili") 
			&& target->query("neili") < me->query("neili") )
		{
			msg += RED "$n�ؿ�һ���ʹ����е��أ�\n" ;
			target->unconcious();
		}

	} 
	else if (random(me->query("xyzx_sys/level")) > random(target->query("xyzx_sys/level") / 3)) 
	{
		msg += "$n���Ա�һ�����ù��˾��磬û�뵽���ָ����Ȼ�л�������$n����ת������������$p�ĺ󱳡�\n";
		target->receive_damage("qi", damage / 2, me);
		target->receive_wound("qi", damage / 6, me);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
				if ( p < 50 )
		{
		msg += RED "$n�����ؿ��е�ʹ���ƺ��˸�����Щ��\n" ;
		target->receive_wound("qi", damage / 6, me);
		}

	}
	else 
	{
		msg += "$n���Ա�һ�����ù��˾��磬ȴ��Ȼ�������ָ����Ȼ�л�������æ��ֻ��һ��ǰ�˲ſ��������ģ���Ǳ�֮����\n" NOR;
	}
	message_vision(msg, me, target);
	me->add("neili", -1000);
	me->start_busy(3);

	return 1;
}
