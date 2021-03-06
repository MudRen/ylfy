//吐雾

#include <ansi.h>


inherit F_SSERVER;


int perform(object me, object target)
{
	
	if( !target ) target = offensive_target(me);
	if( !target
		|| !target->is_character()
		|| !me->is_fighting(target) )
		return notify_fail("吐雾只能在战斗中使用。\n");
	if( target->query_temp("block_msg") )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");
  
	message_vision(HIW"只见$N"HIW"口一张，一团白色巨热的浓雾径直喷向$n!\n" NOR, me, target);
	
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) 
	{
		message_vision(HIR "$n"HIW"一下啥也看不清了,只得采取守式，不敢妄动！\n" NOR, me, target);
		target->set_temp("block_msg/all",1);
		call_out("tuwu_end", 3+random(12), me, target);
		target->start_busy(6);
	}
	else 
	{
		message_vision(HIC "$n"HIC"身形一闪，跃出了浓雾的攻击范围！\n" NOR, me, target);	
		me->start_busy(1); 	
	}

	return 1;
}

void tuwu_end(object me, object target)
{
	if ( !objectp(target) ) return;
	//if ( environment(me) != environment(target) ) return;
	//target->enable_player();
	target->delete_temp("block_msg/all");
	message_vision("$N眼前的迷雾渐渐散开，$N暗暗松了口气。\n", target);	
	write(HIR"你眼前的迷雾散尽，终于可以看到周围的情景了。\n"NOR);
	return;
}
