
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
    if( duration < 1 ) return 0;
    if( !living(me) ) {
        message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
    }else {
        tell_object(me, HIB "��Ȼһ��̹ǵ��溮Ϯ�������е������ƶ������ˣ�\n" NOR );
        message("vision", me->name() + "������ͻȻ�������Σ����ظ�������������\n",environment(me), me);
    }
    me->receive_wound("qi",15 + random(10));
    me->receive_wound("jing", 10);
    me->apply_condition("xx_poison", duration - 1);
   /* if ( (int)me->query_temp("powerup") ) {
        me->delete_temp("apply/attack");
        me->delete_temp("apply/dodge");
        me->delete_temp("powerup");
    }*/
    me->set_temp("die_for","�������ƶ�");
    me->delete_temp("last_damage_from");
    if( duration < 1 ) return 0;
    return CND_CONTINUE;
}
