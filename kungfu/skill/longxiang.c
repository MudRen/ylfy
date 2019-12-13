// longxiang.c ���������

#include <ansi.h>
inherit FORCE;
mapping *action = (
{
([      "action" : "$N����һ�����˾������������������Х����$n��$l����ȥ",
	"dodge"  : 37,
	"force"  : 430,
	"attack" : 173,
	"parry"  : 41,
	"damage" : 133,
"damage_type": "����"
	 ]),
([      "action" : "$N��ȭ���ƣ�������������������ľ������͵�����$n��$l",
	"dodge"  : 35,
	"force"  : 440,
	"attack" : 177,
	"parry"  : 47,
	"damage" : 121,
"damage_type": "����"
	 ]),
([      "action" : "$N����������˫ȭͬʱ���������������������$n$l����ȥ",
	"dodge"  : 37,
	"force"  : 450,
	"attack" : 182,
	"parry"  : 46,
	"damage" : 123,
"damage_type": "����"
	 ]),
([      "action" : "$N���������������˫ȭƽ�ƣ���ʱһ���������ֱϮ$n",
	"dodge"  : 27,
	"force"  : 480,
	"attack" : 183,
	"parry"  : 35,
	"damage" : 145,
"damage_type": "����"
	 ]),
});
int valid_enable(string usage)
{
	int lvl;
	lvl = (int)this_player()->query_skill("longxiang", 1);

	if (lvl >= 150)
		return usage == "force" ||
		       usage == "parry" ||
		       usage == "unarmed";

	else if (lvl >= 30)
		return usage == "force";

	else
		return usage == "";
}

int valid_learn(object me)
{
	mapping skl;
	string *sname;
	int i;
	int lvl = (int)me->query_skill("longxiang", 1);
	int t = 1, j;
	for (j = 1; j < lvl / 10; j++) t*= 2;
	if (((string)me->query("class") != "bonze") && lvl > 29)
		return notify_fail("�㲻��ɮ�ˣ�ѧ���˸���������������\n");
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ�����㣬����ѧ�����������\n");
	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ���������������������������������\n");
//    if (i > 10 && (int)me->query("shen") > t * 100)
//        return notify_fail("Ҫѧ�������������ı��ֻ������ɣ� \n");
	if (me->query_skill("force",1)<=lvl)
		return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
	skl = me->query_skills();
	sname  = keys(skl);
	for (i=0; i<sizeof(skl); i++)
	{
		if (sname[i]=="longxiang") continue;
		if (sname[i]=="xiaowuxiang") continue;
		if (sname[i]=="yijing-force") continue;
		if (sname[i]=="xixing-dafa") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
			return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����������\n");
	}
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("���������ֻ����ѧ(learn)�������������ȡ�\n");
}
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

mapping exercise_msg(object me)
{
	return ([
            "status_msg" : YEL + me->name()+"��ɫٲȻ,�����Ŀ��"NOR,
            "start_my_msg" : YEL"����ϥ�붨,������������,�ݶ���Ϣ������һ˿˿������������\n"NOR,
            "start_other_msg" :YEL + me->name()+"��ϥ����,һ�������Ƴ�,һ�ִ��ڵ���,��Ŀ���ǹ���,��������ҡ����\n"NOR,
            "halt_msg" : YEL "$NͻȻ˫������ǰһ��,ѹס������Ϣ,���Խ��\n"NOR,
            "end_my_msg" : YEL "��һ�����н�����,��ʱ����ů,�е������ھ�������һ�֡�\n"NOR,
            "end_other_msg" : YEL "ֻ��"+me->name()+"ͷ��������ɢ,˫������ǰһ��,����վ��������\n"NOR
	        ]);
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	string msg;
	int ap, dp;
	int lvl, layer;
	int damage, myneili, yourneili, my_max, your_max;
	lvl = me->query_skill("longxiang", 1);
	layer = lvl / 30;

	if (layer > 13) layer = 13;

	if (damage_bonus < 130
	        || layer < 6
	        || me->query("neili") < 500
	        || me->query_temp("weapon")
	        || me->query_temp("secondary_weapon")
	        || me->query_skill_mapped("force") != "longxiang"
	        || me->query_skill_mapped("unarmed") != "longxiang"
	        || random(3) == 0)
		return 0;

	if (layer >= 10 && random(2) == 1)
	{
		me->add("neili", -50);
		victim->receive_wound("qi", (damage_bonus - 50) / 3+20);
		return HIY "$N" HIY "ȭ��֮�Ͼ��̲��š�" HIR "ʮ��ʮ��"
		       HIY "��֮��������壬�ݻ���$n" HIY "����Ԫ��\n" NOR;
	}
	else
	{
		me->add("neili", -50);
		victim->receive_wound("qi", (damage_bonus - 100) / 3+20);
		return HIY "$N" HIY "˫ȭ���������������" + chinese_number(layer) +
		       "�㹦����$n" HIY "�����������һ����Ѫ��\n" NOR;
	}

	ap = me->query("combat_exp")/1000;
	ap += me->query_skill("force");
	dp = victim->query("combat_exp")/1000;
	dp += victim->query_skill("force");
	ap = (ap + random(ap*2))/2;

	msg = HIR"$N�����ս���������ڲ����������ԣ�������֮����$n��ȥ��\n"NOR;

	myneili = (int)me->query("neili");
	yourneili = (int)victim->query("neili");
	my_max = (int)me->query("max_neili")*2;
	your_max = (int)victim->query("max_neili")*2;
	myneili = my_max > myneili ? myneili : my_max;
	yourneili = your_max > yourneili ? yourneili : your_max;
	me->add("neili", - factor );
	damage = myneili/20 + factor - yourneili/25;

	if( me->query_temp("longxiang") && (ap > dp) )
	{
		damage *= 2;
		message_vision(msg,me,victim);
	}
	return damage;
}


int ob_hit(object ob, object me, int damage)
{

	string msg;
	int j, neili;
	int level2,damage2;

	level2= (int) me->query_skill("longxiang",1);
	neili = me->query("neili");

	
	if ( level2<= 0) level2= (int) me->query_skill("xiaowuxiang",1);
	damage2= (int) ob->query("neili",1)/10;
	if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "longxiang" || me->query_skill_mapped("force") == "xiaowuxiang"))
	{
		j = -damage/2;
		if (damage2> 5000)	damage2=5000;
		if (damage2 < 0 ) damage2=0;
		msg = HIM"$N ���������𡸽�����ħ�䡹��������ӿ������һ��һ��ļ�ǿ��$n����һ�ң�������Ȼ�᲻������\n"NOR;
		ob->set_temp("apply/attack", 0);
		ob->set_temp("apply/defense", 0);
		if (random(2)==0)
		{
			msg += HIM"$N"+HIM+"Ĭ������������ԣ��ֽ�Ħ��֧���ŭӡ! $n����һ�����³�һ����Ѫ!"+NOR;
			if (ob->query("qi") > damage2)
			{
				ob->receive_damage("qi", damage2/2);
				ob->receive_wound("qi", damage2/2);
			}
			if (!ob->is_busy() && random(3)==0) ob->start_busy(2);
		}

		message_vision(msg, me, ob);
		return j;
	}
}

string perform_action_file(string action)
{
	return __DIR__"longxiang/perform/" + action;
}

string exert_function_file(string action)
{
	return __DIR__"longxiang/exert/" + action;
}