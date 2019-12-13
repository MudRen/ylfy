#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill;
        object weapon;
        
        if( me->query("neili")<600 )
                return notify_fail("�������������\n");

        if ((int)me->query_skill("badao", 1) < 500)
                return notify_fail("��İԵ���Ϊ������\n");

        if (me->query_skill_mapped("blade") != "badao")
                return notify_fail("�㻹û�м����Ե��ء�\n");
                
        if( me->query_temp("badao-dasha") )
                return notify_fail("���Ѿ�ʩչ��ɷ�ˡ�\n");
                
        if( !objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "blade" )
                return notify_fail("��ʹ�õ��������ԣ�\n");
                
        skill = me->query_skill("badao");
        me->add("neili", -500);

        message_vision(HIY "$N�Ӷ�������" + weapon->name() + HIY "��һ��ǿ����������ȫ��ӿ��" + weapon->name() + 
                        HIY "����ʱ���������磬ɱ�����ڡ�\n" NOR, me);

        me->add_temp("apply/damage", skill);
        me->set_temp("badao-dasha", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), 600);

        if (me->is_fighting()) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
	if (!me) return;
        if( me->query_temp("badao-dasha") )
        {
                me->add_temp("apply/damage", -amount);
                me->delete_temp("badao-dasha");
                tell_object(me, "��İԵ�������ϣ��������ջص��\n");
        }
}