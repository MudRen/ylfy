// This is player's own perform (Write by Lonely@nt2)
// Create by ������(Rare) at Sat Apr  8 14:47:07 2006
// ��������(dragon)

#include <ansi.h>
#include <combat.h>

#define PFM "��" HIW "��������" NOR "��"

inherit F_SSERVER;


string *xue_name = ({ 
"�͹�Ѩ", "����Ѩ", "����Ѩ", "��ԪѨ", "����Ѩ", "�м�Ѩ",
"�н�Ѩ", "��ͻѨ", "�ٻ�Ѩ", "����Ѩ", "����Ѩ", "���Ѩ",
"�Ϲ�Ѩ", "��ԨѨ", "�쾮Ѩ", "��ȪѨ", "����Ѩ", "����Ѩ", }); 
string *weapon_sk = ({
        "sword", "blade", "staff", "whip", "club", "hammer", "axe"
});

int perform(object me, object target)
{
        object weapon;
        string msg,wp;
        int ap, dp,i;
        int damage;

        if (! target)
        {
            me->clean_up_enemy();
            target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(PFM "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(PFM "ֻ�ܿ���ʹ�á�\n");             
       
      /*  if ((int)me->query_skill("kurong-changong",1) < 180)
            return notify_fail("��Ŀ�������̫�͡�\n");*/
      
        if ((int)me->query_skill("liuyin-guimai", 1) < 1000)
                return notify_fail("����������������죬����ʩչ" PFM "��\n");
        
        if (me->query("neili") < 300)
                return notify_fail("�����ڵ���������������ʩչ" PFM "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N�������տտ��˫��ƽ�죬����Ѩ֮�и���ӿ��һ���������漴$N˫��һ�ϣ������������������У�����������ײ��ֹ����������ʢ֮ʱ$N˫���ٷ֣���������֮�Ͼ�����������$n��ȥ��" + "\n" + NOR;

        ap =  me->query_skill("unarmed") + me->query_skill("dodge") + me->query_skill("force");
        dp =  target->query_skill("parry") + target->query_skill("dodge") + target->query_skill("force");
         
        if (ap * 2 / 3 + random(ap * 2) > dp)
        {
                damage = me->query_skill("unarmed");
				damage += me->query_skill("liuyin-guimai");
				damage *=3;
                target->add("qi",-damage);
                target->add("eff_qi",-damage);
                //target->apply_condition("yyz_damage",30);

                        msg +=HIM "$n�ۼ�����Ϯ�������޿ɱܣ����޿ɶ㣬ֻ�ñ�Ŀ������ɲ�Ǽ䱻������û����̱�ڵء�" + "\n" NOR;
                me->add("neili", -200);
                me->start_busy(1);
         if (! target->is_busy()) target->start_busy(2);
        } else
        {
                msg += NOR + CYN "$p������Ϯ��������η�壬����䣬һ��ץס����������ʹ��֮�£����������ʹ�ɢ���ˡ�" + "\n" NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }
                
        message_vision(msg, me, target); 
        damage = me->query_skill("unarmed");
        ap =  me->query_skill("unarmed") + me->query_skill("dodge") + me->query_skill("force");
        dp =  target->query_skill("parry") + target->query_skill("dodge") + target->query_skill("force");

        msg = HIW "ͻȻ��";

        if (objectp(weapon = target->query_temp("weapon")))
        {
                wp = weapon->name();
                msg += "$N" HIW "��ָһ�����$n" HIW "����" + wp + NOR + HIW
                       "�������ϡ�" HIY "���" HIW "������" HIY "����" HIW "��"
                       "����" HIY "����" HIW "����Ѩ��\n" NOR;

                ap =  me->query_skill("unarmed",1) + me->query_skill("dodge",1) + me->query_skill("force",1);
                dp =  target->query_skill("parry",1) + target->query_skill("dodge",1) + target->query_skill("force",1);

                if (ap / 2 + random(ap) > dp)
                {
                        msg += HIR "��ʱ��$n" HIR "ֻ��������һ�飬����" + wp +
                               HIR "��Ҳ�óֲ�ס�����ֵ��ڵ��ϡ�\n\n" HIW "��"
                               "����";
                        me->add("neili", -150);
                        weapon->move(environment(target));
                } else
                {
                        msg += CYN "����$n" CYN "������" + wp + NOR + CYN "ת"
                               "�����֣����ڻ�������һ�С�\n\n" HIW "������";
                        me->add("neili", -100);
                }
        }

        msg += "$N" HIW "������ָ��һʽ��" HIR "��������" HIW "���������ʱһ��"
               "����������ֱϮ$n" HIW "�ؿڣ�\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
            target->add("qi",-damage);
            target->add("eff_qi",-damage);
            target->apply_condition("yyz_damage",30);

                     msg += HIR "���$n" HIR "��$N" HIR "һָ����"
                            HIY + xue_name[random(sizeof(xue_name))] +
                            HIR "��ȫ�������������ϣ���ʱŻ��һ��"
                            "����Ѫ��\n" NOR;

                target->add_temp("liumai-shenjian/die", 1);
        } else
        {
                msg += CYN "����$p" CYN "�����磬ȫ��������$P"
                       CYN "�⾫���һָ��\n" NOR;
        }

        ap =  me->query_skill("unarmed") + me->query_skill("dodge") + me->query_skill("force");
        dp =  target->query_skill("parry") + target->query_skill("dodge") + target->query_skill("force");

        msg += "\n" HIW "����$N" HIW "̤ǰһ�������������ŷ�������һָ����$n" HIW
               "��ȥ��ָ���ݺᣬ��Ȼ���죡\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
            target->add("qi",-damage*2);
            target->add("eff_qi",-damage);
            //target->apply_condition("yyz_damage",30);
			
                 msg += HIR "���$n" HIR "��$N" HIR "һָ����"
                        HIY + xue_name[random(sizeof(xue_name))] +
                        HIR "��ȫ�������������ϣ���ʱŻ��һ��"
                                           "����Ѫ��\n" NOR;

                target->add_temp("liumai-shenjian/die", 1);
        } else
        {
                msg += CYN "����$p" CYN "�����磬ȫ��������$P"
                       CYN "�⾫���һָ��\n" NOR;
        }

        ap =  me->query_skill("unarmed") + me->query_skill("dodge") + me->query_skill("force");
        dp =  target->query_skill("parry") + target->query_skill("dodge") + target->query_skill("force");

        msg += "\n" HIW "���$N" HIW "һ���ͺȣ���ָ���͡���һ�����������ָ��ͬ"
               "ʱ����$n" HIW "ȫ�����ҪѨ��\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
            target->add("qi",-damage);
            target->add("eff_qi",-damage);
            //target->apply_condition("yyz_damage",30);

                     msg += HIR "���$n" HIR "��$N" HIR "һָ����"
                            HIY + xue_name[random(sizeof(xue_name))] +
                            HIR "��ȫ�������������ϣ���ʱŻ��һ��"
                                           "����Ѫ��\n" NOR;

                target->add_temp("liumai-shenjian/die", 1);
        } else
        {
                msg += CYN "����$p" CYN "�����磬ȫ��������$P"
                       CYN "�⾫���һָ��\n" NOR;
        }

        if (target->query_temp("liumai-shenjian/die", 1) == 3 && target->query("neili"))
        {
                msg += HIY "\n$n" HIY "��$N" HIY "��ָ���У�ȫ��������"
                       "ɢ������ƺӾ��̣�������ʱ��к������\n\n" NOR;
        if (userp(target))
        {
            target->set("neili", 0);
        }
       else
        {
	        target->add("neili", -2000);
	        target->start_busy(4);
        }
        }

        target->delete_temp("liumai-shenjian/die");
        message_vision(msg, me, target);

        if (! target->query("neili"))
                tell_object(target, HIC "��ֻ�������ھ��ƿտ���Ҳ��һʱ˵���������ܡ�\n" NOR);
                  msg = HIR "������$N" HIR "ʮָ�׷ɣ����������������ν�����$n"
                        HIR "����˷��Ա����������֡�\n"NOR;
        message_vision(msg, me, target);
        me->add_temp("apply/attack", 100);

        for (i = 0; i < 6; i++)
        {
            msg=HIR "$N��"+chinese_number(i+1)+"ָ���򩥩�����$n��" HIY + xue_name[random(sizeof(xue_name))] +
                                           HIR "\n" NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
        me->start_busy(5);
        me->add("neili", -800);
        return 1;
}

