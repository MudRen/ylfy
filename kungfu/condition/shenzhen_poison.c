//shushan2 by yushu 2000.12
#include <ansi.h>
int update_condition(object me, int duration)
{
	me->receive_wound("jingi", 40);
	me->receive_damage("jing", 40);
	me->receive_damage("qi", 40);
	me->receive_wound("qi", 40);
	me->set_temp("death_msg","�о綾������\n");
	me->apply_condition("shenzhen_poison", duration - 1);
	if (duration >0 )
	tell_object(me, HIR "��о����������ѣ��ǳ����ܣ�\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
