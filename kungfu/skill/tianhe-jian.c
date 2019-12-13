
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N���$n���������޾�ɫ��һʽ�����󵱷硹��$wƽƽ���˳�ȥ",
        "damage" : 100,
        "parry"  : 0,
        "force"  : 100,
        "lvl"  : 0,
        "dodge"  : 0,
        "skill_name" : "���󵱷�",
        "damage_type" : "����"
]),
([      "action" : "$N�������飬����$n���ߣ�ͻȻһͣ������$wһʽ��������ɽ����ն$n��ȥ",
        "damage" : 100,
        "parry"  : 0,
        "force"  : 100,
        "lvl"  : 0,
        "dodge"  : 0,
        "skill_name" : "������ɽ",
        "damage_type" : "����"
]),
([      "action" : "$Nչ�ۼ���$w�����������ϼ��һʽ��ǧˮһ����������һ����$n��$l",
        "damage" : 100,
        "parry"  : 0,
        "force"  : 100,
        "lvl"  : 0,
        "dodge"  : 0,
        "skill_name" : "ǧˮһ��",
        "damage_type" : "����"
]),
([      "action" : "$N��Խ��գ�$w��ջ��µ��ƬƬ���⣬һʽ��ѩ��̫ɽ������ѩ�������޴��ɶ�",
        "damage" : 100,
        "parry"  : 0,
        "force"  : 100,
        "lvl"  : 0,
        "dodge"  : 0,
        "skill_name" : "ѩ��̫ɽ",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ��ɽˮƮҡ���������Ρ�����Ӱ����������ƮƮȻ��$n���˹�ȥ",
        "damage" : 100,
        "parry"  : 0,
        "force"  : 100,
        "lvl"  : 0,
        "dodge"  : 0,
        "skill_name" : "ɽˮƮҡ",
        "damage_type" : "����"
]),
([      "action" : "$N������һ����������$w�߾٣�һʽ�������ٽ�����$n��ն��ȥ",
        "damage" : 100,
        "parry"  : 0,
        "force"  : 100,
        "lvl"  : 0,
        "dodge"  : 0,
        "skill_name" : "�����ٽ�",
        "damage_type" : "����"
]),
([      "action" : "$N������̤�����ǣ�����$wʹһʽ����ҡ���Ρ���ҡ���г��֣���Ȼ������Ŀ�����",
        "damage" : 100,
        "parry"  : 0,
        "force"  : 100,
        "lvl"  : 0,
        "dodge"  : 0,
        "skill_name" : "��ҡ����",
        "damage_type" : "����"
]),
([      "action" : "$N��һ��أ���������һʽ����ӷɶݡ����˽���һ�Ƴ�������â��ֱ��$n��ȥ",
        "damage" : 100,
        "parry"  : 0,
        "force"  : 100,
        "lvl"  : 0,
        "dodge"  : 0,
        "skill_name" : "��ӷɶ�",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; } 

int valid_learn(object me)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((int)me->query("max_neili") < 300)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("sword", 1) < 50)
                return notify_fail("��Ľ������̫ǳ��\n");

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

        level   = (int) me->query_skill("tianhe-jian",1);

        for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
                return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("�����������������ӽ�������\n");
        me->receive_damage("qi", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tianhe-jian/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string msg;
        if( damage_bonus < 100 ) return 0;
        if (!(me->query("yiqiguan-riyue"))) return 0;
        if( random( me->query_skill("sword") ) > random( victim->query_skill("force")) && me->query_skill_mapped("force") == "yiqiguan-riyue" ) {        
                if (me->query("yiqiguan-riyue")==1) {
                        victim->receive_wound("qi", (damage_bonus - 100) / 2 );
                        msg= WHT "$nһ���������������м��ӵġ������������ھ����ˡ�\n" NOR;
                }
                if (me->query("yiqiguan-riyue")==2) {
                        victim->receive_wound("qi",damage_bonus/2 );
                        msg= CYN "$nһ���������������м��ӵġ��Ƿ��켫���ھ����ˡ�\n" NOR;
                }
                return msg;
        }
}