#include <ansi.h>

inherit F_SSERVER;

#define LIAN "��" HIW "�۰�����" NOR "��"

int perform(object me, object target)
{
	object weapon;
	string msg;
	int i;
	int count;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	//  if( userp(me) && !me->query("can_perform/badao/xiong") )
	//       return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail(LIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( !objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "blade" )
		return notify_fail("��ʹ�õ��������ԣ�\n");

	if( me->query("neili")<3000 )
		return notify_fail("��������������޷�ʩչ" LIAN "��\n");

	if ((int)me->query_skill("force") < 900)
		return notify_fail("����ڹ���򲻹�������ʩչ" LIAN "��\n");

	if ((int)me->query_skill("badao", 1) < 700)
		return notify_fail("��İԵ��������ң��޷�ʩչ" LIAN "��\n");

	if (me->query_skill_mapped("blade") != "badao")
		return notify_fail("��û�м����Ե����޷�ʩչ" LIAN "��\n");

	if (! living(target))
		return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "ʹ��ʧ���ѾõİԵ�������" HIW "�۰�����" HIY"����������Ȼ�ӿ죬գ�ۼ䣬�˵����� ����\n" NOR;

	message_vision(msg, me);
	me->add("neili", -2600);

	count = me->query_skill("blade")/2;
	me->add_temp("apply/damage", count);

	for (i = 0; i < 8; i++)
	{
		if (! me->is_fighting(target))
			break;

		if (random(2) && ! target->is_busy())
			target->start_busy(1);

		COMBAT_D->do_attack(me, target, weapon, 0);
	}

	me->add_temp("apply/damage", -count);
	me->start_busy(2 + random(3));
	return 1;
}