// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i,attack_time;
	object weapon;
	
	extra = me->query_skill("hujia-dao",1); 
	attack_time = me->query_skill("hujia-dao",1) / 100; 
	if(attack_time>50) attack_time=50;
	
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���ҵ�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
    if ( me->query_skill_mapped("blade") != "hujia-dao")
         return notify_fail("����뼤�����ҵ�������ʹ�á�������������\n");      
    if( (int)me->query_skill("hujia-dao", 1) < 500 )      	
		return notify_fail("��ĺ��ҵ���������죬�����õ���������\n");
    if ( (int)me->query("neili") < 25000 ) 
		return notify_fail("�������������\n");
           	            	
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	me->add_temp("lianzhao", attack_time);
	
	msg = HIR  "$Nһҧ�������϶����ӿ죬ͬʱʹ���ۺ��ҵ����Уݵĵ������������е�"+ weapon->name() +" һ������һ���������Ļ���$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIR "��һƬ�����У�һ�����˹���\n" NOR;
    message_vision(msg, me, target);
	for(i=0;i < attack_time;i++)
	{
	msg = HIY "$Nҧ�����أ�һ�������˹�����\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->delete_temp("lianzhao");
	me->add("neili", -100*attack_time);
	me->start_busy(5);
	return 1;
}

