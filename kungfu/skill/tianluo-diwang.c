// tianluo-diwang ���޵�����
#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([      "action" : "$N���ƻ�һ��Բ�����ƻ�����һ��Բ���ʺ�£֮�ƣ�����$n����ǰ��Ѩ",
        "force" : 160,
        "dodge" : 15,
        "lvl" : 0,
        "damage_type" : "����",
]),
([      "action" : "$N���ƻ��أ���ȭ�����󷢣�����һ��������������$n��$l",
        "force" : 185,
        "dodge" : 10,
        "damage_type" : "����",
        "lvl" : 20,     
]),
([      "action" : "$N������ǰ��ȥ��һ�¼��弲�����������۽���δ��֮�ʣ�˫�ֱ���$n��$l",
        "force" : 200,
        "dodge" : 10,
        "lvl" : 30,
        "damage_type" : "����"
]),
([      "action" : "$N�������»��أ�����ͻȻһ�䣬��Ȼ��Ϊ�������꣬����$n",
        "force" : 280,
        "dodge" : 10,
        "damage_type" : "����",
        "lvl" : 50,     
]),
([      "action" : "$N����Ӵ�����������˳���$nֻ�����ܲ�͸�磬��������ӡ����ôҲ���㲻��",
        "force" : 340,
        "dodge" : 15, 
        "lvl" : 70,        
        "damage_type" : "����"
]),
([      "action" : "$N˫�۷��裬��ֻ�������ƻ�����ǧ��ǧ�ƣ���$n���Ծ�����㣬ʼ�շɲ���ֻ����Χ����ȦȦ", 
        "force" : 400,
        "dodge" : 20,
        "lvl" : 90,
        "damage_type" : "����"
]), 
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���ַ�����ϰ���޵����ơ�\n");
        if ((int)me->query_skill("yunu-xinjing", 1) < 10)
                return notify_fail("�����Ů�ľ����򲻹����޷���ϰ���޵����ơ�\n");
        if ((int)me->query_skill("strike", 1) < 20)
                return notify_fail("��Ļ����Ʒ�̫��޷���ϰ���޵����ơ�\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("tianluo-diwang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
          if ((int)me->query("jing") < 40)
                return notify_fail("�������̫���ˡ�\n");
          me->receive_damage("jing", 30);
        me->add("neili", -10);
        return 1;
}


