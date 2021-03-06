#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i;
	string *style = (
	{
		HIR "回形天罡－－$N探出手中$w，剑风呼啸，刺向$n！"NOR,
		HIB"酣烟如溪－－$N手中$w化做剑影重光，将$n团团围住！"NOR,
		HIY"旺故纵然－－$N向前一纵，手中$w持一字状，向$n猛扑过去！"NOR,
		HIG"七星移位－－$N欺身急进，互换身位，手中$w头尾齐出，分打$n的两处要害！"NOR,
		HIM"风雨血腥－－$N手中$w一顿，暗蓄内力，点向$n的手指！"NOR,
		HIW"悠然无措－－$N身形连纵连跃，手中$w威势陡增，连连向$n打去！"NOR,
		HIC"一切随缘－－$N身影绕着$n连续晃动，手中$w连发，扫向$n的罩门！"NOR
	});
	object ob,*obs;
	if( !target ) target = offensive_target(me);
	if( !target ||	!target->is_character() ||	!me->is_fighting(target) )
		return notify_fail("［七星连阵］只能对战斗中的对手使用。\n");
	if(!pointerp(obs=me->query_team()) || !me->is_team_leader())
		return notify_fail("只有队伍领袖才可以发动此式！\n");
	if(me->query_skill_mapped("array") != "qixing-array")
		return notify_fail("你的队伍没有用北斗七星阵！\n");
	if(me->query_skill("qixing-array",1)<sizeof(obs)*10)
		return notify_fail("你的阵法不够！\n");
	if(sizeof(obs) >=7 )
		return notify_fail("队伍最多七个人！！\n");
	for(i=0; i<sizeof(obs); i++)
	{
		if(!obs[i]) return notify_fail("你需要从新组合队伍。\n");
		if(environment(obs[i]) != environment(me)) return notify_fail("你队伍成员不全在你身边。\n");
		if(!obs[i]->query_skill("quanzhen-jianfa",1)) return notify_fail("你队伍中有人不会全真剑法。\n");
		if(!objectp(ob=obs[i]->query_temp("weapon"))) return notify_fail("你的队伍中有人没有兵器！\n");
		if(ob->query("skill_type") != "sword") return notify_fail("你的队伍中有人没有用剑法！\n");
		if(obs[i]->query_skill_mapped("sword") != "quanzhen-jianfa") return notify_fail("你的队伍中有人没有用全真剑法！\n");
	}
	message_vision(HIY+"\n\n$N高喝一声：－－北－－斗－－七－－星－－阵－－！！\n"+HIW+"--------------------------------------七星连阵！！\n\n"NOR,me);
	for(i=0; i<sizeof(obs); i++)
	{
		ob=obs[i]->query_temp("weapon");
		msg = style[i];
		extra = obs[i]->query_skill("sword");
		extra *= (i+1);
		obs[i]->add_temp("apply/attack", 2*extra);
		obs[i]->add_temp("apply/damage", 2*extra);
		COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
		obs[i]->kill_ob(target);
		obs[i]->add_temp("apply/attack", -2*extra);
		obs[i]->add_temp("apply/damage", -2*extra);
		obs[i]->start_busy(2);
	}
	return 1;
}
