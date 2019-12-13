inherit SKILL;

#include <ansi.h>

string *parry_msg = ({
        HIY "$N" HIY "��ʽ���ͣ�$n" HIY "��������֮�⣬����һ����ն������������л��⡣\n" NOR,
        HIY "$n" HIY "����������������磬$N" HIY "�Ͻ����У������ٽ���\n" NOR,
});

mapping *action = ({
([      "action" : "$N����$w���ɨ����һ�С��ϲ��������������ź������ذ��������$n$l��ȥ",
        "skill_name" : "�ϲ�����",
        "force"  : 500,
        "attack" : 360,
        "parry"  : 100,
        "damage" : 600,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С������项������һ����࣬˫��΢�գ�$w�����Ļ���������$n��$l",
        "skill_name" : "������",
        "force"  : 500,
        "attack" : 360,
        "parry"  : 100,
        "damage" : 600,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С��̲��񵶡���$w���纣Х�㣬����ǵؾ���$n",
        "skill_name" : "�̲���",
        "force"  : 500,
        "attack" : 360,
        "parry"  : 100,
        "damage" : 600,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С��׺�������������$w��ת������һ����â����ն���������$n",
        "skill_name" : "�׺�����",
        "force"  : 500,
        "attack" : 360,
        "parry"  : 100,
        "damage" : 600,
        "damage_type" : "����",
]),
([      "action" : "$N����$w��ת��Ծ��һ�С��쵶��ʽ����$wһ���������˵��׹�����$n��$l",
        "skill_name" : "�쵶��ʽ",
        "force"  : 600,
        "attack" : 360,
        "parry"  : 100,
        "damage" : 600,
        "damage_type" : "����",
]),
([      "action" : "$Nһ����̾�����׾��£�����һ��������һ�С����쵶ɷ��ʹ����$w��������������������ְ�ӿ��$n",
        "skill_name" : "���쵶ɷ",
        "force"  : 600,
        "attack" : 360,
        "parry"  : 200,
        "damage" : 600,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if( me->query("str")< 38 )
                return notify_fail("������������㣬�޷������Ե���\n");

        if( me->query("con")< 38 )
                return notify_fail("������������㣬�޷������Ե���\n");

        if( me->query("reborn/times") < 3 )
                return notify_fail("��ת�������������޷�����Ե��ľ��衣\n");

        if( me->query_skill("sword",1) && me->query("reborn/times") < 3 )
                return notify_fail("����ѧ����ѧ̫���ˣ��޷�ר����ϰ�Ե���\n");

        if( me->query_skill("club",1) && me->query("reborn/times") < 3 )
                return notify_fail("����ѧ����ѧ̫���ˣ��޷�ר����ϰ�Ե���\n");
                
        if( me->query_skill("staff",1) && me->query("reborn/times") < 3 )
                return notify_fail("����ѧ����ѧ̫���ˣ��޷�ר����ϰ�Ե���\n");
                
        if( me->query_skill("whip",1) && me->query("reborn/times") < 3 )
                return notify_fail("����ѧ����ѧ̫���ˣ��޷�ר����ϰ�Ե���\n");
                
        if( me->query_skill("dagger",1) && me->query("reborn/times") < 3 )
                return notify_fail("����ѧ����ѧ̫���ˣ��޷�ר����ϰ�Ե���\n");
                
        if( me->query_skill("hammer",1) && me->query("reborn/times") < 3 )
                return notify_fail("����ѧ����ѧ̫���ˣ��޷�ר����ϰ�Ե���\n");
                                                          
        if( me->query("max_neili")<20000 )
                return notify_fail("���������Ϊ���㡣\n");

        if ((int)me->query_skill("force", 1) < 500)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("martial-cognize", 1) < 500)
                return notify_fail("�����ѧ�������㡣\n");

        if ((int)me->query_skill("blade", 1) < (int)me->query_skill("badao", 1))
                return notify_fail("��Ļ���������򲻹����޷���������İԵ���\n");  
                
        if ((int)me->query_skill("dodge", 1) < (int)me->query_skill("badao", 1))
                return notify_fail("��Ļ����Ṧˮƽ���ޣ��޷���������İԵ���\n");  
                              
        if ((int)me->query_skill("parry", 1) < (int)me->query_skill("badao", 1))
                return notify_fail("��Ļ����м�ˮƽ���ޣ��޷���������İԵ���\n"); 
                
        if ((int)me->query_skill("force", 1) < (int)me->query_skill("badao", 1))
                return notify_fail("��Ļ����ڹ�ˮƽ���ޣ��޷���������İԵ���\n"); 
                
        if ((int)me->query_skill("martial-cognize", 1) < (int)me->query_skill("badao", 1))
                return notify_fail("�����ѧ�������ޣ��޷���������İԵ���\n"); 
/*
        // ѧ���˵���������Ҫ���׽
        if( query("can_perform/badao/san", me) )
        {
                if ((int)me->query_skill("yijinjing", 1) * 3 < (int)me->query_skill("badao", 1))
                {
                        return notify_fail("���׽��Ϊ���㣬ǿ���������»��߻���ħ��\n");
                }
        }
  */      
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
        return action[random(sizeof(action))];
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int double_attack()
{
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("�Ե�������޷��򵥵�ͨ����ϰ������\n");
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string *desc;
        object weapon;
        
        weapon = me->query_temp("weapon");
        
        if (! objectp(weapon))return damage_bonus;
        
        desc = ({
                HIY "$N" HIY "������𣬾�������" + weapon->name() + HIY "�������£�����һ�����绮��$n" HIY "��\n" NOR,
                HIC "$N" HIC "����" + weapon->name() + HIC "������ֱ������ʽ��֮����ȴ�����ޱȡ�\n" NOR,
                HIR "$N" HIR "�Ӷ�����" + weapon->name() + HIR "����ʱ��ɳ��ʯ�������������ĵ��ƣ���$n" HIR "���֡�\n" NOR,
        });

        if (me->is_busy() 
           || random(4) >= 1
           || ! living(victim) 
           || damage_bonus < 150 
            || me->query("neili")<500
           || me->query_skill("badao", 1) < 500) 
                return 0; 

        // ׷����Ч
        victim->receive_wound("qi", damage_bonus / 4, me);

        if (random(6) == 1)victim->start_busy(3 + random(5));
        
        return desc[random(sizeof(desc))];
}

mixed ob_hit(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp, cost;

        if ((int)me->query_skill("badao", 1) < 350
            || me->query_skill_mapped("parry") != "badao"
            || me->query("neili")<200 || !living(me) )
                return;

        cost = damage / 2;
        if (cost > 100) cost = 100;

        ap = ob->query_skill("force") * 4 + ob->query_skill("martial-cognize", 1);
        dp = me->query_skill("blade") * 5 + me->query_skill("martial-cognize", 1) + 100;

        if (dp / 2 + random(dp / 2) >= ap)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(3))
                {
                case 0:
                        result += (["msg" : HIG "$n" HIG "����������˳��һ����Ӳ��$N" HIG "���ˡ�\n" NOR]);
                        break;
                case 1:
                        result += (["msg" : HIG "$n" HIG "���˲���������������$N" HIG "����֮�£���æ���С�\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIG "$n" HIG "�ᵶ��ǰ������$N" HIG "�����������ַ���������$N" HIG "��ʽ���� ��\n" NOR]);
                        break;
                }
                return result;
        }
}

string perform_action_file(string action)
{
        return __DIR__"badao/" + action;
}

int difficult_level()
{
        return 30000;
}
