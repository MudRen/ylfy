// ����Ī��	

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
		return notify_fail("������Ī����ֻ����ս����ʹ�á�\n");	
	if ( !objectp(weapon=me->query_temp("weapon")) ) 
		return notify_fail("�����ʹ����������ʹ�á�����Ī������\n");     
	if ( base_name(weapon)!="/clone/weapon/yuenv" ) 
		return notify_fail("������ֳ�ԽŮ����������ʹ�á�����Ī������\n"); 
	if ( (int)me->query_str() < 35 ) 
		return notify_fail("��ı�������, ������ʹ���������! \n");
	if ( (int)me->query_skill("sword",1) < 1000 ) 
		return notify_fail("��Ļ��������Ļ�򻹲�����, ����ʹ����һ���� !\n");	
	if ( me->query_skill_mapped("sword") != "wuming-jianfa")
         return notify_fail("����뼤��������������ʹ�á�����Ī������\n");       
	if ( (int)me->query_skill("wuming-jianfa", 1) < 500 ) 
		return notify_fail("������������Ļ�򻹲�����, ����ʹ����һ���� !\n"); 	
	if ( (int)me->query("neili") < 50000 ) 
		return notify_fail("�������������\n");
	if ( (int)me->query("max_neili") < 500000 )	
		return notify_fail("���������Ϊ������\n");
	if ( me->is_busy() ) 
		return notify_fail("����һ��������û����ɣ�\n");
	msg = MAG "\n$N������˼,�����糱ӿ����ͷ,���н�����бָһ��Թ���ӽ���ɢ������������\n" NOR;	
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
