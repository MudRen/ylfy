// yufeng_poison.c 玉蜂针毒
// By Kayin @ CuteRabbit Studio 1999/3/23 new

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
      tell_object(me, HIR "忽然一阵彻骨的麻痒，你中的玉峰针发作了！\n" NOR );
      message("vision", me->name() + "突然卷缩在地上伸手在身上到处乱抓。\n",
            environment(me), me);
   }
      me->receive_wound("qi",25 + random(10));
      me->receive_wound("jing", 10);
      me->apply_condition("yufeng_poison", duration - 1);
      /*if ( (int)me->query_temp("powerup") ) 
         { me->add_temp("apply/attack", - (int)(me->query_skill("force")/3));
	     me->add_temp("apply/dodge", - (int)(me->query_skill("force")/3));
	     me->delete_temp("powerup");  }*/

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
