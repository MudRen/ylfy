
// bx_arrow.c ��Ѫ��

inherit F_SSERVER;

int exert(object me, object target)
{
	
	int success, ap, dp;


	if( !target ) target = offensive_target(me);
       if ( target == me ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("��Ѫ��ֻ����ս����ʹ�á�\n");

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("��Ҫ��˭ʩչ��Ѫ����\n");

	if((int)me->query("max_neili") < 1000 )
		return notify_fail("�������������������Чʩչ��Ѫ����\n");

	if((int)me->query("max_jingli") < 200 )
		return notify_fail("��ľ���������������Чʩչ��Ѫ����\n");

	if((int)me->query_skill("force",1) < 100 
         || (int)me->query_skill("wudu-shengong",1) < 80 )
		return notify_fail("����ڹ���Ϊ������������Чʩչ��Ѫ����\n");

	if((int)me->query("combat_exp") < (int)target->query("combat_exp")/20)
		return notify_fail("�Է��书ǿ�㼸ʮ�����������õģ����ǿ��ܰɣ�\n");

	message_vision( HIC"$N˫ĿѪ�죬��ͷɢ�������췢��һ����Х��\n\n$N����һ�ᣬ���Լ�������һҧ����������������һ���涾Ѫ����$n���˹�ȥ��\n" NOR,me,target);

	success = 1;
	ap = me->query_skill("force",1) + me->query_skill("wudu-shengong",1) + me->query("xyzx_sys/level") * 100;
	ap *= 100;
	dp = target->query_skill("force",1) + target->query_skill("wudu-shengong",1) + target->query("xyzx_sys/level") * 100;
	dp *= 100;

	if( random(ap) < random(dp) )
		success = 0;

	ap = (int)me->query("max_neili");
	dp = (int)target->query("max_neili");
	
	if( random(ap) < random(dp) ) success = 0;

	if(success == 1 )
	{
	    message_vision( HIR "���$n�ٲ�������Ѫ��������ţ���ʱ����һ���ҽУ�\n$N��״������Цһ������ǰһ�ڵ��ڵ��ϡ�\n" NOR,me,target);
		me->kill_ob(target);
		target->kill_ob(me);
		me->add("max_neili", -100);
		me->add("max_jingli", -100);
		me->save();
		target->receive_wound("qi", (int)target->query("max_qi")+1, me);
		target->receive_wound("jing", (int)target->query("max_jing")+1, me);
		COMBAT_D->report_status(target);
		me->receive_wound("qi", (int)me->query("max_qi")+1, target);
		me->receive_wound("jing", (int)me->query("max_jing")+1, target);
		COMBAT_D->report_status(me);

	}
	else
	{
		message_vision( HIR "����Ѫ����$n�������𣬻���һ��Ѫ����ɢƮȥ��\n$Nһ����Ц����̾һ������ǰһ�ڵ��ڵ��ϡ�\n" NOR,me,target);
		me->kill_ob(target);
		target->kill_ob(me);
		me->add("max_neili", -50);
		me->add("max_jingli", -50);
		me->save();
		me->receive_wound("qi", (int)me->query("max_qi")+1, target);
		me->receive_wound("jing", (int)me->query("max_jing")+1, target);
		COMBAT_D->report_status(me);
	} 
	
	return 1;
}

