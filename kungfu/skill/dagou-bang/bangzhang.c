// bangzhang����˫��

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int damage,damage2;
	if( !target ) target = offensive_target(me);

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "club")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query("max_neili") < 100000  )
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < 20000 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("xianglong-zhang", 1) < 1000 )
		return notify_fail("��Ľ����Ƶȼ�����!���ܹ�ͨʹ�ã�\n");

	if( (int)me->query_skill("dagou-bang", 1) < 2000 )
		return notify_fail("��Ĵ򹷰��ȼ�����!���ܹ�ͨʹ�ã�\n");

	if( (int)me->query_skill("huntian-qigong", 1) < 1000 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if ( !wizardp(me) && me->query_skill_mapped("force") != "huntian-qigong")
		return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

	msg = HBWHT "$N��ͨؤ����ѧ��ʹ����ؤ��ľ�ѧ֮���裡\n" NOR;
	me->add("neili", - 10000);
	message_vision(msg, me, target);
	damage += me->query_skill("dagou-bang",1);
	damage += me->query_skill("club");
	damage *= me->query("con");
	msg = YEL "$N����һ��,ûͷû�Ե���ǰ����˳�ȥ,�����Ǵ򹷰����ľ�Ҫ֮���ڣ�\n" NOR;
	msg+= HIR"$Nŭ��һ�������"+ weapon->name()+HIG"һ�����Ծ����δ�������ȵ��������»�����ʩ����ɱ�֣�\n" NOR;
	message_vision(msg, me);
	if (random(2)==0) target->start_busy(3);
	me->add_temp("apply/attack", (int)me->query_skill("dagou-bang",1));
	me->add_temp("apply/damage", (int)me->query_skill("dagou-bang",1));
	msg = WHT  "$Nת��"+ weapon->name()+HIG"��ˢˢˢ��������������������ף����Ǵ򹷰����е�ɱ�У�" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->receive_wound("qi",damage/4);
	msg = HIC  "$NͻȻ�ɳ�"+ weapon->name()+HIG"��ӭ������$n������������£�������ʱ֮��ֵ�$p�ؿ�������Ѩ��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->receive_wound("qi",damage/4);
	msg = RED "$N����ӳ�������Ϊ�������ӳ��򹷰����еĹ��֣�����������ɱ�У�" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = RED "��һ�� $N����ӳ���ʹ���˷��־���" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = RED "�ڶ��� $N����ӳ���ʹ����ת�־���" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = RED "������ $N����ӳ���ʹ���˰��־�����" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->receive_wound("qi",damage);

	me->add_temp("apply/attack", - (int)me->query_skill("dagou-bang",1));
	me->add_temp("apply/damage", - (int)me->query_skill("dagou-bang",1));
	me->add_temp("apply/strength", (int)me->query_skill("xianglong-zhang",1));
	me->add_temp("apply/attack", (int)me->query_skill("xianglong-zhang",1));
	me->add_temp("apply/damage", (int)me->query_skill("xianglong-zhang",1));
	me->add("neili", -1000);
	weapon->unequip();
	msg = YEL "$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ������ʮ���Ƶ����һ�С�"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+YEL"��һ�а�ʽ����$n��" NOR;
	message_vision(msg, me, target);
	msg =  HIC  "��һʽ��$N����һʽ��������Ұ���������ޱȵ�����$n��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR  "�ڶ�ʽ��$N˫��ʩ��һʽ��������½��������ԼԼ�����Ʒ�����$n��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIB  "����ʽ��$N�������أ�����һʽ��Ǳ����������������$n��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIY  "����ʽ��$Nʹ������Ծ���졹����$n���������ƣ�" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIG "����ʽ��$N˫��һʽ��˫��Ϸˮ��һǰһ����$n����ǰ��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIM  "����ʽ��$N����ת����ʹ����������������$n�������£�" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = YEL  "����ʽ��$N����һת��ͻȻ�۵�$n��ǰ��һʽ����ս��Ұ��ֱ����$n����" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIW "�ڰ�ʽ��$NͻȻ����˫�ƾӸ��������һʽ����Х���졹ȫ������$n��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	me->add_temp("apply/strength", -(int)me->query_skill("xianglong-zhang",1));
	me->add_temp("apply/attack", -(int)me->query_skill("xianglong-zhang",1));
	me->add_temp("apply/damage", -(int)me->query_skill("xianglong-zhang",1));
	if( random(me->query("combat_exp")) > target->query("combat_exp")/4)
	{

		msg = HIR"$Nҧ�����أ�˫�ƻ�������Ĭ���ʮ���ƵĿھ�!"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��!!"NOR+" ";
		msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
		damage2 = me->query_skill("xianglong-zhang",1);
		damage2 = me->query_skill("unarmed");
		damage2 *= me->query("con");
		target->receive_damage("qi",damage2);
		target->receive_wound("qi",damage2);
		target->receive_wound("jing", random(damage2));
		if (!target->is_busy()) target->start_busy(3);
		message_vision(msg, me, target);
		COMBAT_D->report_status(target);
	}
	me->start_busy(4);

	weapon->wield();
	return 1;
}

