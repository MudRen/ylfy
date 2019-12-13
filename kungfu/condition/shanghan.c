//modified by wind
//伤寒
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
      tell_object(me, HIB "忽然一阵天旋地转，你的伤寒病又发作了。\n" NOR );
      message("vision", me->name() + "的身子突然晃了两晃，牙关格格地响了起来。\n",
            environment(me), me);
   }
      me->receive_wound("qi",10);
      me->receive_wound("jing", random(10));
      me->apply_condition("shanghan", duration - 1);
      if ( (int)me->query_temp("powerup") ) 
         { me->add_temp("apply/attack", - (int)(me->query_skill("force")/3));
             me->add_temp("apply/dodge", - (int)(me->query_skill("force")/3));
             me->delete_temp("powerup");  }

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
