// zu.c  by sinb

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("��ֻ����ڤ���񹦻ָ��Լ�����Ѫ��\n");

        if ((int)me->query("neili") < 1000)
                return notify_fail("�������������");

        if ((int)me->query_skill("mingyu-shengong", 1) < 160)
                return notify_fail("���ڤ���񹦵ȼ�������\n");
        if ((int)me->query_temp("qizu"))
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("mingyu-shengong");

        me->add("neili", -100);

        message_vision(HIC "$N" HIC "�������㡹�湦����������һƬ��â���漴�ָ�����\n" NOR, me);

        me->set_temp("qizu", 1);

        me->apply_condition("mingyu_qizu", skill / 80);
        if (me->is_fighting()) me->start_busy(3);

        return 1;
}

