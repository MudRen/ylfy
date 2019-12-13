
// Create by rongg@XBTXIII
// diviemagic.c
// ��ʥħ��.��˵�еĴ�ħ��ʦ����˹ʹ�õ�ħ��,��ħ��һǧ������һֱ�������ľ���������.
// ӵ�и�ħ����ħ��ʦ�����������ľ�������ѡ,һ�������ϰ��ħ�����ʸ�,Ҳ��ζ�Ŵ��˼縺
// ���˱�������������.
// ��ʥħ����7��������ħ�� �ռ�ħ��1��,5���ħ��
// 0-40 ���絯 40-80 ����  80-120 ����Ƶ� 120-150 ����ʮ��ն
// 150-180  ���Ƿ籩 180-250 ��̫�籩
// �ռ�ħ�� 250 ��ҫ����
// ������ħ�� ������10 ħ���� �ƶ���Ը ����ħ��(�ٻ�) ˲���ƶ�(200) ����ͨ
inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="magic"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("spell",1) < (int)me->query_skill("divinemagic")/2 )
		return notify_fail("��Ļ���������Ϊ�������޷�������������ʥħ����\n");
	return 1;
}

string cast_spell_file(string spell)
{
	return CLASS_D("divine") + "/divinemagic/" + spell;
}

string scribe_spell_file(string spell)
{
	return CLASS_D("divine") + "/divinemagic/" + spell;
}

int practice_skill(object me)
{	

	if( (int)me->query("mana") < 10 )
		return notify_fail("��ķ���������\n");

	if( (int)me->query("sen") < 30 )
		return notify_fail("��ľ����޷����С�\n");

	me->add("mana", -10);
	me->receive_damage("sen", 30);

	write("�����˫��,������������ʥħ����ĳЩ����......\n");
	return 1;
}
void skill_improved(object me)
{
        int s;
    if( (int)me->query_skill("magic",1) < 10
    ||  (int)me->query_skill("magic",1) <= (int)me->query_skill("divinemagic",1) )
        {
        s = (int)me->query_skill("divinemagic",1);
        me->set_skill("divinemagic",s-1);
        tell_object(me,"��ʥħ�������ĳЩ�־�̫�����,��һֱ�޷����\n");
        }
}
