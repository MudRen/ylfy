// fuxue.c ������Ѩ�� ��������Ѩ��
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if((int)me->query_str() < 30)
                return notify_fail("���������,����ʹ����һ����!\n");
        if((int)me->query_skill("bibo-shengong",1) < 200)
                return notify_fail("��̲��񹦵Ĺ�����������ʹ��������Ѩ!\n");
        if((int)me->query_skill("unarmed") < 200)
                return notify_fail("���ȭ����Ϊ����,Ŀǰ������ʹ��������Ѩ����!\n");
        if((int)me->query("neili") < 500)
                return notify_fail("���������ڲ���, ����ʹ��������Ѩ! \n");
		if( !target ) return notify_fail("��Ҫ��˭ʩչ������Ѩ��\n");
        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
        msg = HIB "$N���ַ������������ָͷ��ת��һ��ʢ������������ӯ������$n��в��ҪѨ, ʹ$n�������á�\n";
        if( random(me->query("unarmed")) > (int)target->query("dodge") / 3 )
        {
                msg +=  HIB "���$p��$P������ţ���ʱ�����޴룬��������! \n" NOR;
                target->start_busy( (int)me->query_skill("lanhua-shou",1) / 20 + 2);
                me->add("neili", -100);
				me->fight_ob(target);
				target->kill_ob(me);
        }
        else
        {
                msg += HIY "����$p������$P����ͼ������һԾ�����˿�ȥ��\n" NOR;
                me->start_busy(4);
				me->fight_ob(target);
				target->kill_ob(me);
        }
        message_vision(msg, me, target);
        return 1;
}
