// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

string name() { return HIC "�׺�Ц" NOR; }

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon, weapon2;
        int skill, ap, dp, damage, px, md, sx;
        int hp;

        me->clean_up_enemy();
        if( !target ) target = me->select_opponent();

        skill = me->query_skill("lonely-sword", 1);

        if( !me->is_fighting(target) )
                return notify_fail(name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( skill < 200 )
                return notify_fail("��Ķ��¾Ž��ȼ��������޷�ʩչ" + name() + "��\n");

        if( !objectp(weapon = me->query_temp("weapon") )
         || weapon->query("skill_type") != "sword" )
                return notify_fail("��ʹ�õ��������ԣ��޷�ʩչ" + name() + "��\n");

        if( me->query_skill_mapped("sword") != "lonely-sword" )
                return notify_fail("��û�м������¾Ž����޷�ʩչ" + name() + "��\n");

        if( (int)me->query_skill("force") < 200 )
                return notify_fail("����ڹ���򲻹�������ʩչ" + name() + "��\n");

        if( !living(target) )
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        if( me->query("neili")<500 ) 
                return notify_fail("���ʱ���������㣬����ʩչ" + name() + "��\n"); 

        ap = me->attack_power("sword");
        dp = target->defense_power("dodge");

        px = target->query_skill("pixie-jian", 1);
        md = target->query_skill("moon-blade", 1);
        sx = target->query_skill("liumai-shenjian", 1);

        if( px || md )
                ap += ap/10;              // ��Ϊ��֮�ڣ��Ա�а������Բ�µ����мӳɡ�

        if( sx )
                ap -= ap/10;              // ���ó�Ӧ�����������ɽ�Զ�̹������м��ɡ�

        if( objectp(weapon2 = target->query_temp("weapon")) )
        {
                msg = HIC "$N" HIC "һϮ������̤���������������Ի��" HBWHT "�׺�һ��Ц����������������������ֻ�ǽ�\n" NOR
                        HIW "�����У�ֻ��$N" HIW "���΢����һ���׹�˲�����������$n��  \n"  NOR;

                if( ap / 2 + random(ap) > dp )
                {
                        me->add("neili", -100);
                        msg += HIR "$n" HIR "�󺧣���æ�������б������ҵֵ���ȴ���뻢�ھ�ʹ������" + weapon2->name() +
                               HIR "��ס�����ֶ�����\n" NOR
                               HIC "$N" HIC "��Ц����$n" HIC "������ˣ���������������ζ��Σ�\n \n" NOR;

                        weapon2->unequip();
                        weapon2->move(environment(me));
                } else
                {
                        me->add("neili", -200);
                        msg += CYN "$n" HIY "�����⶯������" + weapon2->name() +  "����һ�㡣\n" NOR
                               HIY "ֻ��[��]��һ���죬$N" HIY "��Ц����$n" HIY "��Ȼ�˵ã�\n" NOR
                               HIY "�����Ҷ��֡��ҽ�������Σ� \n \n"NOR;
                }
                message_vision(msg, me, target);
        }
        else
        {
                msg = HIC "$N" HIC "һϮ������̤���������������Ի��" WHT "�׺�һ��Ц����������������������ֻ�ǽ�\n" NOR
                      HIW "$N" HIW "Ц��������$n" HIW "�������ҽ�������Σ�  \n"  NOR;
                        message_vision(msg, me, target);

        }

        msg = HIC "$N" HIC "���������" WHT" ����Ц���׷����ϳ���˭��˭ʤ����֪�� \n" NOR
              HIC "$N" HIC "����������е�" + weapon->name() +"��������" HIW "����"HIC"������������\n" NOR
              HIC "������˷���$n" HIC" ֱ���ȥ��\n" NOR;

        damage = me->damage_power("sword");

        if( ap * 2/3 + random(ap) > dp )
        {
                damage = damage * 3;

                //msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 200,
                                     msg += HIR "$n" HIR "�����콣������������ɫ��ֻ��"
                                           "�������ܣ����޿ɵ���ת�ۼ�" HIW "����" HIR "����"
                                           "ȫ�����Ѩ����Ѫ�罦��\n\n" NOR;


                        if( me->query_temp("apply/fatal_blow") && me->query("ability2/fatal_blow") )
                        {
                                if( random(100) < me->query("ability2/fatal_chance") )
                                {
                                        target->receive_damage("qi", target->query("qi") * me->query_temp("apply/fatal_blow")/100, me);
                                        target->receive_wound("qi", target->query("qi") * me->query_temp("apply/fatal_blow")/200, me);
                                        msg += HIR "�����ţ�$N" HIR "׷��������һ������$n" HIR "��ɸ����صĴ��ˡ�\n" NOR;
                                }
                        }

                me->start_busy(2);
                if( !target->is_busy() )
                        target->start_busy(3);
                me->add("neili", -300);

        } else
        {
                msg += CYN "$n" CYN "�ۼ�����" HIW "����" CYN "���Ʋ��ɵ���"
                       "������֮�£��������˿�ȥ������һ���亹��\n\n" NOR;
                me->start_busy(3);
                me->add("neili", -300);
                target->start_busy(3);
        }
        message_vision(msg, me, target);

        hp=target->query("qi");

        if( hp < target->query("max_qi")/10 )
        {
                msg  = HIR "$N" HIR "��$n" HIR"����ԡѪ������ҡҡ��׹��̾��һ������ \n" NOR
                       HIR "������̣���������Ͷ̥ȥ�ɣ�����" + weapon->name() +" һ�ӣ�\n" NOR
                       HIR "$n" HIR "���п������죬���Ͼ��ǲ���֮ɫ�����ڵ�����ȥ�� \n\n" NOR;
                msg += HIC"$N" HIC "����ƮƮ��ȥ��������磺����Ц�����ټ��ȣ��������ڳճ�ЦЦ~~ \n\n\n" NOR;
                message_vision(msg, me, target);
                target->die(me);
                return 1;
        }

        msg = HIC"$N" HIC "����ƮƮ��ȥ��������磺����Ц�����ټ��ȣ��������ڳճ�ЦЦ~~ \n\n\n" NOR;

        message_vision(msg, me, target);
        return 1;
}
