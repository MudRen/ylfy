// jail.c

#include <ansi.h>
#include <login.h>

inherit F_DBASE;

int update_condition(object me, int duration)
{
	string room_file;

	duration--;
	me->apply_condition("move", duration);

	if ( stringp(room_file = me->query_temp("move_temp_room")) 
		&& duration < 1 && base_name(environment(me)) == VOID_USER )
		{
			tell_object(me, "һ��ʱ�յ�Ť�����㴫�͵���һ���ط�....\n");
			me->move(room_file);
			me->delete_temp("move_temp_room");
		}

	return 1;
}

