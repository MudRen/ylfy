
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
	if ((int)me->query_skill("shayi-xinfa", 1) < 30)
		return notify_fail("���ɱ���ķ���򲻹���\n");

	extra = me->query_skill("aikido",1);
	if(extra <= 3 ) return notify_fail("��ģۺ������ݲ���������\n");
	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ�Ѿ���æ�����ˣ��ŵ������ɢ�\n");

	if( (int)me->query("neili") < 200  )
		return notify_fail("�������������\n");

	msg = HIG "$N˫üһ�һ�����ú��������÷���Ȼ��ץס��$n��"+bw+"!\n";

	if( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3 || random(me->query("unarmed")) > target->query("dodge")/3 )
	{
		msg += HIW " ���$p��$Pץס��ʱ���ܶ�����\n" NOR;
		target->start_busy( (int)me->query_skill("aikido",1) / 50 + 2 );
	}
	else
	{
		msg += HIC"����$p������$P����ͼ��û�и�ץס��\n"NOR NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);
	me->add("neili", - 60);
	if(!target->is_fighting(me)) target->fight_ob(me);

	return 1;
}

