// chan.c 太极剑法「缠」字诀
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int time;
    object weapon;
    string msg="";
    if( !target ) target = offensive_target(me);
    if( !target
    ||  !target->is_character()
    ||  !me->is_fighting(target) )
        return notify_fail("牵制攻击只能对战斗中的对手使用。\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");
      
    if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
        
    if( (int)me->query_skill("taiji-jian", 1) < 80 )
        return notify_fail("你的太剑法极不够娴熟，不会使用「缠」字诀。\n");
        if( me->is_busy()) return notify_fail("你现在正忙着。\n");     
    if (!me->visible(target))    return notify_fail("你看不到"+target->name()+"。\n");
    msg = HIG "$N使出太极剑法「缠」字诀，连递数个虚招企图扰乱$n的攻势。\n";
    me->start_busy(2);
    time = (int)me->query_skill("taiji-jian") / 30;       	
    if (time<3) time = 3;
    if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/3 ) 
    {    	
        msg += HIR " 结果$p被$P攻了个措手不及！\n" NOR;
        target->start_busy(time*15);     	
    } 
    else 
    {
    	if(time > 5) time = 5;
        me->start_busy(time/2);
        msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
    }
    message_vision(msg, me, target);
    return 1;
}
