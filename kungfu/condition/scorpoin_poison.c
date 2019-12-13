// scorpoin_poison.c
#include <ansi.h>
int update_condition(object me, int duration)
{
    if(me->query_temp("nopoison")) return 0;
    me->receive_wound("qi", 5);
    me->receive_damage("jing", 5);
    me->apply_condition("scorpoin_poison", duration - 1);
    if (! duration%2){
        tell_object(me, HIG "���е�Ы�������ˣ�\n" NOR );
    }
    me->set_temp("die_for","��Ы����");
    me->delete_temp("last_damage_from");
    if( duration < 1 ) return 0;
    return 1;
}
