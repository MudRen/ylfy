//yihun.c

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
        int skill = (int)me->query_skill("jiuyin-zhenjing", 1), i;
        string msg;
	
	if( !target || target == me ) target = offensive_target(me);

	if( environment(me)->query("citybiwu") )
		return notify_fail("���ﲻ׼��ܡ�\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ׼��ܡ�\n");
	if( !target || target==me || !target->is_character() )
		return notify_fail("�ƻ��ֻ�ܶԶ���ʹ�á�\n");
		
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("���ƻ�󷨡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if ((int)me->query_skill("jiuyin-zhenjing", 1) < 1500)
		return notify_fail("��ľ����澭��Ϊ̫���ˣ��޷�ʹ���ƻ�󷨡�\n");
	if(!me->query("jiuyin/jm"))
		return notify_fail("�㻹û����������澭�ľ��裬�޷�ʹ���ƻ�󷨡�\n");
	if ( (int)me->query_skill("taoism", 1) < 3000)
		return notify_fail("����Ŀǰ�ĵ�ѧ��Ϊ�������������������ƻ�󷨣�\n");

    if( !living(target) && userp(target) && target->query("combat_exp")/5 > me->query("combat_exp") )
	return notify_fail("����Ҫɱ���ˣ���������ǿ̫�࣬�㲻�Ҷ��֡�\n");
	
    if (me->query_temp("yihun"))
                return notify_fail("�����������ƻ���ˡ�\n");
    if (me->query("max_neili") < 2000)
                return notify_fail("���������Ϊ���������ƻ�����裡\n");
    if (me->query("neili") < 1000)
                return notify_fail("����������������ƻ�����裡\n");

	me->start_busy(1);
	msg = HIW"$N����ӨȻ�й⣬����ͻȻ��ʼ����������ֵı��顣\n";
	
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/5	){
		msg += "$n��������ȡЦ$N��ȴ��֪������ѧ��$N�ı��顣\n"NOR;
		msg += CYN"\n$N��Ȼ�������Լ������Ķ�����$n�������Լ������ƵĹ�������������Խ��Խ�أ�\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili", - 600);
		if (random(skill) > (int)target->query_skill("dodge", 1)/3)
			target->start_busy(random(skill/50) + 3);
		if (!target->is_busy())
			target->start_busy(random(2) + 1);
		//target->add("qi",-target->query("max_qi"));//�������ƻ���˺�
		target->add_temp("apply/attack", skill/2);
		target->add_temp("apply/damage", skill/2);
		target->add_temp("apply/dodge", -skill*10);
		for (i=0; i<random(skill/100)+3; i++)
			COMBAT_D->do_attack(target, target, target->query_temp("weapon"));
		target->add_temp("apply/attack", -skill/2);
		target->add_temp("apply/damage", -skill/2);
		target->add_temp("apply/dodge", skill*10);
		target->add_temp("apply/attack", -skill/20);
		target->add_temp("apply/dodge", -skill/20);
	} else {
		msg += HIY"����$N��ô�仯���飬$n����������޶����ԡ�\n"NOR;
		message_vision(msg, me, target);
		me->add("neili", -600);
	}
	if(!me->is_fighting(target)) me->fight_ob(target);
	if(!target->is_fighting(me)) target->fight_ob(me);

        me->set_temp("yihun", 1);
	remove_call_out("checking");
        call_out("checking", 1, me);
        return 1;
}

void checking(object me)
{
	object target;
        int skill = (int)me->query_skill("jiuyin-zhengong", 1), i;
        string msg;
        target = offensive_target(me);

        if (!me || !me->query_temp("yihun")) return;
        if (!target ) return;
        if (me->is_ghost() || !living(me)){
                me->delete_temp("yihun");
                return;
                }
        if (!me->is_fighting() || me->query("neili") < 600) {
        	message_vision("\n$N�����𽥻��ǣ����ϻָ���ԭ�������顣\n\n", me);
        	me->delete_temp("yihun");
        	return;
        	}
	if( !target || !target->is_character() ) {
	        call_out("checking", 1, me);
	        return;
	}

	if (userp(target))
{
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/5	)
{
		msg = CYN"\n$N��Ȼ�������Լ������Ķ�����$n�������Լ������ƵĹ�������������Խ��Խ�أ�\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili", - 400);
		if (!target->is_busy())
			target->start_busy(random(2) + 1);
		target->add_temp("apply/attack", skill/2);
		target->add_temp("apply/damage", skill/2);
		target->add_temp("apply/dodge", -skill*10);
		for (i=0; i<(random(skill/100)+3)/2; i++)
			COMBAT_D->do_attack(target, target, target->query_temp("weapon"));
		target->add_temp("apply/attack", -skill/2);
		target->add_temp("apply/damage", -skill/2);
		target->add_temp("apply/dodge", skill*10);
		target->add_temp("apply/attack", -skill/20);
		target->add_temp("apply/dodge", -skill/20);
}
}
else {
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/5	){
		msg = CYN"\n$N��Ȼ�������Լ������Ķ�����$n�������Լ������ƵĹ�������������Խ��Խ�أ�\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili", - 400);
		if (!target->is_busy())
			target->start_busy(random(2) + 1);
		target->add_temp("apply/attack", skill/2);
		target->add_temp("apply/damage", skill/2);
		target->add_temp("apply/dodge", -skill*10);
		for (i=0; i<(random(skill/100)+3)/2; i++)
			COMBAT_D->do_attack(target, target, target->query_temp("weapon"));
		target->add_temp("apply/attack", -skill/2);
		target->add_temp("apply/damage", -skill/2);
		target->add_temp("apply/dodge", skill*10);
		target->add_temp("apply/attack", -skill/20);
		target->add_temp("apply/dodge", -skill/20);
	}
}
        call_out("checking", 1, me);
}       
