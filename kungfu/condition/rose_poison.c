// rose_poison.c
#include <ansi.h>
int update_condition(object me, int duration)
{
    me->receive_wound("jing", 20);
    me->receive_damage("qi", 10);
    me->apply_condition("rose_poison", duration - 1);
    tell_object(me, HIG "���е�" HIR "��õ�嶾" HIG "�����ˣ�\n" NOR );
    me->set_temp("die_for","�л�õ�嶾��");
    me->delete_temp("last_damage_from");
    if( duration < 1 ) return 0;
    return 1;
}
