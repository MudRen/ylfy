#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N��׼��϶������һ����һ��ӡ��$n�������Ŀ�Ѩ��",
        "dodge": 30,
        "damage" : 180,
        "force": 160,
        "damage_type": "����"
]),
([      "action": "$N�˾���˫��֮�ϣ�����ǧ��޸�������$n���š�",
        "dodge": 10,
        "force": 160,
        "damage" : 200,
        "damage_type": "����"
]),
([      "action": "$Nʩչ�����ó��������Σ��ĵ��������������������$n��$l",
        "dodge": 20,
        "force": 150,
        "damage" : 220,
        "damage_type": "����"
]),
([      "action": "$N��Ӱһ�����û����ĸ����Σ����ƴ���������������$nȫ��",
        "dodge": 30,
        "force": 200,
        "damage" : 240,
        "damage_type": "����"
]),
([      "action": "$N�͵��ڿն����ڰ�ջû��ɰ˵����Σ��ƾ�����ǵذ�ĳ�$n�Ƕ����¡�",
        "dodge": 40,
        "force": 300,
        "damage" : 280,
        "damage_type": "����"
]),
});



int valid_enable(string usage) { return usage=="unarmed" || usage=="parry" || usage=="strike"; }
int valid_combine(string combo) { return combo=="tianmo-quan"; }

mapping query_action(object me)

{
        if (random(me->query_skill("unarmed")) > 60 &&
            me->query_skill("force") > 50 &&
            me->query("neili") > 100 ) {
                me->add("neili", -100);
                return ([
                "action": HIY"ֻ��$N�վ�ȫ����ȫ����������˫�ƺ��Ⱪ�֣�һ�ɺ��˵���������$n����ǰ"NOR,
                "force": 600,
                "damage" : 880,
                "damage_type": "����"]);
        }
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����ħ�Ʊ�����֡�\n");

        if ((int)me->query_skill("tianmo-shengong", 1) < 10)
                return notify_fail("�����ħ�񹦻�򲻹����޷�����ħ�ơ�\n");

        if ((int)me->query("max_neili") < 60)
                return notify_fail("�������̫�����޷�����ħ��");
        return 1;

}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 8)
                return notify_fail("���������������ħ�ơ�\n");
        if (me->query_skill("tianmo-zhang", 1) < 50)
                me->receive_damage("qi", 20);
        else
                me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tianmo-zhang/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{

	int level,level2,i;
	object weapon;
	string name;
	weapon = me->query_temp("weapon");
	
        level = (int) me->query_skill("kuihua-xinfa",1);
        level2= (int) me->query_skill("kuihua-xinfa",1);
        if (me->query_temp("weapon"))
	        name = "����" + weapon->name();
        else
	        name = "˫��";
if (!me->query_temp("action_flag") && random(3)==0 && level>=300 && me->query_skill_mapped("force") == "tianmo-shengong" )
{

	        message_vision(HIW "\n��ʱ��ֻ��$N" HIW "�����Ͱڣ���ʱ����Ϊ������Ӱ��" + name +
        	               HIW "\n�������ǰ�ִӲ�ͬ�ķ�λͬʱ����$n" HIW "��\n"
                	       NOR, me, victim);
        me->set_temp("action_flag", 1);
        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(victim))
                        break;
      if (random(2)==0) victim->start_busy(2);
       // OMBAT_D->do_attack(me, victim, weapon, 0);
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
if (random(4)==0 && level>=300 && me->query_skill_mapped("force") == "tianmo-shengong")
{
ob->add("neili",-damage2);
me->add("neili",damage2);
msg = HIC "$N" HIC "һ����Ц! ��������!! " HIC "$n" HIC "ȫ��������ˮ��ԴԴ����������$N�����壡\n" NOR;

           message_vision(msg, me, ob);
           return j;
}       
}