
#include <ansi.h>
inherit F_SSERVER;

int exert(object me, object target)
{
	int sp, dp,max_suck,skill,top_limit;
	int skill_limit=0;
	if ( target == me )
		target = offensive_target(me);
	
	if( !objectp(target) || environment(me)!=environment(target)||target->query("id") == "mu ren"|| target->query("id") == "tong ren")
		return notify_fail("��Ҫ��˭��������\n");
	
	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ������������δ�ܻ�ת��\n");
	
	if (target->query("age") < 18)
		return notify_fail("С��������ʲô����?\n");
	
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʩ�ñ�ڤ�񹦣�\n");
	
	skill=(int)me->query_skill("beiming-shengong",1);
	
	//suimeng ����2015.9.24,ԭ��Ϊһ����ڤ��800
	if(  skill < 50 || me->query("max_neili") > skill*22000 )
		return notify_fail("��ı�ڤ�񹦹���������������ȡ�Է����������\n");
	
	if( (int)me->query("neili",1) < 200 )
		return notify_fail("�����������������ʹ�ñ�ڤ�񹦡�\n");
	
	if( (int)target->query("max_neili") < 60  || !living(target))
		return notify_fail( target->name() + "�Ѿ�������ɢ�����Ѿ��޷�����������ȡ�κ������ˣ�\n");
	
	if(me->is_busy()) 
		return notify_fail("��������æ����ȡ������\n");
	
	if(!me->query("xy_huiyuan") && me->query("max_neili") >=330000)
		return notify_fail(HIY"ֻ�л�Ա������ȡ33������������\n"NOR);

	if ( !me->query("xy_huiyuan") && target->query("id") == "nai niu" && domain_file(base_name(environment(me))) == "party" )
		return notify_fail(HIY"�������ţֻ�ṩ��ע���Աʹ�ã����޷���ȡ��\n"NOR);
	
	message_vision(HIM "$N����Ȼ�ӿ죬����ֱ�����͵ض�׼$n�����д�Ѩ������ȥ��\n\n" NOR, me, target );
	
	if ( living(target) )
	{
		me->kill_ob(target);
		target->kill_ob(me);
	}
	
	if( wiz_level(target)>0 || (int)target->query("max_neili") <= 0 || (int)target->query("no_suck"))
		return notify_fail( target->name() + "û���κ�������\n");
	
	sp = me->query_skill("force") + me->query_skill("lingboweibu",1);
	dp = target->query_skill("force") + target->query_skill("dodge",1);
	top_limit = (int)me->query("max_neili") / (int)target->query("max_neili");
	
	me->set_temp("sucked", 1);
	
	if (( random(sp) > random(dp) ) )
	{
		tell_object(target, HIY "��پ�ȫ��������ˮ����ѭ�׷�й������\n" NOR);
		tell_object(me, HIG "�����" + target->name() + "������������ԴԴ���������˽�����\n" NOR);
		
		max_suck=(int)target->query("max_neili") - (int)me->query("max_neili")/2;       	
	if (max_suck<1) max_suck=1+random(2);
	else max_suck/=15;
	if (max_suck > 2000 ) max_suck=2000;    	
	max_suck=max_suck+skill + target->query("jiali");
	max_suck/=20;
	
	if ( target->query("max_neili") < max_suck ) max_suck=target->query("max_neili");
	if (me->query("max_neili") > 200000 ) max_suck = (skill/40)+10;
	if (userp(target)) max_suck/=7;
	if(skill_limit>0) max_suck=skill/200;
	
	target->add("max_neili",  -max_suck );
	me->add("neili",-max_suck*3/2);
	if ( me->query("max_neili") > 200000) {
		me->add("max_neili", max_suck); 
                
	}
	else if ( me->query("max_neili") <= 200000)
	{
	    if (top_limit>1)	
		me->add("max_neili", (max_suck / 5 ) + 1);                 	
	    else {
		me->add("max_neili",  max_suck*2 );
	    }  	
	}
	if ( target->query("max_neili") <1 )
	    target->set("max_neili",0);
	if ( me->query("neili") <1 )
	    me->set("neili",0);
		
		me->start_busy(random(5)+2);
		target->start_busy(random(3)+1);
	}
	else
	{   
		message_vision(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
		me->start_busy(4);
	}
	
	call_out("del_sucked", 6, me);
	return 1;
}
void del_sucked(object me)
{ 
	if ( !objectp(me) ) return;
	if ( me->query_temp("sucked") ) me->delete_temp("sucked");
}


