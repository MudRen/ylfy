//jinsheng by yushu 2001.2
//lilong alter 2002.01.12
 //modify by jzw /2006/1/27

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage, ap, dp;

	if ( !target ) target = offensive_target(me);
	if ( !target || !target->is_character() || !me->is_fighting(target) || !living(target))
		return notify_fail(HIW"��ֻ����ս����ʹ�á�\n"NOR);
	if ( playerp(me) && me->query("family/family_name") != "��ɽ��" ) return notify_fail("������ɽ�Ĳ����á�������������\n");
	if ( playerp(me) && me->query("shushan/jinsheng_perform") != 1 ) return notify_fail("�㻹û��ᡸ������������\n");
	if ( (int)me->query("max_neili") < 1500000 ) return notify_fail("���������Ϊ̫�͡�\n");
	if ( (int)me->query("neili") < 1500000 ) return notify_fail("����������㡣\n");
	if ( (int)me->query_skill("sword", 1) < 1500 ) return notify_fail("��Ļ��������ȼ�����������ʹ����һ�У�\n");
	if ( (int)me->query_skill("yujianshu", 1) < 1500 ) return notify_fail("����������ȼ�����������ʹ����һ�У�\n");
	if ( !(weapon = me->query_temp("weapon")) ) return notify_fail("������ֳֽ�����ʹ�ý�����\n");
	if ( (int)me->query_skill("shushan-force", 1) < 900 ) return notify_fail("�����ɽ�ķ��ȼ�����������ʹ����һ�У�\n");
	if ( me->query_skill_mapped("force") != "shushan-force" ) return notify_fail("û����ɽ�ķ��޷���Ԧ������\n");

	me->set("qi", 0);
	me->set("eff_qi", 0);
	me->set("jing", 0);
	me->set("eff_jing", 0);
	me->set("neili", 0);
	me->set("jingli", 0);

	message_vision(HIB"\n$N�ۼ����У������˷�����������ʫ������Ĭ�",me,target);
	message_vision(HIG"\n\n���е���һ�ж�ֻ�еȴ�������......",me,target);
	//message_vision(HIB"\n\n$Nһ��ˣ�������"+weapon->name()+NOR+HIB"��Ϊһ��ֱ��$n���������� \n\n"NOR,me,target);
	message_vision(HIB"\n\n$Nһ��ˣ����������г�����Ϊһ��ֱ��$n���������� \n\n"NOR,me,target);

	ap = me->query_skill("yujianshu", 1);
	ap /= 10;
	ap = ap * ap;
	dp = target->query_skill("dodge", 1);
	dp /= 10;
	dp = dp * dp;
	
	if ( random(ap) < dp/2 ) 
	{
		message_vision(HIB"\n\n$nһ�����Ʋ��ƴ�������Խ����Ȼ���Ǳ�����֮�ʽ��ҵض������ƴ����һʽ������\n\n"NOR, me, target);
		target->start_busy(random(30));
	}
	else
	{
		message_vision(HIB"\n\n$n����$N��˾�������Ȼ����������˲��һ����������$n���ϵ��ش���������\n\n"NOR, target ,me);
		if ( playerp(target) ) target->unconcious();
		else
		{
			damage = me->query("max_neili")/10;
			target->receive_damage("qi", damage, me);
			target->receive_damage("jing", damage, me);
		}
	}
	
	message_vision(HIR"\n\n����д���һ����̾�������Ҳ���������� \n\n"NOR,me);
	me->unconcious();
	return 1;
}

