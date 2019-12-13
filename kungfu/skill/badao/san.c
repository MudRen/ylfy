#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
#define XIAN "��" HIR "���ǵ�����" NOR "��"

inherit F_SSERVER;

string attack1(object me, object target, int damage);
string attack2(object me, object target, int damage);

int perform(object me, object target)
{
	int damage, p;
	string msg;
	object weapon;
	int ap, dp;

	// if( userp(me) && !me->query("can_perform/badao/san") )
	//      return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail(XIAN "ֻ����ս���жԶ���ʹ�á�\n");

	if( !objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "blade" )
		return notify_fail("��ʹ�õ��������ԣ�\n");

	if ((int)me->query_skill("badao", 1) < 1000)
		return notify_fail("��Ե�����㣬�޷�ʩչ" XIAN "��\n");

	if ((int)me->query_skill("force", 1) < 800)
		return notify_fail("������ڹ���Ϊ�������޷�ʩչ" XIAN "��\n");

	if( me->query("neili")<3000 )
		return notify_fail("�����������������޷�ʩչ" XIAN "��\n");

	if (me->query_skill_mapped("blade") != "badao")
		return notify_fail("��û�м����Ե����޷�ʹ��" XIAN "��\n");

	if (! living(target))
		return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	me->add("neili", -3000);

	ap= me->query_skill("blade") + me->query_skill("force") + me->query_str();
	dp = target->query_skill("dodge") + target->query_skill("force") + target->query_skill("parry");

	message_vision(HIW "\n$N" HIW "һ����̾���ƺ�����������ɣ����̬��ǧ���ֵ�������ң����� ����\n\n", me, target);

	// ��һ��
	msg = HIY "$N" HIY "̤����ǰ��ʩչ�����ǵ�����֮��һ����ħ����" + weapon->name() + HIY"˳��������������𣬴�ػع�ڰ� ����\n" NOR;

	if (ap * 4 / 5 + random(ap) > dp)
	{
		damage = ap * 3 + random(ap);
		target->receive_damage("qi", damage, me );
		target->receive_wound("qi", damage/2 , me);
		msg += HIR "$n" HIR "����δ������Ȼ��֪��ܣ���$Nһ���������������壬������Ѫ���������ˡ�\n" NOR;
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	}
	else
	{
		msg += CYN "$n" CYN "����һԾ������һ�ߡ�\n" NOR;
	}

	// �ڶ���
	msg += HIY "\n$N" HIY "��̾����Ȼ�䣬�ֱ�һ�ӣ�һʽ���ǵ�����֮���˼���������Ȼʹ����" + weapon->name() + HIY "����һ��"
	       "�����ƺڰ��������䣬һ�����ȵİ׹����$n" HIY "����Χ����������Ϣ��\n" NOR;

	if (ap * 4 / 5 + random(ap) > dp)
	{
		damage = ap * 4 + random(ap);
		target->receive_damage("qi", damage, me );
		target->receive_wound("qi", damage/2 , me);
		msg += HIR "$n" HIR "����δ������Ȼ��֪��ܣ���$Nһ���������������壬������Ѫ���������ˡ�\n" NOR;
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	}
	else
	{
		msg += CYN "$n" CYN "����ʩչ��ʽ���������л��⡣\n" NOR;
	}

	// ������
	msg += HIY "\n$N" HIY "˫��һ�죬������������Ȼŭ��һ����������𣬵���������ع�ڰ����ƺ����������Ѿ�"
	       "׹���޼�����㣬�������ް�����ͻȻ�����ܳ���Ź���Ǻ��ľ��죬$N" HIY "ȴ����û����Ӱ��\n" NOR;
	if (ap * 4 / 5 + random(ap) > dp)
	{
		damage = ap * 5 + random(ap);
		target->receive_damage("qi", damage, me );
		target->receive_wound("qi", damage/2 , me);
		msg += HIR "$n" HIR "����δ������Ȼ��֪��ܣ���$Nһ���������������壬������Ѫ���������ˡ�\n" NOR;
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	}
	else
	{
		msg += CYN "$n" CYN "��������С��Ӧ�ԣ��������л��������Ρ�\n" NOR;
	}

	me->start_busy(4 + random(4));
	message_vision(msg, me, target);
	return 1;
}

string attack1(object me, object target, int damage)
{
	string msg;

	msg = HIR "$n" HIR "ֻ������һ���������ؿ�ȴ�ѷ��ڲ�Ϣ��˵���������ܡ�\n" NOR;

	target->add("neili", -damage/2);

	return msg;
}

string attack2(object me, object target, int damage)
{
	string msg;

	msg = HIR "$n" HIR "����ʮ��ʧ�˰��ǣ������ɼ䣬��ǰһ��������͸�������\n" NOR;

	target->receive_wound("jing", damage / 8, me);
	if (random(4) == 1)target->start_busy(5 + random(5));

	return msg;
}