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
	
	extra = me->query_skill("feixian-jian",1) / 25;
    	attack_time = extra/4;
	if (attack_time > 50) attack_time = 50;
	
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if ( me->query_skill("feixian-jian",1) < 100) 
			return notify_fail("��ķ��ɽ������������죡\n");
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
        return notify_fail("ʹ��������ɱ�������һ�ѽ���\n");
	 if ( me->query_skill_mapped("sword") != "feixian-jian")
         return notify_fail("����뼤�����ɽ�������ʹ�á�������ɡ���\n");   
	if( (int)me->query("neili") < 5000  ) 
		return notify_fail("�������������\n");
	me->add_temp("apply/attack", extra);	
	me->add_temp("lianzhao", attack_time);
	msg = RED  "$N��̤�����²����ݣ�ͬʱʹ���۷��ɽ����ݵľ��裭��������ɣ����е�"+ weapon->name() +"����һ�����磬�����Ļ���$n��" NOR;

	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIW "����һ������ʧ��������\n" NOR;
    message_vision(msg, me, target);

	for(i=0;i < attack_time;i++)
	{
	msg = RED "$N����ͻת�������طɣ�\n" NOR;

	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->delete_temp("lianzhao");
	me->add("neili", -100*attack_time);
	me->start_busy(4);
	return 1;
}
