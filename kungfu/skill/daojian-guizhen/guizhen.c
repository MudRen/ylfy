// This is player's own perform (Write by Lonely@nt2)
// Create by ��ݶ(Xiaot) at Fri Mar 10 11:48:11 2006
// ��豹���(guizhen)

#include <ansi.h>
#include <combat.h>
#define PFM "��" HIW "��豹���" NOR "��"
inherit F_SSERVER;

string *weapon_sk = (
{
	"sword", "blade", "staff", "whip", "club", "hammer", "axe"
});

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int damage;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail(PFM "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (member_array("sword", weapon_sk) != -1)
	{

		if (! objectp(weapon = me->query_temp("weapon"))
		        || (string)weapon->query("skill_type") != "sword"
		        && (string)weapon->query("skill_type") != "blade" )
			return notify_fail("����ʹ�õ��������ԣ�����ʩչ" PFM "��\n");
	}
	else
	{

		if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
			return notify_fail(PFM "ֻ�ܿ���ʹ�á�\n");
	}

	if ((int)me->query_skill("daojian-guizhen", 1) < 500)
		return notify_fail("��" + to_chinese("daojian-guizhen") + "������죬����ʩչ" PFM "��\n");

	if (member_array("sword", weapon_sk) == -1)
	{
		if (me->query_skill_prepared("sword") != "daojian-guizhen")
			return notify_fail("��û��׼��" + to_chinese("daojian-guizhen") + "������ʩչ" PFM "��\n");
	}
	if( me->is_busy() )
		return notify_fail("( ����һ��������û����ɣ�����ʩ���ڹ���)\n");
	if (me->query("neili") < 800)
		return notify_fail("�����ڵ���������������ʩչ" PFM "��\n");

	if (! living(target))
		return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "$NͻȻ�������ס��ߵ����ᣬ�����ǽ��������ǵ������򲻱䣬�ó�һƬ���⽣Ӱ����$n����׽��,���ǵ������ռ�ɱ�С���豹��桱��" + "\n" + NOR;

    ap = me->query_skill("blade") + me->query_skill("sword");
	dp = target->query_skill("parry") + target->query_skill("dodge");

	if (ap * 2 / 3 + random(ap * 2) > dp)
	{
		damage = (me->query_skill("sword") + me->query_skill("blade") + me->query_skill("force"))* 5;
		target->add("qi",-damage);
		target->add("eff_qi",-damage);
		me->add("neili", -150);
		msg +=HIM "ֻ��$nһ���ҽУ��ؿڸ�����һ���޴�Ŀ��ӣ���Ѫ��ӿ�����" + "\n" NOR;
		me->add("neili", -200);
		me->start_busy(1);
		if (! target->is_busy())
			target->start_busy(3);
	}
	else
	{
		msg += NOR + CYN "$p���Ʋ�������ˣ����ձܹ�$P�����ɱ�У����������У������ѿ���һ������ӣ�" + "\n" NOR;
		me->add("neili", -100);
		me->start_busy(2);
	}

	message_vision(msg, me, target );
	return 1;
}

