// tianlei.c ����--������

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
        string msg;
        object weapon;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ����������\n");

        if( (int)me->query_skill("guiyuan-tunafa", 1) < 119 )
		return notify_fail("�����������δ���ɣ�����ʹ�ã�\n");

        if( (int)me->query("neili", 1) < 600 )
		return notify_fail("�������������㣬����ʹ����������\n");	

	if( (int)me->query_skill("tiezhang-zhangfa", 1) < 119 )
		return notify_fail("��������Ʒ�������죬����ʹ����������\n");

    msg = HIY "\n$N��Ȼ������һ������ �� ������˫����糵������������һ�����������ƿ�쭶������Ʋ��ɵ���\n"NOR;

	if( weapon = target->query_temp("weapon") ){
        if( random(me->query("str")) > (int)target->query("str")*3/4 ) {  
    msg += HIM"\n$pֻ���û���һ�ȣ����ƻ��ھ�ʹ������"
                + target->query_temp("weapon")->query("name") + "���ֶ�����\n" NOR;
		message_vision(msg, me, target);
		(target->query_temp("weapon"))->move(environment(target));
	} else {
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
		message_vision(msg, me, target);
	}
	me->start_busy(1);
        }
        else
        {
        if (random(me->query_skill("force",1)) > target->query_skill("force",1)/2 )
	{
		me->start_busy(3);
		target->start_busy(random(3));		
		damage = (int)me->query_skill("force");	
		damage = damage*4 + random(damage);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
		msg += HIR"\n���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;
		
	} else 
	{
		me->start_busy(1);
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
	}
	message_vision(msg, me, target);

        }
        me->add("neili", -600);
	return 1;
}
