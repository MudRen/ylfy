// ailao.c ����ɽ����

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i, a;

        if (!target) target=offensive_target(me);

        if (!target || !target->is_character() || !me->is_fighting(target))
                return notify_fail("�㲻��ս���У�\n");

//      if (target->is_busy())
//              return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

           weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("�������޽������ʹ�ó�����ɽ���⣿\n");

        if (me->query_skill("kumu-shengong", 1)<300)
                return notify_fail("����ڹ����δ�����޷���Ԧ����ɽ���⣡\n");

        if (me->query_skill("sword", 1) < 1000)
                return notify_fail("�㽣����Ϊ�������޷�ʩչ����ɽ���⣡\n");

        if (me->query_skill("duanjia-sword",1)<300)
                return notify_fail("��μҽ���Ϊ�������޷�ʩչ����ɽ���⣡\n");

        if( me->query_skill_mapped("force") != "kumu-shengong")
                return notify_fail("�����õ��ڹ��밧��ɽ������·��㣣�\n");

        if( me->query("neili") <= 500 )
                return notify_fail("�����������ʹ�ð���ɽ���⣡\n");

        message_vision(HIR "\nͻȻ��$N����ͻ�䣬�����ݺᣬ����������������ǰ����������������������\n\n"NOR, me, target);
        message_vision(HIR "\n��������ʩչ����ɽ�����$n����ʵʵ��������ʮ������\n\n" NOR, me, target);     
		
        if (me->query("xyzx_sys/level")/12 < target->query("xyzx_sys/level")/10)
                a=3;
        else {
                if (me->query("xyzx_sys/level")/15 < target->query("xyzx_sys/level")/10)
                        a=4;
                else {
                        if (me->query("xyzx_sys/level")/18 < target->query("xyzx_sys/level")/10)
                                a=5;
                        else a=6;
                }
        }

        for (i=1; i<=a; i++)
                COMBAT_D->do_attack(me, target, weapon);
        if (a>4)
        {
                me->start_busy(a-random(3));
        } else
                me->start_busy(1);

        me->add("neili", -200);
        me->add("jing", -20);
        return 1;
}