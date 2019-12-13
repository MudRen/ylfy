// wang.c ÍıÏëÁ¬Ğø»÷÷

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("ÍıÏëÁ¬Ğø»÷Ö»ÄÜ¶ÔÕ½¶·ÖĞµÄ¶ÔÊÖÊ¹ÓÃ¡£\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "axe")
                return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
        if ((int)me->query("shen") < 0) 
                return notify_fail("ÄãµÄÏÀÒåÕıÆøÌ«µÍÁË£¬ÎŞ·¨¼¯ÖĞĞÄÖ¾£¡\n");
        if ( me->query("neili")<150 )  
		return notify_fail("ÄãµÄÄÚÁ¦²»×ã!\n");
 
        if( (int)me->query_skill("wangxiang-fufa", 1) < 100 )
                return notify_fail("ÄãµÄÍıÏë¸«·¨²»¹»æµÊì£¬²»»áÊ¹ÓÃÍıÏëÁ¬Ğø»÷¡£\n");
        if ((int)me->query_skill("wangran-xinfa", 1) < 50)
                return notify_fail("ÄãµÄ±¾ÃÅĞÄ·¨»ğºò²»¹»£¬ÎŞ·¨Ê¹ÓÃ¡£\n");
        if( (int)me->query_skill("shuiyue", 1) < 100 )
                return notify_fail("ÄãµÄ¾µ»¨Ë®ÔÂ²½²»¹»æµÊì£¬²»»áÊ¹ÓÃÍıÏëÁ¬Ğø»÷¡£\n");

        msg = HIR "$NÊ¹³öÍıÏëÁ¬Ğø»÷£¬¿ÕÆøÖĞÒ»¹ÉÉ±ÆøÆÌÌì¸ÇµØµÄÆËÏò$n¡£\n";

        if( random(me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/10 )
        {
                attack_time = random((int)me->query_skill("wangxiang-fufa", 1) / 40);
                if (me->query("family/family_name") == "³ÕĞÄÍıÏëÃÅ")
                {
                if(attack_time < 2) attack_time = 2;
                if(attack_time > 5) attack_time = 5;
                }
                else
                {
                if(attack_time < 1) attack_time = 1;
                if(attack_time > 2) attack_time = 2;
                }
                msg += YEL " ½á¹û$n"YEL"±»$N¹¥µÃÊÖÃ¦½ÅÂÒ¡£\n" NOR;
                message_vision(msg, me, target);
                for(i = 0; i < attack_time; i++){
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);                
				}
                me->start_busy(2+random(1));
                me->add("neili", -100);
        }
        else
        {
                msg += CYN "¿ÉÊÇ$n"CYN"Àä¾²µÄ±Ü¿ªÁË$NµÄÖÂÃüÒ»»÷¡£\n" NOR;
                message_vision(msg, me, target);
                me->start_busy(3);
        }


        return 1;
}
