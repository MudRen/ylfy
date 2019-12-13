
#include <ansi.h>
inherit F_CLEAN_UP;
int exert(object me, object target)
{
	int ap;
        int dp;
        int damage;
        string msg;

        if (target == me || ! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! me->is_fighting(target))
		return notify_fail("��ֻ���ú�������ս���еĶ��֡�\n");

    if (me->query_skill("lengyue-shengong", 1) < 150)
        return notify_fail("��������񹦻�򲻹����޷����ú�����\n");

	if ((int)me->query("neili") < 1000)
		return notify_fail("�����������!");

        msg = HIW "$N" HIW "Ĭ�������񹦣�һ�ɺ���ӭ������$n"
              HIW "�����ܵ�ʱѩ��ƮƮ��\n" NOR;

        ap = me->query_skill("force") + me->query("xyzx_sys/level") + me->query_skill("martial-cognize", 1);
        dp = target->query_skill("force") + target->query("xyzx_sys/level") + target->query_skill("martial-cognize", 1);

        me->start_busy(2);

        if (ap / 2 + random(ap) > random(dp))
        {
                damage = ap / 5 + random(ap / 3);
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage, me);
                if (target->query("neili") > damage)
                        target->add("neili", damage);
                else
                        target->set("neili", 0);

                msg += HIG "$n" HIG "��Ȼ����һ��͸�Ǻ��⣬��ʱ������ѪҺ������Ҫ�����ˡ�\n" NOR;
                target->start_busy(1);
        } else
                msg += HIY "$n" HIY "�е�һ�������ĵ׷�����æ�˶��ֿ����������¡�\n" NOR;

        message_vision(msg, me, target);

	return 1;
}
