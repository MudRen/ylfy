// lifeheal.c�����ˣ�

#include <ansi.h>

int exert(object me, object target)
{
    if( me->is_fighting() )
        return notify_fail("ս�����˹����ˣ�������\n");

   if( !target )
      return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");
 
   if( (int)me->query("max_neili") < 240 )
      return notify_fail("���������Ϊ������\n");

   if( (int)me->query("neili") < 120 )
      return notify_fail("�������������\n");

   if( (int)target->query("eff_qi") == (int)target->query("max_qi") )
      {
         if ( me == target )
            return notify_fail("������û�����κ��ˡ�\n");
         return notify_fail( target->name() + "����û�����κ��ˡ�\n");
      }

   if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
      return notify_fail( target->name() + "�Ѿ����˹��أ����ܲ�����������𵴣�\n");

      message_vision( MAG"$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n"
"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR, me, target );

   target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
   target->add("qi", 10 + (int)me->query_skill("force")/3 );
   if( (int)target->query("qi") > (int)target->query("eff_qi") )
target->set("qi", (int)target->query("eff_qi"));

   me->add("neili", -120);
   me->add("combat_exp",1);
    if( (int)me->query("mud_age")>86400) me->start_busy(2+random(1));

   return 1;
}

