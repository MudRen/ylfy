// mie.c  �ط�����������𽣡�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;

	if (!target ) target = offensive_target(me);
	if (!objectp(weapon = me->query_temp("weapon"))
	        || (string)weapon->query("skill_type") != "sword")
		return notify_fail(RED"��ʲô��Ц��ûװ��������ʹ���𽣡���\n"NOR);
	if (!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���𽣡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if ((int)me->query_skill("huifeng-jian", 1) < 60 )
		return notify_fail(WHT"��Ļط��������������죬��ʹ�������𽣡���\n"NOR);
	if ((int)me->query_skill("linji-zhuang", 1) < 60 )
		return notify_fail(RED"����ټ�ʮ��ׯ��򲻹������𽣡�������ʽ��\n"NOR);
	if ((int)me->query("max_neili")<400)
		return notify_fail(RED"���������Ϊ���㣬�޷����㡸�𽣡���������\n"NOR);
	if ((int)me->query("neili")<200)
	{
		return notify_fail(HIC"����������������û�ܽ����𽣡�ʹ�꣡\n"NOR);
	}
	msg = HIC "$N���г�����âԾ�������Ⱪ�����ó�������ɫ�ʣ����⽥\n"NOR;
	msg += HIC"���ƽ�$n��$n�������콣�⣬�����Ծ��ֻ��һɲ�����콣\n"NOR;
	msg += HIC"Ӱ��Ϊһ��ֱ��$nǰ�أ�������ף�ֻ��һ����\n"NOR;
	if (random(me->query_skill("sword"))>target->query_skill("force")/2 || random(me->query("xyzx_sys/level"))>(int)target->query("xyzx_sys/level")/3)
	{
		me->start_busy(2);
		target->start_busy(2+random(3));
		damage = (int)me->query_skill("huifeng-jian", 1);
		damage = damage + random(damage);
		target->receive_damage("qi", damage/2,me);
		target->receive_wound("qi", damage,me);
		target->receive_damage("jing", damage,me);
		target->receive_wound("jing", damage/2,me);
		msg += HIC"$n����û����ܣ�һʽ���ط���������ľ��С��𽣡��˶���\n"NOR;
		msg += HIC"��������$n�ؿڣ�$nһ��ͷ�����������ؿڰγ���\n"NOR;
		me->add("neili", -200);
	}
	else
	{
		me->start_busy(2);
		msg += HIY"����$p����һЦ��������ת�������ָ��������$P�Ľ��ϣ���\n"NOR;
		msg += HIY"����$p��໮�����������ˡ�\n"NOR;
		me->add("neili", -200);
	}
	message_vision(msg, me, target );
	if(!target->is_fighting(me)) target->fight_ob(me);

	return 1;
}

