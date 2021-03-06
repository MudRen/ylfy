// tianwaifeiyin.c 天外飞音
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object *ob;
	int i, skill, damage;

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的内力不够。\n");

	if(me->query_skill("art",1)<450)
		return notify_fail("你的琴术不够。\n");

    if (! present("gu zheng", me))
 	return notify_fail("你要弹什么？\n"); 
	
	skill = me->query_skill("force");
	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");
	
	me->add("neili", -500);
	me->receive_damage("qi", 10);

	me->start_busy(3);
    message_vision(HIY "$N摆出了一张古筝，近地而坐，静静地将一曲「天外飞音」弹了起来，一时间，万具晖音，周围的人都沉静在一片琴音之中！\n" NOR, me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
	{
		if( !living(ob[i]) || ob[i]==me )
			continue;

		if(random(ob[i]->query_skill("art",1)) > me->query_skill("art",1))
		{
			tell_object(ob[i], HIC"你只觉听得心旷神怡，无比舒坦......\n"NOR);
			ob[i]->add("jing", 1);
		}
		else
		{
			damage = skill*3;
			ob[i]->receive_damage("jing",(int)random(damage)*2);

			if( (int)ob[i]->query("neili") < (int)me->query("max_neili"))
				{
				if( (int)ob[i]->query("neili") > 50000)
					{				
				    ob[i]->add("neili", -random(50000));
					}
				
				if( (int)ob[i]->query("jingli") > 1000)
					{				
				    ob[i]->add("jingli",-random(1000));
					}
				}
		tell_object(ob[i], HIR"你只觉听得心烦意乱，气血一阵翻腾，逆转到丹田......\n"NOR);
		}
	
	if( !me->is_killing(ob[i]) )
		me->fight_ob(ob[i]);

    if( !ob[i]->is_killing(me) )
	    ob[i]->kill_ob(me);
	}

	return 1;
}
