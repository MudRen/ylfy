// regenerate.c
//inherit SSERVER;
int exert(object me, object target)
{
    int n, q;
    if (target != me) 
        return notify_fail("��ֻ�����ڹ��ָ��Լ��ľ�����\n");
    
    q = (int)me->query("eff_jing") - (int)me->query("jing");
    if (q < 10)
        return notify_fail("�����ھ������档\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("�������������\n");
if(!me->query_skill("force"))
return notify_fail("����δѧ���ڹ��ķ���\n");   	
    n = 100 * q / me->query_skill("force");
    n = 30 * n / me->query_con();
    if (n < 20)
        n = 20;
    if ((int)me->query("neili") < n) {
        q = q * (int)me->query("neili") / n;
        n = (int)me->query("neili");
    }
    me->add("neili", -n);
    me->receive_heal("jing", q);
    
        message_vision(HIG"$N�������˼����������������ö��ˡ�\n"NOR, me);
        if( me->is_fighting() ) me->start_busy(1);
        me->improve_skill("force", random(me->query_skill("force", 1)),0);
    return 1;
}
