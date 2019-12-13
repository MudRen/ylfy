
#include <ansi.h>
inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp,max_suck,skill,top_limit;
	int skill_limit=0;
	if ( target == me )
		target = offensive_target(me);
	if( !objectp(target) || environment(me)!=environment(target)||target->query("id") == "mu ren"|| target->query("id") == "tong ren")
		return notify_fail("你要吸谁的内力？\n");
    if ( me->query("gender") == "无性")
        return notify_fail("你无根无性，阴阳不调，难以使用吸星大法。\n");
	if ( me->query_temp("sucked") )
		return notify_fail("( 你上一个动作还没有完成，不能施用内功。)	\n");
	if (target->query("age") < 18)
		return notify_fail("小孩子能有什么内力?\n");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能施用化功大法！\n");
	skill=(int)me->query_skill("xixing-dafa",1);
	if( skill < 100 )
		return notify_fail("你的吸星大法功力不够，不能吸取对方的内力！n");
	if(me->query("max_neili") > skill*22000 )
		skill_limit=1;
	if( (int)me->query("neili",1) < 100 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");
	if( (int)target->query("max_neili") < 60  || !living(target))
		return notify_fail( target->name() + "已经内力涣散，你已经无法从他体内吸取任何内力了！\n");
	if(me->is_busy()) return notify_fail("你现在正忙着吸取内力！\n");
	if(!me->query("xy_huiyuan") && me->query("max_neili") >=330000)
		return notify_fail(HIY"只有会员才能吸取33万以上内力。\n"NOR);
	if ( !me->query("xy_huiyuan") && target->query("id") == "nai niu" && domain_file(base_name(environment(me))) == "party" )
		return notify_fail(HIY"帮会中奶牛只提供给注册会员使用，你无法吸取。\n"NOR);
	message_vision( HIY"$N手臂猛地长出正抓在$n右手腕上。突然之间，$n猛觉右腕“内关”“外关”两处穴道中内力源源外泄！\n\n" NOR, me, target );
	if ( living(target) )
	{
		me->kill_ob(target);
		target->kill_ob(me);
	}
	if( wiz_level(target)>0 || (int)target->query("max_neili") <= 0 || (int)target->query("no_suck"))
		return notify_fail( target->name() + "没有任何内力！\n");
	sp = me->query_skill("force") + me->query_skill("dodge",1);
	dp = target->query_skill("force") + target->query_skill("dodge",1);
	top_limit = (int)me->query("max_neili") / (int)target->query("max_neili");
	me->set_temp("sucked", 1);
	if (( random(sp) > random(dp) ) )
	{
		tell_object(target, HIR"你只觉得手腕上“内关”“外关”两处穴道便如开了两个大缺口，立时全身内力急泻而出，有如河水决堤，再也难以堵截！\n" NOR);
		tell_object(me, HIG"你觉得" + target->name() + "的丹元自手掌源源不绝地流了进来。\n" NOR);
		max_suck=(int)target->query("max_neili") - (int)me->query("max_neili")/2;
		if (max_suck<1) max_suck=1+random(2);
		else max_suck/=15;
		if (max_suck > 1500 )
			max_suck = 1500;
		max_suck=max_suck+skill + target->query("jiali");
		max_suck/=20;
		if ( target->query("max_neili") < max_suck )
			max_suck=target->query("max_neili");
		if (me->query("max_neili") > 200000 ) max_suck = (skill/70)+5;
		if (userp(target))
			max_suck/=7;
		if(skill_limit>0)
			max_suck=skill/200;
		target->add("max_neili",  -max_suck );
		me->add("neili",-max_suck*3/2);
		if ( me->query("max_neili") > 200000)
		{
			me->add("max_neili", max_suck);
		}
		else if ( me->query("max_neili") <= 200000)
		{
			if (top_limit>1)
				me->add("max_neili", (max_suck / 5 ) + 1);
			else
			{
				me->add("max_neili",  max_suck*2 );
			}
		}
		if ( target->query("max_neili") <1 )
			target->set("max_neili",0);
		if ( me->query("neili") <1 )
			me->set("neili",0);
		me->start_busy(random(5)+3);
		target->start_busy(random(3)+1);
	}
	else
	{
		message_vision(HIY"可是$p看破了$P的企图，内力猛地一震，借势溜了开去。\n" NOR, me, target);
		me->start_busy(5);
	}
	call_out("del_sucked", 8, me);
	return 1;
}
void del_sucked(object me)
{
	if ( !objectp(me) ) return;
	if ( me->query_temp("sucked")) me->delete_temp("sucked");
}


