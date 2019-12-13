// canxin-jian.c�����Ľ�����
inherit SKILL;
#include <ansi.h>
mapping *action = ({
([      "name":   "��������",
    "action" : "$N������ת�����ֽ�ָ������ǰ��һ�紦�̴ٶ�������\n"
    "һ��"HIR"���������ܡ�"NOR"������$w���������һ�����϶�������$n��",
    "dodge" : 5,
    "damage" : 35,
    "parry"  :10,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "������",
    "action" : "$N���β�������ǰ�������������ϱ���һ��"HIR"�������֡�"NOR"��\n"
    "����$w��ǰ�·��̣�һ��ָ��$n",
    "dodge" : 10,
    "damage" : 40,
    "parry"  :15,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "��ҹ����",
    "action" : "$N�����ǰ���ŵ���������$wͻ��ǰ�̣���ת�����\n"
    "ʹ��һʽ"HIR"����ҹ���"NOR"��������ƥ����й��$n",
    "dodge" : 5,
    "damage" : 45,
    "parry"  :15,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "����δ��Ե",
    "action" : "$Nƽ��бϴ����Բ��ֱ��˫�Ž��满������������$wʹ��һʽ"HIR"������δ��Ե��"NOR"��"
    "����������ת�������಻������$n",
    "dodge" : 5,
    "damage" : 50,
    "parry"  :15,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "��˿�Ѷ�",
    "action" : "$N����̧�ۣ�����ǰ����Ϸ������ͦ����ƽ��������ǰ������$wʹ��\n"
    "һʽ"HIR"����˿�Ѷϡ�"NOR"����$n",
    "dodge" : 10,
    "damage" : 60,
    "parry"  :10,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "���Ѹ�",
    "action" : "$N���ϲ����������أ�����$wһʽ"HIR"�����Ѹ���"NOR"��"
    "����Բ�󣬴���$n",
    "dodge" : 0,
    "parry"  :15,
    "damage" :70,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "�̽�����",
    "action" : "$N�����˲������ֽ�ָ��ת������$wһ��"HIR"���̽�������"NOR"��"
    "��������ָ��$n",
    "dodge" :-10,
    "damage" :80,
    "parry"  :15,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "����Զ",
    "action" : "$N�鲽�������ὣ�ؽ��������ϱ���һ��"HIR"������Զ��"NOR"ֱȡ$n",
    "dodge" : 5,
    "damage" : 90,
    "parry"  :25,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "�������һ����",
    "action" : HIG"\n��һ���������ɵ������ɣ��������һ�������������϶��£�"NOR,
    "dodge" : 15,
    "damage" : 100,
    "force"  : 100,
    "parry"  :100,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "����������Բȱ",
    "action" : HIG"\n�ڶ���������������Բȱ��������ңĪ���У����������ң�"NOR,
    "dodge" : 15,
    "damage" : 110,
    "parry"  :100,
    "force"  : 100,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "��������ʶ��Ů",
    "action" : HIG"\n����������������ʶ��Ů��ͬ������Ѱ��;��������ת������"NOR,
    "dodge" : 10,
    "damage" : 120,
    "parry"  :100,
    "force"  : 100,
    "lvl" : 0,
    "damage_type" : "����"
]),

});
int valid_enable(string usage) { 
    return (usage == "sword") || (usage == "parry");
}
int valid_learn(object me)
{
    if ((int)me->query("neili") < 100)
   return notify_fail("�������������\n");
    if ((int)me->query_skill("force", 1) < 500)
   return notify_fail("����ڹ����̫ǳ��\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
        int i;
        i=me->query("xiangsi");
        if( !me->query("xiangsi") ) {
        return action[random(8)];
        }else {
        return action[i];
        }
}        
int practice_skill(object me)
{
        if( (int)me->query("qi") < 30
        ||      (int)me->query("neili") < 3 )
                return notify_fail("�����������������û�а취��ϰ���Ľ�����\n");
        me->add("qi", -300);
        me->add("neili", -300);
        write(HIC"�������������ϣ������޺��³�Բ��\n"NOR,me);
        return 1;
}
string perform_action_file(string func) {
  return __DIR__"canxin-jian/" + func;
}


