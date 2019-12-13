// heal.c
#include <ansi.h>
int heal_target(object me,object target)
{
    string force_skill=me->query_skill_mapped("force");
    if( !target->is_character() || target->is_corpse() )
        return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

    if (!stringp(force_skill)) return notify_fail("����ѧ���ڹ���û������ܡ�\n");
    if( me->is_fighting() || target->is_fighting())
        return notify_fail("ս�����޷����˹�������\n");
    if( (int)me->query("max_neili") < 300 )
        return notify_fail("���������Ϊ������\n");
    if( (int)me->query("neili") < 150 )
        return notify_fail("�������������\n");
if( (int)target->query("eff_qi") == (int)target->query("max_qi") )	
return notify_fail(target->name()+"���ں����ѣ�����Ҫ��Ϊ"+(target->query("gender")=="Ů��"?"��":"��")+"���˹�������\n");	
    if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
        return notify_fail( target->name() +
            "�Ѿ����˹��أ����ܲ�����������𵴣�\n");
    if( living(target)  )
        return notify_fail(target->name()+"���ں����ѣ�����Ҫ��Ϊ"+(target->query("gender")=="Ů��"?"��":"��")+"���˹�������\n");
    message_vision( HIY "$N�������������ڹ���������һ�����������$n���죬�����ؽ���������$n����....\n\n"
        "���˲��ã�$N��ͷ��ð������ĺ��飬$n������³�һ��������ɫ������������ˡ�\n" NOR,
        me, target );
    target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
    target->add("qi", 10 + (int)me->query_skill("force")/3 );
    if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));
    me->add("neili", -150);
    me->start_busy(5);
    target->start_busy(5);
    me->improve_skill(force_skill, random(me->query_skill(force_skill, 1)/3),0);
    return 1;
}
int exert(object me, object target)
{
    if( !target ||  target == me)
        return notify_fail("���ܸ��Լ�������\n");
    else
        return heal_target(me,target);
}