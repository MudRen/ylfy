inherit SKILL;
#include <ansi.h>
mapping *action = ({
([      "action" : "$n����һ�������Ų�æ��һ�С�"HIM"��"HIY"��"HIC"����"NOR"������ԭ�ص��ض���\n",
        "dodge"  : 150,
]),
([      "action" : "$nһ�С�"WHT"��˷"MAG"����"NOR"����$Nֻ����ǰ$n����Ӱ��ʱ����������������֪����Ǻá�\n",
        "dodge"  : 150,
]),
([      "action" :  "$nһ�С�"HIB"����"HIR"Ʈҡ"NOR"��������΢�Σ��о����յرܿ���$N��һ�С�\n",
        "dodge"  : 200,
]),
([      "action" : "ֻ��$n������ǰһ�ݣ�һ�С�"HIY"����"HIG"���"NOR"�����͵Ĵ�$Nͷ�Ϸɹ���\n" ,
        "dodge"  : 200,
]),
([      "action" : "$nһ�С�"MAG"��"BLINK HIY"��"NOR HIG"��"HIM BLINK"��"NOR"���������Ʈ�����,$N�Ĺ������̵�Ȼ�޴档\n",
        "dodge"  : 350,
]),
([      "action" : "ȴ��$nһʽ��"HIR"��"HIC"��"YEL"��"HIB"��"NOR"�������������Ӱ����������գ�ʹ��$N�޿��κΡ�\n",
        "dodge"  : 400,
]),
([      "action" : "$nƮȻʹ��"HIG"��"HIW""BLINK"����ˮ��"NOR""HIG"����$N"HIG"�Ĺ���ȫ��������$n��"HIB""BLINK"��Ӱ"NOR""HIG"�ϣ���ͻȻ�ı仯����$N"HIG"Ŀ�ɿڴ���"NOR"\n",
        "dodge"  : 600,
])
});
int practice_skill(object me)
{
        if( (int)me->query("qi") < 45 )
                return notify_fail("�������̫���ˣ�����������ˮ�²���\n");
        me->receive_damage("qi", 35);
        return 1;
}

mapping query_action(object me, object weapon)
{
        int zhaoshu;
        zhaoshu = sizeof(action);
/*
        if ( random(me->query_skill("dodge")) > 450 &&
            me->query_skill("force") > 150 &&
            me->query("neili") > 50 ) {
            me->add("neili",-5);
            return (["action" :  
""HIG"ֻ�����һ�ڣ�$nƮȻʹ��"HIR"����ʽ"HIG"��"HIW""BLINK"����ˮ��"NOR""HIG"����$N"HIG"�Ĺ���ȫ��������$n��"HIB""BLINK"��Ӱ"NOR""HIG"�ϣ���ͻȻ�ı仯����$N"HIG"Ŀ�ɿڴ���"NOR"\n",
        "dodge"  : 600
                          ]); 
            }
*/
        return action[random(zhaoshu)];
}
int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        object me, ob;
        mapping action;

        me = this_player();
        action = query_action(me, ob);

        return action["action"];
}

