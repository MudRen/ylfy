inherit SKILL;
mapping *action = (
{
	([
    "action":"$N����һ����$w���⻯Ϊ����׹⣬�ֱ���$n���ʺ����Ҽ硢�����ҽ��󼲴�",
	    "damage":       150,
    "damage_type":    "����",
	]),
	([
    "action":"$N���²�������������$w����ǰһ��,һƬ���ΰ׹���$n��ȥ��\n"
	    "$nʶ�����С�����С�ȡ�����������æ��ܲ���",
	    "damage":       180,
    "damage_type":    "����",
	]),
	([
    "action":"$N����Ծ������$w����������⣬��$n�����ŵ�ȥ��\n"
	    "���С��������ޡ���Ȼ��$n�Ƶ���æ����",
	    "damage":       210,
    "damage_type":    "����",
	]),

	([
    "action":"$N���类�������,ȹ��ƮƮ������$w��$n������£�\n"
	    "���С��������ˡ�����ǳ�����������,$n��ֱ������",
	    "damage":       240,
    "damage_type":    "����",
	]),
	([
    "action":"$N����Ʈ��,���μ�ת,ת�ۼ�ͳ���һƬ����һ������Ӱ����л���$n!\n"
	    "���С��������衹�ȱ���,���˵�,�����ڲ���֮��",
	    "damage":       270,
    "damage_type":    "����",
	]),
	([
    "action":"$N���潣�ߣ�Ѹ�����׵���$n��Χ����һ��������\n"
	    "$nֻ����Χ������Ӱ����ʱ���п�����һ��$w�����벻����\n"
	    "λ�ô�����ʵ����Σ������",
	    "damage":       300,
    "damage_type":    "����",
	]),
});

int valid_learn(object me)
{
	object ob;

	if (me->query("family/family_name") != "������")
		return notify_fail("�㲻�ǰ����ִ���,�޷���ϰ�����������\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("����������㣬�������򽣷��ľ���֮����\n");

	if (!(ob = me->query_temp("weapon"))
	        ||      (string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if (me->query("family/family_name") != "������")
		return notify_fail("�㲻�ǰ����ֵ���,�޷���ϰ�����书��\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�����̫�ͣ�������ȥ����Σ�յģ�\n");
	if ((int)me->query("neili") < 35)
		return notify_fail("�������������û�а취���÷��ɽ�����\n");
	me->receive_damage("qi", 40);
	me->add("neili", -45);
	write("�㰴����ѧ����һ����ɽ�����\n");
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"feixian-jian/"+action;
}
