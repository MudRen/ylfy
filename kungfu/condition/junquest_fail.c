// junquest_fail
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{      
        if( duration < 1 ) return 0;
        me->apply_condition("junquest_fail", duration - 1); 

        if( duration == 2)
        {
          tell_object(me,HIR"��͢�����ȥ����ؾ�ʦ��ּ�ɣ�����\n"NOR);
        }
        return CND_CONTINUE;      
}

