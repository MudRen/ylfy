// hebi.c
// by dubei
#include <ansi.h>
inherit F_SSERVER;
private int remove_effect(object me, int skill);
int perform(object me, string arg)
{
    object weapon, weapon1, target;
    int skill, skill1;

    if(!arg) return notify_fail("�����˭һ��˫����赣�\n");
    if(!objectp(target = present(arg, environment(me))))
             return notify_fail("����û������ˡ�\n");

    if( !target->is_fighting() || !target->is_character() || !me->is_fighting() )
                return notify_fail("˫�����ֻ����ս����ʹ�á�\n");

    if(!living(target))
                return notify_fail(target->name()+"�Ѿ��޷�ս���ˡ�\n"); 
    if(target==me) return notify_fail("����Լ���赣�\n"); 
    if(me->is_fighting(target))
                return notify_fail("�����ں�"+target->name()+"����ء�\n");            

    weapon = me->query_temp("weapon");  
    weapon1 = target->query_temp("weapon");  

    if(!weapon || weapon->query("skill_type") != "sword"
      || me->query_skill_mapped("sword") != "yunv-jian"
      || me->query_skill_mapped("parry") != "yunv-jian")
        return notify_fail("��Ҫ����Ů����Ϊsword,parry�����á�˫����赡���\n");

    if(!weapon1 || weapon1->query("skill_type") != "sword"
      || target->query_skill_mapped("sword") != "yunv-jian"
      || target->query_skill_mapped("parry") != "yunv-jian")
        return notify_fail(target->name()+"Ҫ����Ů����Ϊsword,parry�����á�˫����赡���\n");

    skill = me->query_skill("yunv-jian", 1);
    skill1 = target->query_skill("yunv-jian", 1);
    
    if(skill < 120 )
        return notify_fail("�����Ů�����ȼ�����������ʹ�á�˫����赡���\n");
    
    if( skill1 < 120 )
	return notify_fail( target->name()+"����Ů�����������죬�޷��������ʹ�á�˫����赡���\n");

    if((int)me->query_skill("yunv-xinfa", 1) < 120 )
        return notify_fail("�����Ů�ķ��ȼ�����������ʹ�á�˫����赡���\n");       

    if((int)target->query_skill("yunv-xinfa", 1) < 120 )
        return notify_fail(target->name()+"����Ů�����������죬�޷��������ʹ�á�˫����赡���\n");       
    
    if((int)me->query("neili") < 300 )
        return notify_fail("����������̫��������ʹ�á�˫����赡���\n");

    if((int)target->query("neili") < 300 )
        return notify_fail( target->name()+"��������̫��������ʹ�á�˫����赡���\n");

    if((int)me->query("eff_neili") < 500 )
        return notify_fail("����������̫��������ʹ�á�˫����赡���\n");

    if((int)target->query("eff_neili") < 500 )
        return notify_fail("����������̫��������ʹ�á�˫����赡���\n");

    if(me->query_temp("gumu_hebi")) 
        return notify_fail("���Ѿ���ʹ�á�˫����赡��ˡ�\n");

    if(target->query_temp("gumu_hebi")) 
        return notify_fail(target->name()+"�Ѿ���ʹ�á�˫����赡��ˡ�\n");
    
    if(me->query_temp("gmhebi_target")){
          if(me->query_temp("gmhebi_target")==target)
                return notify_fail("���Ѿ����ú�"+target->name()+"˫����赵�׼���ˡ�\n");
          else{               
               tell_object(me->query_temp("gmhebi_target"), YEL+me->name()+"�������������˫������ˡ�\n"NOR); 
               me->delete_temp("gmhebi_target");
               }
          }
    if(target->query_temp("prepare_gmhebi")) {
	message_vision(HIC"$N��Хһ����������"+weapon->name()+"һ�ڣ��������$nһ���źš�\n"NOR,me,target);
        message_vision(HIC"$n������"+weapon->name()+"һ�ڣ�����$N��"+weapon1->name()+"�ϣ�˫����ӣ���ʱ��â���䣬������أ�\n"NOR,me,target);
        me->delete_temp("prepare_gmhebi", 1);     
        me->delete_temp("gmhebi_target", 1);
        me->set_temp("gumu_hebi", target); 
        target->set_temp("gumu_hebi", 1); 
        me->add("neili", -300);
        target->add("neili", -300);
        me->add("jing", -50);
        target->add("jing", -50);
        me->add_temp("apply/attack", skill);
        me->add_temp("apply/dexerity", skill/15);
        target->add_temp("apply/attack", skill1);
        target->add_temp("apply/dexerity", skill1/15);
        me->start_call_out( (: call_other, __FILE__, "check_fight", me, target, skill :), 1);
        target->start_call_out( (: call_other, __FILE__, "check_fight", target, me, skill1 :), 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), (skill+skill1)/2);
        target->start_call_out( (: call_other, __FILE__, "remove_effect", target, skill1 :), (skill+skill1)/2);
        return 1;
        }
    message_vision(YEL"$N������"+weapon->name()+"һ�ᣬ��ʾ$n��$Pһ������˫����赡�\n"NOR,me,target);
    tell_object(target, YEL"�����Ը���"+me->name()+"����˫���ͱڣ���Ҳ��"+me->name()+"��һ�� ( perform hebi player<name> ) �����\n"NOR); 
    me->set_temp("prepare_gmhebi", 1);     
    me->set_temp("gmhebi_target", target);
    return 1;
}

void check_fight(object me, object target, int skill, int skill1)
{
    object weapon;      

    if(!objectp(weapon = me->query_temp("weapon")) 
     || !objectp(weapon = target->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "blade")
    {
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), 1);
    target->start_call_out( (: call_other, __FILE__, "remove_effect", target, skill :), 1);
    remove_effect(target, 1);
    remove_effect(me, 1);
	}
    else if( !present(target->query("id"), environment(me)) 
	  || !me->is_fighting() 
	  || !living(target) 
	  || !target->is_fighting()
          || target->is_ghost() 
	  || me->is_ghost() 
	  || !living(me)) {

    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), 1);
    target->start_call_out( (: call_other, __FILE__, "remove_effect", target, skill1 :), 1);
    remove_effect(target, 1);
    remove_effect(me, 1);
	}
    else {
	call_out("check_fight", 1, me, target, skill);
	 return;
	}
}
private int remove_effect(object me, object target)
{
    int skill;
    me->add_temp("apply/attack", -skill/15);
    me->add_temp("apply/dexerity", -skill/15);
    me->delete_temp("shuangdao_hebi");
    me->delete_temp("gmhebi_target");
    me->delete_temp("prepare_gmhebi");     
    target->delete_temp("gumu_hebi");
    target->delete_temp("prepare_gmhebi");  
    target->delete_temp("gmhebi_target");   
    tell_object(me, HIR"$N��˫�������ᣬ����Ҳ�ָ������ˡ�\n"NOR);
    tell_object(target, HIR"$n��˫�������ᣬ����Ҳ�ָ������ˡ�\n"NOR);
}
 