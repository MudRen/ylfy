// qiong.c ��¥����

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int bonus;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("����¥���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ( me->query_temp("weapon"))
                return notify_fail("���ֲ���ʩչ����¥�����\n");

        if ( me->query("neili") < 40000 )
                return notify_fail("���������ʣ�޼����޷�ʩչ����¥�����\n");

        if ( me->query("max_neili") < 10000 )
                return notify_fail("���������Ϊ���㣬�޷�ʩչ����¥�����\n");

        if ( me->query_skill("mingyu-shengong", 1) < 500 )
                return notify_fail("��������񹦲�����죬����ʹ�á���¥�����\n");

        if ( me->query_skill("unarmed", 1) < 500 )
                return notify_fail("��Ļ���ȭ�Ų�����죬����ʹ�á���¥�����\n");

        if ( me->query("jiali") < 1 )
                return notify_fail("�����̫�٣��޷�ʹ�á���¥�����\n");

        if ( me->query_skill_mapped("force") != "mingyu-shengong" )
                return notify_fail("����ڹ�û��ʹ�����񹦣��޷�ʹ�á���¥���������\n");
        //if ( me->query_skill_mapped("parry") != "mingyu-shengong" )
            //    return notify_fail("����м�û��ʹ�����񹦣��޷�ʹ�á���¥���������\n");
        if ( me->query_skill_mapped("unarmed") != "mingyu-shengong" )
                return notify_fail("���ȭ��û��ʹ�����񹦣��޷�ʹ�á���¥���������\n");

        if ( me->query_temp("mingyu_pfm/qiong") )
                return notify_fail("������ʹ�á���¥�����\n");

        if ( me->query_temp("mingyu_pfm/qiong_over") )
                return notify_fail("��ո�ʹ�ù�����¥�������ʱ��Ѫ���������ǵ�һ�����ðɡ�\n");

        bonus = me->query_skill("mingyu-shengong", 1) / 3;
        bonus += me->query_skill("unarmed", 1) /3;
        bonus += me->query_skill("force", 1) /3;

       if (bonus>300) bonus=300;
        me->add_temp("apply/attack", bonus);
        me->add_temp("apply/damage", bonus);
        me->add_temp("apply/defense", bonus);
         
         message_vision(WHT"��"HIY"��¥����"WHT"��\n\n"HIG"ֻ��$N�ֹ⾢���ٶ�������������������չ�ᣬ
����һ�Ź�â����â��Ȼ����������һƬ���꣬��������$n������\n" NOR, me, target);

        me->set_temp("mingyu_pfm/qiong", bonus);
        me->add("neili", -200);

        remove_call_out("check_fight");
        // call_out("check_fight", 1, me, target, bonus);
	 me->start_call_out((: call_other, __FILE__, "remove_effect",me, bonus :), bonus/4);

        return 1;
}

void remove_effect(object me, int bonus)
{
	   if (!me) return;
        me->add_temp("apply/attack", -bonus);
        me->add_temp("apply/damage", -bonus);
        me->add_temp("apply/defense", -bonus);
        me->delete_temp("mingyu_pfm/qiong");
        me->set_temp("mingyu_pfm/qiong_over", 1);
        if ( me->is_fighting() )
                me->start_busy(1);

        remove_call_out("qiong_done");
        call_out("qiong_done", 8, me);
}

void qiong_done(object me)
{
        if ( !me ) return;

        tell_object(me, HIY"����һ��ʱ�����Ϣ�����ֿ���ʹ�á���¥����ˣ�\n"NOR);

        me->delete_temp("mingyu_pfm/qiong_over");
}

void check_fight(object me, object target, int bonus)
{
        if ( !me ) return;

        if ( !me->is_fighting() || !me->query_temp("mingyu_pfm/qiong") || me->query_temp("mingyu_pfm/qiong") < 1
             || !target || !living(target) )
        {
                message_vision(WHT"\n$N������һ���������е����ξ���Ҳ�Բ�����ǰһ�������ˡ�\n"NOR, me);
                remove_effect(me, bonus);
                return;
        }

        if ( me->query("neili") < 5000 )
        {
                message_vision(HIR"\n$N��ͷð�����������������棬���ϵľ���һ����ʧ�����ˡ�\n"NOR, me);
                remove_effect(me, bonus);
                return;
        }

        if ( me->query_skill_mapped("unarmed") != "mingyu-shengong" )
        {
                message_vision(HIR"\n$N��Ȼ��ʽһ�ߣ����ϵľ�����ʱ��ʧ����Ӱ���١�\n"NOR, me);
                remove_effect(me, bonus);
                return;
        }

        if ( me->query_temp("weapon") )
        {
                tell_object(me, HIR"\n��װ���ϱ������޷�����ʹ�á���¥����ˡ�\n"NOR, me);
                remove_effect(me, bonus);
                return;
        }

        remove_call_out("check_fight");
        call_out("check_fight", 1, me, target, bonus);
}


