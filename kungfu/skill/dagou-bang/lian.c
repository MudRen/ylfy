// lian.c �򹷰����������־�
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int attack_time,slow;
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�������־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "club")
		if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "club")
			return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query_skill("dagou-bang", 1) < 300 )
		return notify_fail("��Ĵ򹷰���������죬����ʹ�á������־���\n");
	if (!me->visible(target))    
		return notify_fail("�㿴����"+target->name()+"��\n");
	if (me->query_temp("perform"))  
		return notify_fail("����һ����ʽ��û���!\n");
	if ( me->query("neili")<150 )  
		return notify_fail("�����������!\n");
	if( me->is_busy()) 
		return notify_fail("��������æ�š�\n");
	msg = HIG "$Nʹ���򹷰����������־�����ͷ�����ó���������Ӱ�����಻��������$n����Ҫ����\n";
	if(  !living(target) || random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/10 )
	{
		attack_time = (int)(me->query_skill("dagou-bang", 1) / 50)-1;
		if(me->query_skill("dagou-bang", 1)<500) slow=2;
		else if(me->query_skill("dagou-bang", 1)<1000) slow=1;
		else slow=0;

		if(attack_time < 1) attack_time = 1;
		if(attack_time > 50) attack_time = 50;
       me->start_call_out( (: call_other, __FILE__, "do_attack", me, target,weapon,attack_time :), 1);
		if (me->query("neili")<150)
			me->set("neili",0);
		else
			me->add("neili", -150);
		me->set_temp("perform",1);
	}
	else
	{
		msg += HIY  "����$p"+ HIY +"������$P����ͼ����û���ϵ���\n" NOR;
		me->start_busy(1);
	}
	message_vision(msg, me, target);
	return 1;
}

void do_attack(object me,object target,object weapon,int attack_time)
{
	int i;
	if (!me) return;
	me->delete_temp("perform");
	if (!living(me) || !target ) return;
	if (weapon == me->query_temp("secondary_weapon") )
		me->set_temp("secondly_weapon",1);
	if (!weapon->query("equipped"))
	{
		me->start_busy(3);
		return;
	}
	if (environment(me)!=environment(target)) return;
	me->add_temp("lianzhao", attack_time);
	for(i = 0; i < attack_time; i++)
		if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0)
		{
			me->set_temp("action_msg","������");
// �ϵ��Ķϵ��Ķϵ��Ķϵ��Ķϵ��Ķϵ��Ķϵ��Ķϵ��ģ�
			if (!weapon->query("equipped"))
			{
				me->start_busy(2);
				return;
			}
			if (me->query_skill_mapped("club")!="dagou-bang")
			{
				me->start_busy(3);
				return;
			}
			COMBAT_D->do_attack(me, target, weapon, 0);
			me->start_busy(1);
		}
		else break;
	me->delete_temp("secondly_weapon");
	me->delete_temp("lianzhao");
	if (i) message_vision(CYN " ���$p��$P���˸����ֲ�����\n" NOR, me, target);
}
