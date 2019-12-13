// bashi.c ������ ��ʽ��һ

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object target, int aamount, int damount);

int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);
	
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("����ʽ��һ��ֻ����ս����ʹ�á�\n");
	if( (int)target->query_temp("bashi") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");
	if( (int)me->query("neili") < 200 ) 
		return notify_fail("��������������ߣ�\n");
	if( (int)me->query_skill("linji-zhuang", 1) < 40) 
		return notify_fail("����ټ�ʹ��ׯ����Ϊ����������ʹ�ð�ʽ��һ! \n");
	if( (int)me->query_skill("jinding-zhang",1) <100) 
		return notify_fail("��Ľ����Ƶİ�ʽ��ϰ��ȫ���޷�ʹ�ð�ʽ��һ��\n");
	if( me->query_skill_mapped("unarmed") != "jinding-zhang")  
		return notify_fail("��û�м��������ƣ��޷�ʹ�ð�ʽ��һ��\n");
//	if( !target->is_killing(me) ) target->kill_ob(me);
	
	msg = HIY "$N��������һ����������ȫ��Ĺ�����˫�ƣ�ֻ����$N����һ���죡\n" NOR;
//        me->start_busy(1);
	if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/2)
	{
		if( me->is_fighting() ) 
		{
			damage = (int)me->query_skill("unarmed")/2;
			damage = damage +  (int)me->query_skill("jinding-zhang", 1);
			target->set_temp("bashi", 1);
			target->add_temp("apply/attack", -damage/3);
			target->add_temp("apply/dodge", -damage/3);
			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage, me);
			msg += HIR "$N�ڿն���ʹ���ˡ���ʽ��һ�����������Ӱ��Ʈ������������$nȫ�������λ��\n" NOR;
			me->start_call_out( (: call_other, __FILE__, "remove_effect",target,damage/3, damage/3:), damage/30); 
			me->add("neili",-100);
			me->start_busy(1+random(2));
			target->start_busy(1+random(3));
		}
	}             
	else 
	{
		msg += CYN"����$p�͵���ǰһԾ,������$P�Ĺ�����Χ��\n"NOR;
		me->start_busy(1);              
	} 
	message_vision(msg, me, target );
	return 1;
}

void remove_effect(object target,int aamount, int damount)
{
	if ( !objectp(target) ) return;
	target->add_temp("apply/attack", aamount);
	target->add_temp("apply/dodge", damount);
	target->delete_temp("bashi");              
	message_vision(HIG"$N�����ҵĹ����а����˳�������������,��ס�˽Ų�\n"NOR, target);
}
