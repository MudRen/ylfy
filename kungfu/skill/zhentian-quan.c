//����ȭ
//cool 981010
inherit SKILL;

mapping *action = ({
([	"action" : "$N��һ��������΢��������һ����һ�С����°��졹��һȭֱͱ$n��$l",
	"force" : 170,
	"dodge" : 0,
       "parry" : 10,
	"lvl" : 0,
	"skill_name" : "���°���",
	"damage_type" : "����"
]),
([	"action" : "$N��������һЦ����ȭ�������ϣ���ȭƽƽ������һ�С��������졹���������$n",
	"force" : 200,
	"dodge" :-5,
       "parry" : 5,
	"lvl" : 15,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N��$nһ����ȣ�ʹһ�С����羭�졹����ȭ�������漴��ȭ���ϣ�������������$n��$l",
	"force" : 230,
	"dodge" : 0,
       "parry" : 10,
	"lvl" : 30,
	"skill_name" : "���羭��",
	"damage_type" : "����"
]),
([	"action" : "$N�ƺ�һ����˫ȭ���Ϸֿ���һ�ǡ��ٻ����졹��ȭ�����ߣ�����ͬʱ����$n��$l",
	"force" : 260,
	"dodge" : 0,
       "parry" : 0,
	"lvl" : 45,
	"skill_name" : "�ٻ�����",
	"damage_type" : "����"
]),
([	"action" : "$Nʩ����һ�����졹��һ�����һȭ��մ����ȭ��ֱ��$n��$l",
	"force" : 290,
	"dodge" : 0,
       "parry" : 5,
	"lvl" : 60,
	"skill_name" : "һ������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ����Х��˫ȭ���������һ�С�ʯ���쾪����ȭ���ܲ�$n��ǰ������",
	"force" : 310,
	"dodge" : 10,
       "parry" : 10,
	"lvl" : 70,
	"skill_name" : "ʯ���쾪",
	"damage_type" : "����"
]),
([	"action" : "$Nŭ��һ������շ���һʽ��������ѡ���˫ȭ�Ӹ����£����봷��$n",
	"force" : 350,
	"dodge" : 20,
       "parry" : -10,
	"lvl" : 80,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([	"action" : "$N�����Ц������������۷��裬һ�С��޷����졹��ȭ����������������$n��ȥ",
	"force" : 380,
	"dodge" : -5,
       "parry" : -10,
	"lvl" : 90,
	"skill_name" : "�޷�����",
	"damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"|| usage=="unarmed"; }
int valid_combine(string combo) { return combo=="chuanyun-tui"; }


int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��������ȭ��������֡�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷���������ȭ����\n");
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
if (( (int)me->query_skill("cuff", 1) >= 120 ) 
        &&	( (int)me->query_skill("zhentian-quan", 1) >= 120 )
	    && ( (int)me->query_skill("leg",1) >= 120 )
       && ( (int)me->query_skill("chuanyun-tui",1) >= 120 )
	  && ( (int)me->query("neili") >= 500 )
      &&  (me->query_skill_prepared("leg") == "chuanyun-tui")
      && (me->query_skill_mapped("parry") != "zhentian-quan")
      && random(10)>8 ) {
		return ([
		"action": "$N������ʽͻȻ�ӿ죬һ�С�ȭ��˫������������$n����һȭ���漴˫�������߳�",
	       "parry":(int)me->query_skill("parry")/8,
             "dodge":(int)me->query_skill("dodge")/20+(int)me->query_skill("leg")/15,
		"force": (int)me->query_skill("strike")+(int)me->query_skill("leg"),
		"damage_type": "����"
  ]);
	}

	level   = (int) me->query_skill("zhentian-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jing") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("qi") < 20)
		return notify_fail("�������������������ȭ����\n");
	me->receive_damage("jing", 25);
	me->add("qi", -5);
	return 1;
}

