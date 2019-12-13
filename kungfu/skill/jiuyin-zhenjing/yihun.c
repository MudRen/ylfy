//yihun.c

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
        int skill = (int)me->query_skill("jiuyin-zhenjing", 1), i;
        string msg;
	
	if( !target || target == me ) target = offensive_target(me);

	if( environment(me)->query("citybiwu") )
		return notify_fail("这里不准打架。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不准打架。\n");
	if( !target || target==me || !target->is_character() )
		return notify_fail("移魂大法只能对对手使用。\n");
		
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「移魂大法」只能对战斗中的对手使用。\n");
	if ((int)me->query_skill("jiuyin-zhenjing", 1) < 1500)
		return notify_fail("你的九阴真经修为太低了，无法使用移魂大法。\n");
	if(!me->query("jiuyin/jm"))
		return notify_fail("你还没有领悟九阴真经的精髓，无法使用移魂大法。\n");
	if ( (int)me->query_skill("taoism", 1) < 3000)
		return notify_fail("以你目前的道学修为来看，还不足以运用移魂大法！\n");

    if( !living(target) && userp(target) && target->query("combat_exp")/5 > me->query("combat_exp") )
	return notify_fail("你想要杀此人，但他比你强太多，你不敢动手。\n");
	
    if (me->query_temp("yihun"))
                return notify_fail("你已在运用移魂大法了。\n");
    if (me->query("max_neili") < 2000)
                return notify_fail("你的内力修为不够运用移魂大法所需！\n");
    if (me->query("neili") < 1000)
                return notify_fail("你的内力不够运用移魂大法所需！\n");

	me->start_busy(1);
	msg = HIW"$N眼神莹然有光，脸上突然开始做出各样奇怪的表情。\n";
	
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/5	){
		msg += "$n看了备取笑$N，却不知不觉的学起$N的表情。\n"NOR;
		msg += CYN"\n$N猛然做出向自己攻击的动作，$n立刻向自己发疯似的攻击起来，出手越来越重！\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili", - 600);
		if (random(skill) > (int)target->query_skill("dodge", 1)/3)
			target->start_busy(random(skill/50) + 3);
		if (!target->is_busy())
			target->start_busy(random(2) + 1);
		//target->add("qi",-target->query("max_qi"));//添加针对移魂的伤害
		target->add_temp("apply/attack", skill/2);
		target->add_temp("apply/damage", skill/2);
		target->add_temp("apply/dodge", -skill*10);
		for (i=0; i<random(skill/100)+3; i++)
			COMBAT_D->do_attack(target, target, target->query_temp("weapon"));
		target->add_temp("apply/attack", -skill/2);
		target->add_temp("apply/damage", -skill/2);
		target->add_temp("apply/dodge", skill*10);
		target->add_temp("apply/attack", -skill/20);
		target->add_temp("apply/dodge", -skill/20);
	} else {
		msg += HIY"不管$N怎么变化表情，$n总是冷冷的无动于衷。\n"NOR;
		message_vision(msg, me, target);
		me->add("neili", -600);
	}
	if(!me->is_fighting(target)) me->fight_ob(target);
	if(!target->is_fighting(me)) target->fight_ob(me);

        me->set_temp("yihun", 1);
	remove_call_out("checking");
        call_out("checking", 1, me);
        return 1;
}

void checking(object me)
{
	object target;
        int skill = (int)me->query_skill("jiuyin-zhengong", 1), i;
        string msg;
        target = offensive_target(me);

        if (!me || !me->query_temp("yihun")) return;
        if (!target ) return;
        if (me->is_ghost() || !living(me)){
                me->delete_temp("yihun");
                return;
                }
        if (!me->is_fighting() || me->query("neili") < 600) {
        	message_vision("\n$N眼神逐渐浑浊，脸上恢复了原来的神情。\n\n", me);
        	me->delete_temp("yihun");
        	return;
        	}
	if( !target || !target->is_character() ) {
	        call_out("checking", 1, me);
	        return;
	}

	if (userp(target))
{
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/5	)
{
		msg = CYN"\n$N猛然做出向自己攻击的动作，$n立刻向自己发疯似的攻击起来，出手越来越重！\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili", - 400);
		if (!target->is_busy())
			target->start_busy(random(2) + 1);
		target->add_temp("apply/attack", skill/2);
		target->add_temp("apply/damage", skill/2);
		target->add_temp("apply/dodge", -skill*10);
		for (i=0; i<(random(skill/100)+3)/2; i++)
			COMBAT_D->do_attack(target, target, target->query_temp("weapon"));
		target->add_temp("apply/attack", -skill/2);
		target->add_temp("apply/damage", -skill/2);
		target->add_temp("apply/dodge", skill*10);
		target->add_temp("apply/attack", -skill/20);
		target->add_temp("apply/dodge", -skill/20);
}
}
else {
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/5	){
		msg = CYN"\n$N猛然做出向自己攻击的动作，$n立刻向自己发疯似的攻击起来，出手越来越重！\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili", - 400);
		if (!target->is_busy())
			target->start_busy(random(2) + 1);
		target->add_temp("apply/attack", skill/2);
		target->add_temp("apply/damage", skill/2);
		target->add_temp("apply/dodge", -skill*10);
		for (i=0; i<(random(skill/100)+3)/2; i++)
			COMBAT_D->do_attack(target, target, target->query_temp("weapon"));
		target->add_temp("apply/attack", -skill/2);
		target->add_temp("apply/damage", -skill/2);
		target->add_temp("apply/dodge", skill*10);
		target->add_temp("apply/attack", -skill/20);
		target->add_temp("apply/dodge", -skill/20);
	}
}
        call_out("checking", 1, me);
}       
