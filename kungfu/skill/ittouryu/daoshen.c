
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i, attack_time;
	object weapon;

	weapon = me->query_temp("weapon");
	extra = (int)me->query_skill("ittouryu",1);	
	attack_time = (int)me->query_skill("ittouryu",1)/100;
	
	if(attack_time>50) attack_time=50;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("［刀神］只能对战斗中的对手使用。\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ( me->query_skill("ittouryu",1) < 300)
		return notify_fail("你的［一刀流剑术］还不够纯熟！\n");
	if ((int)me->query_skill("shayi-xinfa", 1) < 500)
		return notify_fail("你的杀意心法火候不够。\n");
	if ( me->query_skill_mapped("blade") != "ittouryu")
		return notify_fail("你必须激发［一刀流剑术］才能使用「刀神」！\n");
	if ( me->query_skill_mapped("force") != "shayi-xinfa")
		return notify_fail("你必须激发杀意心法才能使用「刀神」！\n");
	if( (int)me->query("neili") < 6000 )
		return notify_fail("你的真气不够！\n");
	
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	me->add_temp("lianzhao", attack_time);
	
	msg = HIR  "$N使出［圆月神刀斩］中的无上绝技－－刀神！"+ weapon->name() +"划着奇异的弧线，急斩$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	for(i=0; i<attack_time; i++)
	{
		msg = CYN "$N御技如神，刀气纵横！\n" NOR;
		COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
		me->add("neili",-100);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->delete_temp("lianzhao");
	me->start_busy(4);
	return 1;
}
