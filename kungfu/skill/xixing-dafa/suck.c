// suck.c
#include <ansi.h>
inherit F_SSERVER;
int exert(object me, object target)
{
    int sp, dp;
    if ( target == me )
        target = offensive_target(me);
    if( !objectp(target) || target->query("id") == "mu ren" )
        return notify_fail("��Ҫ��ȡ˭��������\n");
    if ( me->query_temp("sucked") )
        return notify_fail("��ո���ȡ��������\n");
    if( (int)me->query_skill("xixing-dafa",1) < 50 )      	
        return notify_fail("������Ǵ󷨹���������������ȡ�Է����������\n");
    if ( me->query("gender") == "����")
        return notify_fail("���޸����ԣ���������������ʹ�����Ǵ󷨡�\n");	
    if( (int)me->query("neili",1) < 100 )
        return notify_fail("�����������������ʹ�û����󷨡�\n");	
    if( (int)target->query("max_neili") <= 0 )
        return notify_fail( target->name() + "û���κ�������\n");
    if( (int)target->query("no_suck"))
        return notify_fail( target->name() + "û���κ�������\n");
    if( (int)target->query("neili") < 100  || !living(target))
        return notify_fail( target->name() +"�Ѿ�������ɢ�����Ѿ��޷�����������ȡ�κ������ˣ�\n");
     if(me->is_busy()) return notify_fail("����æ���ء�\n");
	 if( me->query("neili",1) > me->query("max_neili",1)*3 )
        return notify_fail("��ֻ����Ϣ�����������Կ��ƣ��ƺ��޷����ɸ����������\n");
	 if ( !me->query("xy_huiyuan") && target->query("id") == "nai niu" && domain_file(base_name(environment(me))) == "party" )
		return notify_fail(HIY"�������ţֻ�ṩ��ע���Աʹ�ã����޷���ȡ��\n"NOR);
     message_vision( HIY"$N�ֱ��͵س�����ץ��$n�������ϡ�ͻȻ֮�䣬$n�;������ڹء�����ء�����Ѩ��������ԴԴ��й��\n\n" NOR, me, target );
    if ( living(target) )
    {
		me->kill_ob(target);
        if( !target->is_killing(me) )
            target->kill_ob(me);
    }
        sp = me->query_skill("force") + me->query_skill("dodge",1);	
        dp = target->query_skill("force") + target->query_skill("dodge",1);
    me->set_temp("sucked", 1);      
    if (( random(sp) > random(dp) ) )
    {
       tell_object(target, HIR"��ֻ���������ϡ��ڹء�����ء�����Ѩ�����翪��������ȱ�ڣ���ʱȫ��������к�����������ˮ���̣���Ҳ���Զ½أ�\n" NOR);
		tell_object(me, HIG"�����" + target->name() + "�ĵ�Ԫ������ԴԴ���������˽�����\n" NOR);
        target->add("neili", -1*((int)me->query_skill("xixing-dafa", 1) + target->query("jiali")) );	
        if ( target->query("neili") <1 )
            target->set("neili",0);
        me->add("neili", (int)me->query_skill("xixing-dafa", 1) + target->query("jiali") );	
        me->start_busy(random(6));
        target->start_busy(random(4));
        call_out("del_sucked", 3, me);
    }
    else
    {   
        message_vision(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
        me->start_busy(4);
        call_out("del_sucked", 4, me);
    }
    return 1;
}
void del_sucked(object me)
{
    if ( !objectp(me) ) return;
    if ( me->query_temp("sucked")) me->delete_temp("sucked");
}
