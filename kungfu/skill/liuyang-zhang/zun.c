// This program is a part of NT MudLIB

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIY"�˻Ķ�����"NOR; }

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int damage;
        int lvl;

        if( me->is_busy() )
                return notify_fail("����æ���ء�\n");

        if( !target )
        {
            me->clean_up_enemy();
            target = me->select_opponent();
        }

        if( objectp(me->query_temp("weapon")) )
                return notify_fail(name()+"ֻ�ܿ��ֲ���ʩչ��\n");

        if( !me->is_fighting(target) )
                return notify_fail(name()+"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !target || !target->is_character() )
                return notify_fail("��Ҫ��˭ʩչ"+name()+"��\n");

        if( !living(target) )
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        if( me->query_skill_mapped("unarmed") != "liuyang-zhang" )
                return notify_fail("�㻹û������ɽ�����ƣ��޷�ʩչ"+name()+"��\n");

        if( (int)me->query_skill("bahuang-gong") < 1000 )
                return notify_fail("��˻�����Ψ�Ҷ�����Ϊ����������ʩչ" + name() + "��\n");

        if( lvl = me->query_skill("liuyang-zhang", 1) < 1000 )
                return notify_fail("�����ɽ�����ƻ�򲻹����޷�ʩչ"+name()+"��\n");

        if( me->query("neili") < 2500 )
                return notify_fail("������������������޷�ʩչ"+name()+"��\n");

        msg = HIY "����$N" HIY "����ƮƮ�������裬��Ŀ����Ĭ���������������������ھ������ڣ�\n"
              HIY "����ϼ������˫�Ƶķ�������������Ȼ$N" HIY "�㲽ǰ�ƣ�˫���ƿջ�����Ю��˿˿���⣬ֱ��$n" HIY "˫���ȥ��\n" NOR;

        msg += HIR "$n" HIR "ֻ���ؿ�һ�ƣ�һ˿����ֱ��θ�������һƬ�հ�ãȻ��֪���룡\n" NOR;

        // ��һ��
        ap = me->query_skill("unarmed") + me->query_skill("dodge");
        dp = target->query_skill("force") + target->query_skill("dodge");
        damage = me->query_skill("unarmed");
        damage += me->query_skill("force");
        damage *= me->query("con");

        if (ap / 2 + random(ap) > dp)
        {
            target->receive_damage("qi", damage, me);
            target->receive_wound("qi", damage/2, me);  
			
         msg += HIR "$n" HIR "��Ȼ���ѣ����´󺧣�������̧���࿹�����ϵ�$N"
                HIR "����֬��ѩ��˫�ƾ�Ȼ�̺�ǧ��������"
                HIR "һ��֮�¶����Լ�˫��������ɢ�����޵ֵ�֮�������ʵʵ�����´��С�\n" NOR;

        } else
        {
                msg += CYN "$p" CYN "�ۼ�$P" CYN "������ӿ���鼱֮������˫�ۣ�����ֿ�����Ȼδռ�·硣\n" NOR;
        }
		
        message_vision(msg, me, target );

        msg = HIY "$N" HIY "һ��δ�ϣ�˲��������裬���ŷ����Ƴ�һ�ƣ���������Ŀ�ģ��ǻ���Ű׺��������ھ�ȷ����ӿһ�㱼��$n"HIY"��ǰ��\n" NOR;
        // �ڶ���
        ap = me->query_skill("unarmed") + me->query_skill("force");
        dp = target->query_skill("dodge") + target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
            target->receive_damage("qi", damage, me);
            target->receive_wound("qi", damage/2, me);
			
                  msg += HIR "���ƾ��������죬ȴ�ֱ��޿ɱܣ���$n" HIR "�ؿ�͸�����,ֱ���$n��Ǵ��ѡ�\n"
                         HIR "$n" HIR "ֻ��������ǧ���������룬����һ��ӿ��һ��Ѫ��ӿ����缤������\n" NOR;

        } else
        {
                msg += CYN "ֻ��$p" CYN "����׼������һ�����������ӵ���ԴԴ���Ϲ�����ǻ��ס������Ӳ�������ƣ���Ҳ�����󰭡�\n" NOR;
        }

        message_vision(msg, me, target );

        // ������
        msg = HIY "$N" HIY "����һԾ����Ȼ�ڿ����ɣ�����һ����߳���Ѹ���Ʈҡ���£�������Ӱ�����һ��޴��ѩ������$n" HIY "ͷ��ѹ�¡�\n" NOR;

        ap = me->query_skill("force",1) + me->query_skill("dodge",1);
        dp = target->query_skill("parry",1) + target->query_skill("dodge",1);

        if (ap / 2 + random(ap) > dp)
        {
                if( !target->is_busy() )
                        target->start_busy(5);
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/2, me);  
			
                 msg += HIR "ֻ����һ�����죬һ���ۻ���ƾ�����$n" HIR "����ը����˳��й��$n" HIR "����\n"
                        HIR "$n" HIR "­��һ����ʹ��ȫ�������������һ����̱���ڵأ��������á�\n" NOR;

        } else
        {
                msg += CYN "$p" CYN "������������ӿ�����óȻ�мܡ������Ʋ���һ���鶯����Ȼ��ǧ��һ��֮�ʳ��������\n" NOR;
        }


        me->add("neili", -1500);
        me->start_busy(2+random(2));
        message_vision(msg, me, target );

        return 1;
}
