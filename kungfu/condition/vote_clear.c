// vote_clear.c
// by Marz 04/21/96

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	duration--;
	
	if ( duration < 1 ) 
	{
		tell_object(me, YEL "��Ϊ��Ӧ���˲��࣬�����ͶƱȡ���ˡ�\n" NOR);
		shout(HIG "��ͶƱ����Ϊ��Ӧ���˲��࣬��" + me->name(1) + "��ͶƱȡ���ˡ�\n" NOR);
		me->delete("vote/reason");
		me->delete("vote/juror");
		me->delete("vote/count");   
		me->apply_condition("vote_clear", duration);
		return 0;
	}
	
	me->apply_condition("vote_clear", duration);
	return 1;
}

string query_type(object me)
{
	return "vote";
}
