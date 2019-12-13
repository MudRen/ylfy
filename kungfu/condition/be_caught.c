// be_caught.c
// by QingP

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		me->move("/d/xingxiu/riyuedong");
		message("vision",
			HIY "ֻ��ƹ��һ����������һ��������һ����\n"
			"ԭ����һ���������ļһﱻ���޵��Ӽ��˽�����\n" NOR, environment(me), me);
		tell_object(me, HIY "���޵���˵�����������ɿ�����������ͽ�������������������£�������ʱ��\n" NOR);
		me->set("startroom", "/d/city/kedian");
		return 0;
	}

	me->apply_condition("be_caught", duration - 1);
	
	return 1;
}