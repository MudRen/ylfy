// zhengqijue.c

inherit SKILL;

#include <ansi.h>

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

// int valid_learn(object me) 
// {
//	if( (int)me->query("guilty") > 0 )
//		return notify_fail("���ŷ�ɮ�����䣬����֮��̫�أ��޷����������ķ���\n");
//	return 1;
// }

int practice_skill(object me)
{	
	return notify_fail("������ֻ�ܿ�ѧ(learn)����ߡ�\n");
}
void skill_improved(object me)
{
    tell_object(me, HIR "������ĵ���һ������֮����\n" NOR );
    me->add("shen", 200);
}