#include <login.h>
int update_condition(object me, int duration)
{
        if (duration < 1) return 0;
        me->apply_condition("rob_task", duration - 1);
        return 1;
}
string query_type(object me)
{
       return "job";
}
