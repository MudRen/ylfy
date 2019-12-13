// heal.c
#include <ansi.h>
int heal_myself(object me)
{
	int flag;
    string force_skill=me->query_skill_mapped("force");
	flag = (int)me->query_skill(force_skill, 1)/500;
		flag += ((int)me->query_skill(force_skill, 1)/1000);
		if ( (int)me->query_skill(force_skill, 1) > 1500 )
			flag += (((int)me->query_skill(force_skill, 1)-1500)/100);
		if ( flag < 1 ) flag = 1;
    
    if (!stringp(force_skill))
        return notify_fail("你所学的内功中没有这项技能。\n");
    if( me->is_fighting() )
        return notify_fail("战斗中运功疗伤？找死吗？\n");
    if ((int)me->query_skill(force_skill, 1) < 50)
        return notify_fail("你的"+to_chinese(force_skill)+"修为还不够。\n");
    if( (int)me->query("neili") < 50 )
        return notify_fail("你的真气不够。\n");
    if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
        return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
    if( (int)me->query("eff_qi") == (int)me->query("max_qi")  )
        return notify_fail("你现在不需要运功疗伤！\n");
    write( HIW "你全身放松，坐下来开始运功疗伤。\n" NOR);
    message("vision", HIW + me->name() + "吐出一口瘀血，脸色看起来好多了。\n" NOR, environment(me), me);
    me->receive_curing("qi", me->query("max_qi")/5 + (int)me->query_skill("force") );
    me->add("neili", -50);
  //me->set("jiali", 0);
    me->start_busy(2);
    me->improve_skill(force_skill, random(me->query_con()/flag)+1, 0);
    return 1;
}
int heal_target(object me,object target)
{
	int flag;
    string force_skill=me->query_skill_mapped("force");

	flag = (int)me->query_skill(force_skill, 1)/500;
		flag += ((int)me->query_skill(force_skill, 1)/1000);
		if ( (int)me->query_skill(force_skill, 1) > 1500 )
			flag += (((int)me->query_skill(force_skill, 1)-1500)/100);
		if ( flag < 1 ) flag = 1;
		
    if( !target->is_character() || target->is_corpse() )
        return notify_fail("看清楚一点，那并不是活物。\n");

    if (!stringp(force_skill)) return notify_fail("你所学的内功中没有这项技能。\n");
    if( me->is_fighting() || target->is_fighting())
        return notify_fail("战斗中无法运功疗伤！\n");
    if( (int)me->query("max_neili") < 300 )
        return notify_fail("你的内力修为不够。\n");
    if( (int)me->query("neili") < 150 )
        return notify_fail("你的真气不够。\n");
    if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
        return notify_fail( target->name() + "已经受伤过重，经受不起你的真气震荡！\n");
    if( (int)target->query("eff_qi") == (int)target->query("max_qi")  )
        return notify_fail(target->name()+"现在不需要疗伤！\n");
    message_vision( HIY "$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"
        "过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n" NOR,
        me, target );
    target->receive_curing("qi", target->query("max_qi")/5 + (int)me->query_skill("force") );
    if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));
    me->add("neili", -150);
  //me->set("jiali", 0);
  //target->set("jiali", 0);
    me->start_busy(5);
    target->start_busy(5);
    me->improve_skill(force_skill, random(me->query_con()/flag)+1, 0);
    return 1;
}
int exert(object me, object target)
{
    if( !target ||  target == me)
        return heal_myself(me);
    else
        return heal_target(me,target);
}
