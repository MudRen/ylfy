//hongtianza.c ��������֮�������ҡ�
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg,*limbs;
	int i,size,damage;
	object my_w,target_w;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�������ҡ�ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "axe")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	
	if( (int)me->query_skill("duanyun-fu",1) < 50)
		return notify_fail("��Ŀǰ������ʹ�����������ҡ���\n");
	if( (int)me->query("neili") < 100 )
		return notify_fail("�������������\n");
	msg = CYN"$NͻȻ����һ���������ң����ң��������ң��������о޸���Ȼ����$p���б��У�\n"NOR;
	me->start_busy(3);

	if (target->query_temp("weapon") || target->query_temp("secondary_weapon"))
	{
		my_w = me->query_temp("weapon");
		target_w = target->query_temp("weapon");
		if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/3 )
		{
			if (target->query_temp("weapon") )
			{
				msg += "���$p���е�"+target_w->query("name")+"��$P�ĺ������Ҹ����ţ���Ҳ���ղ�?ס���������ַɳ���\n" NOR;
				me->add("neili", -160);
				target_w->unequip();
				target_w->move(environment(target));
				target->reset_action();
			}
			msg += HIC"ֻ��$n���е�"+target_w->query("name")+"��Ȼ���Ҷ������Σ������ܵ�$N�ľ����ļ�������$nѸ����ȥ��\n"NOR;
			me->add("neili", -160);
			message_vision(msg,me,target);
			target_w->unequip();
			target_w->move(environment(target));
			target_w->set("name", target_w->query("name") + "����Ƭ");
			target_w->set("value", target_w->query("value")/10);
			target_w->set("weapon_prop", 0);
			target->reset_action();
			target->start_busy( (int)me->query_skill("duanyun-fu") / 20 );
			limbs=target->query("limbs");
			me->start_busy(1);
			msg += "���$p���������������˸����ֲ�����\n" NOR;
			size=(int)(me->query_skill("duanyun-fu")/30);
			damage=random(size)+size;
			damage=damage+me->query_str()+random(me->query_temp("apply/damage"));
			for(i=0; i<=random(size); i++)
			{
				msg =HIB"���͡�����Ƭ����$p"+limbs[random(sizeof(limbs))]+"��\n"NOR;			
				target->receive_damage("qi",damage,me);
				target->receive_wound("qi",damage,me);
				message_vision(msg,me,target );
			}
			COMBAT_D->report_status(target);
		}
		else
		{
			msg += "����$p��æ���Լ��ı�����������û����$P�ļ�ı�óѡ�\n" NOR;
		}
		return 1;
	}
	return notify_fail(target->name() + "Ŀǰ�ǿ��֣�������ʲô��\n");
}

