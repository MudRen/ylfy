// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i, attack_time;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("̫�������������־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
		
	if ( me->query_skill_mapped("sword") != "taiji-jian")
         return notify_fail("����뼤��̫����������ʹ�á������־���\n");
     
	if( (int)me->query("neili") < 400  ) 		
		return notify_fail("�������������\n");

	if( (int)me->query_skill("taiji-jian", 1) < 150 )
		return notify_fail("���̫������������죬�����á������־���\n");
    if (!(int)me->query("breakup"))
        return notify_fail("���ζ�����δͨ,�޷�ʹ��["+HIR+"��"+NOR+"]\n"NOR,); 		

   if( (int)me->query_skill("taiji-shengong", 1) < 60 )    	
        return notify_fail("���̫���񹦲�����죬����ʹ�á������־���\n");	

	extra = me->query_skill("taiji-jian",1) / 20;
	extra += me->query_skill("taiji-shengong",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
    msg = HIR  "$Nʹ����̫�������Уݵġ������־������е�"+ weapon->name() +" һ������һ�л���Ȧ���������Ļ���$n��" NOR;	
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIW "����һ������ʧ��������\n" NOR;
    message_vision(msg, me, target);
	attack_time = extra/4;
	if(attack_time > 50 ) attack_time = 50;
	me->add_temp("lianzhao", attack_time);
	for(i=0;i<attack_time;i++)
	{
	msg = HIY "$N�ý�����һ��Ȧ��һ��������������\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	i = extra/4;
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->delete_temp("lianzhao");
	me->add("neili", - 100 * i);
	me->start_busy(3);
	return 1;
}

