//xuecan_poison.c by wyz
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
    if( duration < 1 ) return 0;
    if( !living(me) ) {
        message("vision", me->name() + "���������ʹ��غ���һ����\n", environment(me), me);
    }else {
        tell_object(me, HIB "��Ȼһ���溮�ӵ�������������֫�ٺ������еĺ��������ˣ�\n" NOR );
        message("vision",HIB+ me->name() + "������ͻȻ�������Σ���ɫһ��"+HIW+"��"+HIB+"��һ��"+NOR+BOLD+"��"+HIB+"�����ظ������졣\n"+NOR,environment(me), me);
    }
    me->receive_wound("qi",15 + random(10));
    me->receive_wound("jing", 10);
    me->apply_condition("xuecan_poison", duration - 1);
    /*if ( (int)me->query_temp("powerup") ) {
        me->add_temp("apply/attack", - (int)(me->query_skill("force")/3));
        me->add_temp("apply/dodge", - (int)(me->query_skill("force")/3));
        me->delete_temp("powerup");  
    }*/
    if (me->query("neili")>=200)   me->add("neili",-200);
    me->set_temp("die_for","�к���");
    me->delete_temp("last_damage_from");
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

