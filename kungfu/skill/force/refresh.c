// recover.c
//inherit SSERVER;
int exert(object me, object target)
{
    int n, q;
    if (me != target)
        return notify_fail("��ֻ�����ڹ��ָ��Լ��ľ�����\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("�������������\n");
    q = (int)me->query("max_jingli") - (int)me->query("jingli");
    if (q < 10)
        return notify_fail("�����ھ������档\n");
if(!me->query_skill("force"))
return notify_fail("����δѧ���ڹ��ķ���\n");   	
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
    
        message_vision("$N�������˼��������о����ֳ����˻�����\n", me);
        if( me->is_fighting() ) me->start_busy(2);
        me->improve_skill("force", random(me->query_skill("force", 1)),0);
    return 1;
}
