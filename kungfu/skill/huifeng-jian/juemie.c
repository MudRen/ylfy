// juemie ���Ǿ�
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int extra;
	int damage;
	int jiali, neili_cost;
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����Ǿ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʼʱ��������һ�ѽ���\n");

	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("max_neili") < 20000  )
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < 2000 )
		return notify_fail("�������������\n");

	if(!wizardp(me) && (int)me->query_skill("huifeng-jian", 1) < 1500 )
		return notify_fail("��Ļط罣������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jinding-zhang", 1) < 1500 )
		return notify_fail("��Ľ��Ʋ�����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("linji-zhuang", 1) < 1000 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if ( !wizardp(me) && me->query_skill_mapped("force") != "linji-zhuang")
		return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

	msg = WHT "$N��ͨ��������ѧ��ʹ���˶����ɵľ�ѧ֮���裡\n" NOR;
	me->add("neili", -10000);
	message_vision(msg, me, target);
	if (random(3)==0) target->start_busy(10);
	extra = me->query_skill("linji-zhuang",1);
	damage = me->query_skill("force");
	damage += me->query_skill("sword");
	damage *= me->query("con");
	msg = YEL "$Nʹ���ط������������һ�������塹��һ���������������е�"+ weapon->name() +"����㹥����һ����" NOR;
	message_vision(msg, me);

	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);
	msg = HIY "ֻ��$N����һ����"+ weapon->name()+ HIY"����$n����磡" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	if (me->query_skill("dodge") > (int)target->query_skill("dodge")/2 )
	{
		msg = HIW "��һ������"+HIR+"����$n����$nֻ����ȫ������ͨ���������������ܸ��ӣ�\n"NOR;
		message_vision(msg, me, target);
		if( !target->is_busy() )
		{
			target->start_busy(2);
			target->apply_condition("no_perform", 3);
		}
	}
	msg =  HIW "$N���һ����"+ weapon->name()+ GRN"����$n���Ҽ磡" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	if (me->query("xyzx_sys/level")> target->query("xyzx_sys/level")/3 )
	{
		msg = HIC "�ڶ�������"+HIM+"ɨ��$n������,$nֻ����ȫ��һ��ʹ��\n"NOR;
		target->add("jing",-damage);
		target->add("eff_jing",-damage);
		message_vision(msg, me, target );
	}
	msg = CYN "$N��Хһ�����۹��������֣�ʹ����������߾���--�𽣣���$n����ǰ��ȥ��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	if (me->query_skill("force") > (int)target->query_skill("force")/2  )
	{
		msg = MAG "���һ������"+HIB+"ɨ��$n������Ѩ,$nֻ����ȫ�������᲻�����ˣ�\n"NOR;
		target->add("neili",-damage);
		target->add("eff_neili",-damage);
		message_vision(msg, me, target );
	}
	me->add_temp("apply/attack", - extra);
	me->add_temp("apply/damage", - extra);
	me->start_busy(2);

	msg = YEL "$N���г�����âԾ�������Ⱪ�����ó�������ɫ�ʣ����⽥���ƽ�$n��\n"NOR;
	msg += YEL"$n�������콣�⣬�����Ծ��ֻ��һɲ�����콣Ӱ��Ϊһ��ֱ��$nǰ�أ�"NOR;

	if( weapon = target->query_temp("weapon") )
	{
		if( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3)
		{
			msg += HIM"\n$pֻ���û���һ�ȣ����ƻ��ھ�ʹ������"
			       + target->query_temp("weapon")->query("name") + "���ֶ�����\n" NOR;
			message_vision(msg, me, target);
			(
			    target->query_temp("weapon"))->move(environment(target));
		}
		else
		{
			msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
			message_vision(msg, me, target);
			message_vision(HIW "��$NƮ�����ʹ�����Ҿ������𽣡��ķ�����ʱ�������Ʈ�ݣ�����ǧ�������裬����ͷ����������$n����֮�£���ʱ����ɢ�ң��޴��мܣ�\n" NOR, me, target);
		}
	}
	else
	{
		if (random(me->query_skill("force")) > target->query_skill("force")/2 || random(me->query("xyzx_sys/level"))+10 > target->query("xyzx_sys/level")/3 )
		{

			damage = (int)me->query_skill("sword");
			damage += (int)me->query_skill("force");
			damage = damage + random(damage);

			target->receive_damage("qi", damage);
			target->receive_wound("qi", damage);
			msg += HIR"\n���ֻ���������������죬һ������,$nһ���ҽУ���̲�����������ȥ����\n"NOR;
			message_vision(msg, me, target );

		}
		else
		{
			msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
			message_vision(HIW "��$NƮ�����ʹ�����Ҿ������𽣡��ķ�����ʱ�������Ʈ�ݶ�������ǧ�������裬����ͷ����������$n���Ѽӱ���������Ըй���ƵƵ�մ졣\n" NOR, me, target);
			target->receive_damage("qi", damage/2,me);
			target->receive_wound("qi", damage,me);
			target->receive_damage("jing", damage,me);
			target->receive_wound("jing", damage/2,me);
			message_vision(msg, me, target );
		}

		message_vision(msg, me, target);
	}
	msg = HIY "\n$NͻȻ��ȫ������з����������ĵ���΢����֮���������������δ������������$n�ؿڻ�ȥ��\n\n"NOR;
	msg += HIG"��һ���Ƕ����ɵľ�ѧ��������������ա����⡰������ա����Ʒ���ֻһ�У�������\n";
	msg += HIG"һ��Ҳ�������仯����ʽƽƽ������һ�ɲ��䣬����������֮�����������Զ����ɾ���\n";
	msg += HIG"�ڹ���Ϊ������һ�Ƽȳ�����������ɽ����һ��Ϯ�������˵��޿ɵ������޿ɱܡ�\n\n";

	if( random( me->query("xyzx_sys/level") ) > random( target->query("xyzx_sys/level")*2 ) || !living(target) )
	{
		damage = me->query_skill("linji-zhuang",1);
		damage += me->query_skill("jinding-zhang",1);
		damage *= me->query("con");
		target->receive_damage("qi", damage);
		target->receive_wound("qi", random(damage));

		msg += HIR"��������Ȼһ�����죬$N�Ѵ�����$p�ؿ�.\n"NOR;
		msg += RED"ֻ��һ�����죬$nȫ��������ѣ���������ɽ�������һ�������Ӵ�������ء�\n"NOR;
		msg += NOR;
	}
	else if( random( me->query("xyzx_sys/level") ) > random( target->query("xyzx_sys/level") ) || random(target->query_skill("dodge")) < random( me->query_skill("unarmed") )  )
	{
		damage = me->query_skill("linji-zhuang",1);
		damage += me->query_skill("jinding-zhang",1);
		damage *= me->query("con");
		damage = damage / 2;

		target->receive_damage("qi", damage);
		target->receive_wound("qi", random(damage));

		msg += HIY"$p�ۿ���һ���������ڣ�֪�����ڶԸ�����æ�����ֿ�����������Ȼһ�����죬$N�Ѵ�����$p�ؿ�.\n"NOR;
		msg += RED"$n���ӱ���һ�����ݰ㣬�ڿ���ƽƽ�ķ��˳�ȥ������ˤ�ڵ��£�������Ѫ���磮\n"NOR;
		msg += NOR;
		target->add( "neili", -damage/3 );
	}
	else if( random( me->query("xyzx_sys/level") ) > random( target->query("xyzx_sys/level") ) ||
	         random( target->query_skill("dodge") ) < random( me->query_skill("unarmed") ) )
	{
		damage = me->query_skill("linji-zhuang",1);
		damage += me->query_skill("jinding-zhang",1);
		damage *= me->query("con");
		damage = damage / 3;
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", random(damage), me);

		msg += HIM"$p�ۿ���һ���������ڣ���æʹ�������������Ծ�����ɣ��������������̲ض�ü�ڼ��ϳ��ڹ���\n";
		msg += "��Բ���ɶ��������𺳣�$pֻ���ú���һ���ѱ�������������.\n"NOR;
		msg += RED"$n���ӱ���һ�����ݰ㣬�ڿ���ƽƽ�ķ��˳�ȥ������ˤ�ڵ��£�������Ѫ���磮\n"NOR;
		msg += NOR;
		target->add( "neili", -damage/4 );
	}
	else
	{
		msg += HIC"$n�ۿ���һ���������ڣ�ʹ��������������Ծ�����ɣ�\n\n"NOR;
		msg += HIW"$N��һ������ʹ����ȫ����˿��������ء�û�뵽ȫ���ô��������������ң�����΢΢������\n" NOR;
		neili_cost = jiali*3;
		if(neili_cost > me->query("neili"))
			neili_cost = me->query("neili");
		me->add("neili", -neili_cost );
		me->start_busy(3);
		message_vision(msg+"\n", me, target );
		return 1;
	}
	message_vision(msg+"\n", me, target);
	COMBAT_D->report_status(target);
	return 1;
}

