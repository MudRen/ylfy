// This program is a part of NITAN MudLIB
// moon-blade.c

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N����$w��ʹ��һ�С�Բ�µ��ա����������ã����ҿ�����������$n",
        "skill_name" : "Բ�µ���",
        "force"  : 120,
        "attack" : 35,
        "dodge"  : -30,
        "parry"  : -32,
        "lvl"    : 0,
        "damage" : 240,
        "damage_type" : "����",
        "skill_name"  : "Բ�µ���",
]),
([      "action" : "$Nչ���鲽������Ծ�䣬һ�С��������š�������һ������ն��$n",
        "skill_name" : "��������",
        "force"  : 160,
        "attack" : 42,
        "dodge"  : -40,
        "parry"  : -45,
        "lvl"    : 30,
        "damage" : 250,
        "damage_type" : "����",
        "skill_name"  : "��������",
]),
([      "action" : "$N����$wһ����һ�С����Ƽ��¡�������$w����һ������������$n��$l",
        "skill_name" : "���Ƽ���",
        "force"  : 185,
        "attack" : 51,
        "dodge"  : -45,
        "parry"  : -47,
        "lvl"    : 50,
        "damage" : 260,
        "damage_type" : "����",
        "skill_name"  : "���Ƽ���",
]),
([      "action" : "$N��̬���У�����$w���أ�һ�С���Ӱ���ˡ��Ӳ���˼��ĽǶȻ���$n��$l",
        "skill_name" : "��Ӱ����",
        "force"  : 220,
        "attack" : 55,
        "dodge"  : -55,
        "parry"  : -61,
        "lvl"    : 80,
        "damage" : 270,
        "damage_type" : "����",
        "skill_name"  : "��Ӱ����",
]),
([      "action" : "$N����$w����$w��ͣ�ز����ţ��������ϵķ��������С���ǰ���¡���������$n",
        "skill_name" : "��ǰ����",
        "force"  : 255,
        "attack" : 65,
        "dodge"  : -60,
        "parry"  : -72,
        "lvl"    : 100,
        "damage" : 280,
        "damage_type" : "����",
        "skill_name"  : "��ǰ����",
]),
([      "action" : "$N����$w��ͬ���Ǳ��꣬����ͣЪ�س�$n��ȥ������һ�С������¡�",
        "skill_name" : "������",
        "force"  : 290,
        "attack" : 70,
        "dodge"  : -70,
        "parry"  : -75,
        "lvl"    : 120,
        "damage" : 290,
        "damage_type" : "����",
        "skill_name"  : "������",
]),
([      "action" : "$N���е�$w����һ���磬��ʱ�����䵶���д��ŷ���֮��һ�С�������Ӱ����$n��$l����ȥ",
        "skill_name" : "������Ӱ",
        "force"  : 320,
        "attack" : 80,
        "dodge"  :- 85,
        "parry"  : -85,
        "lvl"    : 140,
        "damage" : 300,
        "damage_type" : "����",
        "skill_name"  : "������Ӱ",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        object weapon;

        if( me->query("con")<26 )
                return notify_fail("���о��˰��죬ֻ���ø�����Щ�ʼ���޷�������е����С�\n");

        if( me->query("int")<30 )
                return notify_fail("���о��˰��죬ֻ����������Щ�ʼ���޷�������е����С�\n");

        if( me->query("str")<26 )
                return notify_fail("���о��˰��죬�о�������Щ�ͣ�ʼ���޷�����ʩչ��\n");

        if( me->query("dex")<39 )
                return notify_fail("���о��˰��죬ֻ�����Լ������鶯�ԣ������޷���ϰ�����书��\n");

        if( me->query("max_neili")<3000 )
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 500)
                return notify_fail("����ڹ����̫ǳ��\n");

        weapon = me->query_temp("weapon");
        if (me->query_skill("moon-blade", 1) < 1000 &&(!objectp(weapon) || weapon->query("id") != "moon blade") )
                return notify_fail("���Բ�µ������֮ǰ������Բ���䵶��ϲ���ѧϰ��\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("moon-blade", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        return notify_fail("Բ�µ���������޷�������ͨ����ϰ������\n");
        if( !objectp(weapon = me->query_temp("weapon") )
         || weapon->query("skill_type") != "blade" )
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if( me->query("qi")<70 )
                return notify_fail("�������������������Բ���䵶��\n");

        if( me->query("neili")<70 )
                return notify_fail("�������������������Բ���䵶��\n");

        if (! me->present("moon blade") && me->query_skill("moon-blade") < 400)
                return notify_fail("���Բ�µ������֮ǰ������Բ���䵶��ϲ�����ϰ��\n");

        me->receive_damage("qi", 55);
        me->addn("neili", -61);
        return 1;
}

mixed hit_ob(object me, object victim, int damage)
{
        int lvl;
		string msg;
		lvl = me->query_skill("moon-blade", 1);
		lvl *= 2;
        if (damage < 100) return 0;

        if (random( me->query_skill("blade") ) > random( victim->query_skill("force")))
        {
                victim->receive_wound("qi", lvl);
                msg =  HIW "$N" HIW "����һХ�������ŷ����������ѩ���ĵ��⣬�������µ��¹��������\n"
                           "��ȴ���˸е�����ɭ�޵����㣬ȫ��ֹ��ס��ս����\n"
                            HIR "��ʱһ�ɱ����ĵ����ӹ�$n" HIR "ȫ��$n" HIR "ȫ���ʱ��Ѫ���죬ҡҡ������\n" NOR ;

                return msg;
        }
}

string perform_action_file(string action)
{
        return __DIR__"moon-blade/" + action;
}
