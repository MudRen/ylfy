// jiuyin-zhenjing.c �����澭

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i;
    int lvl = (int)me->query_skill("jiuyin-zhenjing", 1);
    if ( me->query("gender") == "����" && lvl > 49)
        return notify_fail("���޸����ԣ���������������������ľ����澭��\n");
    if (me->query_skill("force",1) <=lvl)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    if (me->query_skill("force",1)<20)
        return notify_fail("��Ļ����ڹ���������������ѧ�����澭��\n");
    skl = this_player()->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="jiuyin-zhenjing") continue;
        if (sname[i]=="yijing-force") continue;
		if (sname[i]=="xixing-dafa") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
            return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����澭����\n");
    }
    return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    string msg;	
	
    if( damage_bonus < 100 ) return 0;
	
		if (me->query_skill("jiuyin-zhenjing",1) > 550)		
		 
        if( random(me->query("max_neili")) > random(victim->query("max_neili")) &&random(3)==0)
        {
            msg = "$n"HIB"��Ȼ�о���$Nһ�������������������\n" NOR;
                victim->receive_wound("qi", damage_bonus);
                //victim->add("jing", -extra);
				victim->apply_condition("no_perform", 1);
				victim->apply_condition("no_enforce", 1);			             
                return msg;
        }
}
int practice_skill(object me)
{
    return notify_fail("�����澭ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
    return __DIR__"jiuyin-zhenjing/" + func;
}

