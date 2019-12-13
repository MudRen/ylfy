// jail.c

#include <ansi.h>
#include <login.h>

inherit F_DBASE;

int update_condition(object me, int duration)
{
	duration = duration - 1;

	if ( duration < 1 && sscanf(base_name(environment(me)), "/d/city/jianyu%*s") )
	{
		message_vision(HIY"�ѵ�һ����һ����������ţ�һ�Ű�$N���˳�ȥ����������׳԰׺ȣ�û�ţ�\n"NOR, me);
		me->move("/d/city/wumiao");
		message("vision", HIY "ֻ��ƹ��һ����������һ��������һ����ԭ����һ���������ļһ�������ﱻ���˳�����\n" NOR, environment(me), me);
		tell_object(me, HIY "ֻ��һ�����Ƽ���㣬��������ر��ӳ����ݼ�����\n" NOR);
		me->set("startroom", "/d/city/wumiao");
		me->unconcious();
	}

	me->apply_condition("yz_jianyu", duration);
	return 1;
}

