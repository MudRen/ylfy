#include <ansi.h>
#include <combat.h>

string name() { return HIY "��ʱ������" NOR; }

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "blade" )
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" + name() + "��\n");

        if ((int)me->query_skill("force") < 160)
                return notify_fail("����ڹ���򲻹�������ʩչ" + name() + "��\n");

        if ((int)me->query_skill("moon-blade", 1) < 120)
                return notify_fail("���Բ���䵶�������ң�����ʩչ" + name() + "��\n");

        if (me->query_skill_mapped("blade") != "moon-blade")
                return notify_fail("��û�м���Բ���䵶������ʩչ" + name() + "��\n");

        if( me->query("neili")<200 )
                return notify_fail("�����������������ʩչ" + name() + "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "������գ�����˸���������ߵ���ÿ������$n" HIY "���ò�ȫ��Ӧ����\n"
              "ÿ��������ʵ��׾��ƫ���У����µ��յĸо���\n"
              "�ҵ��������$n" HIY "�����α仯�����ǰ�$n" HIY "��ͨ��͸һ�㣡\n" NOR;

        ap = me->query_skill("blade") + me->query_skill("force");
        dp = target->query_skill("parry") + target->query_skill("dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->damage_power("blade");
                damage+= me->query("jiali");
                damage *= 3;
                me->add("neili", -150);
				target->receive_damage("qi", damage, me );
		        target->receive_wound("qi", damage/2 , me);	
                msg += HIR "��ʱһ�ɱ����ĵ����ӹ�ȫ��$n"HIR "ȫ���ʱ��Ѫ���죬ҡҡ������\n" NOR;
                me->start_busy(2);
                if (ap / 2 + random(ap * 2) > dp && ! target->is_busy())
                        target->start_busy(ap / 80 + 3);
        } else
        {
                msg += CYN "$p" CYN "���һ����Ҳ���мܣ��������������ߣ��ܿ���$P" CYN "��һ�С�\n" NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_vision(msg, me, target);

        return 1;
}

