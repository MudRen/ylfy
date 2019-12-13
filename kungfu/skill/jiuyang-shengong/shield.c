// shield.c 九阳护体神功

#include <ansi.h>

inherit F_CLEAN_UP;
int check_fight(object me);
void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能用九阳神功来提升自己的防御力。\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("你的真气不够。\n");

	if ((int)me->query_skill("jiuyang-shengong", 1) < 40)
		return notify_fail("你的九阳神功等级不够。\n");

	/* if (!me->query("jiuyangok"))
	         return notify_fail("你虽然听说过九阳神功是护体神功，但不会用。\n");*/
	if( (int)me->query_temp("liuyun") )
		return notify_fail(HIG"你已经在默运流云水袖神功了。\n");

	if( (int)me->query_temp("qzj_tong") )
		return notify_fail("你已经在运同归剑了。\n");
	if( me->query_temp("fumo")   )
		return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");
	if( me->query_temp("powerup")   )
		return notify_fail("你正在使用战斗力提升！\n");
	if( me->query_temp("jingang")   )
		return notify_fail("你正在使用大金刚拳的特殊攻击「大金刚神通」！\n");
	if( me->query_temp("fanzhen")   )
		return notify_fail("你正在运用「金刚不坏体神功」！\n");
	if( (int)me->query_temp("jiuyin/powerup") )
		return notify_fail("你已经在运九阴真功中了。\n");
	if( (int)me->query_temp("hslj/powerup") )
		return notify_fail("你已经在运万法归宗中了。\n");
	if( me->query_temp("yuxiao/tianwu") )
		return notify_fail("你正在运用「凤凰天舞」心法！\n");

	if((int)me->query_temp("tzzf") )
		return notify_fail("你已经在掌刀的运功中。\n");

	if ((int)me->query_temp("shield"))
		return notify_fail("你已经在运功中了。\n");
	if(me->query_temp("wdpowerup") )
		return notify_fail("你现在正在使用「五毒神功」的绝技。\n");
	if(me->query_temp("zhuihun/lpf"))
		return notify_fail("你正在使用五毒追魂钩之「乱披风」\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	// me->receive_damage("qi", 0);

	message_vision(HIR "$N" HIR "默念九阳神功的口诀：他"
	               "强由他强，清风拂山冈。他横任他横，"
	               "明月照大江……\n刹那间只见$N"
	               HIR "全身顿时浮现出一层刚猛的劲气，将$P"
	               HIR "全全笼罩。\n" NOR, me);



	me->add_temp("apply/dodge", skill/3);
	tell_object(me,HIG"你的轻功提高了!\n"NOR);
	me->add_temp("apply/damage", skill/3);
	tell_object(me,HIG"你的杀伤力提高了!\n"NOR);
	me->add_temp("apply/attack", skill/3);
	tell_object(me,HIG"你的攻击力提高了!\n"NOR);
	me->add_temp("apply/armor", skill );
	tell_object(me,HIG"你的防御力提高了!\n"NOR);
	me->set_temp("shield", 1);
	check_fight(me);
me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill  :), skill);

	if (me->is_fighting()) me->start_busy(2);

	return 1;
}

int check_fight(object me)
{
	// if (me->query("qi") < 0) return;  //解决 气血为负数 不晕不死的bug
	//if (me->query("jing") < 0) return;
	if (!me || !(int)me->query_temp("shield")) return 0;
	if (!me->is_ghost() && living(me)
	        && me->is_fighting() && me->query("neili") > 500
	        && me->query_skill_mapped("force") == "jiuyang-shengong")
	{
		if(me->query("qi") < (int)me->query("max_qi"))
		{
			message_vision(HIR"$N运起九阳神功，身上的伤好了很多!\n"NOR,me);
			me->add("neili", -200);
			me->add("eff_qi",me->query_skill("jiuyang-shengong"));
			if (me->query("eff_qi") > me->query("max_qi")) me->set("eff_qi", me->query("max_qi"));
			me->add("qi",me->query_skill("jiuyang-shengong"));
			if (me->query("qi") > me->query("eff_qi")) me->set("qi", me->query("eff_qi"));
		}

		if(me->query("jing") < (int)me->query("max_jing"))
		{
			message_vision(HIR"$N运起九阳神功，身上的伤好了很多!\n"NOR,me);
			me->add("neili", -200);
			me->add("eff_jing",me->query_skill("jiuyang-shengong"));
			if (me->query("eff_jing") > me->query("max_jing")) me->set("eff_jing", me->query("max_jing"));
			me->add("jing",me->query_skill("jiuyang-shengong"));
			if (me->query("jing") > me->query("eff_jing")) me->set("jing", me->query("eff_jing"));
		}
	}
	if ( me->query_skill_mapped("parry") == "qiankundanuoyi"
	        && me->is_busy()
	        && me->is_fighting()
	        && me->query_skill_mapped("force") == "jiuyang-shengong"
	        && random(1)==0 )
	{
		message_vision(HIC"$N暗运乾坤大挪移，本来忙乱的动作快了起来!\n"NOR, me);
		me->start_busy(1);
	}

	call_out("check_fight", 2, me);
	return 1;
}

void remove_effect(object me, int amount)
{
	if (!me) return;
	if (me->query_temp("shield"))
	{
		me->add_temp("apply/dodge", -amount);
		me->add_temp("apply/damage", -amount);
		me->add_temp("apply/attack", -amount);
		me->add_temp("apply/armor", -amount);
		me->delete_temp("shield");
		tell_object(me, "你的九阳神功运行完毕，将内力收回丹田。\n");
	}
}

