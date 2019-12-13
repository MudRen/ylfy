// bidu.c 逼毒
// marry 99.9
#include <ansi.h>

int exert(object me, object target)
{
	int time = this_player()->query_condition("killer");
	if( me->is_fighting() )
		return notify_fail("战斗中运功逼毒？找死吗？\n");

	if ((int)me->query_skill("wangran-xinfa", 1) < 100)
		return notify_fail("你的内功修为还不够。\n");
	if( (int)me->query("neili") < 500 || (int)me->query("max_neili") < 500 )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 10 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
	if( me->query_condition("qidu") || me->query_condition("xx_poison")
	        || me->query_condition("zhua_poison") || me->query_condition("snake_poison")
	        || me->query_condition("rose_poison") || me->query_condition("ninemoonpoison")
	        || me->query_condition("tian") ||  me->query_condition("zhua_poison")
	        || me->query_condition("iceshock") || me->query_condition("ice_poison")
	        || me->query_condition("xiake_ming"))
	{
		write( HIY "你全身放松，坐下来开始运功逼毒。\n" NOR);
		message("vision",
		        HIW + me->name() + "吐出一口腥臭的瘀血，脸色看起来好多了。\n" NOR,
		        environment(me), me);
		if (this_player()->query_condition("killer"))
		{
			this_player()->clear_condition();
			this_player()->apply_condition("killer", time);
		}
		else
		{
			me->clear_condition();
		}
		me->add("qi",-(int)me->query_skill("force")*5);
		me->add("neili",-500);
		me->start_busy(5);
	}
	else
	{
		write( HIW "你运起妄然心法逼毒，可是毫无反应。\n" NOR);
		me->add("neili",-500);

	}
	return 1;
}
