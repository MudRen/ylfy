//by mudwu
#include <combat.h>
inherit SKILL;
mapping *action = ({
([      "action": "$N˫���������裬һ�С������롹��$wֱ��$n���ظ�Ҫ��",
        "dodge": -10,
        "damage": 200,
        "lvl" : 0,
        "skill_name" : "������",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        "damage_type":  "����"
]),
([      "action": "$N���λζ���һ�С������롹������$w��һ�����ߣ���$n�ʺ��ȥ",
        "dodge": -20,
        "damage": 300,
        "lvl" : 60,
        "skill_name" : "������",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        "damage_type":  "����"
]),
([      "action": "$N��ָ΢�ţ�һ�С���Ѫ�롹������$w���ð���$nȫ��ȥ",
        "dodge":  -40,
        "damage": 400,
        "lvl" : 90,
        "skill_name" : "��Ѫ��",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        "damage_type":  "����"
]),
([      "action": "$N���һ����һ�С�����롹��$w�û�����Ŀ����������$n",
        "dodge": -50,
        "damage": 500,
        "lvl" : 100,
        "skill_name" : "�����",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        "damage_type":  "����"
]),
([      "action": "$N��һԾ��һ�С������롹��$w�����������磬����$nȫ��",
        "dodge": -60,
        "damage": 600,
        "lvl" : 110,
        "skill_name" : "������",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        "damage_type":  "����"
]),
([      "action": "$N˫Ŀ��â������һ�С���Ѫ�롹������$wȫ�����ַɳ�����ɽ���������$nȫ��",
        "dodge": -60,
        "damage": 700,
        "lvl" : 120,
        "skill_name":  "��Ѫ��",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        "damage_type":  "����"
]),
([      "action": "$N������Х��һ�С������롹��$w��Ȼ����һ��ǿ�Ҿ��磬ɨ��$n",
        "dodge": -70,
        "damage": 800,
        "lvl" : 130,
        "skill_name" : "������",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        "damage_type":  "����"
]),
([      "action": "$N����ɱ��ͻȻ��ʢ��һ�С�ɱ���롹��$w�ɻȰ����$nȫ��",
        "dodge": 100,
        "damage": 900,
        "lvl" : 200,
        "skill_name" : "ɱ����",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        "damage_type":  "����"
]),
});
int valid_enable(string usage) { return usage == "throwing"; }
int practice_level(){   return 200;  }
int valid_learn(object me)
{
      if (me->query_skill("throwing",1) <= me->query_skill("huaxue-shenzhen",1))
      return notify_fail("��Ļ����������޷���������ļ��ɣ�\n");
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
    
    level   = (int) me->query_skill("huaxue-shenzhen",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["damage"] = level+random(level);
    if ((int)me->query_temp("huaxue-shenzhen")>0)
        return (["action": BOLD "һ"+weapon->query("unit")+"$w"+BOLD+"����$n"+BOLD+"��$l" NOR,
                 "dodge": -3*random(level),
                 "damage": level,
                 "damage_type":"����",
                 "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                ]);
    return a_action;

}

int practice_skill(object me)
{
    object ob;
    if( (int)me->query("qi") < 30
    ||  (int)me->query("neili") < 35 )
        return notify_fail("�����������������û�а취��ϰ��Ѫ���롣\n");
    if (!objectp(ob = me->query_temp("weapon"))
    || (string)ob->query("skill_type") != "throwing")
    if (!objectp(ob = me->query_temp("secondary_weapon"))
    || (string)ob->query("skill_type") != "throwing")
        return notify_fail("��װ�����������ԡ�\n");
    me->receive_damage("qi", 30);
    me->add("force", -20);
    me->add_temp("pratice_throwing",1);
    if (me->query_temp("pratice_throwing") > me->query_skill("huaxue-shenzhen",1)/20 ){
           if( (int)ob->query_amount()==1 ) {
                   ob->unequip();
                   tell_object(me, BOLD "\n���" + ob->query("name") + "�����ˣ�\n\n"+NOR);
           }
           ob->add_amount(-1);
           me->delete_temp("pratice_throwing");
    }
    write("�㰴����ѧ����һ�黯Ѫ���롣\n");
    return 1;
}

void do_interlink(object me, object victim)
{
	int skill, max_enemy, max_att, i, j;
    object *enemy, weapon;
    string all_enemy, skill_name;

	if ( !objectp(weapon=me->query_temp("weapon")) ) return;
	
	skill = me->query_skill("huaxue-shenzhen", 1);
	
	if ( skill > 500 )
	{
		enemy = me->query_enemy();
		if ( !(max_enemy=sizeof(enemy)) ) return;
		if ( playerp(me) && !me->query("xy_huiyuan") ) return;

		all_enemy = "";
		max_att = skill/(80*max_enemy);
          if(max_att*max_enemy > 50) max_att = 50/max_enemy;
		  me->add_temp("lianzhao", max_att);
		for ( i=0; i<max_enemy; i++ )
		{
			if ( !objectp(enemy[i]) ) continue;
			all_enemy += enemy[i]->name();
			if ( i < max_enemy-1) all_enemy += "��";
		}
        
		message_vision(BOLD+"$N����Ծ������һ�ӣ���"+weapon->query("unit")+weapon->name()+"ͬʱ����"+all_enemy+"��\n\n" NOR,me);
		me->set_temp("huaxue-shenzhen", 1);
		
		for ( i=0; i<max_enemy; i++ )
		{
			if ( !objectp(enemy[i]) ) continue;
			for ( j=0; j<max_att; j++ )
			{
				if ( !objectp(weapon=me->query_temp("weapon")) ) break;
				if ( !stringp(skill_name=weapon->query("skill_type")) 
					|| skill_name != "throwing" )
					break;
				if ( (me->is_fighting(enemy[i]) || enemy[i]->is_fighting(me)) 
					&& enemy[i]->query("eff_qi") > 0 )
				{
					if ( environment(me) == environment(enemy[i]) )
						COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"), TYPE_QUICK);
				}
				else 
					break;
			}
		}
		me->delete_temp("huaxue-shenzhen");
		 me->delete_temp("mantianhuayu");
	}
}

int is_interlink()
{
	return 1;
}