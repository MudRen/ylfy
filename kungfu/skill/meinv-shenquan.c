//÷����Ū.c
#include <ansi.h>
#include <combat.h>
inherit SKILL;
string *order = ( {""RED"", ""MAG"", ""HIW"", ""HIR"", ""HIM""});
mapping *action = ({
([
     "action" : "$N�������һʽ"+(order[random(5)])+"��÷��һŪϷ��ߡ�"NOR"��˫����£���У�����$n��̴��Ѩ",
     "force"  : 100,
     "dodge"  : 120,
     "parry"  : 90,
     "lvl"    : 0,
     "damage"    : 120,
     "skill_name"  : "÷��һŪϷ���",
     "damage_type" : "����"
]),
([
     "action" : "$N������ת��ʹһʽ"+(order[random(5)])+"��������������Ʈ��"NOR"����������������縧��$n�����",
     "force"  : 150,
     "dodge"  : 110,
     "parry"  : 90,
     "lvl"    : 0,
     "damage"    : 150,
     "skill_name"  : "������������Ʈ",
     "damage_type" : "����"
]),
([
     "action" : "ͻ��$N˫�������޹Ƿ���ѩ����"+(order[random(5)])+"ʹ������㺬������Ҷ��"NOR"��ס$n�Ĳ���",
     "force"  : 180,
     "dodge"  : 150,
     "parry"  : 110,
     "lvl"    : 0,
     "damage"    : 200,
     "skill_name"  : "��㺬������Ҷ",
     "damage_type" : "����"
]),
([
     "action" : "ֻ��$N������ͷ��ͷ����񣬳���$n��ǰ̽�ӣ�ͻȻʹ��"+(order[random(5)])+"�����ְ�ϲӳ���ۡ�"NOR"����$n��ץ����",
     "force"  : 200,
     "dodge"  : 150,
     "parry"  : 150,
     "lvl"    : 0,
     "damage"    : 200,
     "skill_name"  : "���ְ�ϲӳ����",
     "damage_type" : "ץ��"
]),
([
     "action" : "$N���ƻ��أ��ұ�΢����ӭ�����������⼲�죬һʽ"+(order[random(5)])+"��÷����Ūӭ������"NOR"����$n������Ѩ",
     "force"  : 220,
     "dodge"  : 150,
     "parry"  : 180,
     "lvl"    : 0,
     "damage"    : 250,
     "skill_name"  : "÷����Ūӭ����",
     "damage_type" : "����"
]),
([
     "action" : "$N����������˫��΢չ��һʽ"+(order[random(5)])+"����ѩ�ܳɱ��񼡡�"NOR"��$n��Ӳ��һ�ƣ�$nֻ�����������ѩ����",
     "force"  : 250,
     "dodge"  : 150,
     "parry"  : 180,
     "lvl"    : 0,
     "damage"    : 280,
     "skill_name"  : "��ѩ�ܳɱ���",
     "damage_type" : "����"
]),
([
     "action" : "$N˫�Ʒ��裬����Ҷ�ɻ���һʽ"+(order[random(5)])+"�������Ӣ�����⡹"NOR"���ó�����÷����䣬������$n��ȥ",
     "force"  : 270,
     "dodge"  : 180,
     "parry"  : 200,
     "lvl"    : 0,
     "damage"    : 300,
     "skill_name"  : "�����Ӣ������",
     "damage_type" : "����"
]),
([
     "action" : "ֻ��$N��������������װ��һʽ"+(order[random(5)])+"���쳾һ��Ц˭�ա�"NOR"��˫�Ʊ�����£���������$n����ǰ",
     "force"  : 280,
     "dodge"  : 200,
     "parry"  : 200,
     "lvl"    : 0,
     "damage"    : 320,
     "skill_name"  : "�쳾һ��Ц˭��",
     "damage_type" : "ײ��"
]),
([
     "action" : "ֻ����$N΢΢һЦ������"+(order[random(5)])+"��÷����Ū��Ⱥ�ɡ�"NOR"��ֻ��һ������ƾ�ճ��֣���$n��̾һ�������Ȳ�ʶ��",
     "force"  : 280,
     "dodge"  : 200,
     "parry"  : 200,
     "lvl"    : 0,
     "damage"    : 350,
     "skill_name"  : "÷����Ū��Ⱥ��",
     "damage_type" : "����"
]),
([
     "action" : "ֻ��$N˫����һԾ����ʹ��һ��"+(order[random(5)])+"������������������"NOR"��$nĿ�����룬������ȭ�ƣ�������ɹ�������ȭ",
     "force"  : 300,
     "dodge"  : 200,
     "parry"  : 200,
     "lvl"    : 0,
     "damage"    : 350,
     "skill_name"  : "��������������",
     "damage_type" : "����"
]),
([
     "action" : "$N����һת��ٿ������$n��ǰ��һ��"+(order[random(5)])+"������������ʡ�"NOR"ֱ��$n�ĺ�",
     "force"  : 350,
     "dodge"  : 150,
     "parry"  : 200,
     "lvl"    : 0,
     "damage"    : 380,
     "skill_name"  : "�����������",
     "damage_type" : "ץ��"
]),
([
     "action" : "$NͻȻ���η���˫�ƾӸ�����һ��"+(order[random(5)])+"��������д�����졹"NOR"��$n��֪���룬�޷��ֵ�",
     "force"  : 380,
     "dodge"  : 190,
     "parry"  : 200,
     "lvl"    : 0,
     "damage"    : 400,
     "skill_name"  : "������д������",
     "damage_type" : "ץ��"
]),
([
     "action" : "ֻ��$Nվ���򻨴��У�˫�����ģ�"+(order[random(5)])+"������һЦ��������"NOR"��$n��ʱ�����һ����������󣬲�֪�������ѱ���������",
     "force"  : 600,
     "dodge"  : 300,
     "parry"  : 200,
     "lvl"    : 0,
     "damage"    : 500,
     "skill_name"  : "����һЦ������",
     "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="parry" || usage=="unarmed"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ů��ȭ������֡�\n");
	if ((int)me->query("max_neili") < 70000)
		return notify_fail("�������̫�����޷�����Ů��ȭ��\n");
	if ( (int)me->query("t") > 1 || (int)me->query("r") > 1  )
		return notify_fail("����������Բ���������Զ�޷�ѧ����Ů��ȭ��\n");
	return 1;
}
string query_skill_name(int level)
{
   int i;
   for(i = sizeof(action); i > 0; i--)
       if(level >= action[i-1]["lvl"])
           return action[i-1]["skill_name"];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 10000)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("qi", 5);
	me->add("neili", -5);
	return 1;
}
mapping query_action(object me, object weapon)
{
   int i, j, level;
   level = (int) me->query_skill("meinv-shenquan",1);
   for(i = sizeof(action); i > 0; i--) {
       if(level > action[i-1]["lvl"]) {
           j = NewRandom(i, 20, level/4);
       if((int)me->query_skill("meinv-shenquan",1) > 100 && random(me->query("per")) > 20){
       return ([
               "action" : replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR)+NOR,
               "force" : 900,
               "dodge": 400,
               "parry" : 300,
               "damage" : 800,
               "damage_type" : "ץ��",
                ]);
       }
       else return action[j];
       }
   }
}

string perform_action_file(string action)
{
	return __DIR__"meinv-shenquan/" + action;
}

