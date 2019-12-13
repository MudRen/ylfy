// diezhang.c (�����Ʒ�)  perform ��ɽ����
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
	string msg, *limbs;
	int p,count, damage = 0;
	int arg=(int)(me->query_skill("kunlun-zhang", 1) / 100);
	if ( arg > 50) arg = 50;
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("����ɽ���ơ�ֻ����ս���жԶ���ʹ�á�\n");

	if( objectp( me->query_temp("weapon")) )
		return notify_fail("ֻ�п��ֲ���ʩչ����ɽ���ơ���\n");

	if( me->query_skill_mapped("unarmed") != "kunlun-zhang" )
		return notify_fail("��û���������Ʒ���\n");

	if( (int)me->query_skill("kunlun-zhang", 1) < 30 )
		return notify_fail("����Ʒ�������죬����ʹ�á���ɽ���ơ���\n");

	if( (int)me->query_skill("xuantian-wuji", 1) < 300 )
		return notify_fail("��������޼����ȼ�����������ʹ�á���ɽ���ơ���\n");

	if( (int)me->query_str() < 25 )
		return notify_fail("���������������ǿ������ʹ�á���ɽ���ơ���\n");

	if(me->query_skill_mapped("force") != "xuantian-wuji" )
		return notify_fail("��û���������޼���\n");
	if( (int)me->query("max_neili", 1) < 1500 )
		return notify_fail("��������Ϊ����������ʹ�á���ɽ���ơ���\n");

	if( (int)me->query("neili", 1) < 100 * arg )
		return notify_fail("�����ڵ�����ʩչ������ô���С�\n");
	message_vision(HIG"$N����һ���������һ������������"HIW+ chinese_number(arg) +HIG"�ƣ���������ǰ�У�����������һ������$n��\n\n"NOR, me, target);
	if( random(me->query("xyzx_sys/level")) > target->query("xyzx_sys/level")/3 )
	{
		limbs = target->query("limbs");
		for(count = 0; count < arg; count++)
		{
			message_vision( replace_string(HIG+SKILL_D("kunlun-zhang")->query_action(me, me->query_temp("weapon"))["action"],
			                   "$l", limbs[random(sizeof(limbs))]) + "��\n"NOR, me, target);
			damage = damage+2000+random(4000);
			p = (int)target->query("qi")*100/(int)target->query("max_qi");
			msg = damage_msg(damage, "����");
			msg += "( $n"+eff_status_msg(p)+" )\n\n";
			//if (damage >1250) damage =1250;
			target->receive_damage("qi", damage);
			target->receive_wound("qi", damage/2);
			message_vision(msg, me, target);
		}
		me->add("neili", -100 * arg);
		me->start_busy(4);
	}
	else
	{
		me->start_busy(3);
		me->add("neili", -200);
		msg =HIY"\n$n���ͼ��ٺ��ˣ�˳���Ʒ����һ�����㿪���⹥����\n" NOR;
		message_vision(msg, me, target);
	}

	return 1;
}