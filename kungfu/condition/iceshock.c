// iceshock.c
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
    me->receive_damage("qi", 25);
    me->receive_wound("jing", 25);
    me->apply_condition("iceshock", duration - 1);
    tell_object(me, HIB "���е��⺮�ƶ������ˣ�\n" NOR );
    me->set_temp("die_for","���⺮�ƶ�");
    me->delete_temp("last_damage_from");
    if( duration < 1 ) return 0;
    return CND_CONTINUE;
}
