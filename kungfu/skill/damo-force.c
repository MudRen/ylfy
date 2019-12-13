#include <ansi.h>

inherit FORCE;

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if ( me->query("family/family_name") != "ͨ�԰�" ) return 0;
    if ( damage_bonus < 600 ) return 0;
	if ( random(5*(me->query_skill("damo-force",1))) > (damage_bonus ) ) 
	{
		victim->receive_damage("qi", random(damage_bonus));
		me->add("neili", -(int)me->query("jiali") );
		return HIB "$N���ӳ�"+HIR+"��Ħ��"NOR HIB"������,�ݻ���$n����Ԫ��������\n" NOR;
	}
}

int valid_enable(string usage) 
{ 
        return      usage=="force";

}

int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i;
    int lvl = (int)me->query_skill("damo-force", 1);
    if ( me->query("gender") == "����" && lvl > 49)
        return notify_fail("���޸����ԣ���������������������Ĵ�Ħ�񹦡�\n");
     if (me->query("kar") < 27)
       return notify_fail("��ĸ�Ե������᲻�˸���Ĵ�Ħ�񹦡�\n");
     if (me->query_skill("force",1)<=lvl)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    skl = me->query_skills();
    sname  = keys(skl);
        if ( !me->query_skill("jiuzhuan-12tian",1) ) {
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="hunyuan-yiqi") continue;
        if (sname[i]=="damo-force") continue;
        if (sname[i]=="taiji-shengong") continue;
		if (sname[i]=="xixing-dafa") continue;
         if (sname[i]=="fanyun-force") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��Ħ�񹦣���\n");
    }
 }
    return 1;
}

int practice_skill(object me)
{
        return notify_fail("��Ħ��ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

int effective_level() { return 21; }



string exert_function_file(string func)
{
        return __DIR__"damo-force/" + func;
}

