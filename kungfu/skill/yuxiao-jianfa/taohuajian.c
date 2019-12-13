// jianzhang.c  
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, count;
	
	if ( !target ) target = offensive_target(me);
	if ( !target || !me->is_fighting() ) 
		return notify_fail("���һ����衹ֻ����ս����ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");
	if ( me->query_skill("bibo-shengong",1) < 500 ) 
		return notify_fail("��ı̲��񹦵ȼ�����, ����ʹ�á��һ����衹��\n");
	if ( (count = me->query_skill("yuxiao-jianfa", 1)) < 500 ) 
		return notify_fail("������｣���ȼ�����, ����ʹ�á��һ����衹��\n");
	if( me->query_skill_mapped("sword") != "yuxiao-jianfa" )
	    return notify_fail("��û�м������｣����\n");
	if ( me->query("neili") < 7000 ) 
		return notify_fail("��������������޷����á��һ����衹��\n");
	if ( !objectp(weapon = me->query_temp("weapon")) ) 
		return notify_fail("�����޽�����ʹ�����һ����衹��\n");

	message_vision(HBMAG"$Nʹ���һ����������һ����衹������Ȼ�ӿ졣��Ӣ�ͷף�\n\n"NOR, me);
	count /= 50;
    if(count > 50 ) count = 50;
	me->add_temp("lianzhao", count);
	for ( i=0; i<count; i++ )
	{
		switch ( random(6) )
		{
			case 0: msg = HIM"�����һ���\n" NOR;
					break;
			case 1: msg = HIR"�����䣡\n" NOR;
					break;
			case 2: msg = HIY"���컨�꣡\n" NOR;
					break;
			case 3: msg = HIC"�仨���⣡\n" NOR;
					break;
			case 4: msg = HIG"�ٻ���ţ�\n" NOR;
					break;
			case 5: msg = HIB"�����޺ۣ�\n" NOR;
					break;
		}
		message_vision(msg, me);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_REGULAR);
		me->add("neili", -100);
		me->delete_temp("lianzhao");
	}

	me->start_busy(2);
	return 1;
}
