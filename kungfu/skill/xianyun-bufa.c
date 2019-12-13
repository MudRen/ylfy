// xianyun-bufa.c ���Ʋ���
// By Kayin @ CuteRabbit Studio 1999/3/15
inherit SKILL;
#include <ansi.h> 
mapping *action = ({
([	"action" : "$n"NOR"ʹ��"HIC" ���Ʋ��� "NOR"���㣬�Ų��ƣ�������������ˮ��ֱ�������ࡣ\n",
	"dodge"  : 50,
]),
([	"action" : "$n"NOR"ʹ��"HIC" ���Ʋ��� "NOR"��Ȼһ������ȫ�����ض��У���ʱ������$N���������ơ�\n",
	"dodge"  : 100,
]),
([	"action" : "$n"NOR"ʹ��"HIC" ���Ʋ��� "NOR"�㲻�����ֲ�̧��һת�ۼ���Ƶ���$N�����\n",
	"dodge"  : 150,
]),
([	"action" : "$n"NOR"ʹ��"HIC" ���Ʋ��� "NOR"һת��䣬����˷�Ʈ����������$n����Ӱ����$N�����޴롣\n",
	"dodge"  : 200,
]),	
([	"action" : "$n"NOR"ʹ��"HIC" ���Ʋ��� "NOR"��̤�㣬��תǬ������һ�Σ��㵽����Զ�ĵط���\n",
	"dodge"  : 250,
]),
([	"action" : "$n"NOR"ʹ��"HIC" ���Ʋ��� "NOR"���ڿ��У������������һ�㣬��$Nͷ���ڿն�����\n",
	"dodge"  : 300,
]),
([	"action" : "$n"NOR"ʹ��"HIC" ���Ʋ��� "NOR"����һ����ȫ��Ϊһ����Ӱ�����ĵش�$Nͷ��Ʈ�䡣\n",
	"dodge"  : 350,
]),
([	"action" : "$n"NOR"ʹ��"HIC" ���Ʋ��� "NOR"���������ݰ㼱ת����ʱһ������ӿ������$N���Զ�����\n",
	"dodge"  : 400,
]),
([	"action" : "$n"NOR"ʹ��"HIC" ���Ʋ��� "NOR"����ٿ�Ĵ�$N����ǰֱ�Ƶ����$N�ɴ������ۣ��������ԡ�\n",
	"dodge"  : 450,
]),
([	"action" : "$n"NOR"ʹ��"HIC" ���Ʋ��� "NOR"����ٿ�Ĵ�$N����ǰƮ��������һ˦������֮����\n",
	"dodge"  : 500,
]),
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("xianyun-bufa");


	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge";
}

int valid_learn(object me)
{	
	if( (int)me->query_skill("tianluo-diwang",1)<30)
	 	return notify_fail("������޵����ƻ���������,����ѧϰ���Ʋ�����\n");
	if( (int)me->query_skill("yunu-xinfa",1)<30)
	 	return notify_fail("�����Ů�ķ���Ϊ����,���������Ʋ�����\n");
	 if((int)me->query_skill("yunu-xinfa",1)<(int)me->query_skill("xianyun-bufa",1))
	 	return notify_fail("�����Ů�ķ���Ϊ�����ˣ����ܼ���ѧϰ���Ʋ�����\n");
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
		return notify_fail("�������̫���ˣ����������Ʋ�����\n");
	me->receive_damage("qi", 20);
	return 1;
}
