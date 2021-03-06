// lian.c 嵩山剑法「连」字诀
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int attack_time;
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「连」字诀只能对战斗中的对手使用。\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
	if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query_skill("songshan-jian", 1) < 40 )
		return notify_fail("你的嵩山剑法极不够娴熟，不会使用「连」字诀。\n");
	if (!me->visible(target))    
		return notify_fail("你看不到"+target->name()+"。\n");
	if (me->query_temp("perform"))  
		return notify_fail("你上一个招式还没完成!\n");
	if ( me->query("neili")<100 )   
		return notify_fail("你的内力不足!\n");
	if( me->is_busy()) 
		return notify_fail("你现在正忙着。\n");
	msg = HIY "$N使出嵩山剑法「连」字诀，招式陡然变快。\n" NOR;
	if( !living(target) || random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/10 )
	{
		attack_time = (int)me->query_skill("songshan-jian", 1) / 50;
		if(attack_time < 1) attack_time = 1;
		if(attack_time > 50) attack_time = 50;
        me->start_call_out( (: call_other, __FILE__, "do_attack", me, target,weapon,attack_time :), 1);
		if (me->query("neili")<150)
			me->set("neili",0);
		else
			me->add("neili", -150);
		me->set_temp("perform",1);
	}
	else
	{
		msg += HIY  "可是$p"+ HIY +"看破了$P的企图，并没有上当。\n" NOR;
		me->start_busy(1);
	}
	message_vision(msg, me, target);
	return 1;
}

void do_attack(object me,object target,object weapon,int attack_time)
{
	int i;
	if (!me) return;
	me->delete_temp("perform");
	if (!living(me) || !target ) return;
	if (weapon == me->query_temp("secondary_weapon") )
		me->set_temp("secondly_weapon",1);
	if (!weapon->query("equipped"))
	{
		me->start_busy(3);
		return;
	}
	if (environment(me)!=environment(target)) return;
	me->add_temp("lianzhao", attack_time);
	for(i = 0; i < attack_time; i++)
		if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0)
		{
			me->set_temp("action_msg","紧接着");
			if (!weapon->query("equipped"))
			{
				me->start_busy(2);
				return;
			}
			if (me->query_skill_mapped("sword")!="songshan-jian")
			{
				me->start_busy(3);
				return;
			}
			COMBAT_D->do_attack(me, target, weapon, 0);
			me->start_busy(1);
		}
		else break;
	me->delete_temp("secondly_weapon");
	me->delete_temp("lianzhao");
	if (i) message_vision(CYN " 结果$p被$P攻了个措手不及！\n" NOR, me, target);
}
