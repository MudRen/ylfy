// jianzhang.c  
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, count;
	
	if ( !target ) target = offensive_target(me);
	if ( !target || !me->is_fighting() ) 
		return notify_fail("「桃花飞舞」只能在战斗中使用。\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");
	if ( me->query_skill("bibo-shengong",1) < 500 ) 
		return notify_fail("你的碧波神功等级不够, 不能使用「桃花飞舞」！\n");
	if ( (count = me->query_skill("yuxiao-jianfa", 1)) < 500 ) 
		return notify_fail("你的玉箫剑法等级不够, 不能使用「桃花飞舞」！\n");
	if( me->query_skill_mapped("sword") != "yuxiao-jianfa" )
	    return notify_fail("你没有激发玉箫剑法。\n");
	if ( me->query("neili") < 7000 ) 
		return notify_fail("你的内力不够，无法运用「桃花飞舞」！\n");
	if ( !objectp(weapon = me->query_temp("weapon")) ) 
		return notify_fail("手中无剑怎能使出「桃花飞舞」？\n");

	message_vision(HBMAG"$N使出桃花岛绝技「桃花飞舞」，身法陡然加快。落英缤纷！\n\n"NOR, me);
	count /= 50;
    if(count > 50 ) count = 50;
	me->add_temp("lianzhao", count);
	for ( i=0; i<count; i++ )
	{
		switch ( random(6) )
		{
			case 0: msg = HIM"人面桃花！\n" NOR;
					break;
			case 1: msg = HIR"万花齐落！\n" NOR;
					break;
			case 2: msg = HIY"漫天花雨！\n" NOR;
					break;
			case 3: msg = HIC"落花无意！\n" NOR;
					break;
			case 4: msg = HIG"百花齐放！\n" NOR;
					break;
			case 5: msg = HIB"花落无痕！\n" NOR;
					break;
		}
		message_vision(msg, me);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_REGULAR);
		me->add("neili", -100);
		me->delete_temp("lianzhao");
	}

	me->start_busy(2);
	return 1;
}
