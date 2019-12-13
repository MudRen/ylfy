#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, attack_time;

	if( !target ) target = offensive_target(me);

	if ( me->query("gender") != "Ů��")
		return notify_fail("����̬��Ӳ���޴���ᡸ�Ʒ������Ʒ���ľ��衣\n");

	/*        if ( !wizardp(this_player()) && (me->query("family/family_name") != "�ƻ���"))
	                return notify_fail("�㲻���ƻ������Ӳ���ʹ��ڤ����.\n
	                                    �Ʒ罣��������, ���ƻ������Ӳ���, �治֪��������ôѧ���!\n
	                                    Ҫ������λ����֪������ɲ���.\n");
	*/
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���Ʒ������Ʒ��ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if((int)me->query_dex() < 60)
		return notify_fail("���������, Ŀǰ������ʹ���������! \n");

	if((int)me->query_skill("mingyu-shengong",1) < 300)
		return notify_fail("���ڤ���񹦵���Ϊ����, ����ʹ����һ���� !\n");

	if ( me->query_skill_mapped("force")!="mingyu-shengong" )
		return notify_fail("���Ʒ������Ʒ��������ڤ���������ӣ�\n");

	if ( me->query_skill_mapped("sword")!="yifeng-jian" )
		return notify_fail("�Ʒ罣�����뼤���ڻ����������ſ���ʹ�á��Ʒ������Ʒ����\n");

	if((int)me->query_skill("dodge",1) < 400)
		return notify_fail("����Ṧ��Ϊ����, ����ʹ���Ʒ������Ʒ��\n");

	if((int)me->query_skill("sword",1) < 150)
		return notify_fail("��Ľ�����Ϊ������ Ŀǰ����ʹ���Ʒ������Ʒ���! \n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("�������������\n");

	msg = HIM "$Nʹ���Ʒ罣���ľ������Ʒ������Ʒ������ʱ������裡\n";
	if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/10 )
	{
		attack_time = (int)me->query_skill("yifeng-jian", 1) / 80;
		if(attack_time < 1) attack_time = 1;
		if(attack_time > 50) attack_time = 50;
		me->add_temp("lianzhao", attack_time);
		msg += HIR " $p����$P���еĽ���Ϊ�����������$p��\n" NOR;
		for(i = 2; i < attack_time; i++)
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);

		me->start_busy(random(2));
		me->add("neili", -100*attack_time);
		me->delete_temp("lianzhao");
	}
	else
	{
		msg += HIY "$p���Ա�һ���������$P����һ�С�\n" NOR;
		me->start_busy(random(2));
	}
	message_vision(msg, me, target);

	return 1;
}

