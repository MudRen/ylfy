// pixie-jian.c ��а����
// Jay 4/5/96
inherit SKILL;

#include <combat.h>

string *dodge_msg = ({
        "ͻȻ֮�䣬��Ӱ���ϣ�$n��󻬳����࣬��ʱ�ֻص���ԭ�أ������$N��һ�С�\n",
        "$n����Ʈ����������ȣ�ת�˼�ת���Ʋ���$N����󣬶����$N��һ�С�\n",
        "$Nֻ����ǰһ�����ƺ�����$n����һ�ϣ����漴�ּ�$n�ص�ԭ�أ�ȴ�ƴ�δ�뿪��\n",
});
// ˫����������
string *weapon_vs_weapon_msg = ({
        "ֻ�������ϡ�һ������$p������$i���ᵴ���ˡ�\n",
        "$n�����������$N������Ѹ���ޱȵ�һ����$N��$w��Щ�����Լ�С����\n",
        "���˷�����$n����$iѸ���ޱȵش���$N�ؿڣ��漴���ֲ���$w��\n",
        "����$n����һ�࣬������������$i��$w������\n",
});
// ������������,�мܷ�������
string *unarmed_vs_weapon_msg = ({
        "$n�ֱۻ�ת����$N������һ�ƣ�˳������һ�ԡ�\n",
        "$n����$iͻȻָ��$N�����ۣ�$N��æ���ܡ�\n",
});


mapping *action = ({
([      "action":"�����$N�����ϣ��ڵ�$n�����$wͱ��$n��$l����Ծ��ԭ��",
        "force" : 80,
        "lvl" : 0,
        "skill_name" : "������",
        "damage_type":  "����"
]),
([      "action":"$NͻȻ���з�һ�䣬$w�����������ʽ������ס�$n����֮�з������",
        "force" : 80,
        "lvl" : 55,
        "skill_name" : "�з�һ��",
        "damage_type":  "����"
]),
([      "action":"$N����Ʈ����������ȣ�ת�˼�ת���Ʋ���$n����࣬$w�Ѿ���$l��ȥ��",
        "force" : 90,
        "lvl" : 80,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action":"$Nһ����Ц������Ｒ����ǰ��һ˲֮�䣬��$n����Ѳ���һ�ߣ�$w�漴�ݳ�",
        "force" : 140,
        "lvl" : 100,
        "skill_name" : "������ǰ",
        "damage_type":  "����"
]),
([      "action":"$N�ȵ������ã������㼴�γ�$w�����ִ���$n��$l������ת����ȥ",
        "force" : 80,
        "lvl" : 140,
        "skill_name" : "���ִ̳�",
        "damage_type":  "����"
]),
([      "action":"$N����ˣ�$n��׷������һ�μ�$N����$n��ǰ������$wֱָ$n��$l",
        "force" : 60,
        "lvl" : 250,
        "skill_name" : "�����",
        "damage_type":  "����"
]),
([      "action":"$N��س嵽$n��ǰ������$wֱ��$n���ۣ�$n��æ�мܣ�����$N��$wͻȻת��$n��$l",
        "force" : 200,
        "lvl" : 300,
        "skill_name" : "ֱ������",
        "damage_type":  "����"
]),
([      "action":"$N����Ծ��$ņ��һ����������$N����ֱ����£�����$w����$n��$l",
        "force" : 340,
        "lvl" : 350,
        "skill_name" : "����Ծ��",
        "damage_type":  "����"
]),
([      "action":"$N��֦һ�ڣ�$n��ǰ�·�ͻȻ�������߰˸�$N���߰�ֻ$wһ�����$n",
        "force" : 380,
        "lvl" : 400,
        "skill_name" : "��֦һ��",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "dodge" || usage == "parry"; 
}
string query_parry_msg(object me,object weapon)
{
    string msg;
    object my_weapon;

    if (!(my_weapon=me->query_temp("weapon"))){
        if (!(my_weapon=me->query_temp("secondary_weapon")))
          return "";
     }else{
        if (!valid_enable(my_weapon->query("skill_type"))){
            if (!(my_weapon=me->query_temp("secondary_weapon")))
                  return "";
            else            
                if (!valid_enable(my_weapon->query("skill_type")))
                  return "";
        }
    }
    if (weapon)
        msg=weapon_vs_weapon_msg[random(sizeof(weapon_vs_weapon_msg))];
    else
        msg=unarmed_vs_weapon_msg[random(sizeof(unarmed_vs_weapon_msg))];
    msg=replace_string( msg, "$i", my_weapon->name() );
    return msg;
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
    level   = (int) me->query_skill("pixie-jian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level*3;
    a_action["parry"]  = 0-level*3;
    a_action["attack"]  = level*2;
    a_action["damage"] = level;
    if (me->query_temp("action_flag"))
       me->set_temp("action_msg","������");
    return a_action;

}
string query_dodge_msg(object me,string limb)
{
        me->set_temp("fight/dodge",3*me->query_skill("pixie-jian",1));
        return dodge_msg[random(sizeof(dodge_msg))];
}
int valid_learn(object me)
{
        return notify_fail("��а����ֻ��ͨ����ϰ���������䡷��ѧϰ��\n");
}

// ��а���������⹥��
void do_interlink(object me, object victim)
{
	int skill, max_enemy, max_att, i, j;
    object *enemy, weapon;
    string skill_name;

	if ( !objectp(weapon=me->query_temp("weapon")) ) return;
	
	skill = me->query_skill("pixie-jian", 1);
	if ( skill > 60 )    
	{
		enemy = me->query_enemy();
		if ( !(max_enemy=sizeof(enemy)) ) return;
		if ( playerp(me) && !me->query("xy_huiyuan") ) return;

		max_att = skill/(30*max_enemy);
		if (max_att > 50) max_att = 50;
		me->add_temp("lianzhao", max_att);
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
					}
				}
				else 
					break;
			}
		}
		me->delete_temp("str");
		me->delete_temp("dex");
		me->delete_temp("lianzhao");
	}
}

int is_interlink()
{
	return 1;
}
