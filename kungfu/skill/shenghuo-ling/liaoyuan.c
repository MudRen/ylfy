// ʥ����ԭ liaoyuan.c	

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

// ��ɫ
nosave string *ansi_arg = ({ RED, GRN, YEL, BLU, MAG, CYN, WHT, HIR, HIG, HIY, HIB, HIM, HIC, HIW });

int perform(object me, object target)
{
	object weapon,ob;
	int skill, times, i, max;
	string msg;

	if ( !target ) target = offensive_target(me);
	if ( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��ʥ����ԭ��ֻ����ս����ʹ�á�\n");
	if ( !objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword" )
		return notify_fail("��ʥ����ԭ�������ý�����ʩչ��\n");
	if ( me->query_skill_mapped("sword") != "shenghuo-ling")
         return notify_fail("����뼤��ʥ�������ʹ�á�ʥ����ԭ����\n");       
	if ( (int)me->query_skill("shenghuo-ling", 1) < 150 )
		return notify_fail("��ġ�ʥ�����������죬����ʹ�á�ʥ����ԭ����\n");
	if ( (int)me->query("neili") < 30000  ) 
		return notify_fail("�������������\n");

	skill = me->query_skill("shenghuo-ling", 1);
	max = sizeof(ansi_arg);
	times=(int)skill/50;
	if(times > 50) times = 50;
	me->add_temp("lianzhao", times);
	for ( i=0; i<times; i++ )
	{
		if ( me->query("neili") < 500 ) break;
		me->add("neili", -500);
		me->clean_up_enemy();                        	
		ob = me->select_opponent();
		if ( ob = me->select_opponent() )
		{
			msg = ansi_arg[random(max)]+"$N�������һ����â�������ǰ������ʥ�����໥һ��,���й�ʽ������ԭ֮�����$n��ȥ��\n"NOR;
			message_vision(msg, me, target);
			COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
		}
	}
    me->delete_temp("lianzhao");
	if ( me->is_fighting() ) me->start_busy(random(3));
	
	return 1;
}
