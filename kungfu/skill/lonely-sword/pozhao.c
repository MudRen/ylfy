// tuwu.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
	int damage;
	string msg;
	object weapon;
	 if( !target ) target = offensive_target(me);


	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_skill("lonely-sword", 1) < 540 )
		return notify_fail("��Ķ��¾Ž�������죬����ʹ���������С�\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("�����������ˡ�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

	if(target->query_temp("block_msg"))
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

	skill = me->query_skill("lonely-sword", 1);

	me->add("neili", -200);
	target->receive_damage("qi", (int)skill/ 3);
	message_vision(HIC "$N���ּ�����$n����,һ��ֻ�¾�ȫ�Ǵ���$n�书�����㣬$n����һ��.....���ɵķ����Ĺֽ�����\n"NOR,me,target);	
    if (random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
    {
		message_vision(	HIR "$N���еĽ������������Ľ���,һ��һ���Ľ�����$n��ȥ$n����һ�ڣ�$nɶҲ�������ˣ�\n" NOR, me, target);
		target->start_busy(1);
	    target->set_temp("block_msg/all",1);
	    damage = (int)me->query_skill("lonely-sword", 1);
	    damage = damage + random(damage);
	    target->receive_damage("qi", damage);
	    call_out("tuwu_end", (int) skill/30, me, target);
        me->start_busy(2);
    }
	else
		{
        me->start_busy(2);
        msg = HIY"$p�鼱���������һ��...�ӳ��˽����ķ�Χ��\n"NOR;
		message_vision(msg, me, target);
		}
		if(!target->is_fighting(me)) target->fight_ob(me);
		return 1;
}

void tuwu_end(object me, object target)
{
	if ( !target ) return;
	target->enable_player();
    message_vision("$NĨ��Ĩ������"HIR"��Ѫ"NOR"�������������ۡ�\n", target);	
	target->set_temp("block_msg/all", 0);
	tell_object(target, HIR"������Ĩ������������Ѫ����������Χ���龰��\n"NOR);
	return;
}
