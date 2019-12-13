// wudu-goufa.c �嶾����

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action":"\n$N����$wһ����һʽ���������š��������ļ�����$n��$l",
	"force" : 160,
	"lvl" : 0,
	"skill_name" : "��������",
	"damage_type":	"����"
]),
([	"action":"\n$Nһʽ����˿��ϵ�����������಻��������һ�����εĴ�����$n���ڵ���",
	"force" : 240,
	"lvl" : 50,
	"skill_name" : "��˿��ϵ",
	"damage_type":	"����"
]),
([	"action":"\n$Nһ����Ц����������һʽ��������צ��������$w���裬�ó�ǧ����\n�ֱۣ���������$n",
	"force" : 280,
	"lvl" : 75,
	"skill_name" : "������צ",
	"damage_type":	"����"
]),
([	"action":"$N����أ�����һ���������ߣ�����$wȴٿ�Ĵ�Ҹ�´�����������$n��$l,\n��һʽ����Ы���롹",
	"force" : 320,
	"lvl" : 120,
	"skill_name" : "��Ы����",
	"damage_type":	"����"
]),
([	"action":"$N�Ų����ģ����κ�����ǰ������һʽ���������¡�������$w���¶���ֱ\n��$n��С��",
	"force" : 380,
	"lvl" : 230,
	"skill_name" : "��������",
	"damage_type":	"����"
]),
([	"action":"$N����һ�Σ�һʽ�����߲��󡹣�����$w�總��֮����������Ϣ�ش���$n\n������",
	"force" : 420,
	"lvl" : 250,
	"skill_name" : "���߲���",
	"damage_type":	"����"
]),
([	"action":"\n$Nһ����Х�����γ������һʽ�����ű䡹������$w����Ȱ�����\n$nȫ��ŵ���Ѩ",
	"force" : 450,
	"lvl" : 330,
	"skill_name" : "���ű�",
	"damage_type":	"����"
]),
([	"action":"$N����һ����˫���չ������ݡ������𡹣�$w���͸��һ��ǿ���ĺ�\n����������Ϯ��$n",
	"force" : 480,
	"lvl" : 380,
	"skill_name" : "������",
	"damage_type":	"����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("wudu-shengong", 1) < 20)
		return notify_fail("����嶾�񹦻��̫ǳ��\n");
	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("��Ļ����ڹ����̫ǳ��\n");
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
        mapping a_action;
        int i, level;
        level   = (int) me->query_skill("wudu-goufa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level/2;
    a_action["damage"] = level/2;
    return a_action;
}


int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("��������������嶾������\n");
	me->receive_damage("qi", 20);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{

  if( random( me->query_skill("sword") ) > random( victim->query_skill("force"))) {
		victim->receive_wound("qi", damage_bonus );
	}
  if ( victim->query("family/family_name")!= "�嶾��" && me->query_skill("wudu-shengong",1)>80) {
	 switch( random(5) ) {
		case 0:
            victim->apply_condition("snake_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("snake_poison"));
			break;
		case 1:
            victim->apply_condition("zhizhu_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("zhizhu_poison"));
			break;
		case 2:
            victim->apply_condition("wugong_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("wugong_poison"));
			break;
		case 3:
            victim->apply_condition("xiezi_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("xiezi_poison"));
			break;
		case 4:
            victim->apply_condition("chanchu_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("chanchu_poison"));
			break;
	}
        return HIR "$nֻ�����˴�һ���飬�ƺ��ж��ˡ�\n" NOR;
   }
}
string perform_action_file(string action)
{
	return __DIR__"wudu-goufa/" + action;
}
