//tianxin-blade  by:pipip
#include <ansi.h>
inherit SKILL;
int tydamage = this_player()->query("tydamage/blade")?this_player()->query("tydamage/blade"):this_player()->query_skill("tianxin-blade");

string type() { return "zhongji"; }
mapping *action = ({
([      "action" : "$N�Ų��ḡ�����е���б�ӣ�һʽ��"HIM"��������"NOR"������ʵʵ��$n������ʮ����",
        "force" : 660,
        "dodge" : 480,
        "parry" : 340,
        "damage" : tydamage,
        "skill_name" : "��������",
        "damage_type" : "����",
]),
([      "action" : "$Nֱ����$n����������һ������Ȼ����$n����󣬽���һ�ǡ�"HIG"����һ��"NOR"�����ȥ",
        "force" : 660,
        "dodge" : 480,
        "parry" : 340,
        "damage" : tydamage,
        "skill_name" : "����һ��",
        "damage_type" : "����",
]),
([      "action" : "$N����ǰ�ˣ�����$wʹһ�С�"HIB"����걩"NOR"����ֻ��һƬ������$n����",
        "force" : 660,
        "dodge" : 480,
        "parry" : 340,
        "damage" : tydamage,
        "skill_name" : "����걩",
        "damage_type" : "����",
]),
([      "action" : "$N�Ų�̫�飬����ƫ�棬һ�֡�"HIY"���΢��"NOR"����������ֱȡ$n�ĺ���"NOR,
        "force" : 660,
        "dodge" : 480,
        "parry" : 340,
        "damage" : tydamage,
        "lvl" : 1001,
        "skill_name" : "���΢��",
        "damage_type" : "����",
]),
([      "action" : "$N��Խ�ϰ�գ�ʹ����"HIB"����ֱ׹"NOR"�����У�һ����ʮ�������������$n�������ֲ���"NOR,
        "force" : 660,
        "dodge" : 480,
        "parry" : 340,
        "damage" : tydamage,
        "lvl" : 1100,
        "skill_name" : "����ֱ׹",
        "damage_type" : "����",
]),
([      "action" : "$N�Ų�̫���鸡��������Ӱ�����е���������֣�$nһʱ������$N���е��⾹Ȼ���������"NOR,
        "force" : 660,
        "dodge" : 480,
        "parry" : 340,
        "damage" : tydamage,
        "lvl" : 1200,
        "skill_name" : "�����п�",
        "damage_type" : "����",
]),
});


int valid_enable(string usage) { return usage == "blade"; }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("�㻹�����Ұѵ����ɡ�\n");
    if ((int)me->query("max_neili") < 20000)
        return notify_fail("�������������\n");
    if (me->query_skill("blade", 1)<=me->query_skill("tianxin-blade",1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
       if ((int)me->query_skill("yijing-force", 1) < 100)
        return notify_fail("����׾��񹦻��̫ǳ��\n");

        if (me->query("family/master_id")!="wuming laoren")
        return notify_fail("���е��������������˵ĵ����书����ֻ������ѧϰ��\n");
    if ((int)me->query_skill("tianxin-blade",1) > 300)
        return notify_fail("���׵����Ҿͽ̴˴������������׵����ϵĳɾ;�Ҫ�����Լ��ˡ�\n");
     return 1;
}


mapping query_action(object me, object weapon)
{
        int i, level;
    level   = (int) me->query_skill("tianxin-blade",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
      object weap,weap1;
      weap = victim->query_temp("weapon");
      weap1 = me->query_temp("weapon");
      if( damage_bonus < 100 ) return 0;

           if( (me->query_skill("tianxin-blade") > 450) && (me->query("neili") > 10000)
       && (victim->query_temp("weapon")) 
       && random(10) > 7){
       message_vision(HIY "ֻ��$N����" + weap1->name() + ""HIY"������һ�㣬һ������һ�����Է���" + weap->name() +""HIR"���Ļ���ֱð��\n" NOR, me ); 
       victim->start_busy(1);
       if ((me->query_skill("force")) > victim->query_skill("force") ){
       message_vision(HIR "\nǱ��ȫ���澢ȫ��һ�����£�ֻ�� ƹ! ��һ�����죬" + weap->name()
  + "��"+weap1->name()+""HIR"��$N"HIR"����ֱ�������Σ�$N"HIR"�鼱֮��ֻ�ÿ���Ӧս��\n" NOR, victim );
       weap->move(environment(me));
       weap->set("name", "�ϵ���"+ weap->query("name") );
       victim->reset_action();
       weap->set("value", 0);
       weap->set("weapon_prop", 0);
       weap->set("long", "һ�Ѷϵ������������жϿ����ƿ����룬�����Ǳ���������һ�������ġ�\n");
       } else {
      message_vision(HIY "\n$N����ж�־���" + weap->name()
   + ""HIY"˳�ŷ��������ת���£���"+weap1->name()+""HIY"�ϵ��澢ȫ��жȥ��\n" NOR, victim );
      victim->add("neili", -1000);
      }
      me->add("neili", - (20+random(30)));
      }
      if( me->query("neili") < 50000   ) return 0;
      if( random(10) < 2   ) return 0;

 //  �����ȼ�������
      if( me->query_skill("tianxin-blade",1)>4000
    && me->query_skill("yijing-force",1)>1500
  && me->query("zjb_dj/dj")>=25  ) {
              victim->receive_damage("qi", (damage_bonus ) * 2 , me);
return WHT "$N���ڵ��׾��񹦵ĸվ��뵶���з��������е����ں�Ϊһ������һ�ɻ�Ԫ����������$n������������\n" NOR;
  }      

 //  ����ȼ�������
      if( me->query_skill("tianxin-blade",1)>3000
    && me->query_skill("yijing-force",1)>1200
  && me->query("zjb_dj/dj")>=15 ) {
              victim->receive_damage("qi", damage_bonus  , me);
return YEL "$N�����е��ѵ�����ȼ���һ������ӳ�,�������۾�һ������$n����������\n" NOR;
  }      
      if( damage_bonus < 100 ) return 0;

 //  ���ĵȼ�������
      if( me->query_skill("tianxin-blade",1)>2000
    && me->query_skill("yijing-force",1)>1000
  && me->query("zjb_dj/dj")>=10 ) {
           victim->receive_damage("qi", (damage_bonus - 100)  , me);
return MAG "$N�����е��ѵ����ĵȼ�������׾��񹦷�������Ӱ��ס$n����������\n" NOR;
  }  

 //  ��3�ȼ�������
        if( me->query_skill("tianxin-blade",1)>1000
       && me->query("zjb_dj/dj")>=4
    && me->query_skill("yijing-force",1)>1000
&& (me->query("neili")*3) > victim->query("max_neili") ) {
                victim->receive_damage("qi", (damage_bonus - 100) / 3 , me);
return CYN "$N�����е����뷵豹��澳�磬����һ�д���������������$n����������\n" NOR;
  }  
 // �ڶ��ȼ�������
        if ( me->query_skill("tianxin-blade",1)>200
         && me->query_skill("yijing-force",1)>200
  && me->query("zjb_dj/dj")>=2        ) {
             victim->receive_damage("qi", (damage_bonus - 100) / 8 , me);
return RED "$N�����˹����׾��񹦵��ᾢ�������е�������ĵ����ڹ���$n������\n" NOR;
}    
}

int practice_skill(object me)
{
    return notify_fail("���е���ֻ��ͨ����"+HIC+"�����п�ʽ"+NOR+"����������\n");
}


string perform_action_file(string action)
{
        return __DIR__"tianxin-blade/" + action;
}


