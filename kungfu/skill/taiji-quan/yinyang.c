// yingyang ������
// by suimeng 2015.4

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,damage;
	int orforce;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������ֻ�ܿ���ʹ�á�\n");		
	if( (int)me->query("neili") < 5000  ) 
		return notify_fail("�������������\n");
	
	if (!(int)me->query("breakup"))
        return notify_fail("���ζ�����δͨ,�޷�ʹ��!!\n"NOR,);

	if( (int)me->query("max_neili") < 200000 ) 
		return notify_fail("�������������\n");

    if( !wizardp(me) &&(int)me->query_skill("taiji-quan", 1) < 1300 )
		return notify_fail("���̫��ȭ������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("taiji-shengong", 1) < 1300 )
		return notify_fail("���̫���񹦲�����!���ܹ�ͨʹ�ã�\n");

    if ( !wizardp(me) && me->query_skill_mapped("force") != "taiji-shengong")
        return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

    if( !wizardp(me) && me->query_temp("weapon") )
        return notify_fail("�������ֲ���ʹ�ñ��ž�ѧ!\n");      
		
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");

	extra = me->query_skill("taiji-quan",1);
    extra += me->query_skill("taiji-shengong",1);	
	damage = me->query_skill("taiji-quan"); 
	damage += me->query_skill("taiji-shengong"); 
	damage += me->query_skill("force",1);
	damage += me->query_skill("unarmed",1);
	damage *= me->query("con");
	me->add("jiali",extra/2);
	orforce = (int) me->query("force");	
		
	weapon = me->query_temp("weapon");
	me->add("str", extra);
	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",extra);

        msg = WHT "$N��ͨ�䵱��ѧ��ʹ�����䵱�ľ�ѧ֮���裡\n" NOR;
        message_vision(msg, me, target);               

	msg = MAG  "$N˫�ֱ��˸�̫��ʽ��ԲȦ����������̫�����Ѵ������һ���Ķ������ľ��磬��\n"NOR;
	message_vision(msg,me,target);
	msg = WHT  "���һ���������" NOR;

if (random(3)==0) target->start_busy(5);

	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "���һ���������" NOR;
        target->receive_wound("qi", random(extra)*2);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT  "��������������" NOR;
	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "��������������" NOR;
        target->receive_wound("qi", random(extra)*2);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT  "��������������" NOR;
	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "��������������" NOR;
        target->receive_wound("qi", random(extra)*2);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT  "�����Ǿ�������" NOR;
	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "�����Ǿ�������" NOR;
        target->receive_wound("qi", random(extra)*2);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT  "�������������" NOR;
	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "�������������" NOR;
        target->receive_wound("qi", random(extra)*2);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
{
                msg = WHT"              ����˫��           !!\n"NOR;
		msg += MAG"��մ���������־��������־��������־���!!\n"NOR;
		damage = damage + random(damage);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
       msg += HIR"\n���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;
	message_vision(msg, me, target);
}
	    me->start_busy(4);
	    me->add("jiali",-extra/2);
        me->add("str", -extra);
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);
	    me->add("neili", -5000);
	return 1;
}
