#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "脸色突然发白，浑身不住的发抖。\n", environment(me), me);
   }
   else {
     tell_object(me, HIM "你觉得心口一阵酸痛，你中的摧心掌毒发作了！\n" NOR );
      message("vision", me->name() + "脸色突然发白，浑身不住的发抖。\n",
            environment(me), me);
   }
      me->receive_wound("qi",10 + random(40));
      me->receive_wound("jing", 250);
      me->apply_condition("cuixin_poison", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

