// yunv-jianfa ��Ů���Ľ�
// Modify By csy 98/12
inherit SKILL;
#include <combat.h>

mapping *action = ({
([      "action" : "$N���߶��£�һʽ������б�����������»�������ֱ��$nͷ��",
        "force" : 130,
        "dodge" : 50,
        "damage" : 40,
        "parry" : 15,
        "lvl" : 0,
        "skill_name" : "����б��",
        "damage_type" : "����"
]),
([      "action" : "$N̤ǰ����������ңָ������$wʹһʽ���˼����ġ�ֱ��$n������",
        "force" : 155,
        "dodge" : 45,
        "damage" : 65,
        "parry" : 20,
        "lvl" : 10,
        "skill_name" : "�˼�����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С���ǰ���¡���$w�������ʻ���չ���У����ػ���",
        "force" : 200,
        "dodge" : 40,
        "damage" : 80,
        "parry" : 10,
        "lvl" : 20,
        "skill_name" : "��ǰ����",
        "damage_type" : "����"
]),
([      "action" : "$N�����Ϸ�����Ȼָ���Լ���ӣ����һ�С�����С�á��������ٱ�����һ�㣬��ɨ$n��$l",
        "force" : 235,
        "dodge" : 35,
        "damage" : 85,
        "parry" : 15,
        "lvl" : 30,
        "skill_name" : "����С��",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ�������ٰ����$w�Ժ���ǰ��������״���漴�����й���ƽ��$n��$l",
        "force" : 260,
        "dodge" : 30,
        "damage" : 90,
        "parry" : 5,
        "lvl" : 40,
        "skill_name" : "���ٰ���",
        "damage_type" : "����"
]),
([      "action" : "$N�ὣб����΢΢������һ�С��ʱʻ�ü��������������ױ֮״��һ�����ߣ�$wȴ˿��δ��ͣ��������$n��$l",
        "force" : 275,
        "dodge" : 25,
        "damage" : 95,
        "parry" : 20,
        "lvl" : 50,
        "skill_name" : "�ʱʻ�ü",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��ٰ���ü����˫�����ս������ٽ�������ֱ��$n�ĵ���",
        "force" : 290,
        "dodge" : 20,
        "damage" : 100,
        "parry" : 25,
        "lvl" : 70,
        "skill_name" : "�ٰ���ü",
        "damage_type" : "����"
]),
([      "action" : "$N��ǰ����������һ�С�ľ�����䡹�������ͦ�������򱳺�̳���ֱ��$n���ؿ�",
        "force" : 305,
        "dodge" : 15,
        "damage" : 105,
        "parry" : 20,
        "lvl" : 90,
        "skill_name" : "ľ������",
        "damage_type" : "����"
]),
([  "action" : "$Nһ�С��ֻ���������$w����ʵ�ң�����ʵ����ʵĪ�磬����$n�ĺ�ͷ",
        "force" : 350,
        "dodge" : 10,
        "damage" : 110,
        "parry" : 15,
        "lvl" : 110,
        "skill_name" : "�ֻ�����",
        "damage_type" : "����"
]),
([  "action" : "$N�۽Ǿ���Ц�⣬üĿ���飬һ�С���Ӱ���桹���������Ӱ��$n��������ƮƮ�н����������ԣ�",
        "force" : 375,
        "dodge" : 15,
        "damage" : 120,
        "parry" : 20,
        "lvl" : 130,
        "skill_name" : "��Ӱ����",
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if (me->query_skill("yunv-jianfa", 1) >= me->query_skill("quanzhen-jianfa",1))
                return notify_fail("���ȫ�潣����Ϊ������\n");	
        if (me->query_skill("yunv-jianfa", 1) >= me->query_skill("meinv-quanfa",1))
                return notify_fail("�����Ůȭ����Ϊ������\n");	
        if (me->query_skill("yunv-jianfa", 1) >= me->query_skill("sword",1))
                return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
        if (me->query_skill("yunv-jianfa", 1) >= me->query_skill("yunv-xinjing",1))
                return notify_fail("�����Ů�ľ�����������\n");
        return 1;
}

string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("yunv-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                       return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
     //return notify_fail("��Ů����ֻ�ܿ�ѧϰ(learn)����ߡ�\n");
	 object weapon;
        if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
		if ((int)me->query_skill("yunv-xinjing", 1) < 420)
                return notify_fail("�����Ů�ľ����̫ǳ��\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("���������������Ů������\n");
        if ((int)me->query("qi") < 40)
                return notify_fail("���������������Ů������\n");
        me->receive_damage("qi", 25);
        me->add("neili", -5);
        return 1;

}

string perform_action_file(string action)
{
        return __DIR__"yunv-jianfa/" + action;
}

void do_interlink(object me, object victim)
{
	int skill, max_enemy, max_att, i, j;
    object *enemy, weapon;
    string skill_name, jifa_skill;

	if ( !objectp(weapon=me->query_temp("weapon")) ) return;
	
	skill = me->query_skill("yunv-jianfa", 1);
	if ( skill > me->query_skill("meinv-quanfa", 1) ) 
		skill = me->query_skill("yunv-xinjing", 1);
	me->set_temp("action_flag", 0);
	
	if ( skill >= 250 
		&& me->query_skill("yunv-xinjing", 1) >= 250 
		&& stringp(jifa_skill=me->query_skill_mapped("force"))
		&& jifa_skill == "yunv-xinjing" )    
	{
		enemy = me->query_enemy();
		if ( !(max_enemy=sizeof(enemy)) ) return;
		if ( playerp(me) && !me->query("xy_huiyuan") ) return;
        
		max_att = skill/(50*max_enemy)+5;
        if(max_att*max_enemy>50) max_att=50/max_enemy;
		if ( me->query("neili") < max_att*(10+me->query("jiali")) ) return;
		
        message_vision(WHT+"$NĬ�˹�Ĺ�ķ�������ֹˮ��ʹ����"+HIC+"��Ů����"+NOR+"��������\n" NOR, me);
		for ( i=0; i<max_enemy; i++ )
		{
			if ( !objectp(enemy[i]) ) continue;
			for ( j=0; j<max_att; j++ )
			{
				if ( !objectp(weapon=me->query_temp("weapon")) ) break;
				if ( !stringp(skill_name=weapon->query("skill_type")) 
					|| skill_name != "sword" )
					break;
				if ( (me->is_fighting(enemy[i]) || enemy[i]->is_fighting(me)) 
					&& enemy[i]->query("eff_qi") > 0 )
				{
					if ( environment(me) == environment(enemy[i]) )
					{
						me->add_temp("str", skill/10);
						me->add_temp("dex", skill/10);
						
						COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"), TYPE_REGULAR);
						if ( me->query("neili") >= 10*max_att ) me->add("neili", -10*max_att);
					}
				}
				else 
					break;
			}
		}
		me->delete_temp("str");
		me->delete_temp("dex");
	}
}

int is_interlink()
{
	return 1;
}