//lilong alter 2002.01.12
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int i,j,k,u,damage;
	
	if ( !target ) target = offensive_target(me);
	if ( !target || !target->is_character() || target->is_corpse() || target==me ) 
		return notify_fail("��Ҫ����˭��\n");
	
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword") 
	    return notify_fail("������ֳֽ�����ʹ�ý�����\n");
	
    if ( (int)me->query_skill("songhe-sword", 1) < 500 ) 
		return notify_fail("����ɺ׽������𻹲�����ʹ����һ�л������ѣ�\n");
	
	if ( !me->is_fighting() ) 
		return notify_fail("����û���ڴ�ܣ�\n");
	if ( me->query_skill_mapped("sword") != "songhe-sword")
         return notify_fail("����뼤���ɺ׽�������ʹ�á��򽣾�����\n"); 
	if ( playerp(me) && me->query("family/family_name") != "��ɽ��" ) 
		return notify_fail("������ɽ�Ĳ����á��򽣾�����\n");  
	
	if ( playerp(me) && me->query("shushan/wanjian_perform") !=1 ) 
		return notify_fail("�㻹û��ᡸ�򽣾�����\n");
	
	if ( (int)me->query("max_neili") < 1500 ) 
		return notify_fail("����ڹ���Ϊ̫�\n");
	if ( (int)me->query("neili") < 1500 ) 
		return notify_fail("����������㣡\n");
	if ( (int)me->query("jing") < 50 ) 
		return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
	if ( me->query_skill_mapped("force") != "shushan-force" ) 
		return notify_fail("û����ɽ�ķ��޷���Ԧ������\n");
	if ( (int)me->query_skill("shushan-force", 1) < 500 ) 
		return notify_fail("�����ɽ�ķ��ȼ�����������ʹ����һ�У�\n");	
	
	k = (int)me->query_skill("songhe-sword", 1);
	u = k / 50;
    if (u > 50)	u = 50;

	k += (int)me->query_skill("sword",1);
	j = (int)target->query_skill("dodge",1);
	
	me->delete("env/brief_message");
	target->delete("env/brief_message");
	message_vision(HIC"\n$N��������һ����\n"NOR,me,target);
	message_vision(HIW"\n�򡫡�����������������\n"NOR,me,target);
	message_vision(HIC"\nһɲ�Ǽ�ǧ�򽣹��ƿն�������������$n\n"NOR,me,target);
	for ( i=0; i<=u; i++ )
	{
		if ( random(k+j) > j ) 
		{
			message_vision(HIY"\n$nһ������������һ��\n"NOR,me,target);
			damage = k+random(k);
			//target->receive_damage("qi", damage, me);
			//target->receive_wound("qi", damage/2, me);
			COMBAT_D->do_attack(me, target, weapon, TYPE_REGULAR, "", random(damage/3));
			//COMBAT_D->report_status(target);
			me->receive_damage("jing", 10);
			me->receive_damage("qi", 20);
		}
		else 
		{
			message_vision(HIY"\n$n�����������ò����ױܿ���һ�ֽ���\n"NOR,me,target);
			me->receive_damage("jing", 10);
			me->receive_damage("qi", 20);
		}
	}
	
	if ( !target->is_fighting(me) ) 
	{
		if ( living(target) ) 
		{
			if ( playerp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
	}
	target->start_busy(random(3));
	me->start_busy(random(3));
	return 1;
}
