#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me)
{
    string msg;
    object weapon2, target;
    int skill, ap, dp, damage;
    me->clean_up_enemy();
    target = me->select_opponent();
    skill = me->query_skill("tianxin-blade",1); 
    if( !(me->is_fighting() ))
        return notify_fail("�����������־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if (!objectp(weapon2 = target->query_temp("weapon")))
       return notify_fail("�Է�û�б��У��㲻�õ��ġ�\n");

    if (me->query_temp("perform"))
    message_vision(HIR"$N����ɢ������������Ȼ����һֻ�������޵ľ��֣����ץ��$n���б��� һһ����������\n"NOR, me, target);
 
    damage = 10 * me->query_skill("blade")+ me->query_skill("force");
    ap = skill+me->query_skill("blade");
    dp = target->query_skill("unarmed");
    if( dp < 1 )
        dp = 1;
    if( random(ap) > dp )
    {
        if(userp(me))
            me->add("neili",-50);
        msg = "$nһ������æ�����ȥ����������һ��";
        msg += weapon2->name();
        msg += "�����ַɳ���\n" NOR;
        target->receive_damage("qi", damage);
        target->start_busy(2);
        weapon2->move(environment(me));
        }
    else
    {
        if(userp(me))
            me->add("neili",-30);
        msg = "�����������������������춱�ס�˱������֣�����������ս��\n"NOR;
    }
      message_vision(msg, me, target);
    return 1;
}
