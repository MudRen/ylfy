//а����ɱȭ��yansha-quan.c
inherit SKILL;
#include <ansi.h>
mapping *action = ({
([ "action":  
"$N��һ��������������ȼ��"+BLINK""+HIR"��ɫ�Ļ���"NOR"��$N��ȭ���գ���ǰ\nһ�������ȵĻ�����ͬ������$n��ȥ��",
"dodge":  -40,
"parry": -30,
"force": 230,
  "damage_type": "����",
]),
 ([ "action":  
"$N����˫�֣�"+BLINK""+HIR"��ɫ�Ļ���"NOR"����ȼ��������$N��˫��һ����\n����ǰһ�ƣ�����������غϳ�һ���޴���������У���������\n�س���$n��ȥ��",
"dodge":  -20,
"parry": -50,
"force": 280,
 "damage_type": "�������",
]),
([ "action":  
"$Nͷ�ϵ�"+BLINK""+HIC"а��"NOR"ͻȻ��â��ʢ������ȼ��\n"+BLINK""+HIR"���ɫ�Ļ���"NOR"����Χ�Ŀ�������$N����ȥһ�㣡\nͻȻ$N���һ���������Ѿ�����$n����ǰ���������ַ�������\n����̶̵��������Ѿ�������"+BLINK""+HIY"���ٶ�ʮ��ȭ"NOR"��",
"dodge":  -80,
"parry":  -30,
"force":  654,
"damage_type": "ȭ��",
]),
([ "action":  
"$N����һ�Σ����������$N��$n���һ������æ����ǰ���Ǹ���û��\n��ȴ�Ǹ��ٵġ�����ʱ��$N�Ѿ�������$n�����һ��������\n��ն��$n��ͷ����������ȭһ����������"+BLINK""+HIC"����ɫ����"NOR"����$n�ĺ�����",
"dodge":  -30,
"parry":  -40,
"force":  310,
"damage_type": "�˺�",
]),
([ "action":  
"$NԾ����գ�ͷ��"+BLINK""+HIC"а��"NOR"�������صĹ�â��$Nһ����������\n����$n���Ͽգ�������������߳��˶�ʮ�ߣ�Ȼ�����һ�գ���\n�Ŵ����������֮�ƹ���$n���ؿڣ�",
"dodge"  : -70,
"parry"  : -5,
"force"  : 350,
"damage_type" : "�˺�",
]),
([ "action":  
"$Nͷ�ϵ�"+BLINK""+HIC"а��"NOR"�ٶ��ſ������Ż���ȼ���ɫ������\n������$N���һ����ƾ��ƵƵ������ȭ����������Ż��������\n������������һ������$n��",
"dodge"  : -20,
"parry"  :  15,
"force"  : 260,
"damage_type" : "����",
]),
});
int valid_learn(object me)
{    
     if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
     return notify_fail("��а����ɱȭ��ÿ��֣���Ȼ�ջ��˶�����ô�죿\n");
     if( (int)me->query("max_kee") < 399 )
     return notify_fail("�������ڵ������������ܲ���а����ɱȭ������ʹ�ࡣ\n");
     if( (int)me->query("max_sen") < 399 )
     return notify_fail("�������ڵľ���Ҫ����а����ɱȭ��ֱ����������ϧ�����ɣ�\n");
     if( (int)me->query("combat_exp") < 20000000 )
     return notify_fail("���ս��������̫�٣�û�취��ϰа����ɱȭ��\n");
{
   message_vision(HIR"$Nͷ�ϵ�а��ͻȻ�ų���ֵĹ⣬����$N������ȼ��������$N���ɵزҽ���һ����\n"NOR,me);
   me->receive_damage("kee", 500 - (int)me->query_skill("unarmed", 1) );
   me->receive_damage("sen", 100 );
   write ("����������Ļ���û��á�\n");
}
   return 1;
}
int valid_enable(string usage)
{
 return usage=="unarmed"||usage=="parry";
}
mapping query_action(object me, object weapon)
{
     return action[random(sizeof(action))];
}
int practice_skill(object me)
{  
   if( (int)me->query_skill("unarmed", 1 ) < 70 )
   return notify_fail("ȭ���Ļ�����û��ã���ô����\n");
   if( (int)me->query("max_kee") < 350 )
   return notify_fail("�������ڵ������������ܲ���а����ɱȭ������ʹ�ࡣ\n");
   if( (int)me->query("max_sen") < 350 )
   return notify_fail("�������ڵľ���Ҫ����а����ɱȭ��ֱ����������ϧ�����ɣ�\n");
   if( (int)me->query("combat_exp") < 20000000 )
   return notify_fail("���ս��������̫�٣�û�취��ϰа����ɱȭ��\n");
{
   message_vision(HIR"$Nͷ�ϵ�а��ͻȻ�ų���ֵĹ⣬����$N������ȼ��������$N���ɵزҽ���һ����\n"NOR);
   me->receive_damage("kee", 500 - (int)me->query_skill("unarmed", 1) );
   me->receive_damage("sen", 100 );
   write ("����������Ļ���û��á�\n");
}
   if( (int)me->query("sen") < 100)
   return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
   if( (int)me->query("kee") < 100 )
   return notify_fail("���������������ˣ���Ϣһ�������ɡ�\n");
   if( (int)me->query("force") < 50 )
   return notify_fail("������������ˡ�\n");
   me->receive_damage("sen", 60);
   me->add("force", -20);
   return 1;
}
string perform_action_file(string func)
{
    return __DIR__"yansha-quan/" + func;
}
void skill_improved(object me)
{
   tell_object (me, "�ۣ��������ѽ��˧ѽ��\n");
}
