#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "��ɫͻȻ���ף�����ס�ķ�����\n", environment(me), me);
   }
   else {
     tell_object(me, HIM "������Ŀ�һ����ʹ�����еĴ����ƶ������ˣ�\n" NOR );
      message("vision", me->name() + "��ɫͻȻ���ף�����ס�ķ�����\n",
            environment(me), me);
   }
      me->receive_wound("qi",10 + random(40));
      me->receive_wound("jing", 250);
      me->apply_condition("cuixin_poison", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

