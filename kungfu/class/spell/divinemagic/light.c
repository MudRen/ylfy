// ������

#include <ansi.h>

inherit SSERVER;
int do_execration(object me,object target,int i);
int do_hit(object me,object target,int skill);

int cast(object me, object target)
{


	int  skill;
	string msg;
	skill=me->query_skill("divinemagic",1);
	if(!skill||skill<=20)
		return notify_fail("�㻹�޷�����������������\n");
	if(me->query_temp("execration"))
		return notify_fail("���������䡣\n");
	if(me->query_temp("execration"))
		return notify_fail("���������䡣\n");
	if((int)me->query("mana") < 50 )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("��ľ���û�а취��Ч���У�\n");
	if(me->query_temp("cast_light")) return notify_fail("���Ѿ�ʩչ��������\n");
	me->add("mana", -50);
	me->receive_damage("sen", 10);

	msg = ""+me->name()+"�������ﲻ֪����˵Щʲ�ᡣ\n";
        message("vision",msg, environment(me), ({me}));
	tell_object(me,"�����Ժ�������������������,����������......\n");
	me->set_temp("execration",1);
	call_out("do_execration",1,me,target,1);
	return 1;
}


int do_execration(object me,object target,int i)
{
	string msg;
	int skill;
	switch(i)
	{
		case 1:
	   	 	msg=HIC"���ܵĹ�֮��\n"NOR;
	    		break;
		case 2:
	    		msg=HIC"������������ҫ�۵Ĺ�â\n"NOR;
	    		break;
        	case 3:
            		msg=HIC"��������ڵĴ��\n"NOR;
            		break;
		default: 
			break;
	}
	tell_object(me,msg);
        i++;
    	if(i<4&&i>=0) call_out("do_execration",1,me,target,i);
	else 
	{
  	    	skill=me->query_skill("divinemagic",1);
        	if(!skill) return 1;
            	call_out("do_hit",1,me,target,skill);
	    	return 1;
    	}
	return 1;
}



int do_hit(object me,object target,int skill)
{

	string msg;
	if(!objectp(me)) return 1;
	me->delete_temp("execration");
	if(random(100)<1)
	{
		msg="$N��������ʧ����\n";	
		message_vision(msg,me);
		return 1;
	}
	else
	{
		msg="����$N�������������������,\n"
		    "$N���Ͽ�ʼ����������͵Ĺ�â,\n"
		    "��Χ�ľ��･����������\n";
		message_vision(msg,me);
		me->set_temp("cast_light",1);
        	//add_light(me,1); δ֪�ĺ������ô�����ʱ���ٲ�
		if(me->is_fighting())
			me->start_busy(me->query_busy()+2);
		me->start_call_out((: call_other, __FILE__,"remove_effect",me :),skill*2);
	}
	return 1;
}


void remove_effect(object me)
{      
	string msg;
	if (!me) return;
    	me->delete_temp("cast_light");
    	// add_light(me,-1); δ֪�ĺ������ô�����ʱ���ٲ�
    	msg=CYN"$N�����彥����������ȥ���ָ���������\n"NOR;
    	message_vision(msg,me);
    	return;
    
}
