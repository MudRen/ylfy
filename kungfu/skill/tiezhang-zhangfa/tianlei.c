// tianlei.c 铁掌--天雷气

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
        string msg;
        object weapon;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("天雷气只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用天雷气！\n");

        if( (int)me->query_skill("guiyuan-tunafa", 1) < 119 )
		return notify_fail("你的天雷气还未练成，不能使用！\n");

        if( (int)me->query("neili", 1) < 600 )
		return notify_fail("你现在内力不足，不能使用天雷气！\n");	

	if( (int)me->query_skill("tiezhang-zhangfa", 1) < 119 )
		return notify_fail("你的铁掌掌法不够娴熟，不能使用天雷气。\n");

    msg = HIY "\n$N忽然仰天大喝一声“天 雷 气”，双掌如风车般连环击出，一阵热浪随掌势狂飙而出，势不可挡！\n"NOR;

	if( weapon = target->query_temp("weapon") ){
        if( random(me->query("str")) > (int)target->query("str")*3/4 ) {  
    msg += HIM"\n$p只觉得浑身一热，手掌虎口巨痛，手中"
                + target->query_temp("weapon")->query("name") + "脱手而出。\n" NOR;
		message_vision(msg, me, target);
		(target->query_temp("weapon"))->move(environment(target));
	} else {
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
		message_vision(msg, me, target);
	}
	me->start_busy(1);
        }
        else
        {
        if (random(me->query_skill("force",1)) > target->query_skill("force",1)/2 )
	{
		me->start_busy(3);
		target->start_busy(random(3));		
		damage = (int)me->query_skill("force");	
		damage = damage*4 + random(damage);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
		msg += HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
		
	} else 
	{
		me->start_busy(1);
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
	}
	message_vision(msg, me, target);

        }
        me->add("neili", -600);
	return 1;
}
