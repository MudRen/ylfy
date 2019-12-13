// ���ߺ��
// bye jfeng

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon, ob;
	string msg;
	int i,j,times,n;

	i = me->query_skill("jinshe-jian", 1);
	j = me->query_skill("sword", 1);
    times = me->query_skill("jinshe-jian",1)/100;
	if(times > 50) times = 50;
	
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����ߺ�ա�ֻ����ս����ʹ�á�\n");
	if ( !me->query_temp("weapon") )
		return notify_fail("�����ʹ����������ʹ�á����ߺ�ա���\n");
	if ( !objectp(weapon=me->query_temp("weapon")) || !(weapon->id("jinshe jian")) || sscanf(base_name(weapon), "/d/npc/m_weapon/%*s") )
		return notify_fail("������ֳֽ��߽�����ʹ�á����ߺ�ա���\n");
	if ( (int)me->query_str() < 32 )
		return notify_fail("��ı�������, ������ʹ���������! \n");
	if ( (int)me->query_skill("sword",1) < 1000 )
		return notify_fail("��Ļ��������Ļ�򻹲�����, ����ʹ����һ���� !\n");
	if ( (int)me->query_skill("jinshe-jian",1) < 500 )
		return notify_fail("��Ľ��߽����Ļ�򻹲�����, ����ʹ����һ���� !\n");
	if ( me->query_skill_mapped("sword") != "jinshe-jian" &&  me->query_skill_mapped("parry") != "jinshe-jian")
		return notify_fail("����뼤�����߽�������ʹ�á����ߺ�ա���\n");
	if ( (int)me->query("neili") < 5000 )
		return notify_fail("�������������\n");
	if( (int)me->query("max_neili") < 50000 )
		return notify_fail("���������Ϊ������\n");

	msg = HIY "\n$N�����������н��߽�һȦһ��,���߽������������ߺ�ա���Ȼ�ݳ�����ʱ��â�����������ν�������ǵؿ������ƺ���������Ҫ˺�ѣ�\n" NOR;
	message_vision(msg, me);
	me->add_temp("apply/strength", i);
	me->add_temp("apply/attack", j);
	me->add_temp("lianzhao", times);
	for ( n=0; n<times; n++ )
	{
		me->clean_up_enemy();
		ob = me->select_opponent();
		if ( !ob ) break;
		msg = HIR "\n���⼱������������.....��\n" NOR;
		message_vision(msg, me);
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);
	}
	me->add_temp("apply/strength", -i);
	me->add_temp("apply/attack", -j);
	me->delete_temp("lianzhao");
	me->add("neili",-100*times);
	me->start_busy(4);
	if ( ob && !ob->is_busy() ) ob->start_busy(random(2)+1);
	return 1;
}
