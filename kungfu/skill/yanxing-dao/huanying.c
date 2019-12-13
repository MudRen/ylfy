// huanying.c  雁行刀法「无形幻影」

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
        return notify_fail(RED"开什么玩笑，没装备刀怎么使「无形幻影」？\n"NOR);
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「无形幻影」只能对战斗中的对手使用。\n");
    if ((int)me->query_skill("yanxing-dao", 1) < 60 )
        return notify_fail(WHT"你雁行刀法不够娴熟，使不出「无形幻影」。\n"NOR);
    if ((int)me->query_skill("linji-zhuang", 1) < 90 )
        return notify_fail(RED"你临济庄火候不够，「无形幻影」不成招式。\n"NOR);
    if ((int)me->query("max_neili")<300)
        return notify_fail(RED"你的内力修为不足，无法运足「无形幻影」的内力。\n"NOR);
    if ((int)me->query("neili")<200)
    {
        return notify_fail(HIC"你现在内力不够，没能将「无形幻影」使完！\n"NOR);
    }
    msg = HIC "$N大喝一声，全场四处游动，$n只看到$N化做数团身影，漫天刀\n"NOR;
    msg += HIC"光席卷而来，$n奋力一架，但$N刀分数路，$n只架住一刀！\n"NOR;
    message_vision(msg, me, target);

    me->clean_up_enemy();
    target = me->select_opponent();

    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    me->add("neili", -100);
    me->start_busy(random(5));
    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}
