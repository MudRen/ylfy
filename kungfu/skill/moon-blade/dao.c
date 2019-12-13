// This program is a part of NT MudLIB

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIW "�����ϣ����ϵ�" NOR; }

int perform(object me)
{
        string msg;
        object weapon, target;
        int ap, dp, count;
        int i, damage;

/*
        if( query("family/family_name", me) != "ħ��" &&
            query("reborn/family_name", me) != "ħ��" )
                return notify_fail("�㲻��ħ�̵��ӣ��޷�ʹ��" + name() + "��\n");

        if( !me->query("reborn/times") )
                return notify_fail("����δת���������޷�ʹ��" + name() + "��\n");
*/
        if (! target) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->is_busy() )
                return notify_fail("������æ���ء�\n");

        if( !objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "blade" )
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" + name() + "��\n");

        if ((int)me->query_skill("moon-blade", 1) < 1000)
                return notify_fail("��Բ���䵶��򲻹�������ʩչ" + name() + "��\n");

        if (me->query_skill_mapped("blade") != "moon-blade")
                return notify_fail("��û�м���Բ���䵶������ʩչ" + name() + "��\n");

        if ((int)me->query_skill("force") < 1200)
                return notify_fail("����ڹ���Ϊ����������ʩչ" + name() + "��\n");

        if( me->query("max_neili")<10000 )
                return notify_fail("���������Ϊ����������ʩչ" + name() + "��\n");

        if( me->query("neili")<1000 )
                return notify_fail("�����ڵ��������㣬����ʩչ" + name() + "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("blade");
        dp = target->query_skill("force");

        if( objectp(weapon = weapon->query_temp("weapon")) )
        {
                msg = HBYEL "$N" HBYEL "˫�ֳֵ���һԾ���𣬾��˵�������һ�������Ļ��ߣ�һ�ɵ���"
                      HBYEL "��һ������Ϯ��$n��\n" NOR;

                if (ap / 2 + random(ap) > dp)
                {
                        me->add("neili", -500);
                        msg += HIR "$n" HIR "���в��ã���æ�������б����ֵ���ȴ���뻢�ھ�ʹ������" + weapon->name() +
                               HIR "��ס�����ֶ�����\n" NOR;

                        weapon->move(environment(me));
                } else
                {
                        me->add("neili", -500);
                        msg += CYN "$n" CYN "����ʮ�ɹ�����ͷ����������������" + weapon->name() +
                               CYN "Ӳ�ǽ�$N" CYN "�ľ����ֵ������ˡ�\n" NOR;
                }
                message_vision(msg, me, target);
        }

        msg = HBBLU "��ʱ��$N" HBBLU "�����Ʈ������֪��ʱ������$n����ǰ��һ��" HIY "�������ϡ�\n" NOR +
              HBBLU "�����������ϻ���һ���������µ���������$n����Ҫ��$nһ������" HBBLU "��\n"NOR;


        dp = target->query_skill("dodge");
        damage = me->query_skill("blade");

        if (ap / 2 + random(ap * 2) > dp)
        {
                damage+= me->query("jiali");
                damage = damage * 6;
                target->receive_damage("jing", damage / 8);
                target->receive_wound("jing", damage / 10);
                msg +=  HIR "$n" HIR "ֻ���������ȣ�һ�ɾ�����������������������ܣ���$N�ľ���Ϯ��ȫ������Ѩ��Ѫ�����ڣ�Ѫ����������\n" NOR;
                target->set_weak(5);
                me->add("neili", -400);
        } else
        {
                msg += CYN "$n" CYN "�ۼ�$N" CYN "������ӿ��˿������С���æ������һ�ԡ�\n" NOR;
                me->add("neili", -200);
        }

        message_vision(msg, me, target);

        msg = HBMAG "������$N" HBMAG "Ծ����У���һɱ��" HIB "�����ϵ���" NOR +
                   HBMAG "���е����裬һ˲������ж�������������£�һ����$n" HBMAG "��ȥ��\n" NOR;

        dp = target->query_skill("parry");

        if (ap / 2 + random(ap * 2) > dp)
        {
                msg += HIR "$n" HIR "���$N" HIR "����ɽ������Ĺ��ƣ���ȫ�޷��ֵ����м�ɢ�ң������˺�\n" NOR;
                count = ap / 10;
        } else
        {
                msg += HIC "$n" HIC "�ĵ�΢΢һ������֪�����æ�������񣬽߾����ܻ���$N" HIC "����������\n" NOR;
                count = 0;
        }

        message_vision(msg, me, target);

        me->add_temp("apply/attack", count);
        me->add_temp("apply/damage", count/2);

        for (i = 0; i < 12; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (! target->is_busy())
                        target->start_busy(3);

                COMBAT_D->do_attack(me, target, weapon, 120);
        }
        me->add("neili", -500);
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -count/2);

        me->start_busy(1 + random(4));

        return 1;
}
