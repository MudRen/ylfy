//xuantie-jianfa.c ��������
inherit SKILL;
#include <ansi.h>
mapping *action = (
{
([      "action" : "$Nһ��"HIW" ������� "NOR"̧ͷ���죬��������������һ�����Լ�ͷ���տ����𣬽���б�£����ɻ��Σ�������������$n��$l��",
	"force" : 10,
"attack":this_player()->query_skill("xuantie-jianfa",1),
"dodge" : (int)this_player()->query_skill("dodge"),
"damage" : (int)this_player()->query("age")*10,
	"lvl" : 0,
"skill_name" : "�������",
"damage_type" : "����"
	 ]),
([      "action" : "$Nһ��"HIG" �������� "NOR"�����´����ް�������ʽ��ͻȻ�������붯���ϲ�����һ�����⻮��$n.",
"attack":this_player()->query_skill("xuantie-jianfa",1),
"dodge" : (int)this_player()->query_skill("dodge"),
	"force" : 30,
"damage" : (int)this_player()->query("age")*11,
	"lvl" : 10,
"skill_name" : "��������",
"damage_type" : "����"
	 ]),
([      "action" : "$Nһ��"HIB" �����ˮ "NOR"��������Ʈ����������ˮ����ɳ��ʯ����ֱ��$n���ʺ�",
	"force" : 40,
"dodge" : (int)this_player()->query_skill("dodge"),
"attack":this_player()->query_skill("xuantie-jianfa",1),
"damage" : (int)this_player()->query("age")*12,
	"lvl" : 20,
"skill_name" : "�����ˮ",
"damage_type" : "����"
	 ]),

([      "action" : "$Nһ��"HIY" �������� "NOR"�����ո���ͷ�������£��Ų����ص�����$n,������������б��$n�����ߡ�",
	"force" : 50,
"damage" : (int)this_player()->query("age")*13,
"dodge" : (int)this_player()->query_skill("dodge"),
"attack":this_player()->query_skill("xuantie-jiafa",1),
	"lvl" : 30,
"skill_name" : "��������",
"damage_type" : "����"
	 ]),
([      "action" : "$Nһ��"HIR" ��ʬ���� "NOR"����һ������һ������ʱ�л��㱣�����ԼԼ���������޵Ĵ���$n��ǰ��",
	"force" : 60,
"damage" : (int)this_player()->query("age")*14,
"attack":this_player()->query_skill("xuantie-jianfa",1),
"dodge" : (int)this_player()->query_skill("dodge"),
	"lvl" : 40,
"skill_name" : "��ʬ����",
"damage_type" : "����"
	 ]),
([      "action" : "$N�ֽ�ƽ�У�һ��"HIM" ӹ������ "NOR"û����ɵ�ɨ��$n��$l.",
	"force" : 70,
"dodge" : (int)this_player()->query_skill("dodge"),
"attack":this_player()->query_skill("xuantie-jianfa",1),
"damage" : (int)this_player()->query("age")*15,
	"lvl" : 50,
"skill_name" : "ӹ������",
"damage_type" : "����"
	 ]),
([      "action" : "$Nһ��"RED" ������ʩ "NOR"ͻȻ�������࣬ͷ�½��ϣ��������ӣ�һ������$n��$l",
	"force" : 80,
"attack":this_player()->query_skill("xuantie-jianfa",1),
"dodge" : (int)this_player()->query_skill("dodge"),
"damage" : (int)this_player()->query("age")*16,
	"lvl" : 60,
"skill_name" : "������ʩ",
"damage_type" : "����"
	 ]),
([      "action" : "$Nһ��"YEL" �������� "NOR"��ĿԶ����ͻȻ������һ�����°�����$n��ͷ����",
	"force" : 90,
"attack":this_player()->query_skill("xuanxie-jianfa",1),
"dodge" : (int)this_player()->query_skill("dodge"),
"damage" : (int)this_player()->query("age")*17,
	"lvl" : 70,
"skill_name" : "��������",
"damage_type" : "����"
	 ]),
([      "action" : "$Nһ��"BLU" ���Ʋ��� "NOR"�����鸡�����缸�첻�Բ�˯��ĽŲ��ʲյ�Ϯ��$n�����ԣ�����һ������$n��ǰ�ġ�",
	"force" : 100,
"dodge" : (int)this_player()->query_skill("dodge"),
"attack":this_player()->query_skill("xuantie-jianfa",1),
"damage" : (int)this_player()->query("age")*18,
	"lvl" : 80,
"skill_name" : "���Ʋ���",
"damage_type" : "����"
	 ]),
([      "action" : "$Nһ��"HIC" �ǻ��չ� "NOR"�����ҽ�������ʵʵ�Ľ������$n��$l��",
	"force" : 110,
"dodge" : (int)this_player()->query_skill("dodge"),
"attack":this_player()->query_skill("xuantie-jiafa",1),
"damage" : (int)this_player()->query("age")*19,
	"lvl" : 90,
"skill_name" : "�ǻ��չ�",
"damage_type" : "����"
	 ]),
});
int valid_enable(string usage)
{
	return (usage == "sword") || (usage == "parry");
}
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("yunv-xinjing", 1) <250 && (int)me->query_skill("yunv-xinfa", 1) <250)
		return notify_fail("��Ĺ�Ĺ�ڹ����̫ǳ��\n");
	if ((int)me->query_skill("xuantie-jianfa", 1) >350)
		return notify_fail("ʦ��ֻ�ܽ��㵽�⣬�Ժ����Լ��ڼ���ϰ�ˡ�\n");
	if (me->query_skill("sword", 1) <=me->query_skill("xuantie-jianfa", 1))
		return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
	mapping a_action;
	a_action = action[random(sizeof(action))];
	a_action["dodge"]=me->query_skill("sword")/2;
	return a_action;
}
int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	        || (string)weapon->query("skill_type") != "sword")
		if (!objectp(weapon = me->query_temp("secondary_weapon"))
		        || (string)weapon->query("skill_type") != "sword")
			return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("�����������������������\n");
	me->receive_damage("qi", 30);
	return 1;
}
int ob_hit(object ob, object me, int damage)
{
	string msg;
	int j;
	int level2,damage2;

	level2= (int) me->query_skill("yunv-xinfa",1);
	if ( level2<= 0) level2= (int) me->query_skill("yunv-xinfa",1);
	damage2= (int) ob->query("neili",1)/10;
	
	if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "yunv-xinfa"))
	{
		j = -damage/2;
		if (damage2> 5000)	damage2=5000;
		if (damage2 < 0 ) damage2=0;
		msg = HIC"$N"+HIC+"�������ߣ��ж����������಻����һ��δ�ϣ������� !$n˫��һ����֪���룡\n" +NOR;
		if (random(2)==0)
		{
			msg += HIY"$N"+HIY+"Ŀ��һ����һ��������ӳ� !$n һ�����ģ����������˼�ö��\n" +NOR;
			ob->apply_condition("yf_poison",20);
		}
		message_vision(msg, me, ob);
		ob->start_busy(6);
	}
	return j;
}

string perform_action_file(string action)
{
	return __DIR__"xuantie-jianfa/" + action;
}
