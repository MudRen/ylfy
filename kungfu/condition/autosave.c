// autosave.c
// writed by shadow

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	object link_ob;

	if (duration != 1)
	{
		link_ob = me->query_temp("link_ob");
		if (link_ob) link_ob->save();
		me->save();
//		tell_object(me, HBBLU HIG "�����̾��顿" HIY " �����������Զ������ˡ�\n" NOR);
		me->clear_condition("autosave");
	return 1;

	}
	else
		me->clear_condition("autosave");
	return 1;
}
