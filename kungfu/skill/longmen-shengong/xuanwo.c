// made by lks

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{      
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�����о���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("force", 1) < 80 )
                return notify_fail("����ڹ�����̫��������ʹ�á�\n");
                                
        if( (int)me->query_skill("longmen-shengong", 1) < 80 )
                return notify_fail("��������񹦲���������\n");
                        
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("����������̫��������ʹ�á����о�����\n");
                        
        msg = HIC "$N���ᵤ�˫��������Ƴ�һ�ɴ������е�����������$n��\n"NOR;

            if (wizardp(me)) {
                  msg += WHT"$nֻ��������������������е������䣬ȫ�����Լ���\n"NOR;
                  target->start_busy( (int)me->query_skill("longmen-shengong") / 10 + 1);
					message_vision(msg, me, target);
                  return 1;
               }
        if (random(me->query_skill("force")) > random(target->query_skill("force")) )
        {
                
                damage = (int)me->query_skill("force");
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                me->add("neili", -200);
                msg += WHT"$nֻ��������������������е������䣬ȫ�����Լ���\n"NOR;
                me->start_busy(1);
        } else 
        {
                msg += YEL"����$p���Ա߲���һ��,���������еĹ�����Χ��\n"NOR;
                me->add("neili", -100);
                me->start_busy(4);
        }
        message_vision(msg, me, target );

        return 1;
}

