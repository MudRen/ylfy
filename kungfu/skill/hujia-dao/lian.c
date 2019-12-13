// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i,attack_time;
	object weapon;
	
	extra = me->query_skill("hujia-dao",1); 
	attack_time = me->query_skill("hujia-dao",1) / 100; 
	if(attack_time>50) attack_time=50;
	
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("胡家刀法刀刀相连只能对战斗中的对手使用。\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
    if ( me->query_skill_mapped("blade") != "hujia-dao")
         return notify_fail("你必须激发胡家刀法才能使用「刀刀相连」！\n");      
    if( (int)me->query_skill("hujia-dao", 1) < 500 )      	
		return notify_fail("你的胡家刀法不够娴熟，不能用刀刀相连。\n");
    if ( (int)me->query("neili") < 25000 ) 
		return notify_fail("你的真气不够！\n");
           	            	
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	me->add_temp("lianzhao", attack_time);
	
	msg = HIR  "$N一咬牙，手上动作加快，同时使出［胡家刀法中］的刀刀相连，手中的"+ weapon->name() +" 一刀连着一刀，闪电般的击向$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIR "在一片刀光中，一刀劈了过来\n" NOR;
    message_vision(msg, me, target);
	for(i=0;i < attack_time;i++)
	{
	msg = HIY "$N咬紧牙关，一刀又劈了过来！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->delete_temp("lianzhao");
	me->add("neili", -100*attack_time);
	me->start_busy(5);
	return 1;
}

