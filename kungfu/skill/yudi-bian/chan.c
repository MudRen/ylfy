// chan.c ��ر� ���־�
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("���־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if( (int)me->query_skill("yudi-bian",1) < 150)
        return notify_fail("��ġ���رޡ�����̫ǳ��ʹ���ˡ������־���\n");
    if( target->is_busy() )
        return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ�������!\n");
    msg = HIB "$Nʹ����ر��еġ������־������ӳ�����ͼ��$n��ȫ���ס��\n";
    if( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3 ) {
        msg += "���$p��$P���˸����ֲ���!\n" NOR;
        target->start_busy( (int)me->query_skill("yudi-bian") / 30 + 1);
        me->start_busy(1+ random(1));
    } else {
        msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
        me->start_busy(3);
    }
    message_vision(msg, me, target);
    return 1;
}

