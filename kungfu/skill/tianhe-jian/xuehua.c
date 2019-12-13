// fenfei.c ѩ��̫ɽ
 
#include <ansi.h>
 
inherit F_SSERVER;

int perform(object me)
{
        string msg, msg_1, msg_2;
        object weapon, target;
        object ob;
        int skill, skill2, skill3, skill4, skill5;
        int qi_wound, count, count_2, i;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("tianhe-jian",1);
        skill2 = me->query_skill("force",1);
        skill3 = me->query_skill("dodge",1);
        if (target)
        {
                skill4 = target->query_skill("parry",1);
                skill5 = target->query_skill("dodge",1);
        }

        if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��������ʹ����ô��ʹ��ѩ��̫ɽ����\n");

        if( !me->is_fighting()|| !living(me) )
                return notify_fail("��ѩ��̫ɽ��ֻ����ս����ʹ�á�\n");

        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("���������Ϊ�������ߣ�\n");

        if( (int)me->query("neili") < 2000 )
                return notify_fail("�����ڵ��������㣡\n");

        if( me->query_skill_mapped("sword") != "tianhe-jian") 
                return notify_fail("��û�м�����ӽ������޷�ʹ�á�ѩ��̫ɽ����\n");

        if( skill < 150 )
                return notify_fail("����ӽ�������Ϊ����������ʹ�á�ѩ��̫ɽ��! \n");

        if( skill2 < 120)
                return notify_fail("���ڹ���Ϊ����������ʹ�á�ѩ��̫ɽ��! \n");
 
        if( skill3 < 150)
                return notify_fail("����Ṧ̫�����ʹ�á�ѩ��̫ɽ��! \n");

        msg = HIW "\n$NŭХһ��������Ҵ̣�ǰ����̣�����Ҵ̣����ǡ�ѩ��̫ɽ������������$n����·������ʵʵʮһ������Ϯ$n��\n\n"NOR;
        message_vision(msg, me, target);
        ob = me->query_temp("weapon");

        if (skill < 240 || skill3 < 240)
        {
                if (random(me->query_dex(1) * skill3) > random(target->query_dex(1) * skill5 / 2))
                {
                        msg_1 = "$n�������۵Ľ��⣬�Ѿ���Ͼ�˼��ж��Ľ���ʵ���Ľ������ˡ�\n";
                        msg_2 = "$nֻ��Ӳ��ͷƤ���������е�һ�����⵲����ȥ��\n";
                        count = 1;
                }
                else
                {
                        msg_1 = "$nһƳ֮��������ˣ�������ʵʵʮһ��ֻ��һ����ʵ�У������������С�\n";
                        if (random(skill * skill3) > random(skill4 * skill5 / 2))
                                msg_2 = "$n��Ȼ������һʵʮ�飬ȴ�޷��ҵ�����ɱ��֮���ڣ�ֻ��Ӳ��ͷƤ���������е�һ�����⵲����ȥ��\n";
                        else msg_2 = "$n���۹�ʵ��������֮�����������֮���Ѿ��жϵ���$N����ɱ��֮���ڣ�������ԥ�ĵ�����ȥ��\n";
                        count = 1;
                }
        }
        else if (skill < 360 || skill3 < 360)
        {
                if (random(me->query_dex(1) * skill3) > random(target->query_dex(1) * skill5 / 2))
                {
                        msg_1 = "$n�������۵Ľ��⣬�Ѿ���Ͼ�˼��ж��Ľ���ʵ���Ľ������ˡ�\n";
                        msg_2 = "$nֻ��Ӳ��ͷƤ���������еļ���������ҵĵ�����ȥ��\n";
                        count = 12;
                }
                else
                {
                        msg_1 = "$nһƳ֮�����в���һ��������$N�Ľ��ƶ��ü��죬������ʵʵʮһ����Ȼ��������ʵ�У�ʵ���ѷ�֮����\n";
                        if (random(skill * skill3) > random(skill4 * skill5 / 2))
                                msg_2 = "$n��Ȼ������������ʵ��ȴ�޷��ҵ�����ɱ��֮���ڣ�ֻ��Ӳ��ͷƤ���������еļ���������ҵĵ�����ȥ��\n";
                        else msg_2 = "$n���۹�ʵ��������֮�����������֮���Ѿ��жϵ���$N����ɱ��֮���ڣ�������ԥ�ĵ�����ȥ��\n";
                        count = 6;
                }
        }
        else
        {
                if (random(me->query_dex(1) * skill3) > random(target->query_dex(1) * skill5 / 2))
                {
                        msg_1 = "$n�������۵Ľ��⣬�Ѿ���Ͼ�˼��ж��Ľ���ʵ���Ľ������ˡ�\n";
                        msg_2 = "$nֻ��Ӳ��ͷƤ���������еļ���������ҵĵ�����ȥ��\n";
                        count = 22;
                }
                else
                {
                        msg_1 = "$N����һ��$n������ʧɫ��ԭ����������ʵʵʮһ������޳�����ͣ��ʵ���顢���ʵ�������޴��жϡ�\n";
                        msg_1 = "$n֪������ʮһ�����жϺ������壬�������ԥ���������н���ӭ����ȥ��\n";
                        count = 11;
                }
        }

        message_vision(HIC + msg_1 + msg_2 + "\n" + NOR, me, target);

        for (i=0;i<count;i++)
        {
                if (random(skill*skill3*me->query_str(1)) > random(skill4*skill5*target->query_str(1)/2))
                        count_2 ++;
                if (count_2 > 6) count_2 = 6;
        }

        if (count_2 == 0)
                msg = HIG"һʱ�佣����Ӱ��֯��һ�𣬶�������һ������֮��$N����һʽ��ѩ��̫ɽ����Ȼ��$n��ȫ����������һ��δ�С�\n\n"NOR;
        else if (count_2 == 1)
                msg = HIM"һʱ�佣����Ӱ��֯��һ��Ȼ��ֻ��һ���ƺߣ���Ӱ��Ȼ�ֿ���\n"
                        + "ֻ��$n�����Ѿ�����������Ѫ������Ȼ$n�����мܣ��Ͼ�������һ��͸�������ط���������$n��\n"NOR;
        else if (count_2 == 2 || count_2 == 3)
                msg = HIM"һʱ�佣����Ӱ��֯��һ��Ȼ��ֻ��һ���ƺߣ���Ӱ��Ȼ�ֿ���\n"
                        + "ֻ��$n������Ѫ��ӿ��ԭ����Ȼ$n�����мܣ�������ʵʵ�ġ�ѩ��̫ɽ��������"
                        + chinese_number(count_2) + "��������$n��\n"NOR;
        else if (count_2 == 4 || count_2 == 5)
                msg = HIR"һʱ�佣����Ӱ��֯��һ��Ȼ��ֻ��һ���ҽУ���Ӱ��Ȼ�ֿ���\n"
                        + "ֻ��$n����������Ѫ��ӿ������$n���м��Ѿ���ͬ���裬����ʵʵ�ġ�ѩ��̫ɽ����Ȼ��"
                        + chinese_number(count_2) + "��������$n��\n"NOR;
        else
                msg = HIR"һʱ�佣����Ӱ��֯��һ��Ȼ��ֻ��һ���ҽУ���Ӱ��Ȼ�ֿ���$n�Ѿ�ҡҡ�����ˡ�\n"
                        + "ֻ��$n�Ѿ����������һ��Ѫ�ˣ�����ʵʵ�ġ�ѩ��̫ɽ����"
                        + chinese_number(count_2) + "��ʵ�н����鷢��ȫ��������$n��\n"NOR;

        message_vision(msg, me, target);
        qi_wound = (skill + random(skill2)) * count_2*5;

        if(qi_wound > target->query("qi")) qi_wound = (target->query("qi") + 1);
        target->add("qi", -qi_wound);
        target->add("eff_qi", -(qi_wound/4));
        if (count_2) COMBAT_D->report_status(target, 0);
        me->start_busy(3 + random(2));
        me->add("neili",-(500 * count_2));

        return 1;
}

    
    
