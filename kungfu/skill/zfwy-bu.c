// zfwy-bu.c ��׷����Ӱ����

#include <ansi.h>
#include <skill.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$nһʽ��ԽӰ׷�硹�������ݷ����У���$Nͷ����Ծ������\n",
        "dodge"  : 10
]),
([      "action" : "$nһʽ��������������һ����磬�滺��������$N���������ơ�\n",
        "dodge"  : 20
]),
([      "action" : "$nһʽ��������Ӱ������ӯ��һԾ������ʧ��$N����ǰ��\n",
        "dodge"  : 30
]),
([      "action" : "$nһʽ�������š���һգ�ۼ䣬�������Ʈ�����뿪��$N�����ߡ�\n",
        "dodge"  : 40
]),
([      "action" : "$nһʽ��������ӿ��������Ȼ�ӿ죬��$N����Ʈ��������\n",
        "dodge"  : 50
]),
([      "action" : "$nһʽ������Ӱ������ʱ��$N��Χ�γ���������Ӱ����$N����ѱ棡\n",
        "dodge"  : 60
]),
([      "action" : "$nһʽ����۵糸����˫�ŵ�أ�ȫ��һ�����磬��������$N�ɱ���\n",
        "dodge"  : 70
]),
([      "action" : "$nһʽ���˷�ŪӰ�������ζ������ҡ�ڣ�����ȫ���·�����$N�޴����֡�\n",
        "dodge"  : 80
]),
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("zfwy-bu");

        if (level < 80 )
                zhaoshu--;

        if (level < 60 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;
        
        if (random(me->query_skill("dodge")) > 100 &&
            me->query_skill("force") > 60 &&
            me->query("neili") > 30) {
            me->add("neili",-5);
            return (["action" : WHT"$n��Ȼʹ����׷����Ӱ�������ռ����硸׷����Ӱ���������һ����ʧ��ʹ$N���һ����\n"NOR,
                     "dodge"  : 200
                          ]); 
            }
        return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        if ((int)me->query_skill("dodge", 1) < 20)
                return notify_fail("��Ļ����Ṧ��򲻹����޷�ѧ��׷����Ӱ������\n");
        if ((int)me->query_skill("zhenfen-xinfa", 1) < 20)
                return notify_fail("��ġ�����ķ�����򲻹����޷�ѧ��׷����Ӱ������\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷�����׷����Ӱ������\n");
        return 1;
}

string query_dodge_msg(string limb)
{   
        object me, ob;
        mapping action;

        me = this_player();

        action = query_action(me, ob);

        return action["action"];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("�������̫���ˣ���������׷����Ӱ������\n");
        me->receive_damage("qi", 30);
        return 1;
}
