#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
#define ZHUAN "��" HIR "תǬ��" NOR "��"

inherit F_SSERVER;
string *xue_name1 = (
{
	"��׶Ѩ",
	"�ٻ�Ѩ",
	"־��Ѩ",
	"�羮Ѩ",
	"�͹�Ѩ",
	"�ڹ�Ѩ",
	"���Ѩ",
	"����Ѩ",
});
string *xue_name2 = (
{
	"����Ѩ",
	"����Ѩ",
	"����Ѩ",
	"�׺�Ѩ",
	"��̨Ѩ",
	"�縮Ѩ",
	"���Ѩ",
	"����Ѩ",
});
string *xue_name3 = (
{
	"����Ѩ",
	"����Ѩ",
	"˿����Ѩ",
	"����Ѩ",
	"����Ѩ",
	"��׵Ѩ",
	"����Ѩ",
	"����Ѩ",
});
string* xuedao = (
{
	"�޹�Ѩ",
	"�ز�Ѩ",
	"�羮Ѩ",
	"�ճ�Ѩ",
	"����Ѩ",
	"���Ѩ",
	"����Ѩ",
	"�縮Ѩ",
	"����Ѩ",
	"�յ�Ѩ",
	"ǿ��Ѩ",
	"�ٺ�Ѩ",
	"����Ѩ",
	"����Ѩ",
	"����Ѩ",
	"��׵Ѩ",
	"��βѨ",
	"����Ѩ",
	"�͹�Ѩ",
	"�ٻ�Ѩ",
	"��̨Ѩ",
	"̫��Ѩ",
	"����Ѩ",
	"����Ѩ",
	"�βѨ",
	"������",
	"����Ѩ"
});
int perform(object me, object target)
{
	object weapon;
	int ap, dp, damage,skill;
	string msg;
	string pmsg;

	skill=(int)me->query_skill("tanzhi-shentong", 1);
	if (! target) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail(ZHUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail(ZHUAN "ֻ�ܿ���ʩչ��\n");

	if ((int)me->query_skill("tanzhi-shentong", 1) < 220)
		return notify_fail("��ĵ�ָ��ͨ������죬����ʩչ" ZHUAN "��\n");

	if ((int)me->query_skill("qimen-wuxing", 1) < 200)
		return notify_fail("�������������Ϊ����������ʩչ" ZHUAN "��\n");

	if (me->query_skill_mapped("unarmed") != "tanzhi-shentong")
		return notify_fail("��û�м�����ָ��ͨ������ʩչ" ZHUAN "��\n");
	
    if (me->query_skill_mapped("force") != "bibo-shengong")
		return notify_fail("��û�м����̲��񹦣�����ʩչ" ZHUAN "��\n");
	
	if ((int)me->query_skill("bibo-shengong", 1) < 120)
		return notify_fail("��ı̲��񹦻��̫ǳ��\n");

	if ((int)me->query_skill("count", 1) < 120)
		return notify_fail("����������Ի��̫ǳ��\n");

	if (me->query("max_neili") < 3500)
		return notify_fail("���������Ϊ���㣬����ʩչ" ZHUAN "��\n");

	if (me->query("neili") < 800)
		return notify_fail("�����ڵ���������������ʩչ" ZHUAN "��\n");

	if (! living(target))
		return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "��ȫ��������һָ��ָ�����ն�ʮ���޷�λ�ƹ�����������һ�����" HIR "תǬ��" HIC "��������\n" NOR;

	ap = me->query_skill("unarmed") + me->query_skill("qimen-wuxing");
	dp = target->query_skill("dodge") + target->query_skill("qimen-wuxing");

	if (ap * 11 / 20 + random(ap) > dp)
	{
		damage = 0;
		if (me->query("max_neili") > target->query("max_neili") * 2)
		{
			me->start_busy(2);
			msg += HIR "���Ǽ�$n" HIR "ֻ����âһ����$N" HIR "ʳָ"
			       "������$p" HIR "ӡ�ð�ߣ�ָ����ʱ���Զ��롣\n"
			       HIW "���������ۡ���һ�������Ͼ�Ȼ���������Խ���"
			       "\n" NOR "( $n" RED "���˹��أ��Ѿ�������в���"
			       "����ʱ�����ܶ�����" NOR ")\n";
			damage = -1;
		}
		else
		{
			me->start_busy(3);
			damage = me->query_skill("unarmed") + me->query_skill("tanzhi-shentong") + me->query_skill("force") * me->query("con");
			me->add("neili", -500);
			target->add("qi",-damage*3);
			target->add("eff_qi",-damage*2);

			msg +=HIR "���Ǽ�$n" HIR "ֻ����âһ����$N"
			      HIR "ʳָ������$p" HIR "���ð�ߣ�ָ��"
			      "��ʱ������롣\n���������͡���һ����"
			      "���Ͼ�Ȼ����������Ѫ��\n" NOR;

		}
	}
	else
	{
		me->start_busy(3);
		me->add("neili", -300);
		msg += CYN "$p" CYN "��$P" CYN "��ʽ���أ����д��⣬��ʱ���Ծ���ɣ�����������\n" NOR;
	}
	message_vision(msg, me, target);

	if (damage < 0)
	{
		target->receive_wound("qi", 9000);
		target->receive_wound("jing", 2000);
		//target->die(me);
	}

	msg = HIG "\n������ ͻȻ��$N" HIG "ָ��һת������ָ�⡰�͡��ĵ���һ����â��ֱϮ$n"
	      HIG "������Ѩ��\n" NOR;

	ap = me->query_skill("unarmed",1);
	dp = target->query_skill("force",1);

	damage = me->query_skill("unarmed") + me->query_skill("force") + me->query_skill("tanzhi-shentong") * me->query("con");

	if (ap * 3 / 2 + random(ap) > dp)
	{
		target->receive_damage("jing", damage+100);
		target->receive_wound("jing", damage+100);
		target->add("neili", -damage * 3);

		if (target->query("neili") < 0)
			target->set("neili", 0);

		msg += HIR "$n" HIR "ֻ��$N" HIR "ָ��Ϯ�壬�漴����һ��������ٸ�������ɢ�������ʡ�\n" NOR;
		me->start_busy(3);
	}
	else
	{
		msg += CYN "����$p" CYN "�������ܣ������Ż�����ʱ��$P"CYN "�Ĺ��ƻ�Ϊ���С�\n" NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);
	msg = HIC "\n���$N" HIC "��ָ�ᵯ��ֻ���ƿ���������һöʯ�Ӽ��ٷɳ�" + "������$n" HIC "��\n" NOR;

	me->start_busy(2);
	ap = me->query_skill("unarmed",1) + me->query_skill("dodge",1);
	dp = target->query_skill("dodge",1) + target->query_skill("parry",1);

	if (ap / 2 + random(ap) > dp)
	{
		msg += HIR "ʯ�����úÿ죬$n"HIR + "һ�����ܲ����������˸����У�����һ���ʹ�������˼�����Ҫɢ���ˡ�\n" NOR;
		target->receive_damage("qi", damage+skill  + random(skill)+100);
		target->receive_wound("qi", damage+skill  + random(skill)+100);
		COMBAT_D->clear_ahinfo();

		if (stringp(pmsg = COMBAT_D->query_ahinfo()))
			msg += pmsg;
		message_vision(msg, me, target);
	}
	else
	{
		msg += CYN "����$p" CYN "����һ���������$P" HIG "������ʯ�ӡ�\n" NOR;
		message_vision(msg, me, target);
	}
	me->add_temp("apply/attack", 100);
	me->add_temp("apply/damage", 1500);
	if (random(3)==0) target->start_busy(3);
	msg = CYN "$N˫��һǰһ�󣬻����������ָͻ��һ��������������һ�ɣ������С�������ֱϮ$nǰ�ء�\n";
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = HIY "$N��ס��ָ���������������£�����ָ�������������۵�ֿ������$n��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))];
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = HIC"$N������ָ������ָ��һ�뵯������ָָ������$n"+xuedao[random(sizeof(xuedao))]+"������ָ�ϰ�������������Ϣ������"+xuedao[random(sizeof(xuedao))];
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg= HIR"$N˫�㲻�����ˣ�̤�Ŷ�����ľ֮λ��ʳ�ж�ָ����סĴָ��һ����Х�����ֵ���������һ�������޼���ָ��������$n��"+xuedao[random(sizeof(xuedao))];
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg=HIB"$N���һ����˫���������У���������һ�����ţ�����ָ����������Ϣ��Ϯ��$n��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))]+"����ҪѨ";
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg=HIG"$N���ӵ�����Ĵ��˰��Ȧ�ӣ���������һ����������â���Ƴ��߰������������������ͻʢ������$n��"+xuedao[random(sizeof(xuedao))];
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -100);
	me->add_temp("apply/damage", -1500);

	return 1;
}

