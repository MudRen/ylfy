// jiushi.c ��ʽ��һ

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage, zhao, max;
	string msg;
	object weapon;

	string  *pfattack_msg = (
	{
		HIG"������ʽ��$NͻȻ�����н�ʽ��תΪʩ������$n��ʱ���Ƶ���æ���ң��Լ���$N�ĳ���ײ��������\n"NOR,
		HIR"���潣ʽ��$N�������������֣����б�����ҵߵ���$nһʱû��Ū�����̸����š�\n"NOR,
		HIC"���佣ʽ��$N������𣬳�ͷ�½����ƣ��ӿ��й���$n��$n�������������$N�Ĵ��С�\n"NOR,
		HIY"��ҡ��ʽ��ֻ��$N�ĳ�����������һ�������ػ��ţ�$n��֪��Ҫ�����Լ���ʲôλ�ã�վ��ԭ�ط�������������С�\n"NOR,
		HIW"������ʽ��$N�Ľ���ͻȻ����������������Ʈ��������$nֻ����ǰһ�����ؿ��ѱ����С�\n"NOR,
		HIB"���˽�ʽ������󺣿��Σ���������$nѹȥ��$nֻ��������$N�Ľ��еĿ�籩��֮�У���֪�����Ѿ������С�\n"NOR,
		YEL"���콣ʽ��$n��$N����һ����ֻ��$N����������һ����$n��С��������$N��һ����\n"NOR,
		HIG"���뽣ʽ��ֻ��$N�����г�������������У��������Ⱪ�����������Ƿ���$n��$n��ܲ������������С�\n"NOR,
		HIW"$N���г������һ�㣬"+HIR"������ʽ��"+HIW"Ӧ�ֶ���������֮�ڽ����ݺ����಻��Ϯ��$n��$n��æ�ڿն����Ѿ�̫�������Ѿ����ض�����\n"NOR
	});
	string *pfparry_msg = (
	{
		HIG"$p������$P����ͼ��ͦ�����ϣ�һȦһ���ƽ���$P�����С�\n"NOR,
		HIB"$p�������$P�Ľ������մӽ��²�����\n"NOR,
		HIY"$PͻȻ���󷽹�ȥһ�������Ա�$p�ϵ���������������Ʈ�����࣬���������С�\n"NOR,
	});

	if ( !target ) target = offensive_target(me);
	if ( !objectp(weapon = me->query_temp("weapon"))
	        || (string)weapon->query("skill_type") != "sword" )
		return notify_fail(RED"��ʲô��Ц��ûװ��������ʹ����ʽ��һ����\n"NOR);
	if ( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("����ʽ��һ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if ( (int)me->query_skill("lonely-sword", 1) < 900 )
		return notify_fail(WHT"����¾Ž�������죬ʹ��������ʽ��һ����\n"NOR);
	if ( (int)me->query("max_neili") < 1000 )
		return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);
	//if ( target->is_busy() )
	//return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
	if ( (int)me->query("neili") < 30000 )
		return notify_fail(HIC"����������������û�ܽ�����ʽ��һ��ʹ�꣡\n"NOR);

	msg = HIW "$N���г�����âԾ�������Ⱪ�����������ʹ�����¾Ž��ģ����ž���"NOR;
	msg += HIR"����ʽ��һ��"+HIW+"��������Ʈ�������²�����ֱ��$n��ȥ��\n\n"NOR;

	message_vision(msg, me, target);

	if ( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3
	        || random(me->query_skill("sword")) > random(target->query_skill("sword")) )
	{
		max = me->query_skill("lonely-sword", 1)/90;
		me->start_busy(2);
		target->start_busy(1+random(3));
		for ( zhao=0; zhao<max; zhao++ )
		{
			damage = (int)me->query_skill("lonely-sword", 1);
			damage = random(damage)*2;
			if ( (int)me->query("neili") < damage ) break;
			message_vision(pfattack_msg[random(sizeof(pfattack_msg))], me, target);
			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage/2, me);
			COMBAT_D->do_attack(me, target, weapon, 0);
			me->add("neili", -damage);
		}
	}
	else
	{
		me->start_busy(2);
		message_vision(pfparry_msg[random(sizeof(pfparry_msg))], me, target);
	}

	return 1;
}
