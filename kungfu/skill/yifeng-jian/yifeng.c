#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, attack_time;

	if( !target ) target = offensive_target(me);

	if ( me->query("gender") != "女性")
		return notify_fail("你体态生硬，无从领会「移风起栖云飞扬」的精髓。\n");

	/*        if ( !wizardp(this_player()) && (me->query("family/family_name") != "移花宫"))
	                return notify_fail("你不是移花宫弟子不能使用冥雨神功.\n
	                                    移风剑法博大精深, 非移花宫弟子不传, 真不知道你是怎么学会的!\n
	                                    要是让两位宫主知道了你可惨了.\n");
	*/
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「移风起栖云飞扬」只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if((int)me->query_dex() < 60)
		return notify_fail("你的身法不够, 目前还不能使用这项绝技! \n");

	if((int)me->query_skill("mingyu-shengong",1) < 300)
		return notify_fail("你的冥雨神功的修为不够, 不能使用这一绝技 !\n");

	if ( me->query_skill_mapped("force")!="mingyu-shengong" )
		return notify_fail("「移风起栖云飞扬」必须以冥雨神功做底子！\n");

	if ( me->query_skill_mapped("sword")!="yifeng-jian" )
		return notify_fail("移风剑法必须激发在基本剑法，才可以使用「移风起栖云飞扬」！\n");

	if((int)me->query_skill("dodge",1) < 400)
		return notify_fail("你的轻功修为不够, 不能使用移风起栖云飞扬！\n");

	if((int)me->query_skill("sword",1) < 150)
		return notify_fail("你的剑法修为不够， 目前不能使用移风起栖云飞扬! \n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("你的真气不够！\n");

	msg = HIM "$N使出移风剑法的绝技「移风起栖云飞扬」，顿时花瓣飞舞！\n";
	if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/10 )
	{
		attack_time = (int)me->query_skill("yifeng-jian", 1) / 80;
		if(attack_time < 1) attack_time = 1;
		if(attack_time > 50) attack_time = 50;
		me->add_temp("lianzhao", attack_time);
		msg += HIR " $p看着$P手中的剑化为无数花瓣刺向$p！\n" NOR;
		for(i = 2; i < attack_time; i++)
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);

		me->start_busy(random(2));
		me->add("neili", -100*attack_time);
		me->delete_temp("lianzhao");
	}
	else
	{
		msg += HIY "$p向旁边一跳，躲过了$P的这一招。\n" NOR;
		me->start_busy(random(2));
	}
	message_vision(msg, me, target);

	return 1;
}

