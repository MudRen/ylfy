#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N����$wһ����һ��"+(order[random(13)])+"��Ψ�Ҷ���"NOR"��һ����$n��$l��ȥ",
        "force" : 220,
        "dodge" : 10,
        "damage": 190,
        "lvl" : 0,
        "skill_name" : "Ψ�Ҷ���",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"��������С�"NOR"������$wһ�Σ�һ����������$n�ĵ���",
        "force" : 280,
        "dodge" : 10,
        "damage" : 225,
        "lvl" : 8,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N���μ�ת��һ��"+(order[random(13)])+"�������޳���"NOR"������$w�ӹ���ĽǶ�ն��$n��$l",
        "force" : 350,
        "dodge" : 5,
        "damage" : 225,
        "lvl" : 16,
        "skill_name" : "�����޳�",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"��Ѫ���ɺӡ�"NOR"��$w���϶��£��Բ���˼���ٶ�����$n",
        "force" : 380,
        "dodge" : 5,
        "damage" : 235,
        "lvl" : 24,
        "skill_name" : "Ѫ���ɺ�",
        "damage_type" : "����"
]),
([      "action" : "$N����$wһ�ӣ�һ��"+(order[random(13)])+"���������¡�"NOR"����������$n",
        "force" : 420,
        "dodge" : 10,
        "damage" : 250,
        "lvl" : 33,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��һ��"+(order[random(13)])+"�������ȼ��"NOR"��$w������ʮ��������϶�������$n",
        "force" : 480,
        "dodge" : 15,
        "damage" : 225,
        "lvl" : 42,
        "skill_name" : "�����ȼ",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"����;ĩ·��"NOR"������ǰ��$w˳��Ю��������$n��$l",
        "force" : 560,
        "dodge" : 5,
        "damage" : 250,
        "lvl" : 51,
        "skill_name" : "��;ĩ·",
        "damage_type" : "����"
]),
([      "action" : "$N�����������࣬һ��"+(order[random(13)])+"��Ⱥħ���衹"NOR"��$w�ڰ�ջ���ǧ�ٵ��������£���$n��Χ��һƬ��Ӱ֮��",
        "force" : 640,
        "dodge" : 20,
        "damage" : 360,
        "lvl" : 60,
        "skill_name" : "Ⱥħ����",
        "damage_type" : "����"
]),
([      "action": "$N����$wһ����$n����û�п����$N�ĳ�����",
        "damage": 200,
        "dodge":  80,
        "parry":  80,
        "damage_type":  "����"
]),
([      "action": "$N��δ�������ѳ���$nֻ��������档����������",
        "dodge":  80,
        "parry":  80,
        "damage":  240,
        "damage_type":  "����"
]),
([      "action": "$N����һ�ۣ�$w���ⲻ����$nȫ�����¶�ʱ���������У�",
        "damage": 220,
        "dodge": 60,
        "parry": 40,
        "damage_type":  "����"
]),
([      "action": "$N����$w����Բ��һ����ת�������ٶȻ��ǽǶȶ���$n�������㡣",
        "dodge":  60,
        "parry":  200,
        "damage_type":  "����"
]),
([      "action": "$n��ǰһ����$N��$w���ѵ���$n����ǰ��",
        "damage": 240,
        "dodge":  60,
        "parry":  60,
        "damage_type":  "����"
]), 

([      "action": "$Nʹ����ħ��ʽ�е�����ʽ����ħ���ѡ������е�$w����һ���âն��$n��$l",
        "damage": 60,
        "dodge":  60,
        "parry": 60,
        "force": 400,
        "damage_type":  "����"
]),
([      "action": "$N��һ����һ�С�ħ�����ɡ����е�$w�ó�һƬ������ɢ��$n��$l",
        "damage": 70,
        "dodge": 90,
        "parry":  90,
        "force":  200,
        "damage_type":  "����"
]),
([      "action": "$N�����ת�����е�$wһ�С�ħ��է�֡������������$n��$l",
        "damage": 80,
        "dodge": 90,
        "parry": 190,
        "force": 200,
        "damage_type":  "����"
]),
([      "action": "$N��Ӱ�ζ������������ң�һ�С���ħ���𡱣����е�$w������·ͻȻ����$n��$l",
        "damage": 260,
        "dodge":  60,
        "parry":  60,
        "force":  200,
        "damage_type":  "����"
]),
([      "action": "$N��˫�ŵ�أ���������һ�С�������ħ��ȫ��ת��һ�ŵ������$n",
        "damage": 280,
        "dodge":  80,
        "parry": 80,
		"force": 200,
        "damage_type":  "����"
]),
([      "action": "$N�������ϣ�һ�С���ħ���족����һ��$n���벻���ĽǶ�����$n��$l",
        "damage": 260,
        "dodge":  60,
        "parry":  60,
        "force":  200,
        "damage_type":  "����"
]),
([      "action": "$N���е�$w���ҺỮ��һ�С���ħ���֡��������ػصؿ�ɨ��$n��$l",
        "damage": 270,
        "dodge": 50,
        "parry": 50,
        "force":  200,
        "damage_type":  "����"
]),
([		"action": "$Nʹ��������ħ������ʽ�е�����ʽ����ħ���ڡ������е�$wѸ���ޱȵؿ���$n��$l",
        "damage": 300,
        "dodge": 50,
        "parry": 50,
		"force": 500,
		"damage_type":  "����"
]),
([      "action": "$N����$wһ����$n��ǰ����һ�ֳ���ħ�������......��",
        "damage": 300,
        "dodge": 50,
        "parry": 50,
        "damage_type": "����"
]),
([      "action": "$N������翣�����$w����һ�ӣ�ʮ����ħ��ʱӿ����$n��ǰ��",
        "dodge": 50,
        "parry": 50,
        "damage": 200,
        "damage_type": "����"
]),
([      "action": "$N��Цһ����$w��������������ħ����Ȼ��$n�������У�",
        "damage": 200,
        "dodge": 50,
        "parry": 50,
        "damage_type": "����"
]),
([      "action": "$N����$wͻȻ���Ѫ��,$w��ʱħ�����ޣ�$n�������⣬��Ȼ�޷����㣡",
        "damage": 250,
        "dodge": 50,
        "parry": 50,
        "damage_type": "����"
]),
([      "action": "$n�۾�һ����Ѫ���$w����������$n�ĺ�ǰ��",
        "damage": 150,
        "dodge": 50,
        "parry": 50,
        "damage_type": "����"
]),      
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_combine(string combo) { return combo=="tianmo-jian"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 30)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("tianmo-shengong", 1) < 10)
                return notify_fail("�����ħ�񹦻��̫ǳ��\n");
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
        level   = (int) me->query_skill("tianmo-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("���������������ħ����\n");
        me->receive_damage("qi", 25);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"tianmo-dao/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
      
	int level, i;
	object weapon;
	string name;
	weapon = me->query_temp("weapon");
	
        level = (int) me->query_skill("tianmo-shengong",1);
        if (me->query_temp("weapon"))
	        name = "����" + weapon->name();
        else
	        name = "˫��";
if (!me->query_temp("action_flag") && random(4)==0 && level>=300 && me->query_skill_mapped("force") == "tianmo-shengong" )
{

	        message_vision(HIW "\n��ʱ��ֻ��$N" HIW "�����Ͱڣ���ʱ����Ϊ������Ӱ��" + name +
        	               HIW "\n�������ǰ�ִӲ�ͬ�ķ�λͬʱ����$n" HIW "��\n"
                	       NOR, me, victim);
        me->set_temp("action_flag", 1);
        for (i = 0; i < 3; i++)
        {
                if (! me->is_fighting(victim))
                        break;
  if (random(2)==0) victim->start_busy(2);
                COMBAT_D->do_attack(me, victim, weapon, 0);
        }
        me->delete_temp("action_flag");
}

}
int ob_hit(object ob, object me, int damage)
{
        string msg;
        int j;
        int level,damage2;
        level = (int) me->query_skill("tianmo-shengong",1);

damage2= (int) ob->query("neili",1)/8;
if (random(4)==0 && level>=300 && (me->query_skill_mapped("force") == "tianmo-shengong" || me->query_skill_mapped("force") == "kuihua-xinfa"))
{
ob->add("neili",-damage2);
me->add("neili",damage2);
msg = HIC "$N" HIC "һ����Ц! ��������!! " HIC "$n" HIC "ȫ��������ˮ��ԴԴ����������$N�����壡\n" NOR;

           message_vision(msg, me, ob);
           return j;
}       
}