// tianwaifeiyin.c �������
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
		return notify_fail("�������������\n");

	if(me->query_skill("art",1)<450)
		return notify_fail("�������������\n");

    if (! present("gu zheng", me))
 	return notify_fail("��Ҫ��ʲô��\n"); 
	
	skill = me->query_skill("force");
	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! \n");
	
	me->add("neili", -500);
	me->receive_damage("qi", 10);

	me->start_busy(3);
    message_vision(HIY "$N�ڳ���һ�Ź��ݣ����ض����������ؽ�һ�����������������������һʱ�䣬�����������Χ���˶�������һƬ����֮�У�\n" NOR, me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
	{
		if( !living(ob[i]) || ob[i]==me )
			continue;

		if(random(ob[i]->query_skill("art",1)) > me->query_skill("art",1))
		{
			tell_object(ob[i], HIC"��ֻ�������Ŀ��������ޱ���̹......\n"NOR);
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
		tell_object(ob[i], HIR"��ֻ�������ķ����ң���Ѫһ���ڣ���ת������......\n"NOR);
		}
	
	if( !me->is_killing(ob[i]) )
		me->fight_ob(ob[i]);

    if( !ob[i]->is_killing(me) )
	    ob[i]->kill_ob(me);
	}

	return 1;
}
