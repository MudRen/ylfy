// chan.c ̫�������������־�
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int time;
    object weapon;
    string msg="";
    if( !target ) target = offensive_target(me);
    if( !target
    ||  !target->is_character()
    ||  !me->is_fighting(target) )
        return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");
      
    if( target->is_busy() )
        return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
        
    if( (int)me->query_skill("taiji-jian", 1) < 80 )
        return notify_fail("���̫������������죬����ʹ�á������־���\n");
        if( me->is_busy()) return notify_fail("��������æ�š�\n");     
    if (!me->visible(target))    return notify_fail("�㿴����"+target->name()+"��\n");
    msg = HIG "$Nʹ��̫�������������־�����������������ͼ����$n�Ĺ��ơ�\n";
    me->start_busy(2);
    time = (int)me->query_skill("taiji-jian") / 30;       	
    if (time<3) time = 3;
    if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/3 ) 
    {    	
        msg += HIR " ���$p��$P���˸����ֲ�����\n" NOR;
        target->start_busy(time*15);     	
    } 
    else 
    {
    	if(time > 5) time = 5;
        me->start_busy(time/2);
        msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
    }
    message_vision(msg, me, target);
    return 1;
}
