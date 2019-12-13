#include <ansi.h>
#include <skill.h>

inherit SKILL;
string *order = ( {""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *xue_name = (
{
	"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
	"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",
});

mapping *action = (
{
([      "action" : "$N����ʳָ΢�㣬����"+(order[random(13)])+"�����������"NOR"��һ���ۻ��һ��ָ������$n�����ֳ��ȣ���������",
	"force" : 200,
	"damage" : 220,
"weapon" : "һ��ָ��",
	"parry" : 10,
	"dodge" : 15,
	"lvl" : 0,
"skill_name" : "�������",
"damage_type" : "����"
	 ]),
([      "action" : "$Nһָ"+(order[random(13)])+"���ճ�ϼ�⡹"NOR"��������һ�����ӿ��$n���������´�ƽ�ͣ�����Ȼ����޿��뿹",
	"force" : 250,
	"parry" : 25,
	"dodge" : 20,
	"damage" : 250,
	"lvl" : 20,
"skill_name" : "�ճ�ϼ��",
"damage_type" : "����"
	 ]),
([      "action" : "�����������죬һ����͵�������$N��ָӿ��������һ��"+(order[random(13)])+"������ů�ڡ�"NOR"����������$n$l",
	"force" : 300,
	"parry" : 10,
	"dodge" : 10,
	"damage" : 245,
"weapon" : "һ��ָ��",
	"lvl" : 40,
"skill_name" : "����ů��",
"damage_type" : "����"
	 ]),
([      "action": "$Nһ���絽$n������������Ծ�أ�һʽ��³�����ա�������ʳָ������ָ��$n��$l",
	"force" : 430,
	"attack": 79,
	"dodge" : 65,
	"parry" : 35,
	"damage": 83,
	"lvl" : 60,
"weapon" : HIR "һ��ָ��" NOR,
"skill_name" : "³������",
"damage_type" : "����"
	 ]),
([      "action": "$N�����������ʳָЮ���ۻ���������$n��$l����ʽ����̹��������һʽ��������ѩ��",
	"force" : 460,
	"attack": 75,
	"dodge" : 91,
	"parry" : 85,
	"damage": 78,
	"lvl" : 80,
"weapon" : HIR "һ��ָ��" NOR,
"skill_name" : "������ѩ",
"damage_type" : "����"
	 ]),
([      "action": "$N��ӰƮ��һʽ���������졹���������϶���������������Ȼ������$n��$l",
	"force" : 490,
	"attack": 105,
	"dodge" : 35,
	"parry" : 24,
	"damage": 98,
	"lvl" : 100,
"weapon" : HIR "һ��ָ��" NOR,
"skill_name" : "��������",
"damage_type" : "����"
	 ]),
([      "action" : "$N̤ǰһ������ָ�������һ�㣬$nֻ����Ϣһ�����ѱ�"+(order[random(13)])+"�����ս�����"NOR"�ĸ�����������$l",
	"force" : 350,
	"parry" : 15,
	"dodge" : 25,
	"damage" : 280,
	"lvl" : 60,
"weapon" : "��������",
	"damage" : 240,
"skill_name" : "���ս���",
"damage_type" : "����"
	 ]),
([      "action" : "$N������ڣ������������׻ӳ���ӿ��$n��$l���������������һ��"+(order[random(13)])+"��������ů��"NOR"",
	"force" : 400,
	"parry" : 25,
	"dodge" : 25,
	"damage" : 300,
	"lvl" : 80,
"skill_name" : "������ů",
"damage_type" : "����"
	 ]),
([      "action": "$N����б����ͻȻ�����Ϊָ���͵�һʽ�����ﳯ������ʹ��һ��ָ��������$n��$l",
	"force" : 528,
	"attack": 119,
	"dodge" : 24,
	"parry" : 23,
	"damage": 98,
	"lvl" : 180,
"weapon" : HIR "һ��ָ��" NOR,
"skill_name" : "���ﳯ��",
"damage_type" : "����"
	 ]),
([      "action" : "$N���΢Ц�������ʳָ����������$n�ؿڣ�����"+(order[random(13)])+"��ĺ��ӳ�ա�"NOR"����������ȴ��˿���ƿ�֮��",
	"force" : 450,
	"parry" : 15,
	"dodge" : 30,
	"damage": 350,
"weapon" : "һ��ָ��",
	"lvl" : 100,
"skill_name" : "ĺ��ӳ��",
"damage_type" : "����"
	 ]),
([      "action" : "ֻ��$Nʳָ΢����һָ"+(order[random(13)])+"������Ǭ����"NOR"���������ɭ�ϣ�Ӻ�����£�������֮�в������߷�ȣ�",
	"force" : 500,
	"parry" : 30,
	"dodge" : 30,
	"damage":485,
"weapon" : "��������",
	"lvl" : 110,
"skill_name" : "����Ǭ��",
"damage_type" : "����"
	 ]),
([ "action" : HIW"$Nͷ�������뵣����۽�Ũ����������һ�㣬ʳָ�����һʽ"+(order[random(13)])+"��������̩��"NOR"����$n��"NOR,
	"force" : 560,
	"parry" : 40,
	"dodge" : 30,
	"damage" : 500,
	"lvl" : 130,
"skill_name" : "������̩",
"damage_type" : "����"
	 ])
});

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" || usage=="finger";
}
int practice_level()
{
	return 100;
}
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��һ��ָ������֡�\n");
	if ((int)me->query_skill("kumu-shengong", 1) < 20)
		return notify_fail("��Ŀ�ľ�񹦻�򲻹����޷�ѧһ��ָ��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷���һ��ָ��\n");
	if (me->query_skill("unarmed", 1) <=me->query_skill("yiyang-zhi", 1))
		return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
	if (me->query_skill("finger", 1) <=me->query_skill("yiyang-zhi", 1))
		return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
	return 1;
}

int valid_combine(string combo)
{
	return combo=="haotian-zhang";
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
	int level=me->query_skill("yiyang-zhi",1);
	mapping a_action = action[random( sizeof(action) )];
	a_action["dodge"]  = 0-level*2;
	a_action["parry"]  = 0-level*2;
	a_action["damage"] = level*2;
	return a_action;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��һ��ָ������֡�\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������һ��ָ��\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yiyang-zhi/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	string name,weapon;
	name = xue_name[random(sizeof(xue_name))];

	if (random(me->query_skill("yiyang-zhi", 1)) > 150
	        && me->query_skill_mapped("unarmed") == "yiyang-zhi"
			&& me->query_skill_mapped("parry") == "yiyang-zhi"
	        && me->query_skill("kumu-shengong",1) > 50
	   )
	{
		if(!victim->is_busy()) victim->start_busy(3);
		victim->apply_condition("yyz_damage",30);
		victim->receive_wound("qi", me->query_skill("yiyang-zhi",1)/2+damage_bonus/2);
		return CYN "$n��$N����"RED+name+CYN"����\n" NOR;
	}

	if(me->query_skill("yiyang-zhi", 1) > 100
	        && me->query("neili") > 500
	        && me->query_skill_mapped("parry") == "yiyang-zhi"
	        && victim->query("neili") > 100
	        && me->query_skill("kumu-shengong",1) > 50)
	{
		victim->add("neili", -random(120));
	}
	if(victim->is_busy()) return 0;
	if (!objectp(weapon = me->query_temp("weapon")))
	{
		if((!random(5)) && (me->query("neili")>200) && me->query_skill("yiyang-zhi", 1) > 60
		        && me->query_skill_mapped("unarmed") == "yiyang-zhi"
				&& me->query_skill_mapped("parry") == "yiyang-zhi"
		        && me->query_skill("kurong-changong",1) > 50)
		{

			if( !victim->is_busy() )
			{
				victim->start_busy(3);
			}
			me->add("neili",-30);
			if (victim->query("neili") <=(damage_bonus/2+30))
				victim->set("neili",0);
			else
				victim->add("neili",-damage_bonus/2+50);
			victim->receive_wound("qi", me->query_skill("yiyang-zhi",1)/2+damage_bonus/2);
			return CYN "$n��$N���һָ����"RED+name+CYN"���������ɵ�һ�ͣ�\n" NOR;
		}
	}
	else
	{
		if((!random(4)) && (me->query("neili")>200) && me->query_skill("yiyang-zhi", 1) > 60
		        && me->query_skill_mapped("unarmed") == "yiyang-zhi"
		        && me->query_skill("kurong-changong",1) > 50)
		{
			if( !victim->is_busy() )
			{
				victim->start_busy(3);
			}
			me->add("neili",-30);
			victim->add("neili",-30);
			victim->receive_damage("qi", me->query_skill("yiyang-zhi",1)/2+damage_bonus/2);
			victim->receive_wound("qi", me->query_skill("yiyang-zhi",1)/2+damage_bonus/2);
			return CYN "$n��$N�����Ľ�������"RED+name+CYN"���������ɵ�һ�ͣ�\n" NOR;
		}
	}

}

int ob_hit(object ob, object me, int damage)
{
	string msg;
	int j, neili;
	int level,damage2;

	level= (int) me->query_skill("kumu-shengong",1);
	neili = me->query("neili");
	damage2= (int) ob->query("neili",1)/10;
	
	if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "kumu-shengong")
	{
		j = -damage/2;
		if (damage2> 5000)	damage2=5000;
		if (damage2 < 0 ) damage2=0;
		if (me->query("qi") <= me->query("max_qi"))
		{
			me->add("qi",damage2);
		}

		if (me->query("eff_qi") <= me->query("max_qi"))
		{
			me->add("eff_qi",damage2);
		}

		msg = HIG"$N ����һ������ʩչ��һ��ָ�����Դ���ָ���鲼ȫ��! ��ɫ������ˡ�\n"NOR;
		if (!ob->is_busy() && random(5)==0)
		{
			msg += HIY"$n"+HIY+"��$N�Ĵ���ָ������! ��������� "+ xue_name[random(sizeof(xue_name))] +NOR;
			ob->apply_condition("yyz_damage",30);
			ob->start_busy(3);
		}

		message_vision(msg, me, ob);
		return j;
	}
}

