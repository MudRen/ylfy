// junquest_fail
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{      
        if( duration < 1 ) return 0;
        me->apply_condition("can_yanjiu", duration - 1); 
        return CND_CONTINUE;      
}

