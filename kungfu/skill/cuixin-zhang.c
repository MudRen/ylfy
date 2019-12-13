// /kungfu/skill/cuixin-zhang.c
// pipip 2:19 PM 5/14/02
inherit SKILL;

string type()
{
	return "zhongji";
}
mapping *action = (
{
([      "action" : "$Nʹһ�С�"BLINK HIC"������ӿ"NOR"����˫��Ʈ�Ʋ�������$n$l",
"force" : this_player()->query_skill("cuixin-zhang",1)/2,
"dodge" : this_player()->query_skill("dodge",1)/4,
"damage" : this_player()->query("zjb_dj/dj")*100,
"parry" : this_player()->query_skill("parry",1)/2,
"skill_name" : "������ӿ",
"damage_type" : "����"
	 ]),
([      "action" : "$Nٿ������$n��ǰ��һ�С�"BLINK HIY"�ﲨ����"NOR"��ֱ��$n��$l",
"force" : this_player()->query_skill("cuixin-zhang",1)/2,
"dodge" : this_player()->query_skill("dodge",1)/4,
"damage" : this_player()->query("zjb_dj/dj")*100,
"parry" : this_player()->query_skill("parry",1)/2,
"skill_name" : "�ﲨ����",
"damage_type" : "����"
	 ]),
([      "action" : "$N������$nһת��һ�С�"BLINK HIG"���ײ���"NOR"����$n$l��������",
"force" : this_player()->query_skill("cuixin-zhang",1)/2,
"dodge" : this_player()->query_skill("dodge",1)/4,
"damage" : this_player()->query("zjb_dj/dj")*100,
"parry" : this_player()->query_skill("parry",1)/2,
"skill_name" : "���ײ���",
"damage_type" : "����"
	 ]),
});

mapping *action2 = (
{
([      "action" : HIB"$N���ΰ����ڰ��һ�С�"BLINK HIC"���羪��"NOR HIB"�������ͻ�$n��$l"NOR,
"force" : this_player()->query_skill("cuixin-zhang",1),
"dodge" : this_player()->query_skill("dodge",1)/2,
"damage" : this_player()->query("zjb_dj/dj")*180,
"parry" : this_player()->query_skill("parry",1),
	"lvl" : 1200,
"skill_name" : "���羪��",
"damage_type" : "����"
	 ]),
([      "action" : YEL"$Nʹһ�С�"BLINK HIR"��ɳ��Ӱ"NOR YEL"������������ֱ��$n��$l"NOR,
"force" : this_player()->query_skill("cuixin-zhang",1),
"dodge" : this_player()->query_skill("dodge",1)/2,
"damage" : this_player()->query("zjb_dj/dj")*180,
"parry" : this_player()->query_skill("parry",1),
	"lvl" : 1200,
"skill_name" : "��ɳ��Ӱ",
"damage_type" : "����"
	 ]),
([      "action" : MAG"$Nһ�����ʹ����"BLINK HIG"���Ǵ���"NOR MAG"�����ó�������Ӱ�����Ʋ���$n��$l"NOR,
"force" : this_player()->query_skill("cuixin-zhang",1),
"dodge" : this_player()->query_skill("dodge",1)/2,
"damage" : this_player()->query("zjb_dj/dj")*180,
"parry" : this_player()->query_skill("parry",1),
	"lvl" : 1200,
"skill_name" : "���Ǵ���",
"damage_type" : "����"
	 ]),
});

int valid_enable(string usage)
{
	return usage=="unarmed";
}

int valid_learn(object me)
{
	if (me->query("family/master_id")!="wuming laoren")
		return notify_fail("�����������������˾�ѧ����ֻ��������̡�\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("�������������\n");
	if (me->query_skill("unarmed", 1) <=me->query_skill("cuixin-zhang", 1))
		return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
	if ((int)me->query_skill("cuixin-zhang",1) > 300)
		return notify_fail("�����书̫���������Ҿͽ̵����ˣ��Ժ�Ϳ����Լ�����ˡ�\n");
	return 1;
}


mapping query_action(object me, object weapon)
{
	int level;
	level   = (int) me->query_skill("cuixin-zhang",1);
	me = this_player();
	if (me->query_skill("cuixin-zhang",1)<=1000)
		return action[random(sizeof(action))];

	if (me->query_skill("cuixin-zhang",1)>=1001
	        && me->query("zjb_dj/dj")>=7)
		return action2[random(sizeof(action2))];

	if (me->query_skill("cuixin-zhang",1)>1000
	        && me->query("zjb_dj/dj")<7)
		return action[random(sizeof(action))];
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 110 ) return 0;

// �ڶ��ȼ�������
	if ( (me->query_skill("cuixin-zhang",1)>200
	        && me->query_skill("yijing-force",1)>200
	        && me->query_skill("cuixin-zhang",1)<1001
	        && (me->query("neili")*3) > victim->query("max_neili"))
	        || (me->query_skill("cuixin-zhang",1)>1000
	            && me->query_skill("yijing-force",1)<1000
	            && (me->query("neili")*3) > victim->query("max_neili")) )
	{
		victim->receive_damage("qi", (damage_bonus - 100) / 8 , me);
		return HIW "$N�����˹����׾��񹦵��ᾢ�������������������ڹ���$n������\n" NOR;
	}

//  �ڶ��ȼ�������
	if( me->query_skill("cuixin-zhang",1)>1000 && me->query("zjb_dj/dj")>=7 && me->query_skill("yijing-force",1)>1000
	        && (me->query("neili")*3) > victim->query("max_neili") )
	{
		victim->receive_damage("qi", (damage_bonus - 100) / 3 , me);
		return HIB "$N���ڵ��׾��񹦵�"BLINK HIG"�վ�"NOR HIB"�����й�����"BLINK HIM"�����ᾢ"NOR HIB"�ں�Ϊһ������һ��"BLINK BLK"��Ԫ����"NOR HIB"������$n������������\n" NOR;
	}

}

int practice_skill(object me)
{
	return notify_fail("������ֻ��ͨ����"+HIM+"����ʽ"+NOR+"����������\n");
}


string perform_action_file(string action)
{
	return __DIR__"cuixin-zhang/" + action;
}

