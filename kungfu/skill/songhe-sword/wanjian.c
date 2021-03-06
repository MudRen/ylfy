//lilong alter 2002.01.12
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int i,j,k,u,damage;
	
	if ( !target ) target = offensive_target(me);
	if ( !target || !target->is_character() || target->is_corpse() || target==me ) 
		return notify_fail("你要攻击谁？\n");
	
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword") 
	    return notify_fail("你必须手持剑才能使用剑法。\n");
	
    if ( (int)me->query_skill("songhe-sword", 1) < 500 ) 
		return notify_fail("你的松鹤剑法级别还不够，使用这一招会有困难！\n");
	
	if ( !me->is_fighting() ) 
		return notify_fail("你们没有在打架！\n");
	if ( me->query_skill_mapped("sword") != "songhe-sword")
         return notify_fail("你必须激发松鹤剑法才能使用「万剑决」！\n"); 
	if ( playerp(me) && me->query("family/family_name") != "蜀山派" ) 
		return notify_fail("不是蜀山的不能用「万剑决」！\n");  
	
	if ( playerp(me) && me->query("shushan/wanjian_perform") !=1 ) 
		return notify_fail("你还没领会「万剑决」！\n");
	
	if ( (int)me->query("max_neili") < 1500 ) 
		return notify_fail("你的内功修为太差。\n");
	if ( (int)me->query("neili") < 1500 ) 
		return notify_fail("你的内力不足！\n");
	if ( (int)me->query("jing") < 50 ) 
		return notify_fail("你的精神不足，没法子施用外功！\n");
	if ( me->query_skill_mapped("force") != "shushan-force" ) 
		return notify_fail("没有蜀山心法无法驾驭剑气。\n");
	if ( (int)me->query_skill("shushan-force", 1) < 500 ) 
		return notify_fail("你的蜀山心法等级不够，不能使用这一招！\n");	
	
	k = (int)me->query_skill("songhe-sword", 1);
	u = k / 50;
    if (u > 50)	u = 50;

	k += (int)me->query_skill("sword",1);
	j = (int)target->query_skill("dodge",1);
	
	me->delete("env/brief_message");
	target->delete("env/brief_message");
	message_vision(HIC"\n$N仰天大喝了一声：\n"NOR,me,target);
	message_vision(HIW"\n万～～～～剑～～～～决\n"NOR,me,target);
	message_vision(HIC"\n一刹那间千万剑光破空而来，劈面罩向$n\n"NOR,me,target);
	for ( i=0; i<=u; i++ )
	{
		if ( random(k+j) > j ) 
		{
			message_vision(HIY"\n$n一个不慎，中了一剑\n"NOR,me,target);
			damage = k+random(k);
			//target->receive_damage("qi", damage, me);
			//target->receive_wound("qi", damage/2, me);
			COMBAT_D->do_attack(me, target, weapon, TYPE_REGULAR, "", random(damage/3));
			//COMBAT_D->report_status(target);
			me->receive_damage("jing", 10);
			me->receive_damage("qi", 20);
		}
		else 
		{
			message_vision(HIY"\n$n左跳右闪，好不容易避开了一轮剑雨\n"NOR,me,target);
			me->receive_damage("jing", 10);
			me->receive_damage("qi", 20);
		}
	}
	
	if ( !target->is_fighting(me) ) 
	{
		if ( living(target) ) 
		{
			if ( playerp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
	}
	target->start_busy(random(3));
	me->start_busy(random(3));
	return 1;
}
