// zhua.c  �����׹�צ������һ����
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("������һ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
//   if( (int)me->query("shen", 1) > 0)	
//      return notify_fail(WHT"�����������ʿ�������ܡ�����һ�������������书��\n"NOR);	
    if( (int)me->query_skill("jiuyin-baiguzhao", 1) < 300 )
  
      return notify_fail(WHT"��ľ����׹�צ������죬��ʹ����������һ������\n"NOR);
    if( (int)me->query_skill("force", 1) < 400 )
        return notify_fail(RED"����ڹ��ķ���򲻹���ʹ�á�����һ�����������Լ��ľ�����\n"NOR);
	damage = (int)me->query_skill("unarmed");
        damage = damage *3 + random(damage);
	if ( me->query("neili") < damage)
		return notify_fail(RED"�������������ʹ�á�����һ�����������Լ��ľ�����\n"NOR);
    msg = HIC "$NͻȻ��˫�Ʊ�צ������ǰ��Ȼ����糵�㼱ת��Ȧ������ʩչ��������һ������˫צ����һ�����������$n��ת��Ȧ���ֻص�ԭ�ء�\n"NOR;
    if (random(me->query_skill("force")) > target->query_skill("force")/2|| random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/3 )
    {
        me->start_busy(2);
        target->start_busy(random(3));
        target->receive_damage("qi", damage, me);
        target->receive_wound("qi", damage, me);
        target->receive_damage("jing", damage, me);
        target->receive_wound("jing", damage, me);
        me->add("neili", -damage);
   msg += HIC"ԭ��$N����$nͷ��������������������ָ����$nֻ����ͷ��һ�������������������һ���ˡ�����������\n"NOR;
    } else
    {
        me->start_busy(4);
        msg += HIY"����$p������$P����ͼ������ͷ������һ�ߡ�\n"NOR;
    }
    message_vision(msg, me, target );
	me->fight_ob(target);
    if(userp(target)) target->fight_ob(me);
    else if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}
