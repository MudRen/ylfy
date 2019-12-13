// 金蛇横空
// bye jfeng

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon, ob;
	string msg;
	int i,j,times,n;

	i = me->query_skill("jinshe-jian", 1);
	j = me->query_skill("sword", 1);
    times = me->query_skill("jinshe-jian",1)/100;
	if(times > 50) times = 50;
	
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「金蛇横空」只能在战斗中使用。\n");
	if ( !me->query_temp("weapon") )
		return notify_fail("你必须使用武器才能使用「金蛇横空」！\n");
	if ( !objectp(weapon=me->query_temp("weapon")) || !(weapon->id("jinshe jian")) || sscanf(base_name(weapon), "/d/npc/m_weapon/%*s") )
		return notify_fail("你必须手持金蛇剑才能使用「金蛇横空」！\n");
	if ( (int)me->query_str() < 32 )
		return notify_fail("你的臂力不够, 还不能使用这项绝技! \n");
	if ( (int)me->query_skill("sword",1) < 1000 )
		return notify_fail("你的基本剑法的火候还不到家, 不能使用这一绝技 !\n");
	if ( (int)me->query_skill("jinshe-jian",1) < 500 )
		return notify_fail("你的金蛇剑法的火候还不到家, 不能使用这一绝技 !\n");
	if ( me->query_skill_mapped("sword") != "jinshe-jian" &&  me->query_skill_mapped("parry") != "jinshe-jian")
		return notify_fail("你必须激发金蛇剑法才能使用「金蛇横空」！\n");
	if ( (int)me->query("neili") < 5000 )
		return notify_fail("你的真气不够！\n");
	if( (int)me->query("max_neili") < 50000 )
		return notify_fail("你的内力修为不够！\n");

	msg = HIY "\n$N提气纵身，手中金蛇剑一圈一划,金蛇剑法绝技「金蛇横空」已然递出，顿时剑芒暴涨漫天蛇形剑气铺天盖地狂卷而下似乎连空气都要撕裂！\n" NOR;
	message_vision(msg, me);
	me->add_temp("apply/strength", i);
	me->add_temp("apply/attack", j);
	me->add_temp("lianzhao", times);
	for ( n=0; n<times; n++ )
	{
		me->clean_up_enemy();
		ob = me->select_opponent();
		if ( !ob ) break;
		msg = HIR "\n剑光急闪，剑气弥漫.....！\n" NOR;
		message_vision(msg, me);
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);
	}
	me->add_temp("apply/strength", -i);
	me->add_temp("apply/attack", -j);
	me->delete_temp("lianzhao");
	me->add("neili",-100*times);
	me->start_busy(4);
	if ( ob && !ob->is_busy() ) ob->start_busy(random(2)+1);
	return 1;
}
