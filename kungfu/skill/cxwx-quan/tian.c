// marry 99.9
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{        
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() )
                return notify_fail("天旋地转只能用在对手身上。\n");

        if( (int)me->query_skill("cxwx-quan", 1) < 200 )
                return notify_fail("你的痴心妄想拳还不够娴熟，不能使敌人天旋地转。\n");
        if( me->query("family/family_name") != "痴心妄想门" )
                return notify_fail("你不是痴心妄想门的人，不能使敌人天旋地转。\n");

        if( (int)me->query_skill("wangran-xinfa", 1) < 200 )
                return notify_fail("你的妄然心法不够娴熟，不能使敌人天旋地转。\n");

        msg = HIR "$N拳中夹着一股"HIY"罡气"HIR"，一招“"HIB"天旋地转"HIR"”奋力击向$n。\n"NOR;

        me->start_busy(1);
        if( random( (int)me->query_skill("cxwx-quan",1)) > random(target->query_skill("dodge",1) ) ) {
                msg +=  HIW" 结果$p被$P攻了个正着！\n" NOR;
                target->receive_damage("qi",(int)me->query_skill("unarmed"));
                target->receive_wound("qi",20 + random(10));
                target->receive_wound("jing", random(50)+20);
                target->apply_condition("tian", random(me->query_skill("cxwx-quan",1)/10) + 1 + target->query_condition("tian"));
                me->start_busy(1 + random(2));
        } else 
       {
                msg += MAG "可是$p眼见不妙，早早的躲了开去。\n" NOR;
                me->start_busy(3);
        }
        message_vision(msg, me, target);
        return 1;
}
