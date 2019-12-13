#include <ansi.h>
 
inherit F_CLEAN_UP;
//inherit F_SSERVER;
 
int exert(object me)
{
        string msg;
        object weapon2, target;
        int skill, ap, dp, damage;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("wudie-xinjing",1);

        if( !(me->is_fighting() ))
            return notify_fail("������Ͻ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon2 = target->query_temp("weapon")) )
            return notify_fail("�Է�û��ʹ���κ����������ò��ˡ�����ľ�����\n");

        if( skill < 300)
                return notify_fail("��ġ�����ľ����ȼ�����, ����ʹ�á�����Ͻ𡹣�\n");

        if( me->query("neili") < 250 )
                return notify_fail("��������������޷����á��ὣʽ����\n");

        msg = HIY "$N΢һ������������ľ���֮������Ͻ𡹣�һ���������$n��\n";
        message_vision(msg, me, target);
 
        damage = 1000 + random(skill * 2);
        ap = me->query_skill("sword",1) + skill;
        dp = target->query_skill("dodge",1);
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp )
        {
                if(userp(me))
                        me->add("neili",-10);
                msg = HIR"$n��ʱ������ǰһ�������������"NOR;
                msg += weapon2->name();
                msg += HIR"�Ѿ��ϳ����ڣ�\n" NOR;

                target->receive_damage("qi", damage);
                target->start_busy(2);
                weapon2->set("name","�ϵ���" + weapon2->query("name"));
                weapon2->set("id","trash " + weapon2->query("id"));
                weapon2->set("hit_trash",1);
                weapon2->move(environment(me));
        }
        else
        {
                if(userp(me))
                        me->add("neili",-10);
                msg = "����$n������$N�Ľ�·�����̽�����" + weapon2->name() + "��÷��겻͸��ʹ$N�ġ�����Ͻ�û�������á�\n"NOR;
                      }
        message_vision(msg, me, target);

        return 1;
}
