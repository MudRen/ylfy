// xuanfeng.c  ���縡Ӱ

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����縡Ӱ��ֻ����ս����ʹ�á�\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����縡Ӱ����ʼʱ�������ű�����\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("bibo-shengong",1) < 50 )
		return notify_fail("��ı̲��񹦲�����\n");

	if( (int)me->query_skill("luoying-zhang",1) < 500 || me->query_skill("xuanfeng-tui",1) < 500)
		return notify_fail("������ƹ��򻹲����ң��޷�ʹ�ÿ�������\n");

	msg =  HIC"$Nʹ���һ������������縡Ӱ��������������������ƣ�\n" NOR;
	message_vision(msg, me, target);
	msg =  HIB  "$N���������ƣ�����һ�Ÿ����߳���" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIM  "��Ӱ�У�$N����������ƴ����û���$n��" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIY  "$N��$n�Ż��󿪣�����������˫����������$n��" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = CYN  "$NԽսԽ�£���Χ����һ�����磬ʹ��$n�����巽��" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIG"$N���ǹ�է�֣������Դ���Ȼ֮ɫ����$n��" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR"$N��Хһ��������෢����Ȼת��$n��󣬷�������һ�ƣ�" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add("neili", -500);
	me->start_busy(4);

	return 1;
}

