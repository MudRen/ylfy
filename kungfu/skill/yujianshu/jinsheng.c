//jinsheng by yushu 2001.2
//lilong alter 2002.01.12
 //modify by jzw /2006/1/27

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage, ap, dp;

	if ( !target ) target = offensive_target(me);
	if ( !target || !target->is_character() || !me->is_fighting(target) || !living(target))
		return notify_fail(HIW"你只能在战斗中使用。\n"NOR);
	if ( playerp(me) && me->query("family/family_name") != "蜀山派" ) return notify_fail("不是蜀山的不能用「御剑今生」！\n");
	if ( playerp(me) && me->query("shushan/jinsheng_perform") != 1 ) return notify_fail("你还没领会「御剑今生」！\n");
	if ( (int)me->query("max_neili") < 1500000 ) return notify_fail("你的内力修为太低。\n");
	if ( (int)me->query("neili") < 1500000 ) return notify_fail("你的内力不足。\n");
	if ( (int)me->query_skill("sword", 1) < 1500 ) return notify_fail("你的基本剑法等级不够，不能使用这一招！\n");
	if ( (int)me->query_skill("yujianshu", 1) < 1500 ) return notify_fail("你的御剑术等级不够，不能使用这一招！\n");
	if ( !(weapon = me->query_temp("weapon")) ) return notify_fail("你必须手持剑才能使用剑法。\n");
	if ( (int)me->query_skill("shushan-force", 1) < 900 ) return notify_fail("你的蜀山心法等级不够，不能使用这一招！\n");
	if ( me->query_skill_mapped("force") != "shushan-force" ) return notify_fail("没有蜀山心法无法驾驭剑气。\n");

	me->set("qi", 0);
	me->set("eff_qi", 0);
	me->set("jing", 0);
	me->set("eff_jing", 0);
	me->set("neili", 0);
	me->set("jingli", 0);

	message_vision(HIB"\n$N眼见不敌，想起了访宁桥上那首诗，心中默念：",me,target);
	message_vision(HIG"\n\n所有的这一切都只有等待来生了......",me,target);
	//message_vision(HIB"\n\n$N一念及此，身形与"+weapon->name()+NOR+HIB"化为一体直射$n～～～～～ \n\n"NOR,me,target);
	message_vision(HIB"\n\n$N一念及此，身形与手中长剑化为一体直射$n～～～～～ \n\n"NOR,me,target);

	ap = me->query_skill("yujianshu", 1);
	ap /= 10;
	ap = ap * ap;
	dp = target->query_skill("dodge", 1);
	dp /= 10;
	dp = dp * dp;
	
	if ( random(ap) < dp/2 ) 
	{
		message_vision(HIB"\n\n$n一见情势不妙，拼命向后纵越，竟然在狼狈不堪之际侥幸地躲过了这拼命的一式！！！\n\n"NOR, me, target);
		target->start_busy(random(30));
	}
	else
	{
		message_vision(HIB"\n\n$n不料$N如此决绝，竟然呆立当场，瞬间一道蓝光已在$n身上当胸穿过！！！\n\n"NOR, target ,me);
		if ( playerp(target) ) target->unconcious();
		else
		{
			damage = me->query("max_neili")/10;
			target->receive_damage("qi", damage, me);
			target->receive_damage("jing", damage, me);
		}
	}
	
	message_vision(HIR"\n\n半空中传来一声长叹：天绝我也～～～～～ \n\n"NOR,me);
	me->unconcious();
	return 1;
}

