#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon, ob;
    string msg;
        me = this_player();
    me->clean_up_enemy();
 ob = me->select_opponent();
if (me->is_fighting())
{
if  (environment(me)!=environment(ob) ) 
     return notify_fail("�Է��Ѿ������ˡ�\n");
}
        if ( (string)me->query("family/family_name") != "��ɽ��") 
                 return notify_fail("ֻ�л�ɽ���Ӳ���ʹ�ø�PFM��\n");
   if (me->query_temp("perform")>time()) return notify_fail("����һ��δʹ�꣡\n");
        if( !me->is_fighting() )
                 return notify_fail("���¾Ž��ġ��������ơ�ֻ����ս��ʱʹ�á�\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    else me->set_temp("secondly_weapon",1);

    if( (int)me->query_skill("sword") < 300 ||
        me->query_skill_mapped("sword") != "dugu-jiujian")
        if( (int)me->query("neili") < 5000 )
                return notify_fail("�������������\n");
        if( (int)me->query("max_neili") < 5000 )
                return notify_fail("���������Ϊ������\n");

        msg = HIW "����$N" HIW "����һ�գ�ʹ����ɽ��������֮"
              HIG"���������ơ�"HIW"��ת��֮�������޷죬\n         һ���ȳ�������"
               "ԴԴ��к�������Ծ̲������������"
               HIW "\n" NOR;
    message_vision(msg, me);
    me->set_temp("perform",time()+3);
        if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        me->add("neili",-random(4500)-150);
}
    me->delete_temp("secondly_weapon");
    return 1;
}

