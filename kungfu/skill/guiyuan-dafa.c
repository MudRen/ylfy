// guiyuan-dafa ��Ԫ��
// modify by lyy 2016-6-27
inherit FORCE;
inherit F_DBASE;
public string query_type()
{
	return "yin";
}
int valid_enable(string usage)
{
	return usage == "force";
}
int valid_learn(object me)
// need more limit here
{
	mapping skl;
	string *sname;
	int i;
	int z = (int)me->query_skill("wuji-shengong", 1);
	int t = 1, j;
	for (j = 1; j < z / 10; j++) t *= 2;
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	if ( me->query("gender") == "����" && me->query_skill("guiyuan-dafa",1) > 49)
		return notify_fail("���޸����ԣ���������������������Ĺ�Ԫ�󷨡�\n");
	skl = this_player()->query_skills();
	sname  = keys(skl);
	for (i=0; i<sizeof(skl); i++)
	{
		if (sname[i]=="yijing-force") continue;
		if (sname[i]=="guiyuan-dafa") continue;
		if (sname[i]=="xixing-dafa") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
			return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��Ԫ�󷨣���\n");
	}
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	string msg;
    if( damage_bonus < 600 ) return 0;
   if( random(5*(me->query_skill("guiyuan-dafa",1))) > (damage_bonus )) {
                        victim->receive_wound("jing", (damage_bonus ));
                        victim->add("neili", -(int)me->query("jiali")/4);
						msg = HIR"$N��������Ϣ������Ԫ����һ��һ�Ŷ�ʱ" + HIB + BLINK"һ�����ֹ�Ԫ����" + NOR + HIW"������$n��" + HIR"�澭��������\n" NOR;
						//return sprintf(msg + CYN"($N�Ĺ�Ԫ����Ч��$n" + CYN + "���" + damage_bonus + "�㾫�˺�)\n", me, victim);
						return msg;
        }
}

int practice_skill(object me)
{
	return notify_fail("��Ԫ��ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
	return __DIR__"guiyuan-dafa/" + func;
}
