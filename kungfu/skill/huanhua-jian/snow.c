// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int i, lmt, damage ;	object weapon;
if( (int)me->query_skill("huanhua-jian",1) < 300)
		return notify_fail(HIW "��ġ�佻��������������ң��޷�ʹ�á�������ѩ����\n"NOR);
	if ((int)me->query("neili",1) < 200)
		return notify_fail("��������������޷�ʹ�á�������ѩ����\n");		
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail(HIW "��������ѩ��ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
	weapon = me->query_temp("weapon");
  if(!weapon) return notify_fail("���ñ���Ҳ���ã�����Ϊ�Լ�������ѽ!");
	msg = HIY  "$N��Хһ�������ж�Ю����֮ʽ�������͵ı������ߣ����е�\n"+ weapon->name()+  "���籩������$n������\n\n" NOR;
	message_vision(msg,me,target);
        if( !target->is_killing(me) ) target->kill_ob(me);
		damage = me->query_skill("sowrd") + (int)me->query_skill("guiyuan-dafa");
		damage = damage - random( target->query_skill("dodge")/3 );
		if(damage < 0 ) damage = 0; //2015.4 �������˺�Ϊ0
	lmt = random(5)+3;
	for(i=1;i<=lmt;i++)
	{
	msg =  HIW "$N���һ�����ӵ�"+chinese_number(i)+"����\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
//      target->receive_wound("jing", random( damage/20 ));
	target->receive_damage("qi", 20 + random(damage));
	target->receive_wound("qi", 20 + damage);
        me->add("neili", -80);
	me->start_busy(4);
	return 1;
}
