#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��"+HIY"��������"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");


	if( (int)me->query_skill("jinshe-zhang", 1) < 500 )
		return notify_fail("��Ľ��������Ʋ�������������ʹ�á�"+HIY"��������"NOR+"����\n");

	if( (int)me->query("max_neili") < 50000 )
		return notify_fail("���������Ϊ�������ߡ�\n");

	if( (int)me->query("neili") < 150000 )
		return notify_fail("������������ˡ�\n");

	if( me->query_temp("weapon"))
		return notify_fail("���ȷ������е�������˵�ɣ���\n");

	msg = HIY "	$N������ͻȻ�������,����Ư������,ǰҡ��ڷ�����Χ��$n��ת����,\n$nֻ��ͷ�����ǵ�������$N����Ӱ,�����м���һ��ɫ��������Ϯ���Լ�Ҫ����λ��\n"NOR;

	if( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3)
	{
		me->start_busy(3);
		target->start_busy(3+random(1));

		damage = (int)me->query_skill("unarmed")*2+(int)me->query_skill("force");
		damage = damage + random(damage);

		target->receive_damage("jing", damage);
		target->receive_wound("jing", damage);
		me->add("neili", -damage-200);
		msg += HIR"$n��æ�м���������Ȼ����,ֻ���ؿھ�ʹ�����׻�,��������������λ�����ε�����������������Ѫ������\n"NOR;
		message_vision(msg, me, target );
		COMBAT_D->report_status(target);		
		return 1;

	}
	else
	{
		me->start_busy(3);
		me->add("neili",-200);
		msg += CYN"$n����ϸ��,����������Ʈ��,�����ŵ�һ��Ь����Ȼȫ����ȥ,$n���ɵ��ų�һ���亹��\n"NOR;
	}
	message_vision(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}


