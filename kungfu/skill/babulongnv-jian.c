#include <ansi.h>;

inherit SKILL;
#include "/kungfu/skill/eff_msg.h";

mapping *action = ({
([      "action":HIY "$N手中$w"HIY"连划圆圈,一式[天龙出云]，剑气如蛟龙一般，直刺$n"HIY"的$l。" NOR,
        "force" : 120,
        "dodge" : 120,
        "damage": 80,
        "lvl" : 0,
        "skill_name" : "天龙出云",
        "damage_type":  "刺伤"
]),
([      "action":WHT "$N一式[龙女成佛]，手中$w"WHT"连晃，幻出无边剑影，蓦的一道白光，剑尖直刺$n"WHT"的$l。" NOR,
        "force" : 150,
        "dodge" : 150,
        "damage": 110,
        "lvl" : 30,
        "skill_name" : "龙女成佛",
        "damage_type":  "刺伤"
]),
([      "action":HIR "$N飘然出尘，左手六阳掌虚晃，一式[皆遥见彼]，$w"HIR"似远似近，飘忽之间刺向$n。" NOR,
        "force" : 120,
        "dodge" : 180,
        "damage": 110,
        "lvl" : 60,
        "skill_name" : "皆遥见彼",
        "damage_type":  "刺伤"
]),
([      "action":HIW "$N身形似真似幻，飘忽之间，一式[人与非人]，$w"HIW"幻出一道白光，直射$n"HIW"的$l。" NOR,
        "force" : 180,
        "dodge" : 120,
        "damage": 150,
        "lvl" : 90,
        "skill_name" : "人与非人",
        "damage_type":  "刺伤"
]),
([      "action":MAG "$N阴笑一声，一式[阿修罗灭世],手中$w"MAG"反撩,万道剑气又快又狠的射向$n"MAG"的$l。" NOR,
        "force" : 220,
        "dodge" : 130,
        "damage": 200,
        "lvl" : 120,
        "skill_name" : "阿修罗灭世",
        "damage_type":  "刺伤"
]),
([      "action":HIC "$N腾身跃起,直扑而下，一式「迦楼罗飞天」,手中$w"HIC"化为万片羽毛般的剑影，铺天盖地的射向$n。" NOR,
        "force" : 230,
        "dodge" : 130,
        "damage": 210,
        "lvl" : 150,
        "skill_name" : "迦楼罗飞天",
        "damage_type":  "刺伤"
]),
([      "action":HIM "$N一式「夜叉渡佛」，双手将$w"HIM"握住，以剑代刀，直劈向$n"HIM"的$l" NOR,
        "force" : 250,
        "dodge" : 170,
        "damage": 250,
        "lvl" : 180,
        "skill_name" : "夜叉渡佛",
        "damage_type":  "刺伤"
]),
([      "action":YEL "$N一式「天王朝圣」，$w"YEL"连划，套出万道剑圈，直罩向$n"YEL"的$l" NOR,
        "force" : 350,
        "dodge" : 200,
        "damage": 350,
        "lvl" : 210,
        "skill_name" : "天王朝圣",
        "damage_type":  "刺伤"
]),
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}
mapping query_action(object me, object weapon)
{
        int i, level, neili, force;
        level   = (int) me->query_skill("babulongnv-jian",1);
        force = me->query_skill("force");
        neili = me->query("neili");

           for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int valid_learn(object me)
{
   return notify_fail("八部龙女剑只能通过八部飞天来提高。\n");   

}
int practice_skill(object me)
{
            return notify_fail("八部龙女剑只能通过八部飞天来提高。\n");   
}

string perform_action_file(string action)
{
        return __DIR__"babulongnv-jian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    object weapon, weapon1;     
    weapon = me->query_temp("weapon");
    weapon1= victim->query_temp("weapon");

    if(weapon1 && me->query_skill("babulongnv-jian", 1) > 150 && me->query("jiali")
       && me->query("max_neili") > 1200 && me->query("neili") > 1000 && random(15) >= 6
       && me->query_int() > 30
       && me->query_skill_mapped("parry") == "babulongnv-jian"
       && random(me->query("combat_exp") > victim->query("combat_exp")/3)){
      message_vision(HIM"$N飞身跃起，"+weapon->name()+HIM"连出八式，招招刺向$n"+weapon1->name()+HIM"的背脊上，劲力传出，"+weapon1->name()+HIM"登时一沉！\n"NOR, me,victim);
      if(random(me->query("str")) > victim->query("str")/3){           
           me->add("neili", -50);
           me->improve_skill("babulongnv-jian", 10 + random((int)me->query("int") * 8 - 8));
           message_vision(HIR"\n$N只觉得手中"+weapon1->name()+HIR"被八股不同的力道牵引环流，一个把持不定，脱手飞出！\n"NOR, victim);
           weapon1->unequip();
           weapon1->move(environment(victim));
           }
      else{
           me->improve_skill("babulongnv-jian", 10 + random((int)me->query("int") * 4 - 4));
           message_vision(HIY"$N眼见这八招似乎毫无章法，但不知$n是否有更厉害的后招，手中"+weapon->name()+HIY"连劈带刺，以进为退，破解了$n的绝杀！\n"NOR, victim);
           victim->start_busy(1);
           }
    }
}

int ob_hit(object ob, object me, int damage)
{
        object wp,wp1;     
        int j,skill, neili, neili1;
        wp = me->query_temp("weapon");
        wp1 = ob->query_temp("weapon");
        skill = me->query_skill("babulongnv-jian", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
 
      if(me->query("jiali") && random(skill) > random(ob->query_skill("parry", 1)) 
         && me->query("combat_exp") > ob->query("combat_exp")/3
         && me->query_skill_mapped("parry") == "babulongnv-jian"
         && me->query_skill("babulongnv-jian", 1) > 150
         && neili > 300 
         && objectp(wp) && wp->query("skill_type")== "sword"
         && !ob->query("env/invisibility"))
         {        
           if(neili >= neili1){
          message_vision(HIY"结果$n的力道被$N手中"+wp->name()+HIY"一挡一挑，卸在了一旁!\n"NOR,me,ob); 
             me->improve_skill("babulongnv-jian", 10 + random((int)me->query("int") * 8 - 8));

              j = -(damage*2+skill);
              }
           else if(neili < random(neili1)+damage && neili*2 > random(neili1)+damage){
              me->improve_skill("babulongnv-jian", 10 + random((int)me->query("int") * 8 - 8));

              message_vision(HIY"结果$n的力道被$N手中"+wp->name()+HIY"一圈，卸掉了一半!\n"NOR,me,ob); 
              j = -damage*3/2;               
              }
           else{
              message_vision(HIY"$N手中"+wp->name()+HIY"回挡，卸掉了$n一小半的力道!\n"NOR,me,ob); 
               me->improve_skill("babulongnv-jian", 10 + random((int)me->query("int") * 8 - 8));

              j = -damage; 
              }           
                 return j;
       }          
}

