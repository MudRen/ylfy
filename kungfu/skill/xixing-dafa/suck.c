// suck.c
#include <ansi.h>
inherit F_SSERVER;
int exert(object me, object target)
{
    int sp, dp;
    if ( target == me )
        target = offensive_target(me);
    if( !objectp(target) || target->query("id") == "mu ren" )
        return notify_fail("你要吸取谁的内力？\n");
    if ( me->query_temp("sucked") )
        return notify_fail("你刚刚吸取过内力！\n");
    if( (int)me->query_skill("xixing-dafa",1) < 50 )      	
        return notify_fail("你的吸星大法功力不够，不能吸取对方的内力！n");
    if ( me->query("gender") == "无性")
        return notify_fail("你无根无性，阴阳不调，难以使用吸星大法。\n");	
    if( (int)me->query("neili",1) < 100 )
        return notify_fail("你的内力不够，不能使用化功大法。\n");	
    if( (int)target->query("max_neili") <= 0 )
        return notify_fail( target->name() + "没有任何内力！\n");
    if( (int)target->query("no_suck"))
        return notify_fail( target->name() + "没有任何内力！\n");
    if( (int)target->query("neili") < 100  || !living(target))
        return notify_fail( target->name() +"已经内力涣散，你已经无法从他体内吸取任何内力了！\n");
     if(me->is_busy()) return notify_fail("你正忙着呢。\n");
	 if( me->query("neili",1) > me->query("max_neili",1)*3 )
        return notify_fail("你只觉内息澎湃已是难以控制，似乎无法吸纳更多的内力。\n");
	 if ( !me->query("xy_huiyuan") && target->query("id") == "nai niu" && domain_file(base_name(environment(me))) == "party" )
		return notify_fail(HIY"帮会中奶牛只提供给注册会员使用，你无法吸取。\n"NOR);
     message_vision( HIY"$N手臂猛地长出正抓在$n右手腕上。突然之间，$n猛觉右腕“内关”“外关”两处穴道中内力源源外泄！\n\n" NOR, me, target );
    if ( living(target) )
    {
		me->kill_ob(target);
        if( !target->is_killing(me) )
            target->kill_ob(me);
    }
        sp = me->query_skill("force") + me->query_skill("dodge",1);	
        dp = target->query_skill("force") + target->query_skill("dodge",1);
    me->set_temp("sucked", 1);      
    if (( random(sp) > random(dp) ) )
    {
       tell_object(target, HIR"你只觉得手腕上“内关”“外关”两处穴道便如开了两个大缺口，立时全身内力急泻而出，有如河水决堤，再也难以堵截！\n" NOR);
		tell_object(me, HIG"你觉得" + target->name() + "的丹元自手掌源源不绝地流了进来。\n" NOR);
        target->add("neili", -1*((int)me->query_skill("xixing-dafa", 1) + target->query("jiali")) );	
        if ( target->query("neili") <1 )
            target->set("neili",0);
        me->add("neili", (int)me->query_skill("xixing-dafa", 1) + target->query("jiali") );	
        me->start_busy(random(6));
        target->start_busy(random(4));
        call_out("del_sucked", 3, me);
    }
    else
    {   
        message_vision(HIY "可是$p看破了$P的企图，机灵地闪了开去。\n" NOR, me, target);
        me->start_busy(4);
        call_out("del_sucked", 4, me);
    }
    return 1;
}
void del_sucked(object me)
{
    if ( !objectp(me) ) return;
    if ( me->query_temp("sucked")) me->delete_temp("sucked");
}
