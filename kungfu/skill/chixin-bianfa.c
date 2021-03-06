// chixin-bianfa 痴心鞭法 
// marry 99.8
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([ "name":   ""MAG"黯然"WHT"销魂"NOR"",
           "action": "$N美眉紧锁，一招「"MAG"黯然"WHT"销魂"NOR"」手中$w向$n的$l舞去。",           
		   "force":  100,
           "dodge":  -10,
           "damage": 30,
           "lvl"    : 0,
           "damage_type":  "割伤"
        ]),
        ([ "name":   "千里共婵娟",
           "action" : "$N一招「"HIC"千里"HIY"共"HIG"婵娟"NOR"」，$w自上而下抛出一个大弧，平平地向$n的$l挥去",
           "force":  150,
           "dodge":  0,
           "damage": 80,
           "lvl"    : 50,
           "damage_type":  "割伤"
        ]),
        ([ "name":   "在水一方",
           "action" : "$N上身往左侧一拧，一招「"HIG"在"CYN"水"HIW"一方"NOR"」右手$w反手向$n的$l挥去",
           "force":  200,
           "dodge":  0,
           "damage": 90,
           "lvl"    : 100,
           "damage_type":  "割伤"
        ]),
        ([ "name":   "但愿人长久",
           "action" : "$N一招「"HIM"但愿"WHT"人"HIR"长"HIB"久"NOR"」，$w轻灵地划出几个圆弧，迅速地向$n的$l挥去",
           "force":  250,
           "dodge":  0,
           "damage": 100,
           "lvl"    : 150,
           "damage_type":  "割伤"
        ]),
        ([ "name":   "只羡鸳鸯不羡仙",
         "action" : "只见$N将手中$w舞成龙凤状，一招「"HIG"只"HIY"羡"HIM"鸳"HIB"鸯"HIW"不"CYN"羡"HIY"仙"NOR"」迅猛的攻向$n",
           "force":  300,
           "dodge":  0,
           "damage": 140,
           "lvl"    : 200,
           "damage_type":  "割伤"
        ]),
        ([ "name":   ""HIM"别鹤"HIB"孤鸾"NOR"",
           "action": "只见$N脸上露出悲伤之色，侧脸挥鞭，一式「"HIM"别鹤"HIB"孤鸾"NOR"」轻飘飘地扫向$n",
           "force":  250,
           "dodge":  0,
           "damage": 100,
           "lvl"    : 230,
           "damage_type":  "割伤"
        ]),
        ([ "name":   ""MAG BLINK"秋水"NOR HIG"伊人"NOR"",
           "action": "$N面泛桃花，双眸似点点秋水，一招「"MAG BLINK"秋水"NOR HIG"伊人"NOR"」，手中$w如灵蟒出洞，软软地缠向$n的$l",
           "force":  250,
           "dodge":  20,
           "damage": 250,
           "lvl"    : 250,
           "damage_type":  "缠伤"
        ]),
        ([ "name":   ""HIB"致死"HIR"不渝"NOR"",
           "action": "$N手中$w对空一指，化鞭为剑，一招「"HIB"致死"HIR"不渝"NOR"」好似不故一切攻向$n。",
           "force":  300,
           "dodge":  25,
           "damage": 300,
           "lvl"    : 300,
           "damage_type":  "刺伤"
        ]),
        ([ "name":   ""HIG"室迩"MAG"人远"NOR"",
           "action": "$N忽然后跳三步，$n正诧异间，$N一式「"WHT"室迩"MAG"人远"NOR"」，手中$w陡然刺向$n的$l。",
           "force":  350,
           "dodge":  35,                          
           "damage": 350,
           "lvl"    : 350,
           "damage_type":  "刺伤"
        ]),
        ([ "name":   ""HIR"痴"HIG"心"HIM"不"HIB"悔"NOR"",
           "action": "$N默念口诀，一招「"HIR"痴"HIG"心"HIM"不"HIB"悔"NOR"」横生挥向$n的$l,$n慌忙招架，不料$N的$w突然打了个弯，重重的缠向$n的$l。",
           "force":  400,
           "dodge":  40,
           "damage": 400,
           "lvl"   : 400,
           "damage_type":  "缠伤"
        ]),
});


int valid_enable(string usage) { return usage=="whip" ||  usage=="parry"; }
int valid_learn(object me)
{
        object weapon;
        int lvl = (int)me->query_skill("chixin-bianfa", 1);
        int t = 1, j;
        if (lvl<=100)
                for (j = 1; j < lvl / 10; j++)
                        t*=2;
        if ( me->query("gender") != "女性" )
                return notify_fail("你又不是女人练什么痴心鞭法？\n");
        if ((me->query("family/master_id")!="shangguan feifeng")&&
            (me->query("family/master_id")!="meng shashaonv")&&  
            (me->query("family/master_id")!="shangguan yunqian")&& 
			(me->query("family/master_id")!="long yujiao"))
                return notify_fail("非本门亲授弟子无法学习。\n");
        if(lvl<=100)
        {
                if (lvl > 10 && (int)me->query("shen") < t * 100) 
                        return notify_fail("你的侠义正气太低了。\n");
        }
        else
        {
                if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000)) 
                        return notify_fail("你的侠义正气太低了。\n");
        }
        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不足，没有办法练痴心鞭法, 多练些内力再来吧。\n");

        if ((int)me->query_skill("whip", 1) < 50)
                return notify_fail("你的基本鞭法火候太浅。\n");

        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("你必须先找一条鞭子才能练鞭法。\n");

        return 1;
}


string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}

int practice_skill(object me)
{
        
        int skill;

       if ((me->query("family/master_id")!="shangguan feifeng")&&
           (me->query("family/master_id")!="meng shashaonv")&&  
           (me->query("family/master_id")!="shangguan yunqian")&& 
		   (me->query("family/master_id")!="long yujiao"))                
		   return notify_fail("非本门亲授弟子无法练习。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力不够练痴心鞭法！\n");
        if( skill > 100 && me->query("shen") < 1)
                return notify_fail("这种武功当得行侠义事。\n");
        me->receive_damage("qi", 40);
        me->add("neili", -30);
        return 1;
}
                                          
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 1 ) return 0;
        if( random( me->query_skill("whip") ) > random( victim->query_skill("force")) && me->query("family/family_name") == "痴心妄想门" 
		 && me->query_skill_mapped("force") == "wangran-xinfa")
        {
                victim->receive_wound("qi", damage_bonus );
                return HIR "只听到「"HIY""BLINK"嗤啦"NOR""HIR"」一声轻响，$w"HIR"竟然陷入皮肉！\n" NOR;
        }
}

mapping query_action(object me, object weapon)
{
        if (random(me->query_skill("chixin-bianfa",1)) > 399 && me->query("neili") > 150 && me->query("family/family_name") == "痴心妄想门" )
        {
                me->add("neili", -150);
                return ([
        "action": ""HIG"忽然$N顿悟灵机，把痴心鞭法使得如行云流水，手中$w"HIG"如银蛇乱舞\n"
        "$n"HIG"只见眼前一片昏暗，顿时心神大乱，只觉得鞭影铺天盖地的向自己缠来。\n"NOR"",
        "force":  600,
        "damage": 600,
        "damage_type": "缠伤"]);
        }
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
        return __DIR__"chixin-bianfa/" + action;
}
