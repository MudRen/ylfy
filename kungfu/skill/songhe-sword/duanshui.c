//Cracked by Roath
//Ansi 99.12
// lilong alter 2002.01.17
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int ap, dp, damage, chance;
	string msg;
	object weapon;
                
	if ( !target ) target = offensive_target(me);
	if ( !target || !target->is_character() || target->is_corpse() || target==me) return notify_fail("��Ҫ��˭ʩչ����ˮ�޺ۡ���\n");
	if ( !me->is_fighting(target) ) return notify_fail("����ˮ�޺ۡ�ֻ����ս����ʹ�ã�\n");     
	if ( playerp(me) && me->query("family/family_name") != "��ɽ��" ) return notify_fail("������ɽ�Ĳ����á���ˮ�޺ۡ���\n");
	if ( playerp(me) && me->query("shushan/duanshui_perform") !=1 ) return notify_fail("�㻹û��ᡸ��ˮ�޺ۡ���\n");
	if ( (int)me->query("max_neili") < 5000 ) return notify_fail("�������������\n");
	if ( (int)me->query("neili") < 5000 ) return notify_fail("����������㣡\n");
	if ( (int)me->query("jing") < 3000 ) return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
	if ( (int)me->query_skill("songhe-sword", 1) < 500 ) return notify_fail("����ɺ׽�����Ϊ��������ʹ����һ�л������ѣ�\n");
	if ( me->query_skill_mapped("force") != "shushan-force" ) return notify_fail("û����ɽ�ķ��޷���Ԧ������\n");
	if ( (int)me->query_skill("shushan-force", 1) < 500 ) return notify_fail("�����ɽ�ķ��ȼ�����������ʹ����һ�У�\n");
	if ( !(weapon = me->query_temp("weapon")) ) return notify_fail("������ֳֽ�����ʹ�ý�����\n");
	
	msg = CYN"\n$N����ζ��缲�磬�Կ�����ǧ�߷������ٶȣ�ֱ��$n��\n"NOR;
	ap = me->query_skill("sword");
	dp = target->query("dodge"); 
	chance = ap*10/((ap+dp)/10);
	
	if ( target->is_busy() ) chance *= 3;
	if ( chance > 40 ) 
	{
		damage = (me->query_skill("sword")+me->query("jiali"))*2;
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/2, me);
		target->start_busy(1+random(3));
		msg += CYN"���$n��$N�ġ���ˮ�޺ۡ�����������\n"NOR;
	}  
	else msg += "���Ǳ�$n�㿪�ˡ�\n"NOR;
	
	message_vision(msg, me, target);
	
	if ( damage > 0 ) COMBAT_D->report_status(target);
	if ( !target->is_fighting(me) ) 
	{
		if ( living(target) ) 
		{
			if ( playerp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
	}
	
	me->receive_damage("qi", 200+me->query("jiali"));
	me->start_busy(1+random(3));
	return 1;
}

