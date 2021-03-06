// 圣火燎原 liaoyuan.c	

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

// 颜色
nosave string *ansi_arg = ({ RED, GRN, YEL, BLU, MAG, CYN, WHT, HIR, HIG, HIY, HIB, HIM, HIC, HIW });

int perform(object me, object target)
{
	object weapon,ob;
	int skill, times, i, max;
	string msg;

	if ( !target ) target = offensive_target(me);
	if ( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「圣火燎原」只能在战斗中使用。\n");
	if ( !objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword" )
		return notify_fail("「圣火燎原」必须用剑才能施展。\n");
	if ( me->query_skill_mapped("sword") != "shenghuo-ling")
         return notify_fail("你必须激发圣火令法才能使用「圣火燎原」！\n");       
	if ( (int)me->query_skill("shenghuo-ling", 1) < 150 )
		return notify_fail("你的「圣火令法」不够娴熟，不会使用「圣火燎原」。\n");
	if ( (int)me->query("neili") < 30000  ) 
		return notify_fail("你的内力不够。\n");

	skill = me->query_skill("shenghuo-ling", 1);
	max = sizeof(ansi_arg);
	times=(int)skill/50;
	if(times > 50) times = 50;
	me->add_temp("lianzhao", times);
	for ( i=0; i<times; i++ )
	{
		if ( me->query("neili") < 500 ) break;
		me->add("neili", -500);
		me->clean_up_enemy();                        	
		ob = me->select_opponent();
		if ( ob = me->select_opponent() )
		{
			msg = ansi_arg[random(max)]+"$N眼中射出一道青芒，飞身而前，手中圣火令相互一击,奇招怪式犹如燎原之火般向$n攻去！\n"NOR;
			message_vision(msg, me, target);
			COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
		}
	}
    me->delete_temp("lianzhao");
	if ( me->is_fighting() ) me->start_busy(random(3));
	
	return 1;
}
