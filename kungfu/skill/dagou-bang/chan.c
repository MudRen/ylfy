// chan.c �򹷰����������־�

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�������־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "club")
		if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "club")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	if( (int)me->query_skill("club") < 100 )
		return notify_fail("��Ĵ򹷰���������죬����ʹ�á������־���\n");
	if (!me->visible(target))    return notify_fail("�㿴����"+target->name()+"��\n");

	if( (int)me->query_skill("force") < 100 )
		return notify_fail("����ڹ�������񣬲���ʹ�á������־���\n");

	msg = HIG "$Nʹ���򹷰����������־�����ͷ�ڵ������㣬���಻��������$n��С�Ⱥͽ��ס�\n";

	me->start_busy(1);
	if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/3 )
	{
		msg += HIR " ���$p��$P���ı�����ͣ����æ���ң�\n" NOR;
		target->start_busy( (int)me->query_skill("dagou-bang") / 10 );
	}
	else
	{
		msg += "����$p������$P����ͼ���򶨽��У�һ˿���ҡ�\n" NOR;
	}
	message_vision(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}


