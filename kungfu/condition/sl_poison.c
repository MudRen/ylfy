// sl_poison.c
//������������֮��
// ����lywin 2000/6/17


#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "ͻȻ�����ȫ��һ���ӷ�����ԭ�����еĻ�������֮��������������\n" NOR );
      message("vision", me->name() + "������ͻȻһ������\n",
            environment(me), me);
   }
      me->receive_wound("qi",12 + random(10));
      me->receive_wound("jing", 5);
      me->apply_condition("sl_poison", duration - 1);
      if ( (int)me->query_temp("powerup") ) 
         { me->add_temp("apply/attack", - (int)(me->query_skill("force")/3));
	     me->add_temp("apply/dodge", - (int)(me->query_skill("force")/3));
	     me->delete_temp("powerup");  }

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
