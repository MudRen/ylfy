// wuqing.c ��Ůȭ-��Ĺ�ľ�
// by liu 24/07/2001
// Xuanyuan 5/9/2001�޸�

/*
�����������������С��Ů���ϣ�����֧�ã���������ӳ�����̾һ�������ּ�
��֮�⡣���ǡ���Ůȭ�������һ�е���ʽ����������Ĺ�ľӡ���ȴ���������
�����ֳ�Ӣ��Ȼ��֪��С��ŮҲ�ǲ��ᡣ�������ѧȫ����Ůȭ��֮��������
ʦ�������ݵ��У������ڹŴ���Ů���书֮�߸�����˵����·ȭ����������ʦ��
���ڣ��㲻�������Ա�����������������һ�У���˵Ϊ��д�ֳ�Ӣ��������ֹ��
̬ȴ��ģ����ʦ��С��Ů������С��Ů������ֻ��΢΢һ�ӣ���Ҳ���������ȥ
���֡�
*/

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int damage,jiali;

	jiali = (int)me->query("jiali");

    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("��Ů����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if( objectp(me->query_temp("weapon")) )
        return notify_fail("������ȷ������еı�����\n");
    if( (int)me->query_skill("yunv-xinjing", 1) < 300 )
        return notify_fail("�����Ů�ķ���δ��죬�����������˵С�\n");
    if( (int)me->query_skill("meinv-quanfa", 1) < 520 )
        return notify_fail("�����Ůȭ��Ϊ����������ʹ�ù�Ĺ�ľӡ�\n");

	if( me->query_skill_mapped("force") != "yunv-xinjing" )
		return notify_fail("�����õĲ�����Ů�ľ���ʹ������Ĺ�ľӣ�\n");

    if( (int)me->query("neili", 1) < 5000 )
        return notify_fail("����������̫��������ʹ�ù�Ĺ�ľӡ�\n");

    if( (int)me->query("jing", 1) < 500 )
        return notify_fail("�����ھ���̫��������ʹ�ù�Ĺ�ľ� n��\n");

	if( jiali > 50 )
	    return notify_fail("��Ĺ�ľ������ϳ��ڼҹ������ϼӴ�����̫���޷�ʹ����\n");

	msg = HIB "\n$N����������Ҫ����������֧�ã�����������$n�ӳ�����̾һ�������ּ���֮�⡣\n\n"NOR;

	msg += HIY"���ǡ���Ůȭ�������һ�е���ʽ����������Ĺ�ľӡ���ȴ��������Դ����ֳ�Ӣ��Ȼ\n";
	msg += HIY"��֪��������С��ŮҲ�ǲ��ᡣ�����������ѧȫ����Ůȭ��֮��������ʦ��������\n";
	msg += HIY"���в����ڹŴ���Ů���书֮�߸�����˵����·ȭ����������ʦ�����ڣ��㲻��������\n";
	msg += HIY"������������������һ�У���˵Ϊ��д�ֳ�Ӣ��������ֹ��̬ȴ��ģ����ʦ��С��Ů��\n\n";

  if( random( me->query("xyzx_sys/level") ) > random( target->query("xyzx_sys/level")) || !living(target) )
  {
	damage = me->query_skill("unarmed") + me->query_skill("force") * me->query("con");
	me->add("neili", - 5000 );

	target->receive_damage("qi", damage, me);
	target->receive_wound("qi", random(damage), me);

	msg += RED"ֻ���顢�顢�顢�鼸�����죬$n����ù������ѷ��˳�ȥ��\n"NOR;
	msg += NOR;
	me->start_busy(2);
	}
	else {
	msg += HIG"$n���һ�֣�����Ծ�𣬱��ܵķ�Ӧ�ٿ���$N�����䡣\n\n"NOR;
	me->add("neili", -1000 );
	me->start_busy(2);
	message_vision(msg+"\n", me, target );
	return 1;
  }

	message_vision(msg+"\n", me, target);
	COMBAT_D->report_status(target);
	return 1;
}
