// feilong.c by yushu@SHXY 2000.11
// lilong alter 2002.01.12

#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
      string msg;
      object weapon, weapon2;
      int skill, dp;

      me->clean_up_enemy();
      target = me->select_opponent();

       if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
              return notify_fail("���Ѿ���æ���ˡ�\n");
      skill = me->query_skill("fumozhang",1);
      
      if( !(me->is_fighting() ))
              return notify_fail("����̽����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

      if(playerp(me) && me->query("family/family_name")!="��ɽ��")
                return notify_fail("������ɽ�Ĳ����á�����̽���֡���\n");

      if (objectp(weapon = me->query_temp("weapon")))
              return notify_fail("�������֡�\n");

      if (!objectp(weapon2 = target->query_temp("weapon")))
         return notify_fail("�Է�û�б��У��㲻�õ��ġ�\n");

      if( skill < 500)
              return notify_fail("��ķ�ħ�Ƶȼ�����, ��ʹ�÷���̽���֣�\n");

      if( me->query("max_neili") < 1500 )
              return notify_fail("��������������޷�����̽���֣�\n");
      
           msg = CYN "$N�����Ϣ������ʩչ����̽���ֶ�ȡ�Է�����. \n";
      message_vision(msg, me);

      dp = target->query("str") * 3;
      if( dp < 1 )
              dp = 1;
      if( random(skill) > dp )
      {
              if(userp(me))
              me->add("neili",-50);
              msg = HIW"$Nʹ������̽���ֵľ���, $n��ʱ������ǰһ��������һ�飬����"HIM+weapon2->query("name")+HIW"����$N�����У�\n" NOR;
              target->start_busy(2);
              weapon2->move(me);
              me->start_busy(random(2));
      }
      else
      {
              msg = "����$n�Ŀ�����$N����ͼ�����̲�ȡ���ƣ�ʹ$Nû�ܶ��±��С�\n"NOR;
              me->start_busy(random(3));
      }
      message_vision(msg, me, target);

      return 1;
}
