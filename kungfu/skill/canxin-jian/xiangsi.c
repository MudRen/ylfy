//xiangxi.c  ��˼����

#include <ansi.h>
#include <combat.h>
#include <condition.h>
inherit F_SSERVER;

int perform(object me, object target)
{       
	int times, i;
	object weapon = me->query_temp("weapon");
	
	if ( !target ) target = offensive_target(me);
	if ( !target || !target->is_character() || target->is_corpse() || target==me) 
		return notify_fail("��Ҫ��˭ʩչ����˼��������\n");
	if ( !weapon ) 
		return notify_fail("����˼�������ý�����ʹ����\n");
	if ( !me->is_fighting(target) ) 
		return notify_fail("����˼������ֻ����ս����ʹ�ã�\n");
	if ( playerp(me) && me->query("family/family_name") != "��ɽ��" ) 
		return notify_fail("����ɽ�����á���˼��������\n");
	if ( playerp(me) && me->query("shushan/xiangsi_perform") !=1 ) 
		return notify_fail("û�����ĵ���ᣬ�ò��˲���ġ���˼��������\n");
	if ( me->query_skill_mapped("force")!="shushan-force" ) 
		return notify_fail("����˼��������������ɽ�ķ������ӣ�\n");
	if ( me->query_skill_mapped("sword")!="canxin-jian" ) 
		return notify_fail("���Ľ������뼤���ڻ��������ϣ��ſ���ʹ�á���˼��������\n");
	if ( (int)me->query("max_neili") < 10000 ) 
		return notify_fail("�������������\n");
	if ( (int)me->query("neili") < 5000 ) 
		return notify_fail("����������㣡\n");
	if ( (int)me->query("jing") < 300 ) 
		return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
	if ( (int)me->query_skill("shushan-force", 1) < 500 ) 
		return notify_fail("�����ɽ�ķ���Ϊ��������ʹ����һ�л������ѣ�\n");
	if ( (int)(times=me->query_skill("canxin-jian", 1)) < 900) 
		return notify_fail("��Ĳ��Ľ���Ϊ��������ʹ����һ�л������ѣ�\n");
	
	message_vision(MAG"$N��˼�����͵�ʩ�����Ľ��ľ��С���˼����������$n��������������\n\n"NOR,me,target);
	times /= 90;
	if( times > 50 ) times = 50;
	me->add_temp("lianzhao", times);
	
	for ( i=0; i<times; i++ )
	{
		switch ( random(4) )
		{
			case 0:
				message_vision(HIG"$n�������е���˼֮���Ⱦ�������鶾��\n"NOR,me,target);
				target->apply_condition("xiangsi", 20);
				break;
			case 1:
				message_vision(HIG"һ�ɾ�������$n��$n�ƺ����˵���⣡\n"NOR,me,target);
				target->apply_condition("drunk", 20);
				break;
			case 2:
				message_vision(HIG"��������Ϊ���\n"NOR,me,target);
				message_vision(HIG"���޺ۣ�����ţ��������³������\n"NOR,me,target);  
				target->apply_condition("xiang_air", 20);
				break;
		}
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	}
	me->start_busy(1+random(3));
	target->start_busy(1+random(3));
	message_vision(HIG"$N�ġ���˼�������ù���ϣ����ص���,�����չ�.\n"NOR,me,target);
	me->receive_damage("qi", 100);
	me->receive_damage("jing", 100);
	me->add("neili", -100*times);
	me->delete_temp("lianzhao");
	return 1;
}
