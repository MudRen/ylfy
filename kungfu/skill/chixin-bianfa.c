// chixin-bianfa ���ı޷� 
// marry 99.8
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([ "name":   ""MAG"��Ȼ"WHT"����"NOR"",
           "action": "$N��ü������һ�С�"MAG"��Ȼ"WHT"����"NOR"������$w��$n��$l��ȥ��",           
		   "force":  100,
           "dodge":  -10,
           "damage": 30,
           "lvl"    : 0,
           "damage_type":  "����"
        ]),
        ([ "name":   "ǧ�ﹲ濾�",
           "action" : "$Nһ�С�"HIC"ǧ��"HIY"��"HIG"濾�"NOR"����$w���϶����׳�һ���󻡣�ƽƽ����$n��$l��ȥ",
           "force":  150,
           "dodge":  0,
           "damage": 80,
           "lvl"    : 50,
           "damage_type":  "����"
        ]),
        ([ "name":   "��ˮһ��",
           "action" : "$N���������һš��һ�С�"HIG"��"CYN"ˮ"HIW"һ��"NOR"������$w������$n��$l��ȥ",
           "force":  200,
           "dodge":  0,
           "damage": 90,
           "lvl"    : 100,
           "damage_type":  "����"
        ]),
        ([ "name":   "��Ը�˳���",
           "action" : "$Nһ�С�"HIM"��Ը"WHT"��"HIR"��"HIB"��"NOR"����$w����ػ�������Բ����Ѹ�ٵ���$n��$l��ȥ",
           "force":  250,
           "dodge":  0,
           "damage": 100,
           "lvl"    : 150,
           "damage_type":  "����"
        ]),
        ([ "name":   "ֻ��ԧ�첻����",
         "action" : "ֻ��$N������$w�������״��һ�С�"HIG"ֻ"HIY"��"HIM"ԧ"HIB"��"HIW"��"CYN"��"HIY"��"NOR"��Ѹ�͵Ĺ���$n",
           "force":  300,
           "dodge":  0,
           "damage": 140,
           "lvl"    : 200,
           "damage_type":  "����"
        ]),
        ([ "name":   ""HIM"���"HIB"���"NOR"",
           "action": "ֻ��$N����¶������֮ɫ�������ӱޣ�һʽ��"HIM"���"HIB"���"NOR"����ƮƮ��ɨ��$n",
           "force":  250,
           "dodge":  0,
           "damage": 100,
           "lvl"    : 230,
           "damage_type":  "����"
        ]),
        ([ "name":   ""MAG BLINK"��ˮ"NOR HIG"����"NOR"",
           "action": "$N�淺�һ���˫���Ƶ����ˮ��һ�С�"MAG BLINK"��ˮ"NOR HIG"����"NOR"��������$w����������������ز���$n��$l",
           "force":  250,
           "dodge":  20,
           "damage": 250,
           "lvl"    : 250,
           "damage_type":  "����"
        ]),
        ([ "name":   ""HIB"����"HIR"����"NOR"",
           "action": "$N����$w�Կ�һָ������Ϊ����һ�С�"HIB"����"HIR"����"NOR"�����Ʋ���һ�й���$n��",
           "force":  300,
           "dodge":  25,
           "damage": 300,
           "lvl"    : 300,
           "damage_type":  "����"
        ]),
        ([ "name":   ""HIG"����"MAG"��Զ"NOR"",
           "action": "$N��Ȼ����������$n������䣬$Nһʽ��"WHT"����"MAG"��Զ"NOR"��������$w��Ȼ����$n��$l��",
           "force":  350,
           "dodge":  35,                          
           "damage": 350,
           "lvl"    : 350,
           "damage_type":  "����"
        ]),
        ([ "name":   ""HIR"��"HIG"��"HIM"��"HIB"��"NOR"",
           "action": "$NĬ��ھ���һ�С�"HIR"��"HIG"��"HIM"��"HIB"��"NOR"����������$n��$l,$n��æ�мܣ�����$N��$wͻȻ���˸��䣬���صĲ���$n��$l��",
           "force":  400,
           "dodge":  40,
           "damage": 400,
           "lvl"   : 400,
           "damage_type":  "����"
        ]),
});


int valid_enable(string usage) { return usage=="whip" ||  usage=="parry"; }
int valid_learn(object me)
{
        object weapon;
        int lvl = (int)me->query_skill("chixin-bianfa", 1);
        int t = 1, j;
        if (lvl<=100)
                for (j = 1; j < lvl / 10; j++)
                        t*=2;
        if ( me->query("gender") != "Ů��" )
                return notify_fail("���ֲ���Ů����ʲô���ı޷���\n");
        if ((me->query("family/master_id")!="shangguan feifeng")&&
            (me->query("family/master_id")!="meng shashaonv")&&  
            (me->query("family/master_id")!="shangguan yunqian")&& 
			(me->query("family/master_id")!="long yujiao"))
                return notify_fail("�Ǳ������ڵ����޷�ѧϰ��\n");
        if(lvl<=100)
        {
                if (lvl > 10 && (int)me->query("shen") < t * 100) 
                        return notify_fail("�����������̫���ˡ�\n");
        }
        else
        {
                if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000)) 
                        return notify_fail("�����������̫���ˡ�\n");
        }
        if( (int)me->query("max_neili") < 500 )
                return notify_fail("����������㣬û�а취�����ı޷�, ����Щ���������ɡ�\n");

        if ((int)me->query_skill("whip", 1) < 50)
                return notify_fail("��Ļ����޷����̫ǳ��\n");

        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("���������һ�����Ӳ������޷���\n");

        return 1;
}


string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}

int practice_skill(object me)
{
        
        int skill;

       if ((me->query("family/master_id")!="shangguan feifeng")&&
           (me->query("family/master_id")!="meng shashaonv")&&  
           (me->query("family/master_id")!="shangguan yunqian")&& 
		   (me->query("family/master_id")!="long yujiao"))                
		   return notify_fail("�Ǳ������ڵ����޷���ϰ��\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("����������������ı޷���\n");
        if( skill > 100 && me->query("shen") < 1)
                return notify_fail("�����书�����������¡�\n");
        me->receive_damage("qi", 40);
        me->add("neili", -30);
        return 1;
}
                                          
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 1 ) return 0;
        if( random( me->query_skill("whip") ) > random( victim->query_skill("force")) && me->query("family/family_name") == "����������" 
		 && me->query_skill_mapped("force") == "wangran-xinfa")
        {
                victim->receive_wound("qi", damage_bonus );
                return HIR "ֻ������"HIY""BLINK"����"NOR""HIR"��һ�����죬$w"HIR"��Ȼ����Ƥ�⣡\n" NOR;
        }
}

mapping query_action(object me, object weapon)
{
        if (random(me->query_skill("chixin-bianfa",1)) > 399 && me->query("neili") > 150 && me->query("family/family_name") == "����������" )
        {
                me->add("neili", -150);
                return ([
        "action": ""HIG"��Ȼ$N����������ѳ��ı޷�ʹ����������ˮ������$w"HIG"����������\n"
        "$n"HIG"ֻ����ǰһƬ�谵����ʱ������ң�ֻ���ñ�Ӱ����ǵص����Լ�������\n"NOR"",
        "force":  600,
        "damage": 600,
        "damage_type": "����"]);
        }
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
        return __DIR__"chixin-bianfa/" + action;
}
