// juemen-gun.c ���Ź�
inherit SKILL;
string *dodge_msg = (
{
	"$n�ҽ�����һ��Ծ�������$N�Ĺ�����\n",
	"$n���Ա��˳���˳��һ��������һ�ߡ�\n",
	"$nб���ǰһ���������죬$N��һ���䵽�մ���\n",
	"$n��Ȼֱ������գ��ܾ�Ҳ������Ӱ�������������$N�ı���\n",
	"$nͻȻһ����ת��$N����һ�л�����һ�ߡ�\n",
});
mapping *action = (
{
([  "action" : "$Nб���ǰһ���������죬����$w��ɨ$n��$l",
	"damage": 50,
	"dodge" : 50,
"damage_type" : "����"
	 ]),
([  "action" : "$N��Ȼֱ������գ��ܾ�Ҳ������Ӱ��$n����Ѱ�䣬$N�ѷ������£�$w����$n��$l",
	"damage": 70,
	"dodge" : 45,
"damage_type" : "����"
	 ]),
([  "action" : "$Nԭ��һ���������ȴ����ص�һɲ�ǣ�������$nƽ�ɹ�ȥ������$wָ��$n��$l",
	"damage": 100,
	"dodge" : 60,
"damage_type" : "����"
	 ]),
([  "action" : "$NͻȻһ����ת��$w��ɨһȦ��Ю�����ҵľ�������$n��$l",
	"damage": 120,
	"dodge" : 75,
"damage_type" : "����"
	 ]),
([  "action" : "$N��ǰ�˳���˳��һ�������ŷ�����������$wб���ϻ���$n��$l",
	"damage": 150,
	"dodge" : 65,
"damage_type" : "����"
	 ])
});
int valid_enable(string usage)
{
	return usage=="staff" || usage=="parry";
}
