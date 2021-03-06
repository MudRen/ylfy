// 剑动莫名	

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
	
	i = me->query_skill("wuming-jianfa", 1);        	
	j = me->query_skill("sword", 1);	
	times = (int)(me->query_skill("wuming-jianfa", 1)/100) - 1; 
    if(times > 50 )	times = 50;
	
	if( !target ) target = offensive_target(me);
	
    if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「剑动莫名」只能在战斗中使用。\n");	
	if ( !objectp(weapon=me->query_temp("weapon")) ) 
		return notify_fail("你必须使用武器才能使用「剑动莫名」！\n");     
	if ( base_name(weapon)!="/clone/weapon/yuenv" ) 
		return notify_fail("你必须手持越女朝阳剑才能使用「剑动莫名」！\n"); 
	if ( (int)me->query_str() < 35 ) 
		return notify_fail("你的臂力不够, 还不能使用这项绝技! \n");
	if ( (int)me->query_skill("sword",1) < 1000 ) 
		return notify_fail("你的基本剑法的火候还不到家, 不能使用这一绝技 !\n");	
	if ( me->query_skill_mapped("sword") != "wuming-jianfa")
         return notify_fail("你必须激发无名剑法才能使用「剑动莫名」！\n");       
	if ( (int)me->query_skill("wuming-jianfa", 1) < 500 ) 
		return notify_fail("你的无名剑法的火候还不到家, 不能使用这一绝技 !\n"); 	
	if ( (int)me->query("neili") < 50000 ) 
		return notify_fail("你的真气不够！\n");
	if ( (int)me->query("max_neili") < 500000 )	
		return notify_fail("你的内力修为不够！\n");
	if ( me->is_busy() ) 
		return notify_fail("你上一个动作还没有完成！\n");
	msg = MAG "\n$N脸现幽思,往事如潮涌上心头,手中剑望空斜指一股怨气从剑尖散发弥漫开来！\n" NOR;	
	message_vision(msg, me);
	me->clean_up_enemy();
	ob = me->select_opponent();
	me->add_temp("apply/strength", i);	
	me->add_temp("apply/attack", j);
    me->add_temp("lianzhao", times);	
	
	for ( n=0; n<times; n++ )	
	{
		if ( !ob ) break;
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);         
	}
	me->add_temp("apply/strength", -i);	
	me->add_temp("apply/attack", -j);
    me->delete_temp("lianzhao");	
	me->add("neili", -500*times);	
	me->start_busy(random(2)+3);	
	if ( ob && !ob->is_busy() ) ob->start_busy(random(2)+1);	
    return 1;
}
