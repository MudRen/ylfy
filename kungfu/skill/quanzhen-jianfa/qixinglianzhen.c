#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i;
	string *style = (
	{
		HIR "���������$N̽������$w�������Х������$n��"NOR,
		HIB"������Ϫ����$N����$w������Ӱ�ع⣬��$n����Χס��"NOR,
		HIY"������Ȼ����$N��ǰһ�ݣ�����$w��һ��״����$n���˹�ȥ��"NOR,
		HIG"������λ����$N��������������λ������$wͷβ������ִ�$n������Ҫ����"NOR,
		HIM"����Ѫ�ȣ���$N����$wһ�٣���������������$n����ָ��"NOR,
		HIW"��Ȼ�޴룭��$N����������Ծ������$w���ƶ�����������$n��ȥ��"NOR,
		HIC"һ����Ե����$N��Ӱ����$n�����ζ�������$w������ɨ��$n�����ţ�"NOR
	});
	object ob,*obs;
	if( !target ) target = offensive_target(me);
	if( !target ||	!target->is_character() ||	!me->is_fighting(target) )
		return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(!pointerp(obs=me->query_team()) || !me->is_team_leader())
		return notify_fail("ֻ�ж�������ſ��Է�����ʽ��\n");
	if(me->query_skill_mapped("array") != "qixing-array")
		return notify_fail("��Ķ���û���ñ���������\n");
	if(me->query_skill("qixing-array",1)<sizeof(obs)*10)
		return notify_fail("����󷨲�����\n");
	if(sizeof(obs) >=7 )
		return notify_fail("��������߸��ˣ���\n");
	for(i=0; i<sizeof(obs); i++)
	{
		if(!obs[i]) return notify_fail("����Ҫ������϶��顣\n");
		if(environment(obs[i]) != environment(me)) return notify_fail("������Ա��ȫ������ߡ�\n");
		if(!obs[i]->query_skill("quanzhen-jianfa",1)) return notify_fail("����������˲���ȫ�潣����\n");
		if(!objectp(ob=obs[i]->query_temp("weapon"))) return notify_fail("��Ķ���������û�б�����\n");
		if(ob->query("skill_type") != "sword") return notify_fail("��Ķ���������û���ý�����\n");
		if(obs[i]->query_skill_mapped("sword") != "quanzhen-jianfa") return notify_fail("��Ķ���������û����ȫ�潣����\n");
	}
	message_vision(HIY+"\n\n$N�ߺ�һ���������������������ߣ����ǣ����󣭣�����\n"+HIW+"--------------------------------------�������󣡣�\n\n"NOR,me);
	for(i=0; i<sizeof(obs); i++)
	{
		ob=obs[i]->query_temp("weapon");
		msg = style[i];
		extra = obs[i]->query_skill("sword");
		extra *= (i+1);
		obs[i]->add_temp("apply/attack", 2*extra);
		obs[i]->add_temp("apply/damage", 2*extra);
		COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
		obs[i]->kill_ob(target);
		obs[i]->add_temp("apply/attack", -2*extra);
		obs[i]->add_temp("apply/damage", -2*extra);
		obs[i]->start_busy(2);
	}
	return 1;
}
