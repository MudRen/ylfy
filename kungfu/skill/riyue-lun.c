// riyue-lun.c �����ַ�
//
#include <ansi.h>
inherit SKILL;
#include <ansi.h>
#include <combat.h>
string *order = ( {""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = (
{
([      "action" : "$Nʹһ��"+(order[random(13)])+"�������ơ�"NOR"���������е�$w��$n��$l��ȥ  ",
"skill_name" : "������",
	"force" : 120,
	"dodge" : 10,
	"parry" : 10,
	"lvl" : 0,
	"damage" : 250,
"damage_type" : "����",
	 ]),
([      "action" : "$Nʹһ��"+(order[random(13)])+"����ɽ���ơ�"NOR"��˫��һ�����趯����$w��$n��$l��ɨ  ",
"skill_name" : "��ɽ����",
	"force" : 160,
	"dodge" : 20,
	"parry" : 20,
	"lvl" : 8,
	"damage" : 255,
"damage_type" : "����",
	 ]),
([      "action" : "$Nʹһ��"+(order[random(13)])+"����΢�ơ�"NOR"���͵�һ�����������¶�������$n��$l  ",
"skill_name" : "��΢��",
	"force" : 200,
	"dodge" : 20,
	"parry" : 10,
	"lvl" : 16,
	"damage" : 260,
"damage_type" : "����",
	 ]),
([      "action" : "$Nʹһ��"+(order[random(13)])+"�������ơ�"NOR"���������֮��$wɨ��$n��$l  ",
"skill_name" : "������",
	"force" : 240,
	"dodge" : 15,
	"parry" : 15,
	"lvl" : 24,
	"damage" : 265,
"damage_type" : "����",
	 ]),
([      "action" : "$Nʹһ��"+(order[random(13)])+"��Բ���ơ�"NOR"��$w������֮����ֱ��$n��$l  ",
"skill_name" : "Բ����",
	"force" : 280,
	"dodge" : 10,
	"parry" : 10,
	"lvl" : 32,
	"damage" : 270,
"damage_type" : "����",
	 ]),
([      "action" : "$NԾ���գ�ʹһ��"+(order[random(13)])+"�����ػ��ơ�"NOR"���߾�$w����$n��$l  ",
"skill_name" : "���ػ���",
	"force" : 320,
	"dodge" : 10,
	"parry" : 10,
	"lvl" : 40,
	"damage" : 275,
"damage_type" : "����",
	 ]),
([      "action" : "$Nʹһ��"+(order[random(13)])+"��׽���ơ�"NOR"��б������$w����$n��$l  ",
"skill_name" : "׽����",
	"force" : 360,
	"dodge" : 15,
	"parry" : 15,
	"lvl" : 48,
	"damage" : 280,
"damage_type" : "����",
	 ]),
([      "action" : "$N��һ��������ʹ��"+(order[random(13)])+"���Լ��项"NOR"��$wɨ��$n��ͷ��  ",
"skill_name" : "�Լ���",
	"force" : 400,
	"dodge" : 20,
	"parry" : 15,
	"lvl" : 56,
	"damage" : 300,
"damage_type" : "����",
	 ]),
([      "action" : "$Nһ��"+(order[random(13)])+"������̾�����ơ�"NOR"����������������ֵ�������$w�����������������$n��$l��ȥ",
"skill_name" : "����̾������",
	"force" : 170,
	"dodge" : 10,
	"lvl" : 5,
	"damage" : 370,
"damage_type" : "����",
	 ]),
([      "action" : "$N������$w���ϰ�գ�Ծ��һ������$w�ϣ���ʽ"+(order[random(13)])+"������������ơ�"NOR"��������׹�أ�ֱ��$n",
"skill_name" : "�����������",
	"force" : 190,
	"dodge" : 10,
	"lvl" : 25,
	"damage" : 375,
"damage_type" : "����",
	 ]),
([      "action" : "ƾ������һ��ѩ�׵Ĺ�Ļ�������˸��$wЮ"+(order[random(13)])+"���󹦵¹����ơ�"NOR"�����Ͼ�������$N���зɳ�����$n��$l",
"skill_name" : "�󹦵¹�����",
	"force" : 200,
	"dodge" : 20,
	"lvl" : 45,
	"damage" : 320,
"damage_type" : "����",
	 ]),
([      "action" : "$N˫�ۿıգ�ȫ������ȴ���ھ����������������$w����"+(order[random(13)])+"���󸣵¹����ơ�"NOR"���ƶ��£���$n����ѹ��",
"skill_name" : "�󸣵¹�����",
	"force" : 300,
	"dodge" : 5,
	"lvl" : 65,
	"damage" : 365,
"damage_type" : "����",
	 ]),
([      "action" : "$N˫�ֻ�Ȧ��ԽתԽ������Ļ����һ�����£���$P���֣���"+(order[random(13)])+"����������ơ�"NOR"�ľ�������$w����ɽ����֮�Ʒ�������",
"skill_name" : "���������",
	"force" : 270,
	"dodge" : 15,
	"lvl" : 85,
	"damage" : 360,
"damage_type" : "����",
	 ]),
([      "action" : "$N���и߳�����ħ�䡹��һ��"+(order[random(13)])+"�������������ơ�"NOR"�ӳ���$w�û����������Ӱ����������ˮ��ӿ��$n",
"skill_name" : "������������",
	"force" : 290,
	"dodge" : 10,
	"lvl" : 105,
	"damage" : 295,
"damage_type" : "����",
	 ]),
([      "action" : "$Nһ��"+(order[random(13)])+"������������ơ�"NOR"��������⣬�����Ͻ�ħ�󷨴߶���$w�����趯�Ĺ�����������$n���ݷ�Ҫ����һ����ħ",
"skill_name" : "�����������",
	"force" : 300,
	"dodge" : 5,
	"lvl" : 125,
	"damage" : 310,
"damage_type" : "����",
	 ]),
([      "action" : "$N��һ��������ʹ��"+(order[random(13)])+"�����ǻ۹����ơ�"NOR"������$w���·��ɣ��ַ�����$n����$p��Ҳ�ֲ����ĸ����棬�ĸ��Ǽ�",
"skill_name" : "���ǻ۹�����",
	"force" : 330,
	"dodge" : 20,
	"lvl" : 145,
	"damage" : 310,
"damage_type" : "����",
	 ]),
([      "action" : "$N���΢Ц����¶�ȹ⣬ȫ����ɢ������"+(order[random(13)])+"����ȱ������ơ�"NOR"�������羪�κ��ˣ�$wһ���һ���ӿ��$n",
"skill_name" : "��ȱ�������",
	"force" : 320,
	"dodge" : 15,
	"lvl" : 165,
	"damage" : 290,
"damage_type" : "����",
	 ]),
([      "action" : "$N˫�ָ߾�$w�����һ��ʹ��"+(order[random(13)])+"����Բ�������ơ�"NOR"���϶���ն��$n�������ޱȣ�������ӿ���Ѵ�Բ��֮��",
"skill_name" : "��Բ��������",
	"force" : 450,
	"dodge" : 20,
	"lvl" : 185,
	"damage" : 400,
"damage_type" : "����",
	 ]),
});

string *parry_msg = (
{
	"$n���㲻�ܣ�����$w�ڿ�����$P��ǰ�γ���һ����Ļ��$N���и����޷��ٽ���\n",
	"ȴ��$n̤ǰһ��������$w���ɣ��������ޣ�$Nǰ�����ܣ�ֻ��������ˡ�\n",
	"$n�ַ�ͻ�䣬$w���ŷ��������ȥ������������$N��û����ʱ������$p��������\n",
	"����$n��$wӲ����ƹ��һ���ܿ����������ڵ�$N��\n",
});

string *msg = (
{
	""+(order[random(13)])+"��������ֻ$w�Ի����������������Ʋ���������$nһ��֮�ʣ�$w�����˳�ȥ��"NOR"",
	""+(order[random(13)])+"���������У�$w��ת������ײ��$n����$p��Ҫ����ʱ��ȴ�ƹ����ɵ�������"NOR"",
	""+(order[random(13)])+"$w���������������ɻأ�����$n����Ȧ�ӣ����ߺ��ͣ�������б����������Ҳ���������죬�Թ����˾����ŵ��ۻ����ң����񲻶�"NOR"",
	""+(order[random(13)])+"һ����С���ˣ�������Ȼ��$w�����һ��������$nײȥ��������ţ���������ɵ�"NOR"",
	""+(order[random(13)])+"ֻ��$w����$n�����·��ɣ�$w��Ծ�鶯�����������������Ƶ����������絶���Ҫ��$n��������"NOR"",
	""+(order[random(13)])+"ͻȻ��������𣬼�������$w������ײ�����ֹ�һ���ϲ�����$n��ȥ"NOR"",
	""+(order[random(13)])+"������$n��ǰ���ģ��͵���$pӭͷ���£������ַ���һ�֣�һ��һ�ͣ��������죬����$n$l"NOR"",
	""+(order[random(13)])+"������Х���У�����ֻ$w��ֱ�ɡ���б�ɡ������������׹������������ʱ��$n��ȫ����·�ѱ�����"NOR"",
	""+(order[random(13)])+"�͵���$w��$n$l�����£���$p����ж��֮ʱ��$w��ͻȻ�Ϸɻ���������$p��$l"NOR"",
	""+(order[random(13)])+"��$w�����ҵ���$nȴ������ͷ�����������һһ��������$w���糤�����۾�һ�㣬��Ȼ�����ɵ���$n$l"NOR"",
});


int valid_enable(string usage)
{
	return usage == "hammer" || usage == "parry";
}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("longxiang", 1) < 100)
		return notify_fail("���������������̫ǳ��\n");
	if (me->query_skill("hammer", 1) <=me->query_skill("riyue-lun", 1))
		return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "hammer")
		if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "hammer")
			return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query_skill("riyue-lun", 1) < 160)
		return notify_fail("��������ַ�̫ǳ��\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("�����������,�����������ַ���\n");
	me->receive_damage("qi", 40);
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
	level = (int) me->query_skill("riyue-lun",1);
	if (level>100 && me->query("neili")>3000)
	{
		me->add_temp("riyue_no", 1);
		if (me->query_temp("riyue_no")>20)
		{
			me->set_temp("riyue_no", 0);
			message_vision( BOLD"\n$N��������˿�������Ȼ���е����ˣ�\n"NOR, me);
			me->set_temp("str",0);
		}
		else if( (int)me->query_temp("riyue_no") % 2 )
		{
			message_vision( HIY"\n$N������һ����������"+me->query_temp("weapon")->name()+HIY+"������������\n"NOR, me);
			me->add_temp("str",level/10);
			me->add("neili",-50);
		}
	}
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
		{
			a_action = action[NewRandom(i, 20, level/10)];
			break;
		}
	a_action["dodge"]  = 0-level;
	a_action["parry"]  = 0-level*3;
	a_action["attack"]  = level*2;
	a_action["damage"] = level*2;
	return a_action;
}

string query_parry_msg()
{
	object weapon;
	if (objectp(weapon = this_player()->query_temp("weapon")) && weapon->query("skill_type") == "hammer")
		return parry_msg[random(sizeof(parry_msg))];
}

string perform_action_file(string action)
{
	return __DIR__"riyue-lun/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	string msg;
	object victim_w;
	int level;
	victim_w = victim->query_temp("weapon");
	level = (int) me->query_skill("riyue-lun",1);

	if (random(me->query_skill("riyue-lun",1)) > 100 && random(2)==0)
	{
		msg = HIR"$N�����ս���������ڲ����������ԣ�������֮����$n��ȥ��\n"NOR;
		victim->receive_damage("qi", level );
		victim->receive_wound("qi", level );
		message_vision(msg,me,victim);
	}

	if (victim->query_temp("weapon") || victim->query_temp("secondary_weapon"))
	{
		if( (int)me->query_skill("riyue-lun", 1) < 20 )
			return HIW "һ�������ײ���������󣬶Է�������Ȼ�������\n" NOR;
		if( victim->query_temp("apply/damage") < random(me->query_skill("riyue-lun", 1)/2 ))
		{
			victim_w->unequip();
			victim_w->reset_action();
			victim_w->move(environment(victim));
			victim_w->set("name", victim_w->query("name") + "����Ƭ");
			victim_w->set("value", 0);
			victim_w->set("weapon_prop", 0);
			victim_w->set("long", "һ���������£������Ǳ�����Ƭ��\n");
			return HIB "������"+(order[random(13)])+"��������"NOR"һ�����������������������Ƭ����һ�أ�\n" NOR;
		}
	}
}

int ob_hit(object ob, object me, int damage)
{
	string msg;
	int j;
	int level2,damage2;
	
	level2= (int) me->query_skill("longxiang",1);	
	if ( level2<= 0) level2= (int) me->query_skill("xiaowuxiang",1);
	
	damage2= (int) ob->query("neili")/10;
	if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "longxiang" || me->query_skill_mapped("force") == "xiaowuxiang"))
	{
		j = -damage/2;
		if (damage2> 5000)	damage2=5000;
		if (damage2 < 0 ) damage2=0;
		msg = HIM"$N ���������𡸽�����ħ�䡹��������ӿ������һ��һ��ļ�ǿ��$n����һ�ң�������Ȼ�᲻������\n"NOR;
		ob->set_temp("apply/attack", 0);
		ob->set_temp("apply/defense", 0);
		if (random(2)==0)
		{
			msg += HIM"$N"+HIM+"Ĭ������������ԣ��ֽ�Ħ��֧���ŭӡ! $n����һ�����³�һ����Ѫ!"+NOR;
			if (ob->query("qi") > damage2)
			{
				ob->receive_damage("qi", damage2/2);
				ob->receive_wound("qi", damage2/2);
			}
			if (!ob->is_busy() && random(3)==0) ob->start_busy(2);
		}

		message_vision(msg, me, ob);
		return j;
	}
}