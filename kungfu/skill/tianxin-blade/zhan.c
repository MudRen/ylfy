// ������һն��

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage, damage2;
	string msg;
	object weapon;

	if (!target ) target = offensive_target(me);
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʲô��Ц��û����Ҳ��ʹ�á�����һն����\n"NOR);
	if (!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("������һն��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if ( (string)me->query("family/family_name") != "������")
		return notify_fail("������һն��ֻ�������ɴ��˲���ʹ�á�\n");

	if ((int)me->query_skill("tianxin-blade", 1) < 1000 )
		return notify_fail("������е���������죬��ʹ����������һն����\n"NOR);
	if ((int)me->query_skill("cuixin-zhang", 1) < 1000 )
		return notify_fail("��û����������Ƶ������ھ�����ʹ����������һն����\n"NOR);
	if ((int)me->query_skill("lingyunbu", 1) < 1200 )
		return notify_fail("������Ʋ���ûѧ���ң���������ϡ�����һն����\n"NOR);
	if ((int)me->query_skill("yijing-force", 1) < 1000 )
		return notify_fail("����׾��񹦻�򲻹���������һն��������ʽ��\n"NOR);
	if ((int)me->query("max_neili")<50000)
		return notify_fail("���������Ϊ���㣬�޷����㡸����һն����������\n"NOR);
	if ((int)me->query("neili")<200)
	{
		return notify_fail("����������������û�ܽ�������һն������ʹ����\n"NOR);
	}
	msg = HIC "      $N�����Ԫ������ȫ����������������֮�ϣ�\n"NOR;
	msg += HIC"      ׼��ʩչ���е�����������������һն������\n"NOR;
	msg += HIC"      $n��$N��ɱ�����壬��Ȼ�������ã���\n"NOR;
	if (random(me->query_skill("blade"))>target->query_skill("force")/2)
	{
		me->start_busy(2);
		target->start_busy(random(3));
		damage = (int)me->query_skill("tianxin-blade")*5+(int)me->query_skill("force")*2;
		damage = damage + random(damage);
		if (damage<target->query("max_qi",1)/8 && me->query("max_neili",1) > target->query("max_neili",1)/2) damage = random (target->query("max_qi",1)/6);
		if (damage>target->query("max_qi",1)/3) damage = random (target->query("max_qi",1)/4);


		damage2 = (int)me->query_skill("tianxin-blade")*5+(int)me->query_skill("force")*2;
		damage2 = damage2 + random(damage2);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/2);
		if (damage>target->query("max_jing",1)/3) damage = random (target->query("max_jing",1)/4);

		target->receive_damage("jing", damage2);
		target->receive_wound("jing", damage2/2);
		msg += HIR"$n����������$N��������������ɱ�⵶�������������Լ�ն��ȴһ��Ҳ���ܶ���\n"NOR;
		msg += HIR"��Ѫ���������$n����û������ʹ��ֻ֪��������ĵ����Ѿ������Լ����ڣ���\n"NOR;
		me->add("neili", -4000);
	}
	else
	{
		me->start_busy(random(3));
		msg += HIY"$p�����ǳ���������$P�ĵ���ն���Լ����ϵ�ʱ��ָ���\n"NOR;
		msg += HIY"������æ�����ȥ���㿪��������һ������\n"NOR;
		me->add("neili", -200);
	}
	message_vision(msg, me, target);
	me->fight_ob(target);
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

