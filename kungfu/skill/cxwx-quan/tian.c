// marry 99.9
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{        
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() )
                return notify_fail("������תֻ�����ڶ������ϡ�\n");

        if( (int)me->query_skill("cxwx-quan", 1) < 200 )
                return notify_fail("��ĳ�������ȭ��������죬����ʹ����������ת��\n");
        if( me->query("family/family_name") != "����������" )
                return notify_fail("�㲻�ǳ��������ŵ��ˣ�����ʹ����������ת��\n");

        if( (int)me->query_skill("wangran-xinfa", 1) < 200 )
                return notify_fail("�����Ȼ�ķ�������죬����ʹ����������ת��\n");

        msg = HIR "$Nȭ�м���һ��"HIY"���"HIR"��һ�С�"HIB"������ת"HIR"����������$n��\n"NOR;

        me->start_busy(1);
        if( random( (int)me->query_skill("cxwx-quan",1)) > random(target->query_skill("dodge",1) ) ) {
                msg +=  HIW" ���$p��$P���˸����ţ�\n" NOR;
                target->receive_damage("qi",(int)me->query_skill("unarmed"));
                target->receive_wound("qi",20 + random(10));
                target->receive_wound("jing", random(50)+20);
                target->apply_condition("tian", random(me->query_skill("cxwx-quan",1)/10) + 1 + target->query_condition("tian"));
                me->start_busy(1 + random(2));
        } else 
       {
                msg += MAG "����$p�ۼ��������Ķ��˿�ȥ��\n" NOR;
                me->start_busy(3);
        }
        message_vision(msg, me, target);
        return 1;
}
