
#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) 
                {
                tell_object(me, HIY "��Ķ���̫��,����ȡ���ˡ�\n" NOR);
        me->delete("do_job");
        return 0;
                }
        if (!duration) return 0;
        me->apply_condition("job_mission", duration - 1);
        return 1;
}

string query_type(object me)
{
        return "job";
}

