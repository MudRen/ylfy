// tie@fengyun

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, i, v, attack_time;
	object weapon;
	
	if ( !target ) target = offensive_target(me);
	if ( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���ƽ���ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
	if ( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����ƽ�����ֻ�ܿ���ʹ�á�\n");		
	if ( (int)me->query_skill("tiezhang-zhangfa", 1) < 500 )
		return notify_fail("��������Ʒ�������죬���������ƽ�����\n");
	
	if( me->query_skill_mapped("unarmed") != "tiezhang-zhangfa" )
	    return notify_fail("��û���������Ʒ���\n");
	if ( (int)me->query_skill("guiyuan-tunafa", 1) < 900 )
	    return notify_fail("��Ĺ�Ԫ���ɷ�������죬����ʹ�����ƽ�����\n");

	extra = me->query_skill("tiezhang-zhangfa", 1) / 50;

	if ( (int)me->query("neili", 1) < extra * 100 )
		return notify_fail("�������������㣬����ʹ�ã�\n");	
	
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra*2);
	
	msg = HIY"\n$N����۹�Ԫ���ɷ��ݣ�ͬʱʹ�������ƽ�����һ��һ����������糱ˮ��Ļ���$n��\n\n" NOR;
	message_vision(msg, me, target);
	msg = HIW "��һ����������������\n" NOR;
	v = 1;
	attack_time = extra;
	if ( attack_time > 50) attack_time = 50;
	message_vision(msg, me, target);

	for ( i=0; i<attack_time; i++ )
	{
		if ( i>4 && !(i%5) )
		{
			v++;
			msg = HIC "$N����ͻת���������������ĳ���"+chinese_number(v)+"��������\n" NOR;
			message_vision(msg, me, target);
		}
		COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra*2);
	me->add("neili", - 100 * extra);
	return 1;
}
