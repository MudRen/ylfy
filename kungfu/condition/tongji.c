#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{                                  
        if (duration < 1)
        {
                tell_object(me,HIW"������������ͨ�����ˣ�\n"NOR);
                return 0;
        }

        me->apply_condition("tongji", duration - 1);
        return CND_CONTINUE;
}            

