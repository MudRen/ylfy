//Ǯ��

#include <ansi.h>
string give_gift();

mixed *story = ({
        "ĳ--�����ˬ��һ��",
        "���κ�һ��������Լ��ktv�Ⱦơ�",
        "�仨........�Ͼơ�",
        "�ֵܣ�������һ����,����ǳ��һ��",
        "˵�ꡣ",
        "�����ƿ..һ�ڼ���.��",
		"....",
		"....",
		"ȷ���Ǿƣ�",
		"......ȷ��.......",
		"˵�꣬�����˶���������......",
		"�ڶ���",
		"���Σ��ҵ�Ǯ���أ�~~~��������",
        (: give_gift :),
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        STORY_D->give_gift("/clone/misc/qian-bao", 1,
                           HIM "\n��ž����һ��һ��Ǯ����������ǰ��\n\n" NOR);
        return HIM "��˵���ξ�ʿ��Ǯ�����ˡ�\n" NOR;
}