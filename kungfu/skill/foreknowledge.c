// literate.c

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
	int s;

	s = me->query_skill("foreknowledge", 1);

        if( s%180==9 && (int)me->query("kar") < s/40) {
		tell_object(me, HIW "��춶�ռ��ѧ�ĸ���һ������⣬�����������ˡ�\n" NOR);
		me->add("kar", 1);
	}
}

int learn_bonus()
{
return 0;	
}

int practice_bonus()
{
	return 0;
}

int black_white_ness()
{
	return 0;
}

