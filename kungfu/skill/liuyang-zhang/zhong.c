// zhong.c ��������
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
		int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() )
        return notify_fail("������ֻ�����ڶ������ϡ�\n");
    if( (int)me->query_skill("bahuang-gong", 1) < 450 )
        return notify_fail("��İ˻����Ϲ�������죬��������������\n");
    if( (int)me->query_skill("liuyang-zhang", 1) < 450 )
        return notify_fail("�����ɽ�����Ʋ�����죬��������������\n");
    if (!objectp(obj=present("jiudai", me)))
            return notify_fail("������û�оƴ������ܻ�ˮΪ����\n");
	if( (int)me->query("neili") < 100 ) return notify_fail("�������������\n");
    msg = CYN "$N��ˮΪ�����������У���ƮƮ������$n��\n";
	damage = me->query_skill("bahuang-gong", 1)+me->query_skill("liuyang-zhang", 1);
	me->fight_ob(target);
    target->kill_ob(me);
    if( random(damage) > random(target->query_skill("dodge") ) ) {
        msg += CYN " ���$p��$P���˸����ţ�\n" NOR;
        target->receive_damage("qi",damage+random(damage),me);
        target->receive_wound("qi",damage,me);
        target->receive_wound("jing", damage/10, me);
		target->receive_wound("jing", damage/8, me);
        target->apply_condition("ss_poison", random(me->query_skill("liuyang-zhang",1)/10) + 1 +
        target->query_condition("ss_poison"));
        me->start_busy(random(4));
    } else {
        msg += "����$p��æ����һ�ԣ����˿�ȥ��\n" NOR;
        me->start_busy(4);
    }
	me->add("neili", - 300);
    message_vision(msg, me, target);
    target->start_busy(1 + random(2));
    destruct(obj);
    return 1;
}
