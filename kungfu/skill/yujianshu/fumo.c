//fumo by greenwc
//fomo by yushu�޸�
//lilong alter 2002.01.08
#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int i,j,e,damage,damagea;

	if ( !target ) target = offensive_target(me);
	if ( !target
		|| !target->is_character()
		|| target->is_corpse()
		|| target==me)
		return notify_fail("��Ҫ����˭��\n");
	if ( !me->is_fighting(target) ) return notify_fail("����û���ڴ�ܣ�\n");
	if ( playerp(me) && me->query("family/family_name") != "��ɽ��" ) return notify_fail("������ɽ�Ĳ����á�������ħ����\n");
	if ( (int)me->query("max_neili") < 20000 ) return notify_fail("���������Ϊ̫�\n");
	if ( (int)me->query("neili") < 20000 ) return notify_fail("����������㣡\n");
	if ( (int)me->query("jing") < 100 ) return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
	if ( !(weapon = me->query_temp("weapon")) ) return notify_fail("������ֳֽ�����ʹ�ý�����\n");
	if ( (int)me->query_skill("shushan-force", 1) < 900 ) return notify_fail("�����ɽ�ķ��ȼ�����������ʹ����һ�У�\n");
	if ( me->query_skill_mapped("force") != "shushan-force" ) return notify_fail("û����ɽ�ķ��޷���Ԧ������\n");

	i = (int)me->query_skill("sword", 1);
	if ( i < 1500 ) return notify_fail("��Ļ����������𻹲�����ʹ����һ�л������ѣ�\n");
	i = (int)me->query_skill("yujianshu", 1);
	j = (int)target->query_skill("dodge", 1);
	e = i + j;
	if ( i < 1500 )
		return notify_fail("������������𻹲�����ʹ����һ�л������ѣ�\n");

	me->delete("env/brief_message");
	target->delete("env/brief_message");
	//message_vision(HIC"\n$N����Ĭ�������ھ�������"+weapon->name()+NOR+HIC"��ʱ��ϼ�����䣬һ�С�������ħ��ֱն$n��\n\n"NOR,me,target);
	message_vision(HIC"\n$N����Ĭ�������ھ������г�����ʱ��ϼ�����䣬һ�С�������ħ��ֱն$n��\n\n"NOR,me,target);
	
	if ( random(e) > j )
	{       
		damage = i+random((int) me->query("max_neili"))/30;
		damagea = i+random((int) me->query("max_neili"))/50;
		target->receive_damage("qi", damage, me);
		target->receive_damage("jing", damagea, me);
		target->receive_wound("qi", damage/10, me);
		me->receive_damage("jing", 10000);
		me->receive_damage("qi", 10000);
		me->receive_wound("qi", 1000);
		me->add("neili", -10000);
		COMBAT_D->report_status(target);
		
		if ( !target->is_fighting(me) ) 
		{
			if ( living(target) )
			{
				if( playerp(target) ) target->fight_ob(me);
				else target->kill_ob(me);
			}
		}
	}

	target->start_busy(random(3)+1);
	me->start_busy(random(3)+1);
	return 1;
}
