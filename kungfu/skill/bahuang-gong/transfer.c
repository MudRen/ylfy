// transfer.c

#include <ansi.h>

int exert(object me, object target)
{
	int force;
	int skl,vaild;

	if( !target || target==me || !living(target) )
		return notify_fail("你要将真气传给谁？\n");

	if( (string)me->query_skill_mapped("force") != target->query_skill_mapped("force") )
		return notify_fail(target->name() + "所使用的内功和你不同。\n");

	if( (int)me->query("neili") <= (int)me->query("max_neili") )
		return notify_fail("你的真气不足。\n");

	force = me->query("neili") - me->query("max_neili");

	if( force/2 < 1 ) return notify_fail("你的真气不足。\n");
	me->add("neili", - force / 2 );
	message_vision("$N将手掌贴在$n背心，运气将体内真气传送过去。\n", me, target);
	skl=target->query_skill("bahuang-gong",1)/2;
	vaild=skl*target->query("max_neili");
	if( random(force/3) > (int)me->query_skill("force"))
		return notify_fail("你失败了。\n");
	if ( target->query("neili") > vaild )
	{
		tell_object(target, HIR "你觉得一股热气突然从丹田涌了上来，不禁一阵恶心，哇的吐出一口鲜血。\n" NOR);
		message_vision("$N被$p的内力一震，眼前一黑，身子向后飞出丈许！\n", me, target);
		target->receive_wound( "qi", skl*5 ,me);
		me->receive_wound( "qi", target->query("max_neili")/30 ,target);
		return 1;
	}
	target->add("neili", force/3);
	me->improve_skill("bahuang-gong", random(me->query_skill("bahuang-gong", 1)/10),0);
	tell_object(target, HIY "你觉得一股热气从" + me->name() + "的手掌传了过来。\n" NOR);
	return 1;
}

