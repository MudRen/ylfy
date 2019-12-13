#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon, ob;
	string msg;
	int i;

	ob = me->select_opponent();

	if (!target ) target = offensive_target(me);
	if (!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����ֵ���ֻ����ս��ʱʹ�á�\n");
	if (me->query_temp("perform")>time()) return notify_fail("����һ��δʹ�꣡\n");
	if ( (string)me->query("family/family_name") != "������")
		return notify_fail("�����ֵ���ֻ�������ɴ��˲���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))|| (string)weapon->query("skill_type") != "blade")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))|| (string)weapon->query("skill_type") != "blade")
		 return notify_fail("��ʹ�õ��������ԡ�\n");
		else me->set_temp("secondly_weapon",1);
	if( (int)me->query("neili") < 200 )
		return notify_fail("�������������\n");
	if( (int)me->query_skill("blade",1) < 100 || me->query_skill_mapped("blade") != "tianxin-blade")
		return notify_fail("��ġ����е������������������޷�ʹ�á����ֵ�����\n");
	msg = HIY "$N��̤̫�飬������翣�˲��������$n����ǰ����ˢ����ˢ����ˢ�������ѿ���$n��\n" NOR;
	message_vision(msg, me, ob);
	me->clean_up_enemy();
	me->add("neili", -150);
	me->set_temp("perform",time()+3);
	me->set_temp("perform_sanfen",1);
	for(i = 0; i < 3; i++)
		if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0)
		{
			me->set_temp("action_msg",NOR WHT"�����ɢ\n"NOR);
			if (!weapon->query("equipped")) break;
			COMBAT_D->do_attack(me, ob,weapon, 0);
		}
		else break;
	me->delete_temp("perform_sanfen");
	me->delete_temp("secondly_weapon");
	return 1;
}

