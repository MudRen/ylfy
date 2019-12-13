// linji_fengyun.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	duration--;
	if( duration < 1 )
	{
		tell_object(me, 
HIB "��Ȼ�����һ�����������������³�ȥ����ʱ˫�����Ǧ���
�أ�ԭ����ķ���ׯ�չ��ˣ�\n" NOR );
		me->add("dex", 0 - me->query("linji/dex"));
		me->delete("linji/dex");
		return 0;
	}
	me->apply_condition("linji_fengyun", duration);

	return CND_CONTINUE;
}