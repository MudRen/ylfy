//�ε���
//lestat for daya-jian
//ȡ���ձ�����ά���ڼ䴫˵�е�ɱ������彣�ĵľ�ѧ
//��彣�ĵĽ������ڷ���������,ά���ڼ�ųưε���
//�����佣������,���аε�������,Ҳ�ǴºŰε��������
//����Ϊ�ձ�������һ����
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	weapon = me->query_temp("weapon");
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�ε���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(!weapon->query("badao"))
		return notify_fail("û���ºۣ������˽���һ����ô��ʹ���ε���? \n");

	if (me->query_temp("badaoing",1))
		return notify_fail("���Ѿ���ʹ���ε�����...! \n");

	if( (int)me->query_skill("daya-jian", 1) < 999 )
		return notify_fail("�㻹����ε�����\n");

	if( (int)me->query("xyzx_sys/level") < (int)target->query("xyzx_sys/level")/2  )
		return notify_fail("�Է�����ǿ̫���ˣ����Ǳ������ɣ�\n");

	if(me->query_temp("start_qijian"))
		return notify_fail("���Ѿ�����������ָ�����ν����ˣ�\n");

	message_vision(RED"$N�ս�����Ŀ��ת���ض���$n��׼����������һ����\n"NOR,me,target);
    me->start_call_out( (: call_other, __FILE__, "kill_him", me, target :), random(5)+5);
	me->start_busy(5);
	me->set_temp("badaoing",1);
//        target->start_busy(7);
	if (userp(target))
		target->start_busy(4);
	if (!userp(target))
		target->start_busy(6);
	return 1;
}
void kill_him(object me, object target)
{
	string msg,str;
	int eff_qi,max_qi,neili;
	me->delete_temp("badaoing");
	eff_qi=me->query("eff_qi");
	max_qi=me->query("max_qi");
//        qi_pcg=eff_qi*100/max_qi;
//   neili=target->query("neili");
	if(me->is_fighting() && target->is_fighting() && environment(me) == environment(target))
	{
		msg = HIB "$N�ν����ʣ�һ������"NOR+HIC"����"NOR+HIB"������$n"NOR+HIB"ֻ��������һ��������" ;
		msg +=  "\nһ��Ѫ����ӿ��������$N��ָ���������վ�ţ�һ�ε���Ѫ�������º��ϵ��£���\n" NOR;
		message_vision(msg, me, target);
		if (!userp(target))
			str=target->query("name")+"��"+me->query("name")+"�ô�˵�е�ɱ�˽���:"HIC"�ε���"NOR+HIM"ն�ˣ�ʬ���������ϣ�";
		if (userp(target))
			str=target->query("name")+"��"+me->query("name")+"�ô�˵�е�ɱ�˽���:"HIC"�ε���"NOR+HIM"���ˣ�";
		message("rumor",HIY"������ˮ�¡�"+HIM"��"+str+"\n"NOR,users());
//        target->die();
		if (userp(target))
		{
			me->delete_temp("badaoing");
			target->set("qi", 0);
			target->set("jing",0);
			target->set("eff_qi",eff_qi*random(5)/10);
			target->set("neili",1);
			target->set("eff_jing",me->query("eff_jing")*random(5)/10);
			call_out("huifu",5,target,neili);
		}
		if (!userp(target))
			me->delete_temp("badaoing");
		target->die();
		/*
		{
		  target->set("qi", -1);
		  target->set("jing",-1);
		target->set("eff_qi",eff_qi*random(5)/10);
		target->set("eff_jing",me->query("eff_jing")*random(5)/10);
		}
		*/
		me->set("qi", 0);
		me->set("eff_qi",eff_qi*random(10)/100);
		me->set("jing",0);
		me->set("eff_jing",me->query("eff_jing")*random(10)/100);
		me->set("neili",0);
	}
	return ;
}
void huifu(object target,int neili)
{
	if (target)
		target->set("neili",neili);
}
