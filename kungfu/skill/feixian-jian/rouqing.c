#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int extra,mk,ms,mp,yk,ys,yp;
        object weapon;
        extra = me->query_skill("feixian-jian",1);
        if ( extra < 80) return notify_fail("��ķ��ɽ������������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("���������ȣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("ʹ�á��������ȡ���������һ�ѽ���\n");
        if ((int)me->query("neili")<150)
                return notify_fail("�������������\n"); 
        me->add("neili",-150);
        weapon = me->query_temp("weapon");
        message_vision(HIM"$Nʹ�����ɽ����еľ��У��������ȣݣ�һ�������˽������е�"+weapon->name()+"�������$n������һ����\n\n" NOR,me,target);        
        mk=me->query("kar");
        ms=me->query("dex");
        mp=me->query("per");
        yk=target->query("kar");
        ys=target->query("dex");
        yp=target->query("per");
        if (random(mk+ms+mp) * me->query("xyzx_sys/level") > (yk+ys+yp)*me->query("xyzx_sys/level"))
        {
        COMBAT_D->do_attack(me,target, weapon); 
        COMBAT_D->do_attack(me,target, weapon);
        COMBAT_D->do_attack(me,target, weapon);
        COMBAT_D->do_attack(me,target, weapon);
        COMBAT_D->do_attack(me,target, weapon);
        COMBAT_D->do_attack(me,target, weapon);
        COMBAT_D->do_attack(me,target, weapon); 
        COMBAT_D->do_attack(me,target, weapon);         
        
        message_vision(WHT"$N�����˽������$n�����˸���æ���ң�\n" NOR,me,target);
        me->start_busy(5);
        } else { 
                message_vision(HIC"����$n������$N����ʽ,�û�����������\n" NOR,me,target);
                me->start_busy(3);
        }        
        return 1;
}


