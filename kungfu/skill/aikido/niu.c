
#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;
string* buwei = (
{
	"�����ⲿ",
	"����",
	"���ֹؽ�",
	"����",
	"�粿�ؽ�",
	"����ҪѨ",
	"ϥ�ؽ�",
	"����"
});
int perform(object me, object target)
{

	string msg;
	int extra;
	string bw;


	bw = buwei[random(sizeof(buwei))];

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("������.��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������.�ܱ�����֡�\n");
	if( (int)me->query("max_neili") < 200 )
		return notify_fail("�������������\n");
	extra = me->query_skill("aikido",1)/10;
	if(extra <= 3 ) return notify_fail("��ģۺ������ݲ���������\n");
	if ((int)me->query_skill("shayi-xinfa", 1) < 30)
		return notify_fail("���ɱ���ķ���򲻹���\n");

	if( (int)me->query("neili") < 200  )
		return notify_fail("�������������\n");

	msg = HIG "$N˫üһ�һ�����ö�Ȼ��ץס��$n��"+bw+"Ȼ���"+bw+"������һŤ��!\n";

	if( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3 || random(me->query("unarmed")) > target->query("dodge")/5 )
	{
		msg += HIR " ���$p��$PŤ�Ĳҽв�ֹ�������˵Ĳ��ᣡ\n" NOR;
		if (userp(target))
			target->add("qi",-target->query("qi")/3);
		else target->add("qi",-extra*20);
	}
	else
	{
		msg += HIC"����$p������$P����ͼ��������$P�����á�\n"NOR NOR;
	}
	message_vision(msg, me, target);
	me->start_busy(2);
	me->add("neili", - 100);
	if(!target->is_fighting(me)) target->fight_ob(me);

	return 1;
}

