//����

#include <ansi.h>


inherit F_SSERVER;


int perform(object me, object target)
{
	
	if( !target ) target = offensive_target(me);
	if( !target
		|| !target->is_character()
		|| !me->is_fighting(target) )
		return notify_fail("����ֻ����ս����ʹ�á�\n");
	if( target->query_temp("block_msg") )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");
  
	message_vision(HIW"ֻ��$N"HIW"��һ�ţ�һ�Ű�ɫ���ȵ�Ũ��ֱ����$n!\n" NOR, me, target);
	
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) 
	{
		message_vision(HIR "$n"HIW"һ��ɶҲ��������,ֻ�ò�ȡ��ʽ������������\n" NOR, me, target);
		target->set_temp("block_msg/all",1);
		call_out("tuwu_end", 3+random(12), me, target);
		target->start_busy(6);
	}
	else 
	{
		message_vision(HIC "$n"HIC"����һ����Ծ����Ũ��Ĺ�����Χ��\n" NOR, me, target);	
		me->start_busy(1); 	
	}

	return 1;
}

void tuwu_end(object me, object target)
{
	if ( !objectp(target) ) return;
	//if ( environment(me) != environment(target) ) return;
	//target->enable_player();
	target->delete_temp("block_msg/all");
	message_vision("$N��ǰ��������ɢ����$N�������˿�����\n", target);	
	write(HIR"����ǰ������ɢ�������ڿ��Կ�����Χ���龰�ˡ�\n"NOR);
	return;
}
