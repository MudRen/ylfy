inherit SKILL;
#include <ansi.h>
string *dodge_msg = ({
        "$n���λζ���ʹ��һ��"HIM" �������� "NOR"������ʵ�ң���ǰ�����������޵�����$N�Ĺ�����\n",
        "$nͻȻ����һ����һ��"HIB"�����伣"NOR"������������֮�⡣\n",
        "����$nһ��"HIR" ����˷� "NOR"��Ȼ�������࣬���λζ��������$N�Ĺ��ơ�\n",
        "ֻ��$n����������������б��������һ��"HIW" �������� "NOR"����֪����$n�Ѿ�����$N�����\n",
        "$n��ס���ˣ���Ȼ���λζ���һ��"RED" ���жݱ� "NOR"ת����$N����ࡣ\n",
        "$n�������ߣ�һ��"YEL" ������� "NOR"�����$N���������ơ�\n",
        "$n����һ�㣬һ��"HIY" ����ת�� "NOR"бб�ķɳ�ǡ�ɶ㿪��$N�Ľ�����\n",
        "$nһ��"MAG" �������� "NOR"����һ�ã�$N�������˸��ա�\n",
});

int valid_enable(string usage) { return (usage == "dodge") ;}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("�������̫���ˣ����������㹦��\n");
        me->receive_damage("qi", 30);
        return 1;
}