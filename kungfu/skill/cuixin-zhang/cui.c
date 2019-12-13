#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��"+HIG"�������"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("cuixin-zhang", 1) < 500 )
		return notify_fail("��Ĵ����Ʋ�������������ʹ�á�"+HIG"�������"NOR+"����\n");

	if ( (string)me->query("family/family_name") != "������")
		return notify_fail("��"+HIG"�������"NOR+"��ֻ�������ɴ��˲���ʹ�á�\n");

	if( (int)me->query_skill("yijing-force", 1) < 500 )
		return notify_fail("����׾��񹦲�������������ʹ�á�"+HIG"�������"NOR+"����\n");

	if( (int)me->query_skill("lingyunbu", 1) < 1000 )
		return notify_fail("������Ʋ�������������������ϴ�����ʹ�á�"+HIG"�������"NOR+"����\n");

	if( (int)me->query("max_neili") < 50000 )
		return notify_fail("���������Ϊ�������ߡ�\n");

	if( (int)me->query("neili") < 800 )
		return notify_fail("������������ˡ�\n");

	if( me->query_temp("weapon"))
		return notify_fail("���ȷ������е�������˵�ɣ���\n");

	msg = HIC "$N˫��һ�֣�ʩչ��������֮�ؼ�"HIM+"��������꡹"+HIC"����$n��ƮƮ���ĳ�һ�ƣ�\n"NOR;

	if( random(me->query_skill("unarmed")) > target->query_skill("force")/5)
	{
		me->start_busy(1);
		target->start_busy(random(2));

		damage = me->query_skill("force") * me->query("con") + me->query_skill("unarmed")*2;

		damage = damage + random(damage);
		if (damage < target->query("max_qi",1)/8 && me->query("max_neili",1) > target->query("max_neili",1)/2)
			damage = random (target->query("max_qi",1)/6);

		if (damage>target->query("max_qi",1)/3)
			damage = random (target->query("max_qi",1)/4);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		me->add("neili", -4000);
		msg += HIR"$n�ۼ���һ������������Ҳ��ȥ��ǣ���$N������������ֻʱ�Ÿе����ھ߷٣���\n"NOR;
		message_vision(msg, me, target );
		COMBAT_D->report_status(target);
		return 1;

	}
	else
	{
		me->start_busy(1);
		me->add("neili",-200);
		msg += HIY"$n�۾�һ���������������̺�������������æ���˶㿪��\n"NOR;
	}
	message_vision(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

