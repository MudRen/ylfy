// wuhu-duanmendao.c �廢���ŵ�

inherit SKILL;

mapping *action = ({
([	"action" : "$N����$wбָ��һ�С�ֱ��ֱȥ��������һ�٣�һ����$n��$l��ȥ",
	"force" : 220,
        "dodge" : 10,
        "parry" : 5,
	"damage" : 215,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�ͯ�ӹһ�������������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
	"force" : 230,
        "dodge" : 10,
        "parry" : 10,
	"damage" : 220,
	"damage_type" : "����"
]),
([	"action" : "$Nչ���鲽������Ծ�䣬һ�С��ƴ����¡�������һ������ն��$n",
	"force" : 240,
        "dodge" : 5,
        "parry" : 5,
	"damage" : 225,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�������ɽ����$w�󿪴��أ����϶��»���һ�����磬ֱ����$n",
	"force" : 160,
        "dodge" : 5,
        "parry" : 5,
	"damage" : 130,
	"damage_type" : "����"
]),
([	"action" : "$N����$wһ����һ�С���Ϫ���㡹��˫�ֳ����������У�����$n���ؿ�",
	"force" : 280,
        "dodge" : 10,
        "parry" : 5,
	"damage" : 235,
	"damage_type" : "����"
]),
([	"action" : "$N����$w��ʹ��һ�С��Ź����ġ����������ã����ҿ�����������$n",
	"force" : 210,
        "dodge" : 15,
        "parry" : 15,
	"damage" : 245,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С��������ۡ������Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
	"force" : 240,
        "dodge" : 5,
        "parry" : 15,
	"damage" : 250,
	"damage_type" : "����"
]),
([	"action" : "$N����פ�أ�һ�С�������Ϣ�����ӳ�һƬ�����ĵ�Ӱ����$n��ȫ��ӿȥ",
	"force" : 280,
        "dodge" : 20,
        "parry" : 10,
	"damage" : 260,
	"damage_type" : "����"
]),
([	"action" : "$N���ֺ󳷣�����һ����һ�С�׳ʿ���󡹣���ʱһ���׹�ֱն��$n���ֱ�",
	"force" : 320,
        "dodge" : 20,
        "parry" : 20,
	"damage" : 170,
	"damage_type" : "����"
]),
([	"action" : "$N�߸�Ծ��һ�С���ͷ��ء�������$wֱ����$n�ľ���",
	"force" : 320,
        "dodge" : 20,
        "parry" : 20,
	"damage" : 270,
	"damage_type" : "����"
]),
([	"action" : "$N���ػ��У�һ�С����Ӿ��������$wֱ��ȥ$n���ɲ�",
	"force" : 350,
        "dodge" : 30,
        "parry" : 30,
	"damage" : 280,
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }
int practice_level(){   return 140;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");
    if ((int)me->query_skill("blade", 1) < 20)
        return notify_fail("��Ļ����������̫ǳ��\n");
    if (me->query_skill("blade", 1) <=me->query_skill("wuhu-duanmendao", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
        mapping a_action;
        int i, level;
        level   = (int) me->query_skill("wuhu-duanmendao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    if ( me->query_temp("perform_duan")) level+=level;
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level*2;
    a_action["attack"]  = level;
    a_action["damage"] = level*4;
    return a_action;
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("��������������廢���ŵ�����\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"wuhu-duanmendao/" + action;
}
