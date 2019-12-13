//梅花三弄.c
#include <ansi.h>
#include <combat.h>
inherit SKILL;
string *order = ( {""RED"", ""MAG"", ""HIW"", ""HIR"", ""HIM""});
mapping *action = ({
([
     "action" : "$N划身错步，一式"+(order[random(5)])+"「梅花一弄戏凤高」"NOR"，双掌内拢外托，攻向$n的檀中穴",
     "force"  : 100,
     "dodge"  : 120,
     "parry"  : 90,
     "lvl"    : 0,
     "damage"    : 120,
     "skill_name"  : "梅花一弄戏凤高",
     "damage_type" : "内伤"
]),
([
     "action" : "$N身随意转，使一式"+(order[random(5)])+"「薄袄轻罗自在飘」"NOR"，手如兰花，似清风抚过$n的面额",
     "force"  : 150,
     "dodge"  : 110,
     "parry"  : 90,
     "lvl"    : 0,
     "damage"    : 150,
     "skill_name"  : "薄袄轻罗自在飘",
     "damage_type" : "震伤"
]),
([
     "action" : "突见$N双臂柔若无骨肤如雪肌，"+(order[random(5)])+"使出「半点含羞遮绿叶」"NOR"缠住$n的脖颈",
     "force"  : 180,
     "dodge"  : 150,
     "parry"  : 110,
     "lvl"    : 0,
     "damage"    : 200,
     "skill_name"  : "半点含羞遮绿叶",
     "damage_type" : "挫伤"
]),
([
     "action" : "只见$N端坐床头，头披红绸，趁着$n向前探视，突然使出"+(order[random(5)])+"「三分暗喜映红袍」"NOR"，向$n连抓几把",
     "force"  : 200,
     "dodge"  : 150,
     "parry"  : 150,
     "lvl"    : 0,
     "damage"    : 200,
     "skill_name"  : "三分暗喜映红袍",
     "damage_type" : "抓伤"
]),
([
     "action" : "$N左掌护胸，右臂微举似迎春，续而向外疾伸，一式"+(order[random(5)])+"「梅花二弄迎春曲」"NOR"攻向$n的气海穴",
     "force"  : 220,
     "dodge"  : 150,
     "parry"  : 180,
     "lvl"    : 0,
     "damage"    : 250,
     "skill_name"  : "梅花二弄迎春曲",
     "damage_type" : "内伤"
]),
([
     "action" : "$N右掌绽开，双臂微展，一式"+(order[random(5)])+"「瑞雪溶成冰玉肌」"NOR"与$n的硬对一掌，$n只觉得内力如冰雪消融",
     "force"  : 250,
     "dodge"  : 150,
     "parry"  : 180,
     "lvl"    : 0,
     "damage"    : 280,
     "skill_name"  : "瑞雪溶成冰玉肌",
     "damage_type" : "震伤"
]),
([
     "action" : "$N双掌飞舞，如落叶飞花，一式"+(order[random(5)])+"「错把落英当有意」"NOR"，幻成漫天梅花朵朵，雨点般向$n击去",
     "force"  : 270,
     "dodge"  : 180,
     "parry"  : 200,
     "lvl"    : 0,
     "damage"    : 300,
     "skill_name"  : "错把落英当有意",
     "damage_type" : "震伤"
]),
([
     "action" : "只见$N合掌竖立做观音装，一式"+(order[random(5)])+"「红尘一梦笑谁痴」"NOR"，双掌变幻吞吐，缓缓推向$n的胸前",
     "force"  : 280,
     "dodge"  : 200,
     "parry"  : 200,
     "lvl"    : 0,
     "damage"    : 320,
     "skill_name"  : "红尘一梦笑谁痴",
     "damage_type" : "撞伤"
]),
([
     "action" : "只听见$N微微一笑，轻吟"+(order[random(5)])+"「梅花三弄唤群仙」"NOR"，只见一花仙子凭空出现，对$n轻叹一声：尔等不识仙",
     "force"  : 280,
     "dodge"  : 200,
     "parry"  : 200,
     "lvl"    : 0,
     "damage"    : 350,
     "skill_name"  : "梅花三弄唤群仙",
     "damage_type" : "挫伤"
]),
([
     "action" : "只见$N双足点地一跃而起，使出一招"+(order[random(5)])+"「雾绕云蒸百鸟喧」"NOR"，$n目光迷离，看不清拳势，待百鸟飞过已中数拳",
     "force"  : 300,
     "dodge"  : 200,
     "parry"  : 200,
     "lvl"    : 0,
     "damage"    : 350,
     "skill_name"  : "雾绕云蒸百鸟喧",
     "damage_type" : "砸伤"
]),
([
     "action" : "$N身形一转，倏忽欺至$n身前，一招"+(order[random(5)])+"「蝶舞蜂飞腾异彩」"NOR"直拍$n的后背",
     "force"  : 350,
     "dodge"  : 150,
     "parry"  : 200,
     "lvl"    : 0,
     "damage"    : 380,
     "skill_name"  : "蝶舞蜂飞腾异彩",
     "damage_type" : "抓伤"
]),
([
     "action" : "$N突然身形飞起，双掌居高临下一招"+(order[random(5)])+"「丹心谱写九重天」"NOR"，$n不知所措，无法抵挡",
     "force"  : 380,
     "dodge"  : 190,
     "parry"  : 200,
     "lvl"    : 0,
     "damage"    : 400,
     "skill_name"  : "丹心谱写九重天",
     "damage_type" : "抓伤"
]),
([
     "action" : "只见$N站在万花丛中，双手捧心，"+(order[random(5)])+"「回眸一笑百媚生」"NOR"，$n顿时心若桃花，无欲无求，不知不觉中已被劲气侵入",
     "force"  : 600,
     "dodge"  : 300,
     "parry"  : 200,
     "lvl"    : 0,
     "damage"    : 500,
     "skill_name"  : "回眸一笑百媚生",
     "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="parry" || usage=="unarmed"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练美女神拳必须空手。\n");
	if ((int)me->query("max_neili") < 70000)
		return notify_fail("你的内力太弱，无法练美女神拳。\n");
	if ( (int)me->query("t") > 1 || (int)me->query("r") > 1  )
		return notify_fail("由于你的天性不够，你永远无法学到美女神拳。\n");
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
	if ((int)me->query("qi") < 10000)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够了！休息一下再练吧。\n");
	me->receive_damage("qi", 5);
	me->add("neili", -5);
	return 1;
}
mapping query_action(object me, object weapon)
{
   int i, j, level;
   level = (int) me->query_skill("meinv-shenquan",1);
   for(i = sizeof(action); i > 0; i--) {
       if(level > action[i-1]["lvl"]) {
           j = NewRandom(i, 20, level/4);
       if((int)me->query_skill("meinv-shenquan",1) > 100 && random(me->query("per")) > 20){
       return ([
               "action" : replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR)+NOR,
               "force" : 900,
               "dodge": 400,
               "parry" : 300,
               "damage" : 800,
               "damage_type" : "抓伤",
                ]);
       }
       else return action[j];
       }
   }
}

string perform_action_file(string action)
{
	return __DIR__"meinv-shenquan/" + action;
}

