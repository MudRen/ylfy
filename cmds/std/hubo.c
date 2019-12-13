
// hubo.c
#include <ansi.h>
inherit F_CLEAN_UP;
void clean_hubo(object me);
int main(object me)
{
string msg;
int count;
if( me->is_busy() )
return notify_fail("��Ķ�����û����ɣ�����ʹ�á�˫�ֻ���֮������\n");
if (!me->query_skill("hubo",1))
return notify_fail("�㲻�ᡸ˫�ֻ���֮������\n");
if( !me->is_fighting() )
return notify_fail("��˫�ֻ���֮����ֻ����ս����ʹ�á�\n");
if (me->query_temp("hubo"))   return notify_fail("��������˫�ֻ�����\n");
if( (int)me->query("jingli") < (int)me->query("max_jingli") ) 
return notify_fail("��ľ���������\n");
if( (int)me->query("jingli") < 100 )
return notify_fail("��ľ������㣡\n");
if (me->query_skill("hubo",1) < 350)		
return notify_fail("��ġ�˫�ֻ���֮�����������졣\n");		
msg = HIY "$Nƽ�ľ�������̨������ʹ����˫�ֻ���֮������˫��ͬʱ���У�\n" NOR;
message_vision(msg, me);
count = (40 - (int)me->query_int()) / 5 + (int)me->query_skill("hubo") / 20 ;
if( count < 1 ) count = 1 ;
if ( count > 5 ) count = 5 ;	
while( count-- ) {
object ob;
me->clean_up_enemy();
ob = me->select_opponent();
if(!ob || (environment(ob) != environment(me))) 
{
message_vision(CYN "$NͻȻ����һ�ң��Ѳ��ܼ���˫�ֻ�����\n" NOR, me);
break;
}
COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
me->add("jingli", -50);
me->set_temp("hubo",1);
call_out("clean_hubo",1,me);
}
return 1;
}
void clean_hubo(object me)
{
if (!me)    return;
me->delete_temp("hubo");
}
int help(object me)
{
write(@HELP
ָ���ʽ : hubo
���ָ����������ڶԵ�ʱʹ��˫�ֻ���֮��,���ٳ��С�
HELP
);
return 1;
}
