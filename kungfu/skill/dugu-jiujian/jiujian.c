// �Ž���һ
// by lonely
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
	int count,skill;
	string msg;
	if( !me->is_fighting() )
		return notify_fail("���Ž���һ��ֻ����ս����ʹ�á�\n");
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���Ž���һ��ֻ����ս����ʹ�á�\n");
	if (me->query_temp("perform"))  return notify_fail("����һ����ʽ��û���!\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if((int)me->query_skill("dugu-jiujian",1) < 1000)
		return notify_fail("��Ķ��¾Ž��Ļ�򻹲�����, ����ʹ����һ���� !\n");
	if((int)me->query_skill("sword",1) < 1000)
		return notify_fail("��Ļ��������Ļ�򻹲�����, ����ʹ����һ���� !\n");
	if( (int)me->query("neili") < 8000 )
		return notify_fail("�������������\n");
	if( (int)me->query("max_neili") < 20000 )
		return notify_fail("���������Ϊ������\n");
	msg =
	    HIY "\n$N����Ĭ������ʤ���У���̾һ����ݲ��ã�ʹ�����¾Ž��ľ������Ž���һ����\n" NOR;
	message_vision(msg,me,target);
	me->clean_up_enemy();
	skill=me->query_skill("dugu-jiujian",1);
	ob = me->select_opponent();
	me->add("neili", -3000);
	if (weapon == me->query_temp("secondary_weapon"))
		me->set_temp("secondly_weapon",1);
	for (count=0; count<10; count++)
	{
		me->add_temp("str",skill/10);
		COMBAT_D->do_attack(me, ob, weapon, 0);
	}
	me->delete_temp("str");
	me->delete_temp("secondly_weapon");
	
	return 1;
}

void del_perform(object me)
{
	if (!me) return;
	me->delete_temp("perform");
}
