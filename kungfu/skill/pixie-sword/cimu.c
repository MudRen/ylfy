 // cimu.c  ��а��������Ŀ��

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("����Ŀ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if ((int)me->query_skill("pixie-sword", 1) < 300 )
        return notify_fail("���а����������죬ʹ��������Ŀ����\n");
    if ((int)me->query("max_neili")<400)
        return notify_fail("��������Ϊ���㣬�޷�����������\n");
    if( (int)me->query_temp("pixie/cimu") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");
        if ((int)me->query("neili")<200)
    {
        return notify_fail("����������������û�ܽ�����Ŀ��ʹ�꣡\n");
    }
	if ( (string)me->query("gender") != "����" )
		return notify_fail("�������֮�����㣬�޷�ʹ����а������\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
       msg = RED "$N������ָ��£���ֱ۱�����Ѹ���쳣�ִ�$n˫Ŀ��\n"NOR;
    else
       msg = RED "$N���г���һ�񣬽���һ�㱩�����ִ�$n����˫Ŀ��\n"NOR;
    if (random(me->query_skill("sword")) > target->query_skill("dodge")/2) 
       //random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
    {
        me->start_busy(5);
        damage = (int)me->query_skill("pixie-sword", 1) + (int)me->query_skill("sword", 1)/2;
        damage = damage/2 + random(damage);
        target->receive_damage("qi", damage);
        target->receive_wound("qi", damage/2);
        msg += WHT"$nֻ��������һ�㣬˫Ŀһ���ʹ����ǰһ�ڣ���ʲôҲ������
�ˣ���ʱ����ʹ��������\n"NOR;
message_vision(msg, me, target);	
        COMBAT_D->report_status(target);
       //target->start_busy(me->query_skill("pixie-sword",1)/50+2);
        me->add("neili", -damage/5);
        me->set_temp("pixie/cimu", 1);
        target->set_temp("block_msg/all",1);
        call_out("cimu_end", (int) 3+random(me->query_skill("pixie-sword",1)/50), me);
    } else
    {
        me->start_busy(3);
        msg += "$n�鼱������̧��Ҳ��$N���۴�ȥ���ȵ�$N�ؽ�Ծ����\n"NOR;
message_vision(msg, me, target);	
    }
    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}

void cimu_end(object me)
{	object target;
	target = offensive_target(me);
	if (!target) me->delete_temp("pixie/cimu");
	else {
        //target->enable_player();
		target->delete_temp("block_msg/all");
message_vision("$NĨ��Ĩ����"HIR"��Ѫ"NOR"�������ܿ����ˡ�\n", target);	
        me->delete_temp("pixie/cimu");
}
        return;
}

