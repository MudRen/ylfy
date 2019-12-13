#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
	 int extra, i, attack_time;
	object weapon;
	
	extra = (int)me->query_skill("lingshe-zhangfa",1);
	attack_time = (int)me->query_skill("lingshe-zhangfa",1)/ 80;
	if(attack_time > 50) attack_time = 50;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	
    if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
         return notify_fail("「狂风扫落叶」只能在战斗中使用。\n");
 
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "staff")
        return notify_fail("你使用的武器不对。\n");
    
    if ( me->query_skill_mapped("staff") != "lingshe-zhangfa")
         return notify_fail("你必须激发灵蛇杖法才能使用「狂风扫落叶」！\n");  	
	   
	if( (int)me->query("neili") < 3000 )
        return notify_fail("你的真气不够！\n");

    if( (int)me->query_skill("lingshe-zhangfa",1) < 200 )
        return notify_fail("你的灵蛇杖法火候不够，无法使用「狂风扫落叶」！\n");

    if( (int)me->query_skill("force",1) < 180 )
        return notify_fail("你的内功修为不够，无法使用「狂风扫落叶」！\n");
			
	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",extra);
	me->add_temp("lianzhao", attack_time);
    msg = HIY "$N跳出数丈外，突然一声暴喝：“------ 狂 ----- 风 ----- 扫 ----- 落 ----- 叶 ----- ！！！”" NOR;
    message_vision(msg, me, target);
	for(i=0;i<attack_time;i++)
	{	
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);
	}		
    me->add_temp("apply/attack",-extra);
	me->add_temp("apply/damage",-extra);
	me->delete_temp("lianzhao");
    me->add("neili",-100*attack_time);	
    me->start_busy(4);
    return 1;
}

