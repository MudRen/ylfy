
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i, attack_time;
	object weapon;

	weapon = me->query_temp("weapon");
	extra = (int)me->query_skill("ittouryu",1);	
	attack_time = (int)me->query_skill("ittouryu",1)/100;
	
	if(attack_time>50) attack_time=50;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�۵����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ( me->query_skill("ittouryu",1) < 300)
		return notify_fail("��ģ�һ���������ݻ��������죡\n");
	if ((int)me->query_skill("shayi-xinfa", 1) < 500)
		return notify_fail("���ɱ���ķ���򲻹���\n");
	if ( me->query_skill_mapped("blade") != "ittouryu")
		return notify_fail("����뼤����һ���������ݲ���ʹ�á����񡹣�\n");
	if ( me->query_skill_mapped("force") != "shayi-xinfa")
		return notify_fail("����뼤��ɱ���ķ�����ʹ�á����񡹣�\n");
	if( (int)me->query("neili") < 6000 )
		return notify_fail("�������������\n");
	
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	me->add_temp("lianzhao", attack_time);
	
	msg = HIR  "$Nʹ����Բ����ն���е����Ͼ�����������"+ weapon->name() +"��������Ļ��ߣ���ն$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	for(i=0; i<attack_time; i++)
	{
		msg = CYN "$N�������񣬵����ݺᣡ\n" NOR;
		COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
		me->add("neili",-100);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->delete_temp("lianzhao");
	me->start_busy(4);
	return 1;
}
