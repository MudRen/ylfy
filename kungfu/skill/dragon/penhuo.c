//���

#include <ansi.h>
inherit F_SSERVER;


int perform(object me, object target)
{
	
 if( !target ) target = offensive_target(me);

	
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		
return notify_fail("���ֻ����ս����ʹ�á�\n");

  
message_vision(	
        HIR "$N"HIR"��������һ�������漴һ��ŭ��һ�Ż������������
 $n"HIR"һ��֮�����һƬ��֮�У�\n" NOR, me, target);
   if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
message_vision(HIR "$n"HIR"һ���ҽУ������˵ò��ᣡ\n" NOR, me, target);	
    target->add("eff_qi", -target->query("eff_qi")/20);           
    target->add("qi", -target->query("qi")/20);           
    me->start_busy(1); 	
}
else 
{
message_vision(HIC "$n"HIC"���Ų�æ��һ����Ծ�����˳�ȥ��\n" NOR, me, target);	
    me->start_busy(1); 	
}
        return 1;
  
 }
