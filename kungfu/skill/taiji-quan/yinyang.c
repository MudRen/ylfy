// yingyang 显阴阳
// by suimeng 2015.4

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,damage;
	int orforce;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("这个绝技只能空手使用。\n");		
	if( (int)me->query("neili") < 5000  ) 
		return notify_fail("你的内力不够。\n");
	
	if (!(int)me->query("breakup"))
        return notify_fail("你任督二脉未通,无法使用!!\n"NOR,);

	if( (int)me->query("max_neili") < 200000 ) 
		return notify_fail("你的内力不够。\n");

    if( !wizardp(me) &&(int)me->query_skill("taiji-quan", 1) < 1300 )
		return notify_fail("你的太极拳法不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("taiji-shengong", 1) < 1300 )
		return notify_fail("你的太极神功不够高!不能贯通使用！\n");

    if ( !wizardp(me) && me->query_skill_mapped("force") != "taiji-shengong")
        return notify_fail("不使用本门内功，如何使用本门绝学!\n");

    if( !wizardp(me) && me->query_temp("weapon") )
        return notify_fail("你必须空手才能使用本门绝学!\n");      
		
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");

	extra = me->query_skill("taiji-quan",1);
    extra += me->query_skill("taiji-shengong",1);	
	damage = me->query_skill("taiji-quan"); 
	damage += me->query_skill("taiji-shengong"); 
	damage += me->query_skill("force",1);
	damage += me->query_skill("unarmed",1);
	damage *= me->query("con");
	me->add("jiali",extra/2);
	orforce = (int) me->query("force");	
		
	weapon = me->query_temp("weapon");
	me->add("str", extra);
	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",extra);

        msg = WHT "$N贯通武当武学，使出了武当的绝学之精髓！\n" NOR;
        message_vision(msg, me, target);               

	msg = MAG  "$N双手抱了个太极式的圆圈，纯以意行太极，已达形神合一，心动气动的境界，！\n"NOR;
	message_vision(msg,me,target);
	msg = WHT  "「乱环诀」！阴" NOR;

if (random(3)==0) target->start_busy(5);

	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "「乱环诀」！阳" NOR;
        target->receive_wound("qi", random(extra)*2);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT  "「阴阳诀」！阴" NOR;
	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "「阴阳诀」！阳" NOR;
        target->receive_wound("qi", random(extra)*2);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT  "「动静诀」！阴" NOR;
	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "「动静诀」！阳" NOR;
        target->receive_wound("qi", random(extra)*2);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT  "「两仪诀」！阴" NOR;
	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "「两仪诀」！阳" NOR;
        target->receive_wound("qi", random(extra)*2);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT  "「刚柔诀」！阴" NOR;
	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "「刚柔诀」！阳" NOR;
        target->receive_wound("qi", random(extra)*2);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
{
                msg = WHT"              阴阳双环           !!\n"NOR;
		msg += MAG"「沾黏诀」「挤字诀」「引字诀」「按字诀」!!\n"NOR;
		damage = damage + random(damage);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
       msg += HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
	message_vision(msg, me, target);
}
	    me->start_busy(4);
	    me->add("jiali",-extra/2);
        me->add("str", -extra);
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);
	    me->add("neili", -5000);
	return 1;
}
