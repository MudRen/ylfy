// jinglisuck.c
#include <ansi.h>
inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp, skill;
	int my_max, tg_max,max_suck;

    if ( target == me ) target = offensive_target(me);
    if( !objectp(target) || target->query("id") == "mu ren" )
        return notify_fail("��Ҫ��ȡ˭�ĵ�Ԫ��\n");
        my_max = me->query("max_jingli");
        tg_max = target->query("max_jingli");
    if ( me->query_temp("sucked") )
        return notify_fail("��ո���ȡ����Ԫ��\n");
    if( objectp(me->query_temp("weapon")) )
        return notify_fail("�������ֲ���ʩ�����Ǵ����˵�Ԫ��\n");
    if( (int)me->query_skill("xixing-dafa",1) < 100 )
        return notify_fail("������Ǵ󷨹���������������ȡ�Է��ĵ�Ԫ��n");
    if( (int)me->query("neili",1) < 20 )
        return notify_fail("�����������������ʹ�����Ǵ󷨡�\n");
    if( (int)target->query("max_jingli") < 10 || !living(target) )
        return notify_fail( target->name() + "��Ԫ��ɢ������δ�ۣ����޷�����������ȡ�κζ�����\n");
    //if( (int)me->query("max_jingli") >= 60000 && !userp(target) )
        //return notify_fail( target->name() + "�ľ�����ΪԶ�����㣬���޷�����������ȡ��Ԫ��\n");
    if (target->query("no_suck"))   
		return notify_fail(target->name()+"û���κξ���!\n");

	skill = (int)me->query_skill("xixing-dafa", 1);	
	
	if ( (int)target->query("max_jingli") < (int)me->query("max_jingli")/10 )
		return notify_fail( target->name() + "�ľ�����ΪԶ�����㣬���޷�����������ȡ��Ԫ��\n");	

    if(!me->query("xy_huiyuan"))
		return notify_fail(HIY"ֻ�л�Ա������ȡ������\n"NOR);
	if ( !me->query("xy_huiyuan") && target->query("id") == "nai niu" && domain_file(base_name(environment(me))) == "party" )
		return notify_fail(HIY"�������ţֻ�ṩ��ע���Աʹ�ã����޷���ȡ��\n"NOR);
	
        message_vision( HIR "$Nȫ��ǽڱ��죬˫�۱������ߣ���Ե�͵���$n������������ȥ��\n\n" NOR,me, target );
        me->kill_ob(target);
        target->kill_ob(me);
    if ( living(target) )
        { if( !target->is_killing(me) ) target->kill_ob(me); }
        sp = me->query_skill("force") + me->query_skill("dodge");
        dp = target->query_skill("force") + target->query_skill("dodge");
        me->set_temp("sucked", 1);      
    if (( random(sp) > random(dp) ) )
    {
        tell_object(target, HIR "��ֻ���춥���ѣ�ȫ�������Զ���������ѩ����ʧ����Ӱ���٣�\n" NOR);
        tell_object(me, HIG "�����" + target->name() + "�ĵ�Ԫ������ԴԴ���������˽�����\n" NOR);
        max_suck = 1 + (me->query_skill("xixing-dafa", 1)-100)/8;
        target->add("max_jingli", -max_suck );
        me->add("max_jingli", max_suck );
    if ( target->query("max_jingli") <1) 
        target->set("max_jingli",0);
    if( (int)me->query("potential") - (int)me->query("learned_points") < 90 )
        me->add("potential",  random(10));
        me->add("combat_exp", 10);
        me->start_busy(7);
        target->start_busy(random(7));
        me->add("neili", -10);
        call_out("del_sucked", 10, me);
}
    else
{
    message_vision(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
    me->start_busy(7);
    call_out("del_sucked", 20, me);
}
return 1;
}
void del_sucked(object me)
{
	if ( !objectp(me) ) return;
	if ( me->query_temp("sucked") )	me->delete_temp("sucked");
}
