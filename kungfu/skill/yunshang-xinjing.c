// yunshang-xinjing.c �����ľ�
// By suimeng
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i;
    int lvl = (int)me->query_skill("yunshang-xinjing", 1);
    if ( me->query("gender") == "����" && me->query("gender") == "����")
        return notify_fail("�����ľ�ֻ��Ů�Բſ���ѧϰ��\n");
    if (me->query_skill("force",1) <=lvl)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    if (me->query_skill("force",1)<100)
        return notify_fail("��Ļ����ڹ���������������ѧ�����ľ���\n");
    skl = this_player()->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="yunshang-xinjing") continue;
        if (sname[i]=="yijing-force") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
            return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����ľ�����\n");
    }
    return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    string msg;
	object weapon;
	weapon = victim->query_temp("weapon");
        if (me->query_skill("yunshang-xinjing",1) > 1000)
        if( random(me->query("neili")) > random(victim->query("neili")) && random(3)==0)
        {
            msg = "$N"HIR"�����������׵����ˣ�$n���������У�ͣ����һ���ж�.........\n" NOR;
                victim->apply_condition("no_perform", 3);
                victim->apply_condition("no_enforce", 3);
                victim->apply_condition("no_exert", 3);
				victim->apply_condition("no_equip", 10);
				
				if (weapon)weapon->unequip();
                return msg;
        }
}
int ob_hit(object ob, object me, int damage)
{
	string msg;
	int damage2, j;
	damage2= (int) me->query("neili",1)/8+1000;
	if (random(5)==0 && me->query_skill("yunshang-xinjing",1)>=300  )
    {
    if (me->query("qi") <= me->query("max_qi"))
    {
    me->add("qi",damage2);
    }
   if (me->query("eff_qi") <= me->query("max_qi"))
    {
   me->add("eff_qi",damage2);
    }
  msg = HIB "$N" HIR "���������ľ����������������衢��ݺ�䡢�����!!\n" NOR;
        ob->apply_condition("no_perform", 1);
           message_vision(msg, me, ob);
           return j;
}       
}
int practice_skill(object me)
{
    return notify_fail("�����ľ�ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
    return __DIR__"yunshang-xinjing/" + func;
}

