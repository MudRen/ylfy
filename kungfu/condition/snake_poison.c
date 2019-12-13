// snake_poison.c

int update_condition(object me, int duration)
{
    if(me->query_temp("nopoison")) return 0;
    me->receive_wound("qi", 20);
    me->receive_damage("jing", 10);
    me->apply_condition("snake_poison", duration - 1);
    if (! duration%5){
        tell_object(me, HIG "���е��߶������ˣ�\n" NOR );
    }
    me->set_temp("die_for","���߶���");
    me->delete_temp("last_damage_from");
    if( duration < 1 ) return 0;
    return 1;
}
