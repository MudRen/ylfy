// tuwu.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
	string msg;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target|| !target->is_character()||	!me->is_fighting(target) )
		return notify_fail("��������ֻ����ս����ʹ�á�\n");

	if ( !objectp(weapon = me->query_temp("weapon")) || base_name(weapon) != "/d/jinshe/obj/jinshe-zhui" )
		return notify_fail("��û�ý���׶������ʹ�þ��У�\n");

	if( (int)me->query_skill("jinshe-zhui", 1) < 1500 )
		return notify_fail("��Ľ���׶��������죬����ʹ�ý�������\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("�����������ˡ�\n");

	if(target->query_temp("block_msg"))
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

	skill = me->query_skill("jinshe-zhui", 1);

	me->add("neili", -200);
	target->receive_damage("qi", (int)skill/ 3);

	if (random(me->query_skill("force")) > target->query_skill("force")/2|| random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/3 )
	{
		message_vision( HIY "ֻ��һ����ɨҶ��������У�$N���е�"YEL"����׶"HIY"������Ŀ�Ĺ�â����ҫ��$n��ð�𻨣���������������ǰһ���ص������⣬$nɶҲ�������ˣ�\n" NOR, me, target);
		COMBAT_D->do_attack(me, target,weapon, 0);
		target->set_temp("block_msg/all",1);
		call_out("tuwu_end", (int) skill/100, me, target);
		me->start_busy(2);
	}
	else
	{
		me->start_busy(2);
		msg = HIY"$p�鼱�������ý����ȿ���$P��������\n"NOR;
		message_vision(msg, me, target);
	}
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
void tuwu_end(object me, object target)
{
	if ( !objectp(target) ) return;
	//if ( environment(me) != environment(target) ) return;
	//target->enable_player();
	target->delete_temp("block_msg/all");
	message_vision("$NĨ��Ĩ������"HIR"��Ѫ"NOR"�������������ۡ�\n", target);
	tell_object(target, HIR"������Ĩ������������Ѫ����������Χ���龰��\n"NOR);
	return;
}
