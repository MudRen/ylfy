
#include <ansi.h>
#include <weapon.h>
#include <combat.h>

#define LIAN "��" HIW "������ת" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string wp, msg;
	int i, count, attack_time;

	if (! target) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail(LIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "hammer")
		return notify_fail("����ʹ�õ��������ԣ�����ʩչ" LIAN "��\n");

	if (me->query_skill_mapped("hammer") != "riyue-lun")
		return notify_fail("��û�м��������ַ�������ʩչ" LIAN "��\n");

	if ((int)me->query_skill("riyue-lun", 1) < 300)
		return notify_fail("�������ַ�����㣬����ʩչ" LIAN "��\n");

	if ((int)me->query_skill("force", 1) < 250)
		return notify_fail("����ڹ�����㣬����ʩչ" LIAN "��\n");

	if ((int)me->query("max_neili") < 3000)
		return notify_fail("���������Ϊ���㣬����ʩչ" LIAN "��\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("�����ڵ��������㣬����ʩչ" LIAN "��\n");

	if (! living(target))
		return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	wp = weapon->name();

	msg = HIY "$N" HIY "��Ŀ��ȣ�ʩչ�������ַ���" HIW "������ת"HIY "���񼼣���ؽ�����" + wp + HIY "����\n����������������â���໥������ѹ��$n" HIY "������ɷΪ���棡\n" NOR;
	message_vision(msg, me, target);

	count = me->query_skill("riyue-lun", 1) / 20;
	count += me->query_skill("longxiang", 1) / 20;
    attack_time = count/4;
	if(attack_time > 50) attack_time = 50;
	
	me->add_temp("apply/attack", count);
	me->add_temp("apply/damage", count);
    me->add_temp("lianzhao", attack_time);

	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
			break;

		if ( weapon->query("id") == "jin lun")
		{
			switch (i)
			{
			case 0:
				msg = WHT "ͻȻ�����ִ����½����з��뿪��������һ����â��$n" WHT "��ȥ��\n" NOR;
				break;
			case 1:
				msg = HIR "ͻȻ�����ִ����½����з��뿪��������һ����â��$n" HIR "��ȥ��\n" NOR;
				break;
			case 2:
				msg = YEL "ͻȻ��ͭ�ִ����½����з��뿪��������һ����â��$n" YEL "��ȥ��\n" NOR;
				break;
			case 3:
				msg = HIW "ͻȻ�����ִ����½����з��뿪��������һ����â��$n" HIW "��ȥ��\n" NOR;
				break;
			default:
				msg = HIY "ͻȻ����ִ����½����з��뿪��������һ����â��$n" HIY "��ȥ��\n" NOR;
				break;
			}
			message_vision(msg, me, target);
			COMBAT_D->do_attack(me, target, weapon, 30);
		}
		else
			COMBAT_D->do_attack(me, target, weapon, 0);
	}
	me->add("neili", -100*attack_time);
	me->add_temp("apply/attack", -count);
	me->add_temp("apply/damage", -count );
	me->delete_temp("lianzhao");
	me->start_busy(3);
	return 1;
}


