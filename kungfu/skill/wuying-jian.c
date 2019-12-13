//wuying-jian ������Ӱ��
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N�ս�����$wһ�С���ȥ���硹����$n��$l",
        "force" : 50,
        "dodge" : 40,
        "damage" : 20,
        "lvl"    : 0,
        "skill_name" : "��ȥ����", 
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С������޹⡹������$w���´̳���ֱ��$n��ȥ",
        "force" : 70,
        "dodge" : 10,
        "damage" : 30,
        "lvl"    : 20,
        "skill_name" : "�����޹�",
        "damage_type" : "����"
]),
([      "action" : "$N��ǰ����һ��������$wʹ�����������ֱ��$n�ĺ�",
        "force" : 90,
        "dodge" : 80,
        "damage" : 50,
        "lvl"    : 40,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N���һ����ʹ�����ľ���ˮ������$wֱ��$n��Ҫ��",
        "force" : 90,
        "dodge" : 60,
        "damage" : 80,
        "lvl"    : 60,
        "skill_name" : "�ľ���ˮ",
        "damage_type" : "����"
]),
([      "action" : "ֻ��$N�������е�$w��ʹ����������ա������ֱ��$n",
        "force" : 90,
        "dodge" : 70,
        "damage" : 110,
        "lvl"    : 80,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N�������е�$w��ʹ��������Ҷ�䡹��������ֱ��$n",
        "force" : 120,
        "dodge" : 60,
        "damage" : 120,
        "lvl"    : 100,
        "skill_name" : "����Ҷ��", 
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��������������������$w�������һ����˸����������$n",
        "force" : 200,
        "dodge" : 80,
        "damage" : 140,
        "lvl"    : 120,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N����ʹ������֮���塸��Ӱ���١�������$w�����һ������ǵصĴ���$n",
        "force" : 300,
        "dodge" : 90,
        "damage" : 250,
        "lvl"    : 150,
        "skill_name" : "����Ӱ���١�",
        "damage_type" : "����"
]),
([      "action" : HIY"$Nʹ����Ӱ����֮���վ�����������ˮ��,����$w��������һ�����$n"NOR,
        "force" : 400,
        "dodge" : 100,
        "damage" : 800,
        "lvl"    : 220,
        "skill_name" : "HIY��������һ��"NOR,
        "damage_type" : "����"
]),

});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query_skill("hunyuan-yiqi", 1) < 150)
                return notify_fail("��ġ���Ԫһ������򲻹����޷�ѧ����Ӱ��������\n");
        if ((int)me->query("max_neili") < 300)
                return notify_fail("�������̫�����޷�������Ӱ��������\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("wuying-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/4)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("�����������������Ӱ��������\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("�����������������Ӱ��������\n");
        me->receive_damage("qi", 40);
        me->add("neili",-15);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"wuying-jian/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;
        if( random( me->query_skill("sword") ) > random( victim->query_skill("force"))) {
                victim->receive_wound("qi", damage_bonus );
                return HIR "���������꡹һ������һ�����������������Ȼ��$nѪð���ɣ���$N�������ˣ�\n"NOR;
        }
}
