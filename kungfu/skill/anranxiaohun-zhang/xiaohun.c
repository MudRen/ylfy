// xiaohun.c ��Ȼ����
// By Kayin @ CuteRabbit Studio 99-4-16 19:18 new
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("anranxiaohun-zhang",1);
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("����Ȼ���꡹ֻ����ս����ʹ�á�\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ȼ���꡹ֻ�ܿ���ʹ�á�\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("�������������\n");

	if(!me->query("couple/have_couple"))
		return notify_fail("�㻹û���������ˣ��޷��������˼��һ���˵ĸ��ܡ�\n");

	if( (int)me->query_skill("anranxiaohun-zhang",1) < 300 )
		return notify_fail("�����Ȼ�����ƻ�򲻹����޷�ʹ�á���Ȼ���꡹��\n");

	if( (int)me->query_skill("force",1) < 200 )
		return notify_fail("����ڹ���Ϊ�������޷�ʹ�á���Ȼ���꡹��\n");
	weapon = me->query_temp("weapon");
	me->add_temp("apply/attack",extra*2);
	me->add_temp("apply/damage",extra);

	msg = HIM "$N����ֹˮ������˼����$N�İ��ˣ�����֮��ʹ����"HIR"����Ȼ���ꡱ��\n" NOR;
	msg += HIM   "���ư����ң�̣���ʱ��ؼ����һ˿��ɬ��\n" NOR;
	message_vision(msg, me, target);
	msg = HIC  "\n   �� \n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIY  "\n      Ȼ\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIW  "\n        ��\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR  "\n          ��\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIB "\n             ��\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack",-extra*2);
	me->add_temp("apply/damage",-extra);

	if( me->query("shen") > 10000
	        && target->query("shen") < 10000 )
	{
		msg = HIG "\n$Nŭ��$n,��һ�����������һ�ƣ����ư����ң�̣���ʱ��ؼ����һ˿��ɬ��\n"NOR;
		if( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3 || random(me->query("unarmed")) > target->query("dodge")/3 )
		{

			msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
			target->receive_damage("qi",extra*3);
			target->receive_wound("qi",extra*3);

			if (!target->is_busy()) target->start_busy(3);
			message_vision(msg, me, target);
			COMBAT_D->report_status(target);
		}
		else
		{
			msg += HIY"����$p�������ǣ����ط����������ܹ���������һ��,���˿�ȥ��\n" NOR;
			message_vision(msg, me, target);
		}
	}
	me->add("neili", -500);
	me->start_busy(3);

	return 1;
}

