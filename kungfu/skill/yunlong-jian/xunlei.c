// jinshe-jianfa perform
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int i, j, z, max;
        object weapon;
        j = me->query_skill("yunlong-jian", 1);
        z = me->query_skill("yunlong-shengong", 1);
		max = j/50;
        if (max > 50) max = 50;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("��Ѹ�ס�ֻ����ս���жԶ���ʹ�á�\n");

		if ( !z || me->query_skill_mapped("force") != "yunlong-shengong" )
				return notify_fail("û�������񹦵Ĵ߶��޷�ʹ����Ѹ�ס���\n");

        if ( !weapon || weapon->query("skill_type") != "sword" || me->query_skill_mapped("sword") != "yunlong-jian" )
                return notify_fail("�������ʹ�ý�ʱ����ʹ����Ѹ�ס���\n");

        if(me->query_skill("yunlong-jian", 1) < 150 )
                return notify_fail("�������������������죬ʹ������Ѹ�ס���\n");

        if( (int)me->query_skill("force") < 200 )
                return notify_fail("����ڹ��ȼ�������ʹ������Ѹ�ס���\n");

        if( (int)me->query_str() < 32)
                return notify_fail("���������������ʹ������Ѹ�ס���\n");

        if( (int)me->query_dex() < 30)
                return notify_fail("�������������ʹ������Ѹ�ס���\n"); 

        if( (int)me->query("max_neili") < 1800 )
                return notify_fail("����������̫����ʹ������Ѹ�ס���\n");      

        if( (int)me->query("neili") < z*2 )
                return notify_fail("����������̫����ʹ������Ѹ�ס���\n"); 
		
		if( (int)me->query("jingli") < z )
                return notify_fail("�����ھ���̫����ʹ������Ѹ�ס���\n"); 
        me->add_temp("apply/strength", z/6);
        me->add_temp("apply/attack", j/6); 
        me->add_temp("lianzhao", max);
		
        msg = BLU"\n$N�����е�"+weapon->name()+"����������������������Ӱ���籼�׳��繥��$n��\n\n"NOR;
        message_vision(msg, me, target);
		for ( i=0; i<max+1; i++ )
		{
	        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		}
 
		me->add("neili",-max*100);
		me->add("jingli",-z);    
        me->add_temp("apply/strength", -z/6);
        me->add_temp("apply/attack", -j/6);
		me->delete_temp("lianzhao");
        me->start_busy(random(3));
        target->start_busy(random(3));
        return 1;
}
