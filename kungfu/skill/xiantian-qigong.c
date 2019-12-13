#include <ansi.h>
// xiantian-qigong.c ��������
inherit FORCE;

mapping *action = (
{
([      "action" : "$N����һ�����˾����칦��������Х����$n��$l����ȥ",
	"dodge"  : 87,
	"force"  : 430,
	"attack" : 163,
	"parry"  : 81,
	"damage" : 383,
"damage_type": "����"
	 ]),
([      "action" : "$N����ƽ�죬�����������칦�ľ������͵�����$n��$l",
	"dodge"  : 85,
	"force"  : 440,
	"attack" : 147,
	"parry"  : 77,
	"damage" : 281,
"damage_type": "����"
	 ]),
([      "action" : "$N����һչ�����ƻ�ס�����������й�ֱ��������$n$l",
	"dodge"  : 75,
	"force"  : 450,
	"attack" : 182,
	"parry"  : 67,
	"damage" : 293,
"damage_type": "����"
	 ]),
([      "action" : "$N��ת����������˫�ƻ�Ȧ����ʱһ�����ȵ�����ֱϮ$n",
	"dodge"  : 87,
	"force"  : 480,
	"attack" : 183,
	"parry"  : 85,
	"damage" : 305,
"damage_type": "����"
	 ]),
});

int valid_enable(string usage)
{
	int lvl;
	lvl = (int)this_player()->query_skill("xiantian-qigong", 1);

	if (lvl >= 180)
		return usage == "force" || usage == "unarmed" || usage == "parry";
	else
		return usage == "force";

}


mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int lvl, n;
	n = me->query_str(1)+me->query_con(1)+me->query_dex(1);
	lvl = me->query_skill("xiantian-qigong", 1);

	if (damage_bonus < 50
	        || lvl < 180
	        || random(5)==0)
		return 0;

	if (random(n/2) > victim->query_con(1) && random(5)==0)
	{
		me->add("neili", -30);
		victim->receive_damage("qi", (damage_bonus - 50) / 3+10, me);
		victim->receive_wound("qi", (damage_bonus - 50) / 3+10, me);
		return HIR"����""$N""�Ĺ���,һ�����촿������˲�䱬���˳�����$n"  //return HIW "$N" HIW "���칦��Ǳ�������˳�����ͻȻ��$n"
		       HIR "ֻ�����ھ�٣�����ɳ���ޱȣ�������һ����Ѫ��\n" NOR;// HIW "ֻ�к���һ�����һ����Ѫ��\n" NOR;
	}
}


int difficult_level()
{
	return 500;
}

int valid_learn(object me)
{
	mapping skl;
	string *sname;
	int i;
	int lvl = (int)me->query_skill("xiantian-qigong", 1);
	int t = 1, j;
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;

	if ( me->query("gender") == "����")
		return notify_fail("���޸����ԣ��������������������������ڵ�����������\n");

	if ( me->query("class") == "bonze" )
		return notify_fail(RANK_D->query_respect(me)+"�����ҵ�����������������ȥ���˷��ţ�\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

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
	skl = this_player()->query_skills();
	sname  = keys(skl);
	for (i=0; i<sizeof(skl); i++)
	{
		if (sname[i]=="xixing-dafa") continue;
		if (sname[i]=="yijing-force") continue;
		if (sname[i]=="xiantian-qigong") continue;
		if (sname[i]=="tiangang-zhengqi") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
			return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ������������\n");
	}
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("��������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"xiantian-qigong/" + func;
}

string perform_action_file(string action)
{

	return __DIR__"xiantian-qigong/perform/" + action;
}

mixed ob_hit(object ob, object me, int damage)
{
	int ap, dp, cost;
	string msg;
	if (me->query_skill("xiantian-qigong", 1) < 200 ||
	        me->query_skill_mapped("force") != "xiantian-qigong" ||
	        me->query("neili") < 1000 ||
	        ! living(me))
		return 1;

	cost = damage / 2;
	if (cost > 100) cost = 100;

	ap = ob->query_skill("force",1) * 12 + ob->query("max_neili");
	dp = me->query_skill("force",1) * 12 + me->query("neili");

	if (ap / 2 + random(ap) < dp )
	{
		me->add("neili", -100);

		switch (random(2))
		{
		case 0:
			msg=HIR "ֻ��$N" HIR "���커������Ȼ��Ȼ��������$n" HIR "���������������ȥ��\n" NOR;
			ob->start_busy(3);
			break;
		case 1:
			msg=HIR "ֻ��$N" HIR "���커������Ȼ��Ȼ��������$n" HIR "�Ĺ�����Ϊ���Ρ�\n" NOR;
			break;
		default:
			msg=HIR "ֻ��$N" HIR "���커������Ȼ��Ȼ�������ֿ�$n" HIR "�Ĺ�����\n" NOR;
			break;
		}
		damage = -damage/2;
		message_vision(msg, me, ob);

	}
	return damage;
}
