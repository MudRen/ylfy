// mingyu-shengong.c 冥雨神功

#include <ansi.h>
inherit FORCE;

int valid_force(string force) { return 1; }  
int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("mingyu-gong", 1);
        return lvl /10 * lvl /10 * 15 * 28 / 10 / 20;
}
string *dodge_msg = ({
        "$N身形加速，电光挪移，饶是$n攻击范围既广且厉，却总能在间不容发的空隙避过",
        "$N空中快速转折，在$n每次攻击前又倏乎消失，一下子就脱出$n的攻击范围",        
        "$N只觉眼前一花，只见到$n身形一幌，自己的招数居然莫名其妙就落空了", 
        "$N凭著高速身法，在$n的攻击范围内进退趋避，险险闪过一道又一道的攻击",
        "$N腾挪快速，竟然在空中形成身影残像，有如无数$N一起挪动",
        "$n眼前忽然一花，眼前$N的身影似乎有些淡化，而另外一个$N竟尔出现在面前不足一尺的近处",
});

string *parry_msg = ({
        "眼看$n转眼已攻至，$N轻描淡写，却又快绝无比，把$n的招式化于无形",
        "$n眼看得手之际，突觉一股阴柔劲道急上，没等接触，整条手臂已剧痛起来，忙叫一声不好，慌然急退",
        "$n陡觉手上劲力如泥牛入海，摸不着底处，暗叫不妙，$N却又已经攻至",
        "$n心下一凛，但见对手守势，如万里长空，旷远不知其深，包容万物，无从下手",
});


string *action_msg = ({
        "$N十指微张，看似简单的，却在张开的同时，爆发了沛然莫敌的冲击力击向$n",
        "$N运起明玉功，身体逐渐变得透明，森寒杀意如有实质，隔空锁镇住$n",
        "$N双手一张一收，平实的一招却让$n有如处于漩涡之中，动弹不得",
        "$N将明玉功提至极限，一招一式，神妙无方，如天外神龙，纵横来去",
        "$N幻化出点点星雨，迳自往四面八方洒去，形成无数小气旋",
        "$n陡觉一股气旋急压而下，扯得自己身形不定，同时一股阴柔内劲夹於其，尽数封死了$n周遭退路",
        "$N一招击中$n，同时一股阴柔内劲绵绵不绝的涌入$n的体内，侵筋蚀脉",
        "$N催运明玉功，，进似神龙矫捷，退若灵蛇窜动，$n只觉得眼花撩乱",
        "$N微一扬手，绕身明玉劲如毒蛇洪水似地爆起，群蛇乱舞，乱攻向$n",
        "$n只觉得股阴柔内劲传来，跟著便是手上一沉，好似有什么东西，让手臂变成千斤重物，拖的自己直往前跌",
});

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "force" : 200 + random(120),
                "attack": 50 + random(60),
                "dodge" : 50 + random(60),
                "parry" : 50 + random(60),
                "damage" : 280 + random(60),
                "damage_type" : "内伤",  
        ]);
}

string query_dodge_msg(string limb){ return dodge_msg[random(sizeof(dodge_msg))];}

string query_parry_msg(object weapon){ return parry_msg[random(sizeof(parry_msg))];}

int valid_enable(string usage)
{
         return usage == "force" || usage == "unarmed" || usage == "sword" ||
                usage == "dodge" || usage == "parry";
}

int double_attack() { return 1; }

int valid_learn(object me)
{
            mapping skl;	
            string *sname;	
            int i;	

        if ( !wizardp(this_player()) && (me->query("family/family_name") != "移花宫"))
                return notify_fail("你不是移花宫弟子不能使用冥雨神功。要是让两位宫主知道了你可惨了.\n");
        if ( me->query("gender") != "女性")
		        return notify_fail("移花宫主最讨厌男人,让她知道了可不得了!\n");
            skl = this_player()->query_skills();	
                sname  = keys(skl);	
                for (i=0;i<sizeof(skl);i++){	
                    if (sname[i]=="xixing-dafa") continue;	
                    if (sname[i]=="yijing-force") continue;     	
                    if (sname[i]=="mingyu-shengong") continue;	
                    if( SKILL_D(sname[i])->valid_enable("force") )	
		    return notify_fail("你不先散了别派内功，怎能学冥雨神功？！\n");
}
	return 1;
}


int ob_hit(object ob, object me, int damage)
{
        string msg;
        int j, neili, neili1;
        int level,level2,damage2,damage3;
         mapping result;
        int ap, dp;
        int cost;
        level = (int) me->query_skill("mingyu-shnegong",1);
        level2= (int) me->query_skill("mingyu-shengong",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
        damage2= (int) me->query("max_neili",1)/10;
        damage3= (int) me->query("max_neili",1)/10+300;
        cost = damage / 2;
		j = damage / 2;
        if (cost > 100) cost = 100;

        ap = ob->query_skill("force");
        dp = me->query_skill("force");
        
        if (ap / 3 + random(ap) < dp && random(5)==0  && me->query("neili") >=300)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(2))
                {
                case 0:
                    msg = HIR "$N" HIR "默念冥雨神功总诀，收敛内劲，承下$n" + HIR "这一招，$N只觉犹如进入绵绵长河中，丝毫不起作用。\n"NOR;

                        break;
                case 1:
                    msg = HIR "$n" HIR "一招击中$n" HIR "上身，可却犹如击在棉花上一般，力道顿时消失得无影无踪。\n" NOR;
                        
                        break;
                default:
                     msg = HIR "但见$N" HIR "微微一笑，浑若无事的接下了$n" HIR "这一招，纯阴之劲随之而起，没有受到半点伤害。\n" NOR;
 
                        break;
                }
        if (me->query("qi") < me->query("max_qi"))
        {
        me->add("qi",damage3);
        }
        if (me->query("eff_qi") < me->query("max_qi"))
        {
        me->add("eff_qi",damage3);
        }
           message_vision(msg, me, ob);
           return j;
        }
 
        if (random(8)==0 && level>=300  )
        {
        if (me->query("qi") < me->query("max_qi"))
        {
        me->add("qi",damage2);
        }
        if (me->query("eff_qi") < me->query("max_qi"))
        {
        me->add("eff_qi",damage2);
        }
        msg = HIB "$N" HIB "运起冥雨神功!! 全身的伤口一瞬间止住了鲜血！\n" NOR;
        msg += HIB "一股寒气优似冰箭，循着手臂，迅速无伦的射入$n的胸膛\n" NOR;
        ob->apply_condition("xscold_poison",12);

           message_vision(msg, me, ob);
           return j;
}       
}     
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        object weapon;
		int n;
	    n = me->query_str(1)+me->query_con(1)+me->query_dex(1);
        lvl = me->query_skill("mingyu-shengong", 1);
        weapon = me->query_temp("weapon");

        if ( me->query_temp("mingyu_pfm/qiong")
             && me->query_temp("mingyu_pfm/qiong") > 0
             && !me->query_temp("mingyu_pfm/qiong_hit_done")
             && !weapon
             && me->query("neili") >=10000
             )
        {
                me->add("neili", -1000);
                message_vision(HIY"\n$N前招将落，后招已至，前后两招形如一式，此起彼伏，连绵不绝！\n"NOR,me);
                me->set_temp("mingyu_pfm/qiong_hit_done", 1);
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
                me->delete_temp("mingyu_pfm/qiong_hit_done");
        }


        if (damage_bonus < 80 || lvl < 150 || me->query("neili") < 300
           || me->query_skill_mapped("force") != "mingyu-shengong"
           || me->query_skill_mapped("unarmed") != "mingyu-shengong"
           )
                return 0;
        if ( random(n/2) > victim->query_con(1) && random(3)==0)
        {
                me->add("neili", -100);
                victim->receive_wound("qi", (damage_bonus - 80) / 2+30);
            victim->apply_condition("cold_poison", (me->query_skill("mingyu-shengong"))/10 +
			victim->query_condition("cold_poison"));
        if (random(2)==0)
{
                return  HIR "只见$N" HIR "冥雨神功内劲自体内迸发，一股柔劲随招式而荡漾，摧毁了$n" HIR "的真元！\n" NOR;
}
else
{
                return  HIR "$N" HIR "冥雨神功的潜力发挥了出来，突然间$n只感喉咙一甜，喷出一口鲜血！\n" NOR;
}
        }

}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("mingyu-shengong", 1);
        if (lvl < 150) return 0;
        if (lvl < 200) return 70;
        if (lvl < 250) return 80;
        if (lvl < 300) return 90;
        if (lvl < 350) return 100;
        if (lvl < 400) return 110;
        return 120;
}

int practice_skill(object me)
{
        return notify_fail("冥雨神功只能用学(learn)的来增加熟练度。\n");
}

int difficult_level()
{
        return 1000;
}

string perform_action_file(string action)
{
        return __DIR__"mingyu-shengong/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"mingyu-shengong/exert/" + action;
}

void skill_improved(object me)
{
        int lvl, layer;

        lvl = me->query_skill("mingyu-shengong", 1);
        layer = lvl / 90;

        if ((lvl % 90) == 0 && layer > 9)
        {
                tell_object(me, HIY "你的冥雨神功又进了一层。\n" NOR);
        } else
        if ((lvl % 90) == 0)
        {
                tell_object(me, HIY "你炼成了第" + chinese_number(layer) +"层的冥雨神功。\n" NOR);
        }
}
