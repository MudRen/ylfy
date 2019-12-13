//qinnashou.c  ������

#include <ansi.h>
inherit SKILL;

object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}
string* buwei = ({
        "�����ⲿ",
        "����",
        "���ֹؽ�",
        "����",
        "�粿�ؽ�",
        "����ҪѨ",
        "ϥ�ؽ�",
        "����"
});

mapping *action = ({
([      "action": "$N˫üһ�˫ȭ΢΢һ�٣�Ȼ��ɿ��ץ��$n��" + buwei[random(8)] + "",
        "dodge": 30,
        "force": 280,
        "damage": 180,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$Nʩ�����þ�����һ����ץ��$n��" + buwei[random(8)] + "",
        "force" : 300,
        "parry" : 5,
        "damage": 180,
        "lvl" : 10,
        "damage_type" : "����"
]),
([      "action": "$N����$n�Ĺ�����һ��ץ��$n��" + buwei[random(8)] + "",
        "force" : 280,
        "parry" : 5,
        "damage": 280,
        "lvl" : 20,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return  usage=="hand" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���������ֱ�����֡�\n");
        return 1;
}


mapping query_action(object me, object weapon)
{
        int i, level;
        object victim;
        string bw;
        
        if( !victim && me->is_fighting() ) victim = offensive_target(me);
        level   = (int) me->query_skill("qinnashou",1);
        
        bw = buwei[random(sizeof(buwei))];
if (me && victim)
{
        if ((int) me->query_skill("qinnashou",1) > random(50) && level > random(240) && me->query("neili") > 300
        && random(me->query("combat_exp")) > victim->query("combat_exp")/2 && random(2)==0
         && me->query_skill_mapped("parry") == "qinnashou"
         && me->query_skill_mapped("unarmed") == "qinnashou"
         && !me->is_busy()
         && !victim->is_busy()
         && !me->query_temp("weapon")) {
                me->add("neili", -50);
                message_vision(HIC"$N�����ü���Ȼ��ץס��$n��"+bw+"!\n"NOR,me,victim);
                message_vision(GRN"$N�˱ܲ�������$n����ס"+bw+",�ж�����ٻ�������\n"NOR,victim,me);
                victim->start_busy(1 + random(level/50));
        }
}
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if (me->query_skill("qinnashou",1) < 99)
           return notify_fail("�����ֻ�ܴ���һ�ټ�ʱ��ѧϰ��\n");

        if ((int)me->query("jing") < 100)
                return notify_fail("��ľ������������书��\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("����������������书��\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("����������������书��\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);
        return 1;
}
