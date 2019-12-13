// �������
// suimeng 2015.5.1
#include <ansi.h>

inherit F_SSERVER;


int perform(object me, object target)
{
  string msg;
  int damage;
  int skill, jiali, neili_cost;

  if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() ||  !me->is_fighting(target) )
         return notify_fail("�������ֻ����ս�����á�\n");

    if( target->query("eff_qi") < target->query("max_qi")/4 )
         return notify_fail("��Ķ��������˺����ۣ�ʹ�÷��������Υ��Ҵȱ�Ϊ���ı��⡣\n");

    if( target->query("qi") < target->query("max_qi")/6 )
         return notify_fail("��Ķ��������˺����ۣ�ʹ�÷��������Υ��Ҵȱ�Ϊ���ı��⡣\n");

    if( me->query_temp("yield") )
         return notify_fail("�㲻���֣����ʹ�ó�������գ�\n");
	 
    if( me->query_temp("weapon"))
        return notify_fail("���ȷ������е�������˵�ɣ���\n");     

    if( (skill = (int)me->query_skill("jinding-zhang", 1)) < 1150 )
         return notify_fail("��Ľ����Ʋ�����죬����ʹ������ա�\n");

    if( (int)me->query_skill("linji-zhuang", 1) < 1120 )
         return notify_fail("����ټ�׮����Ϊ����������ʹ�÷�����ա�\n");

    if( me->query_skill_mapped("force") != "linji-zhuang" )
         return notify_fail("�����õĲ����ټ�׮��ʹ����������գ�\n");

    jiali=(int)me->query("jiali");
        if( jiali < 1000 )
         return notify_fail("������������ڼҹ������ϲ�������ʹ��������\n");

    if( me->query("neili") < 30000 ) 
	    return notify_fail("������������ڼҹ����������������㣬ʹ������һ�С�\n");

     msg = HIY "\n$NͻȻ��ȫ������з����������ĵ���΢����֮���������������δ������������$n�ؿڻ�ȥ��\n\n"NOR;
     msg += HIG"��һ���Ƕ����ɵľ�ѧ��������������ա����⡰������ա����Ʒ���ֻһ�У�������\n";
     msg += HIG"һ��Ҳ�������仯����ʽƽƽ������һ�ɲ��䣬����������֮�����������Զ����ɾ���\n";
     msg += HIG"�ڹ���Ϊ������һ�Ƽȳ�����������ɽ����һ��Ϯ�������˵��޿ɵ������޿ɱܡ�\n\n";

    if( random( me->query("xyzx_sys/level") ) > random( target->query("xyzx_sys/level")*2 ) || !living(target) )
       {
            damage = random(  me->query_skill("force") + me->query_skill("unarmed") + me->query("jiali") )*( 1 + me->query("con")) ;                     
            me->add("neili", -damage/10 );
            target->receive_damage("qi", damage,  me);
            target->receive_wound("qi", random(damage), me);
            target->start_busy(2+random(3));

            msg += HIR"��������Ȼһ�����죬$N�Ѵ�����$p�ؿ�.\n"NOR;        
            msg += RED"ֻ��һ�����죬$nȫ��������ѣ���������ɽ�������һ�������Ӵ�������ء�\n"NOR;                
            msg += NOR;
            me->start_busy(2);
  }
  else if( random( me->query("xyzx_sys/level")*2 ) > random( target->query("xyzx_sys/level") ) 
	    || random(target->query_skill("dodge")) < random( me->query_skill("unarmed") )  )
  {
                        damage = random( me->query_skill("force") + me->query_skill("unarmed") + me->query("jiali") )*( 1 + me->query("con"));
                        damage = damage ;
                        me->add("neili", -damage/10 );
                        target->receive_damage("qi", damage,  me);
                        target->receive_wound("qi", random(damage), me);
                        target->start_busy(1+random(3));

                        msg += HIY"$p�ۿ���һ���������ڣ�֪�����ڶԸ�����æ�����ֿ�����������Ȼһ�����죬$N�Ѵ�����$p�ؿ�.\n"NOR;
                        msg += RED"$n���ӱ���һ�����ݰ㣬�ڿ���ƽƽ�ķ��˳�ȥ������ˤ�ڵ��£�������Ѫ���磮\n"NOR;

                msg += NOR;
                target->add( "neili", -damage/10 );
                me->start_busy(2+random(2));
  }
  else if( random( me->query("xyzx_sys/level")*2 ) > random( target->query("xyzx_sys/level") ) 
	    || random( target->query_skill("dodge")*2 ) > random( me->query_skill("unarmed") ) )
  {
                        damage = random( me->query_skill("force") + me->query_skill("unarmed") + me->query("jiali") )*( 1 + me->query("con"));
                        damage = damage ;                    
                        me->add("neili", -damage/10 );

                        target->receive_damage("qi", damage,  me);
                        target->receive_wound("qi", random(damage), me);
                        target->start_busy(1+random(3));

                        msg += HIM"$p�ۿ���һ���������ڣ���æʹ�������������Ծ�����ɣ��������������̲ض�ü�ڼ��ϳ��ڹ���\n";
                        msg += "��Բ���ɶ��������𺳣�$pֻ���ú���һ���ѱ�������������.\n"NOR;
                        msg += RED"$n���ӱ���һ�����ݰ㣬�ڿ���ƽƽ�ķ��˳�ȥ������ˤ�ڵ��£�������Ѫ���磮\n"NOR;

                msg += NOR;
                target->add( "neili", -damage/10 );
                me->start_busy(2+random(2));
  }
  else {
         msg += HIC"$n�ۿ���һ���������ڣ�ʹ��������������Ծ�����ɣ�\n\n"NOR;
         msg += HIW"$N��һ������ʹ����ȫ����˿��������ء�û�뵽ȫ���ô��������������ң�����΢΢������\n" NOR;
         neili_cost = jiali*3;
         if(neili_cost > me->query("neili")) 
                neili_cost = me->query("neili");     
         me->add("neili", -neili_cost );       
         me->start_busy(3);
         message_vision(msg+"\n", me, target);
         return 1;
  }

  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);
  return 1;
}

