// dugu-jiujian.c ���¾Ž�
inherit SKILL;
string *parry_msg = ({
        "$n�Թ�Ϊ�أ��Խ�Ϊ�ˣ�����������$P�͹����ػӳ���λ�����̩ɽ��"+MAG+"�����"+NOR+"��������\n",
        "$n����ͻ�䣬�����������������ڽ�ز����ʹ��ɽ�����ġ�"+YEL+"��������"+NOR+"����ͼ��ʹ$P���С�\n",
        "$nͻȻʹ��������ɷ罣���ġ�"+RED+"���ڤڤ"+NOR+"�������Ƿ�λȴ����ƫ���������$Pһ�ʣ���\nͼͻ��$P�Ĺ��ƣ�\n",
        "ֻ��$n���˷���������Ʈ�磬�����һʽ��"+HIW+"��������"+NOR+"���������޶�����׽���ص�ס��$P��\n������\n",
        "$n���˷�����ʹ����ɽ���С�"+HIR+"�������"+NOR+"����ɭɭ�����������ܣ��ܿ���$P������\n",
});
string *parry_msg2 = ({
        "$n�������ܣ��ٽ������ʹ����"+BLU+"���両��"+NOR+"������$P��$l��\n",
        "ȴ��$n̤ǰһ������ʽбָ$N���ұۣ���Ҫʹ$N������ˡ�\n",
        "$nͻȻһ������$P��$l����һ��ȴ�����������ţ�$P�����޴룬��æ���ֻط���\n",
        "$nͦ��һ�����ǡ�"+HIW+"���Ƴ��"+NOR+"���ش�$P��$l����ͼ��$P�Ĺ��ƻ��⡣\n",
});

mapping *action = ({
([  "action" : "����$Nͦ����ϣ�$wһ����һ�з·�̩ɽ�����ġ�"+HIC+"������Ȫ"+NOR+"��ֱ��$n��$l��",
    "force" : 100,
    "dodge" : -5,
    "lvl" : 0,
    "damage_type" : "����"
]),
([  "action" : "$N������$n�ӳ���"+RED+"Ȫ��ܽ��"+NOR+"������"+YEL+"�����ϸ�"+NOR+"������"+BLU+"ʯ������"+NOR+"������"+MAG+"��������"+NOR+"��\n����"+YEL+"���ף��"+NOR+"����ɽ���񽣣�",
    "force" : 120,
    "dodge" : -10,
    "lvl" : 7,
    "damage_type" : "����"
]),
([
    "action" : "$N������ת�������̳�ʮ�Ž�����Ȼ�ǻ�ɽ��"+MAG+"��Ůʮ�Ž�"+NOR+"�������������ʮ��\n������һ�У��ַ�֮�죬ֱ�Ƿ�����˼��",
    "force" : 150,
    "dodge" : -5,
    "lvl" : 14,
    "damage_type" : "����"
]),
([  "action" : "$N���ƺ��������裬�������������������ɽ����Ϊһ������$n������ȥ��",
    "force" : 170,
    "dodge" : -15,
    "lvl" : 21,
    "damage_type" : "����"
]),
([  "action" : "$N����ͻ������ɭ�ϣ�����ǧ�������۶�������ǹ��ꪣ���ɳǧ�������ɽ\n���ƻ���$n��$l��",
    "force" : 190,
    "dodge" : -20,
    "lvl" : 28,
    "damage_type" : "����"
]),
([  "action" : "ȴ��$N���潣�ߣ����һ�գ��ұ�һ�䣬����Ҳ��ԽתԽ�Ӻ�����������"+HIG+"̩ɽʮ����"+NOR+"��\nΪһ������$n��",
    "force" : 230,
    "dodge" : -25,
    "lvl" : 35,
    "damage_type" : "����"
]),
([  "action" : "$N����ͻ�䣬ʹ����ɽ�ġ�"+HIC+"һ�������"+NOR+"��������$n��$l����֪������;��ͻȻת\n�򣬴��$n����֮�⣡",
    "force" : 240,
    "dodge" : -35,
    "lvl" : 42,
    "damage_type" : "����"
]),
([  "action" : "$N����������һ�����ǡ�"+WHT+"������ɽ"+NOR+"��������$w����ն�䣬ֱ����$n��$l��",
    "force" : 250,
    "dodge" : -40,
    "lvl" : 49,
    "damage_type" : "����"
]),
([  "action" : "$N����$wԽתԽ�죬ʹ�ľ�Ȼ�Ǻ�ɽ�ġ�"+MAG+"�ٱ�ǧ������ʮ��ʽ"+NOR+"������ʽ������\n����ӿ���Թ��߲��ɵ�ĿΪ֮ѣ��",
    "force" : 260,
    "dodge" : -45,
    "lvl" : 56,
    "damage_type" : "����"
]),
([  "action" : "$N��Ц����������ׯ�ϣ�$w��ӣ����ڡ���Ħ����Ϊһʽ������ش���$n��",
    "force" : 270,
    "dodge" : -50,
    "lvl" : 63,
    "damage_type" : "����"
]),
([  "action" : "$N����$w��ʹ��̫���������⣬�������СС������ԲȦ�������޾�ԴԴ������\n����$n��",
    "force" : 280,
    "dodge" : -60,
    "lvl" : 70,
    "damage_type" : "����"
]),
([  "action" : "$N�������أ�$w�����������Һ�ɨ��Ю�������֮�Ʊ���$n������Ħ�����Ľ���\n��¶���ţ�",
    "force" : 290,
    "dodge" : -65,
    "lvl" : 77,
    "damage_type" : "����"
]),
([  "action" : "ȴ��$NͻȻ�鲽������ʹ�������䵱��"+BLU+"���ѵ�ˮ"+NOR+"����һ�У�",
    "force" : 300,
    "dodge" : -70,
    "lvl" : 84,
    "damage_type" : "����"
]),
([  "action" : "$N�˽���磬��������з���$n��$l�����Ա�$n���أ��������Ƿ�ħ��\n�ġ�"+RED+"����ʽ"+NOR+"����",
    "force" : 320,
    "dodge" : -75,
    "lvl" : 91,
    "damage_type" : "����"
]),
([  "action" : "$NͻȻ�˽����һ�ֹ���ġ�"+YEL+"�����罣��"+NOR+"������Ȼ��$n�����Ҵ�������",
    "force" : 340,
    "dodge" : -80,
    "lvl" : 98,
    "damage_type" : "����"
]),
([  "action" : "$N�������ߣ�����һ��������һ������$nĪ������ֲ���$N��������ʵ��",
    "force" : 360,
    "dodge" : -90,
    "lvl" : 105,
    "damage_type" : "����"
]),
([  "action" : "$N��������ת��$n����������µ���$n�̳�һ������֪ʹ����ʲô������",
    "force" : 380,
    "dodge" : -95,
    "lvl" : 112,
    "damage_type" : "����"
]),
([  "action" : "$NͻȻһ������$n��$l����һ��ȴ�����������ţ�$n�����޴룬��֪����Ǻã�",
    "force" : 400,
    "dodge" : -100,
    "lvl" : 119,
    "damage_type" : "����"
]),
([  "action" : "$N��Ю���ƣ��󿪴��ص��ҿ�һͨ�������нԻ���$n���Ƶ��������ȵ�$n���ò��أ�",
    "force" : 220,
    "dodge" : -110,
    "lvl" : 126,
    "damage_type" : "����"
]),
([  "action" : "$N���ֺὣ����$n��$l���������������е�һ����������Ȼ���$n���Կ���\n�������ƣ�",
    "force" : 240,
    "dodge" : -115,
    "lvl" : 133,
    "damage_type" : "����"
]),
([  "action" : "$N�ٽ���ӣ�Ѹ���ޱȵص���$n��$l��ȴ���˿�������������ʲô��ʽ��",
    "force" : 260,
    "dodge" : -120,
    "lvl" : 140,
    "damage_type" : "����"
]),
([  "action" : "$N����һ��ָ��$n���������$n���������ڣ��˵����������ף�����˼�飡",
    "force" : 280,
    "dodge" : -130,
    "lvl" : 147,
    "damage_type" : "����"
]),
([  "action" : "$N����ͻ��Ц�ݣ��ƺ��ѿ���$n���书��ʽ�����г����һ������$n��$l��",
    "force" : 300,
    "dodge" : -150,
    "lvl" : 154,
    "damage_type" : "����"
]),
([
    "action" : "$N��$w����һ�ڣ�����$n�Լ���$wײ����������֮����ʵ�����Ѳ⣡",
    "force" : 400,
    "dodge" : -160,
    "lvl" : 180,
    "damage_type" : "����"
])
});

int valid_enable(string usage)
{
    return (usage == "sword") || (usage == "parry");
}
string query_parry_msg(object me,object weapon)
{
    object my_weapon;

    if (!(my_weapon=me->query_temp("weapon"))){
    	if (!(my_weapon=me->query_temp("secondary_weapon")))
		  return "";
     }else{
	    if (!valid_enable(my_weapon->query("skill_type"))){
    		if (!(my_weapon=me->query_temp("secondary_weapon")))
				  return "";
			else			
			    if (!valid_enable(my_weapon->query("skill_type")))
				  return "";
	    }
	}
    if (weapon)
    	return parry_msg[random(sizeof(parry_msg))];
	else
	    return parry_msg2[random(sizeof(parry_msg2))];
}

int valid_learn(object me)
{
	if (me->query("family/master_id")!="feng qingyang")
        return notify_fail("���¾Ž��Ƿ���������������ʦ�����������������ܽ��㣿\n");
    if ((int)me->query("max_neili") < 2000)
        return notify_fail("�������������\n");
    if (me->query_skill("sword", 1) <=me->query_skill("dugu-jiujian", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    if ((int)me->query_skill("dugu-jiujian",1) > 300)
        return notify_fail("���׽����Ҿͽ̵�������Ժ��Ҫ�����Լ����ˡ�\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}
int practice_skill(object me)
{
    return notify_fail("���¾Ž�ֻ��ͨ����"+RED+"�ܾ�ʽ"+NOR+"����������\n");
}
string perform_action_file(string action)
{
    return __DIR__"dugu-jiujian/" + action;
}
