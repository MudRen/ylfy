// vote_suspension.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	duration--;
	if (duration < 1) {
		tell_object(me, HIG "观察期已满，你又可以投票了！\n" NOR);
		me->delete("vote/deprived");
		return 0;
	}
	me->apply_condition("vote_suspension", duration);
	return 1;
}

string query_type(object me)
{
	return "vote";
}
