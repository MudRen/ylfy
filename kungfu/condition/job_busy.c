// xx_task.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        if (duration <= 1) return 0;
           
        me->apply_condition("job_busy", duration - 1);
        return 1;
}
