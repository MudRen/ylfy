// bidu.c �ƶ�
// marry 99.9
#include <ansi.h>

int exert(object me, object target)
{
	int time = this_player()->query_condition("killer");
	if( me->is_fighting() )
		return notify_fail("ս�����˹��ƶ���������\n");

	if ((int)me->query_skill("wangran-xinfa", 1) < 100)
		return notify_fail("����ڹ���Ϊ��������\n");
	if( (int)me->query("neili") < 500 || (int)me->query("max_neili") < 500 )
		return notify_fail("�������������\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 10 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");
	if( me->query_condition("qidu") || me->query_condition("xx_poison")
	        || me->query_condition("zhua_poison") || me->query_condition("snake_poison")
	        || me->query_condition("rose_poison") || me->query_condition("ninemoonpoison")
	        || me->query_condition("tian") ||  me->query_condition("zhua_poison")
	        || me->query_condition("iceshock") || me->query_condition("ice_poison")
	        || me->query_condition("xiake_ming"))
	{
		write( HIY "��ȫ����ɣ���������ʼ�˹��ƶ���\n" NOR);
		message("vision",
		        HIW + me->name() + "�³�һ���ȳ�����Ѫ����ɫ�������ö��ˡ�\n" NOR,
		        environment(me), me);
		if (this_player()->query_condition("killer"))
		{
			this_player()->clear_condition();
			this_player()->apply_condition("killer", time);
		}
		else
		{
			me->clear_condition();
		}
		me->add("qi",-(int)me->query_skill("force")*5);
		me->add("neili",-500);
		me->start_busy(5);
	}
	else
	{
		write( HIW "��������Ȼ�ķ��ƶ������Ǻ��޷�Ӧ��\n" NOR);
		me->add("neili",-500);

	}
	return 1;
}
