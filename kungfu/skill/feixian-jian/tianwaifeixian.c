// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i, attack_time;
	object weapon;
	
	extra = me->query_skill("feixian-jian",1) / 25;
    	attack_time = extra/4;
	if (attack_time > 50) attack_time = 50;
	
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("天外飞仙只能对战斗中的对手使用。\n");
	if ( me->query_skill("feixian-jian",1) < 100) 
			return notify_fail("你的飞仙剑法还不够纯熟！\n");
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("天外飞仙只能对战斗中的对手使用。\n");
    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
        return notify_fail("使用天外飞仙必须拿着一把剑！\n");
	 if ( me->query_skill_mapped("sword") != "feixian-jian")
         return notify_fail("你必须激发飞仙剑法才能使用「天外飞仙」！\n");   
	if( (int)me->query("neili") < 5000  ) 
		return notify_fail("你的内力不够。\n");
	me->add_temp("apply/attack", extra);	
	me->add_temp("lianzhao", attack_time);
	msg = RED  "$N脚踏［琼崖步法］，同时使出［飞仙剑法］的精髓－－天外飞仙，手中的"+ weapon->name() +"划出一道长虹，闪电般的击向$n！" NOR;

	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIW "剑光一闪，消失．．．．\n" NOR;
    message_vision(msg, me, target);

	for(i=0;i < attack_time;i++)
	{
	msg = RED "$N身形突转，御剑回飞！\n" NOR;

	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->delete_temp("lianzhao");
	me->add("neili", -100*attack_time);
	me->start_busy(4);
	return 1;
}
