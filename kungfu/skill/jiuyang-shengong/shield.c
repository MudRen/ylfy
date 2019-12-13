// shield.c ����������

#include <ansi.h>

inherit F_CLEAN_UP;
int check_fight(object me);
void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("��ֻ���þ������������Լ��ķ�������\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("�������������\n");

	if ((int)me->query_skill("jiuyang-shengong", 1) < 40)
		return notify_fail("��ľ����񹦵ȼ�������\n");

	/* if (!me->query("jiuyangok"))
	         return notify_fail("����Ȼ��˵���������ǻ����񹦣��������á�\n");*/
	if( (int)me->query_temp("liuyun") )
		return notify_fail(HIG"���Ѿ���Ĭ������ˮ�����ˡ�\n");

	if( (int)me->query_temp("qzj_tong") )
		return notify_fail("���Ѿ�����ͬ�齣�ˡ�\n");
	if( me->query_temp("fumo")   )
		return notify_fail("������ʹ�ô���ȭ�����⹥������շ�ħ����\n");
	if( me->query_temp("powerup")   )
		return notify_fail("������ʹ��ս����������\n");
	if( me->query_temp("jingang")   )
		return notify_fail("������ʹ�ô���ȭ�����⹥����������ͨ����\n");
	if( me->query_temp("fanzhen")   )
		return notify_fail("���������á���ղ������񹦡���\n");
	if( (int)me->query_temp("jiuyin/powerup") )
		return notify_fail("���Ѿ����˾����湦���ˡ�\n");
	if( (int)me->query_temp("hslj/powerup") )
		return notify_fail("���Ѿ������򷨹������ˡ�\n");
	if( me->query_temp("yuxiao/tianwu") )
		return notify_fail("���������á�������衹�ķ���\n");

	if((int)me->query_temp("tzzf") )
		return notify_fail("���Ѿ����Ƶ����˹��С�\n");

	if ((int)me->query_temp("shield"))
		return notify_fail("���Ѿ����˹����ˡ�\n");
	if(me->query_temp("wdpowerup") )
		return notify_fail("����������ʹ�á��嶾�񹦡��ľ�����\n");
	if(me->query_temp("zhuihun/lpf"))
		return notify_fail("������ʹ���嶾׷�깳֮�������硹\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	// me->receive_damage("qi", 0);

	message_vision(HIR "$N" HIR "Ĭ������񹦵Ŀھ�����"
	               "ǿ����ǿ������ɽ�ԡ����������ᣬ"
	               "�����մ󽭡���\nɲ�Ǽ�ֻ��$N"
	               HIR "ȫ���ʱ���ֳ�һ����͵ľ�������$P"
	               HIR "ȫȫ���֡�\n" NOR, me);



	me->add_temp("apply/dodge", skill/3);
	tell_object(me,HIG"����Ṧ�����!\n"NOR);
	me->add_temp("apply/damage", skill/3);
	tell_object(me,HIG"���ɱ���������!\n"NOR);
	me->add_temp("apply/attack", skill/3);
	tell_object(me,HIG"��Ĺ����������!\n"NOR);
	me->add_temp("apply/armor", skill );
	tell_object(me,HIG"��ķ����������!\n"NOR);
	me->set_temp("shield", 1);
	check_fight(me);
me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill  :), skill);

	if (me->is_fighting()) me->start_busy(2);

	return 1;
}

int check_fight(object me)
{
	// if (me->query("qi") < 0) return;  //��� ��ѪΪ���� ���β�����bug
	//if (me->query("jing") < 0) return;
	if (!me || !(int)me->query_temp("shield")) return 0;
	if (!me->is_ghost() && living(me)
	        && me->is_fighting() && me->query("neili") > 500
	        && me->query_skill_mapped("force") == "jiuyang-shengong")
	{
		if(me->query("qi") < (int)me->query("max_qi"))
		{
			message_vision(HIR"$N��������񹦣����ϵ��˺��˺ܶ�!\n"NOR,me);
			me->add("neili", -200);
			me->add("eff_qi",me->query_skill("jiuyang-shengong"));
			if (me->query("eff_qi") > me->query("max_qi")) me->set("eff_qi", me->query("max_qi"));
			me->add("qi",me->query_skill("jiuyang-shengong"));
			if (me->query("qi") > me->query("eff_qi")) me->set("qi", me->query("eff_qi"));
		}

		if(me->query("jing") < (int)me->query("max_jing"))
		{
			message_vision(HIR"$N��������񹦣����ϵ��˺��˺ܶ�!\n"NOR,me);
			me->add("neili", -200);
			me->add("eff_jing",me->query_skill("jiuyang-shengong"));
			if (me->query("eff_jing") > me->query("max_jing")) me->set("eff_jing", me->query("max_jing"));
			me->add("jing",me->query_skill("jiuyang-shengong"));
			if (me->query("jing") > me->query("eff_jing")) me->set("jing", me->query("eff_jing"));
		}
	}
	if ( me->query_skill_mapped("parry") == "qiankundanuoyi"
	        && me->is_busy()
	        && me->is_fighting()
	        && me->query_skill_mapped("force") == "jiuyang-shengong"
	        && random(1)==0 )
	{
		message_vision(HIC"$N����Ǭ����Ų�ƣ�����æ�ҵĶ�����������!\n"NOR, me);
		me->start_busy(1);
	}

	call_out("check_fight", 2, me);
	return 1;
}

void remove_effect(object me, int amount)
{
	if (!me) return;
	if (me->query_temp("shield"))
	{
		me->add_temp("apply/dodge", -amount);
		me->add_temp("apply/damage", -amount);
		me->add_temp("apply/attack", -amount);
		me->add_temp("apply/armor", -amount);
		me->delete_temp("shield");
		tell_object(me, "��ľ�����������ϣ��������ջص��\n");
	}
}

