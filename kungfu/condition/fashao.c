//偶感风寒，发烧
//modified by wind
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
   }
   else {
      if(random(2)==0)
              tell_object(me, HIB "忽然一阵燥热，你竟然脸都红透了\n" NOR );
      else
              tell_object(me, HIB "忽然一阵奇冷，你感觉如同身入冰窖，冷得直发抖。\n" NOR );
      message("vision", me->name() + "的身子突然颤了两颤，脸上一阵红一阵白，牙关咬得格格直响。\n",
            environment(me), me);
   }
      me->receive_wound("qi",20);
      me->receive_wound("jing", 9);
      if(me->query("neili")>30)
              me->add("neili",-30);
      else
              me->set("neili",0);
      me->apply_condition("fashao", duration - 1);
      if ( (int)me->query_temp("powerup") ) 
         { me->add_temp("apply/attack", - (int)(me->query_skill("force")/3));
             me->add_temp("apply/dodge", - (int)(me->query_skill("force")/3));
             me->delete_temp("powerup");  }

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}