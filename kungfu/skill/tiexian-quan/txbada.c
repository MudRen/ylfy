// txbada ���߰˴�
// modify by lyy 2016-6-27

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;
 
int perform(object me, object target)
{
    string msg;
	object weapon;
	
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("�����߰˴�ֻ����ս����ʹ�á�\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����߰˴�ֻ�ܿ���ʹ�á�\n");		
    
	if( me->query_skill_mapped("unarmed") != "tiexian-quan" )
	    return notify_fail("��û��ʹ������ȭ��\n");
	
	if( (int)me->query("neili") < 700 )
        return notify_fail("�������������\n");

    if( me->query_skill("tiexian-quan",1) < 5000 )
       return notify_fail("�������ȭ��򲻹����޷�ʹ�á����߰˴򡹣�\n");

    if( (int)me->query_skill("force",1) < 6000 )
        return notify_fail("����ڹ���Ϊ�������޷�ʹ�á����߰˴򡹣�\n");
	
	weapon = me->query_temp("weapon");

        msg = HIY "$Nʹ���������µ�[����ȭ]��һ��[���߰˴�]��ʽ������\n" NOR;
        	message_vision(msg, me, target);                
		msg = HIC "��һȭ------Ц���߽�һָ�ɣ�" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "�ڶ�ȭ------Ҷ��������ɽ����" NOR;
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "����ȭ------�����������ͷ������" NOR;
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "����ȭ------�ط������ķ�����������" NOR;
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "����ȭ------���Ļ����忴�أ���������" NOR;
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "����ȭ------ãã��ˮ�����죡����������" NOR;
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "����ȭ------�������������ƣ�������������" NOR;
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		msg = HIC "���һȭ----�紵��ѩ��ǧɽ����������������" NOR;
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);  
        me->add("neili", -700);
        me->start_busy(2);

        return 1;
}