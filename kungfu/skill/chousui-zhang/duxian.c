// ������
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
	int extra,p;
	if( !target ) target = offensive_target(me);

	if (!target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("ֻ����ս����ʹ�á�\n");
	weapon = me->query_temp("weapon");
	if( objectp(me->query_temp("weapon")) && (string)weapon->query("skill_type") != "staff")
		return notify_fail("�������ֲ���ʹ�����������\n");
	if( me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  )
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 )
		return notify_fail("�������������\n");

	if( !wizardp(me) &&(int)me->query_skill("tianshan-zhang", 1) < 500 )
		return notify_fail("�����ɽ�ȷ��ȼ�̫��!���ܹ�ͨʹ�ö����ף�\n");

	if(!wizardp(me) && (int)me->query_skill("chousui-zhang", 1) < 500 )
		return notify_fail("��ĳ����Ƶȼ�̫��!���ܹ�ͨʹ�ö����ף�\n");

	if(!wizardp(me) && (int)me->query_skill("huagong-dafa", 1) < 500 )
		return notify_fail("��Ļ����󷨵ȼ�̫��!���ܹ�ͨʹ�ö����ף�\n");

	if ( !wizardp(me) && me->query_skill_mapped("force") != "huagong-dafa")
		return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");


	msg = HBWHT "$N��ͨ��������ѧ��ʹ���������ɵľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
	message_vision(msg, me, target);

	msg = HIM "\n$NͻȻ�������㵸�����������дʣ��е����������񹦣��������Ž��ޱȡ���\n";
	msg += HIM "���Ž�������������������ͣ������·������������޽����裬�����Ŀ���ࡣ\n\n"NOR;

	message_vision(msg, me, target );
	if (random(3)==0) target->start_busy(3);
	msg = HIY "$Nʹ����ɽ�ɾ�������ɽ��塹������Ȼ�ӿ졣�������ڣ�" NOR;
	p = me->query_skill("force") * random(me->query("con")) + me->query_skill("unarmed");
	extra = me->query_skill("tianshan-zhang",1);
	extra += me->query_skill("huagong-dafa",1);
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIB  "        ^^�����أ�^^       " NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  RED  "      ^^^^ɽ��������^^^^  " NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIM  "    ^^^^^^���ż�ɽ��^^^^^ " NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIC  "^^^^^^^^^^^��ɽѩ����^^^^^^^^^^^ " NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	message_vision(HIY"$N����ʽͻ�䣬����ð�����̹�! $n���̹�ɨ�У�ȫ����һ��!\n"NOR,me,target);
	target->apply_condition("xx_poison",50);
	msg =  HIR  "����ʬ����" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("poison_sandu",50);
	msg =  HIR  "����ɰ�ơ�" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("sanpoison",50);
	msg =  HIR  "�����ζ���" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add("neili", -150);
	if (random(me->query("xyzx_sys/level")) >target->query("xyzx_sys/level")/3)
	{
		msg =  HIR  "����Ц��ңɢ��" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		message_vision(HIR"$NͻȻ�����һЦ��$n��Ȼ����Ц��Ц!\n"NOR,me,target);
		target->receive_damage("qi", p);
		target->receive_wound("qi", p);
		target->apply_condition("sanxiao_poison",6);
		me->add("neili", -50);
	}
	message_vision(RED "\n$N��ȫ�������ע����ϣ����ŵ���һָ..���ϳ�������"HIR"����\n" NOR, me);
	message_vision(BLU"\n$N��ɫ�ҵ������ִ򿪷��٣������´����������ϣ����ŵ�ȼ���׷ۣ�ҧ����⣬һ��"RED"��Ѫ"BLU"���������ȥ��"HIR"�������һ�����漴��Ϊ"RED"����"HIR"��ҫ�������۾�Ҳ����������\n\n"NOR,me);
	msg = BLU"\n$N�͵����Ӽ����������ݰ���ת��ʮ���Ȧ�ӣ�����$P���������"HIR"��������Ѷ��ز������ȼ�գ�����һ��"RED"��ǽ"HIR"�㣬������ɽ����֮����$nѹ����\n"NOR;
	if( random( (int)me->query("xyzx_sys/level",1)) > target->query("xyzx_sys/level")/3  )
	{

		msg += HIY"\n$nֻ��Ŀ�ɿڴ���һ��֮�䣬��æԾ�𣬵�һ��"HIW"��"HIY"���䵽��ǰ���͵�һ���죬�������϶Ǹ���$n��������һ����У���������������"HIR"���ǽ"HIY"Ҳ�����������С�\n" NOR;
		target->receive_damage("qi", p);
		target->receive_wound("qi", p);
		msg += "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n";
		msg += "( "RED"$n���˹��أ��Ѿ�������в�����ʱ�����ܶ�����"NOR")\n";
		message_vision(msg, me, target);
	}
	else
	{
		msg += "$p������������һ�𣬽�$N����Ĵ��ǽж��������!\n" NOR;
		message_vision(msg, me, target);
	}
	me->start_busy(4);
	return 1;
}
