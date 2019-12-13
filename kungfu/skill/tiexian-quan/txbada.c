// txbada 铁线八打
// modify by lyy 2016-6-27

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;
 
int perform(object me, object target)
{
    string msg;
	object weapon;
	
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「铁线八打」只能在战斗中使用。\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「铁线八打」只能空手使用。\n");		
    
	if( me->query_skill_mapped("unarmed") != "tiexian-quan" )
	    return notify_fail("你没有使用铁线拳。\n");
	
	if( (int)me->query("neili") < 700 )
        return notify_fail("你的真气不够！\n");

    if( me->query_skill("tiexian-quan",1) < 5000 )
       return notify_fail("你的铁线拳火候不够，无法使用「铁线八打」！\n");

    if( (int)me->query_skill("force",1) < 6000 )
        return notify_fail("你的内功修为不够，无法使用「铁线八打」！\n");
	
	weapon = me->query_temp("weapon");

        msg = HIY "$N使出名震天下的[铁线拳]，一招[铁线八打]八式连环！\n" NOR;
        	message_vision(msg, me, target);                
		msg = HIC "第一拳------笑问七剑一指仙！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "第二拳------叶落枫舞二穿山！！" NOR;
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "第三拳------袖里风云三点头！！！" NOR;
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "第四拳------回风轻吟四方喧！！！！" NOR;
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "第五拳------孤心化月五看地！！！！！" NOR;
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "第六拳------茫茫秋水六荒天！！！！！！" NOR;
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "第七拳------飞燕逐月意凌云！！！！！！！" NOR;
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		msg = HIC "最后一拳----风吹残雪漫千山！！！！！！！！" NOR;
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);  
        me->add("neili", -700);
        me->start_busy(2);

        return 1;
}