#include <ansi.h>;

inherit SKILL;
#include "/kungfu/skill/eff_msg.h";

mapping *action = ({
([      "action":HIY "$N����$w"HIY"����ԲȦ,һʽ[��������]������������һ�㣬ֱ��$n"HIY"��$l��" NOR,
        "force" : 120,
        "dodge" : 120,
        "damage": 80,
        "lvl" : 0,
        "skill_name" : "��������",
        "damage_type":  "����"
]),
([      "action":WHT "$Nһʽ[��Ů�ɷ�]������$w"WHT"���Σ��ó��ޱ߽�Ӱ�����һ���׹⣬����ֱ��$n"WHT"��$l��" NOR,
        "force" : 150,
        "dodge" : 150,
        "damage": 110,
        "lvl" : 30,
        "skill_name" : "��Ů�ɷ�",
        "damage_type":  "����"
]),
([      "action":HIR "$NƮȻ������������������Σ�һʽ[��ң����]��$w"HIR"��Զ�ƽ���Ʈ��֮�����$n��" NOR,
        "force" : 120,
        "dodge" : 180,
        "damage": 110,
        "lvl" : 60,
        "skill_name" : "��ң����",
        "damage_type":  "����"
]),
([      "action":HIW "$N���������ƻã�Ʈ��֮�䣬һʽ[�������]��$w"HIW"�ó�һ���׹⣬ֱ��$n"HIW"��$l��" NOR,
        "force" : 180,
        "dodge" : 120,
        "damage": 150,
        "lvl" : 90,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action":MAG "$N��Цһ����һʽ[����������],����$w"MAG"����,��������ֿ��ֺݵ�����$n"MAG"��$l��" NOR,
        "force" : 220,
        "dodge" : 130,
        "damage": 200,
        "lvl" : 120,
        "skill_name" : "����������",
        "damage_type":  "����"
]),
([      "action":HIC "$N����Ծ��,ֱ�˶��£�һʽ����¥�޷��졹,����$w"HIC"��Ϊ��Ƭ��ë��Ľ�Ӱ������ǵص�����$n��" NOR,
        "force" : 230,
        "dodge" : 130,
        "damage": 210,
        "lvl" : 150,
        "skill_name" : "��¥�޷���",
        "damage_type":  "����"
]),
([      "action":HIM "$Nһʽ��ҹ��ɷ𡹣�˫�ֽ�$w"HIM"��ס���Խ�������ֱ����$n"HIM"��$l" NOR,
        "force" : 250,
        "dodge" : 170,
        "damage": 250,
        "lvl" : 180,
        "skill_name" : "ҹ��ɷ�",
        "damage_type":  "����"
]),
([      "action":YEL "$Nһʽ��������ʥ����$w"YEL"�������׳������Ȧ��ֱ����$n"YEL"��$l" NOR,
        "force" : 350,
        "dodge" : 200,
        "damage": 350,
        "lvl" : 210,
        "skill_name" : "������ʥ",
        "damage_type":  "����"
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
   return notify_fail("�˲���Ů��ֻ��ͨ���˲���������ߡ�\n");   

}
int practice_skill(object me)
{
            return notify_fail("�˲���Ů��ֻ��ͨ���˲���������ߡ�\n");   
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
      message_vision(HIM"$N����Ծ��"+weapon->name()+HIM"������ʽ�����д���$n"+weapon1->name()+HIM"�ı����ϣ�����������"+weapon1->name()+HIM"��ʱһ����\n"NOR, me,victim);
      if(random(me->query("str")) > victim->query("str")/3){           
           me->add("neili", -50);
           me->improve_skill("babulongnv-jian", 10 + random((int)me->query("int") * 8 - 8));
           message_vision(HIR"\n$Nֻ��������"+weapon1->name()+HIR"���˹ɲ�ͬ������ǣ��������һ���ѳֲ��������ַɳ���\n"NOR, victim);
           weapon1->unequip();
           weapon1->move(environment(victim));
           }
      else{
           me->improve_skill("babulongnv-jian", 10 + random((int)me->query("int") * 4 - 4));
           message_vision(HIY"$N�ۼ�������ƺ������·�������֪$n�Ƿ��и������ĺ��У�����"+weapon->name()+HIY"�������̣��Խ�Ϊ�ˣ��ƽ���$n�ľ�ɱ��\n"NOR, victim);
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
          message_vision(HIY"���$n��������$N����"+wp->name()+HIY"һ��һ����ж����һ��!\n"NOR,me,ob); 
             me->improve_skill("babulongnv-jian", 10 + random((int)me->query("int") * 8 - 8));

              j = -(damage*2+skill);
              }
           else if(neili < random(neili1)+damage && neili*2 > random(neili1)+damage){
              me->improve_skill("babulongnv-jian", 10 + random((int)me->query("int") * 8 - 8));

              message_vision(HIY"���$n��������$N����"+wp->name()+HIY"һȦ��ж����һ��!\n"NOR,me,ob); 
              j = -damage*3/2;               
              }
           else{
              message_vision(HIY"$N����"+wp->name()+HIY"�ص���ж����$nһС�������!\n"NOR,me,ob); 
               me->improve_skill("babulongnv-jian", 10 + random((int)me->query("int") * 8 - 8));

              j = -damage; 
              }           
                 return j;
       }          
}

