// recover.c
//inherit SSERVER;
int exert(object me, object target)
{
    int n, q;
    if (me != target)
        return notify_fail("你只能用内功恢复自己的精力。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够。\n");
    q = (int)me->query("max_jingli") - (int)me->query("jingli");
    if (q < 10)
        return notify_fail("你现在精力充沛。\n");
if(!me->query_skill("force"))
return notify_fail("你尚未学过内功心法。\n");   	
    n = 100 * q / me->query_skill("force");
    n = 100 * n / me->query_con();
    if (n < 20)
        n = 20;
    if ((int)me->query("neili") < n) {
        q = q * (int)me->query("neili") / n;
        n = (int)me->query("neili");
    }
    me->add("neili",-n);
    me->add("jingli", q);
    if(me->query("jingli")<me->query("max_jingli"))
    me->set("jingli",me->query("max_jingli"));
    
        message_vision("$N深深吸了几口气，感觉到又充满了活力。\n", me);
        if( me->is_fighting() ) me->start_busy(2);
        me->improve_skill("force", random(me->query_skill("force", 1)),0);
    return 1;
}
