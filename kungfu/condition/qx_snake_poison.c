#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        me->apply_condition("qx_snake_poison", duration - 1);

    if (! duration%5){
    me->receive_wound("qi", 50);
    me->receive_damage("jing", 50);
        message_vision(BLU"$N�����巢������ɫ�����⣬��������ʹ����,Ť��ɹ�������.\n"NOR, this_player());
        tell_object(me, HIR "���е������߶������ˣ�\n" NOR );
    }
    me->set_temp("die_for","�������߶�");
    me->delete_temp("last_damage_from");
        if( duration < 1 ) return 0;
  return CND_CONTINUE;
}   
