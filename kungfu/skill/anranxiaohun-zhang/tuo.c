
// tuo.c
// 杨过决战金轮法王时所施展的决定胜负的一招。

#include <ansi.h>
#include <combat.h>

#define TUO "「" HIM "拖泥带水" NOR "」"

inherit F_SSERVER;


int perform(object me, object target)
{
	int damage;
	string msg;
	int ap, dp;
	int effqi, maxqi,skill;
	string couple;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail(TUO "只能对战斗中的对手使用。\n");

	if(me->query_skill_mapped("force") != "yunv-xinfa" )
		return notify_fail("你要把玉女心法做为内功才能用。\n");

	if ((int)me->query_skill("force",1) < 250)
		return notify_fail("你的内功火候不够，使不出" TUO "。\n");

	if ((int)me->query_skill("anranxiaohun-zhang", 1) < 180)
		return notify_fail("你的黯然销魂掌不够熟练，不会使用" TUO "。\n");

	if ((int)me->query("neili") < 5000)
		return notify_fail("你的真气不够，无法使用" TUO "。\n");

	if (! stringp(couple = me->query("couple/couple_id")))
	    return notify_fail("你没有妻子，体会不到这种万念俱灰的感觉。\n");
	/*
	if (! objectp(cob = find_player(couple)))
	        return notify_fail("老婆不在啊，苦闷向谁发？\n");
	*/

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	effqi = me->query("eff_qi");
	maxqi = me->query("max_qi");

	ap = me->query_skill("unarmed") + me->query_skill("force");

	dp = target->query_skill("parry") + target->query_skill("force");

	me->start_busy(3);

	if (effqi < maxqi * 25 / 100)
	{
		msg = HIR "$N" HIR "心下万念俱灰，凄然向妻子"
		      HIR "望了一眼，暗道：“别了！你自己保重。”\n"
		      "当下失魂落魄，随手一招，恰好使出了黯然销魂掌中"
		      "的「拖泥带水」。\n" NOR;
		ap += ap * 20 / 100;
	}
	else
	{
		msg = HIM "只见$N" HIM "没精打采的挥袖卷出，拍出一掌，正是黯然销魂掌中的「拖泥带水」。\n"NOR;
	}
	if (ap * 2 / 3 + random(ap) > dp)
	{
		damage = me->query_skill("unarmed") + me->query_skill("force");
		me->add("neili", -300);
		target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);

		msg +=HIR "只听$n" HIR "一声闷哼，“噗”的一声，这一掌正好击在$p" HIR "肩头。 \n"NOR;
	}
	else
	{
		me->add("neili", -100);
		msg += HIC "可是$p" HIC "小心应付、奋力招架，挡开了这一招。\n"NOR;
	}
	message_vision(msg, me, target);
	skill=(int)me->query_skill("anranxiaohun-zhang", 1);
	if (skill > 350)
	{
		me->add_temp("apply/damage",5000);
		me->add_temp("apply/attack",580);
		msg = HIB"$N心下万念俱灰，没精打采的挥袖卷出，拍出一掌，只听得噗的一声，这一掌正好击向$n肩头！" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

		msg = HIY"紧跟着$N踢出一脚。这一脚发出时恍恍惚惚，隐隐约约，若有若无。砰的一响，向$n胸口袭去！！" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

		msg = HIC"$N一招穷途末路闪身到$n身旁，左掌举到胸前平推而出，接着右掌斜斜劈向$n！" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

		msg = HIR"$N一招「"MAG"六神不安"HIR"」身如陀螺急转，展开轻功围着$n快速游走，忽然飞身而起，拍向$n" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

		msg = HIB"$N一招「"RED"倒行逆施"HIB"」突然纵起丈余，头下脚上，倒过身子，一掌拍向$n" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

		msg = HIM"$N一招「"HIY"力不从心"HIM"」含胸收腹，头缓缓低下，脚步沉重，右掌软绵绵的拍向$n" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		me->add_temp("apply/damage",-5000);
		me->add_temp("apply/attack",-580);
	}
	return 1;
}
