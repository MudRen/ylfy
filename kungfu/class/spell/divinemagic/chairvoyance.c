// feeblebolt.c

#include <ansi.h>

inherit SSERVER;
int do_execration(object me,object target,int i);
int do_hit(object me,object target,int skill);

int cast(object me, object target)
{


	int  skill;
	string msg;
	skill=me->query_skill("divinemagic",1);
	if(!skill||skill<=100)
		return notify_fail("�㻹û��ѧ�����ʹ������ͨ\n");
	if(me->query_temp("execration"))
		return notify_fail("���������䡣\n");
	if(me->query_temp("execration"))
		return notify_fail("���������䡣\n");
	if((int)me->query("mana") < 50 )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("��ľ���û�а취��Ч���У�\n");

	me->add("mana", -50);
	me->receive_damage("sen", 10);
        if(!target||me==target||!userp(target)) return notify_fail("�Ҳ���������\n");
	msg = ""+me->name()+"�������ﲻ֪����˵Щʲ�ᡣ\n";
        message("vision",msg, environment(me), ({me}));
	tell_object(me,"�����������������ͨ,��ʼ������������......\n");
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
	   	 	msg=HIC"�����ҵľ�����\n"NOR;
	    		break;
		case 2:
	    		msg=HIC"�������˵��������\n"NOR;
	    		break;
        	case 3:
            		msg=HIC"��Զ������Ϣ\n"NOR;
            		break;
		case 4:
		        msg=HIC"�����ҵ���ǰ\n"NOR;
		default: 
			break;
	}
	tell_object(me,msg);
        i++;
    	if(i<5&&i>=0) call_out("do_execration",1,me,target,i);
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
	object room;
	
	me->delete_temp("execration");
	
	if(!target||!objectp(target)||userp(target))
		return notify_fail("���������������,������ȷ�޷���֪������ȷ�еĵط�\n");
	room=environment(target);
	if(!room) return notify_fail("���������������,������ȷ�޷���֪������ȷ�еĵط�\n");
	if(room->query("no_magic"))
               	return notify_fail("���������������,�㷢�ֶԷ����ڵ���һ��ħ�����ϵ�ס��������ߡ�\n");
	if(random(100)<1)
	{
		msg="$N������ͨʧ����\n";	
		message_vision(msg,me);
		return 1;
	}
	else
	{
		
		msg="���������������,�㽥���������"+target->name()+"���ڵĵط�......\n";
		tell_object(me,msg);
		"/cmds/std/look"->look_room(me, environment(target));
                tell_object(target,"��е����ӷ������ڰ���������˫�۾������㣡\n"
                       "����ϸ�ؿ���һ�����ܣ�ȴʲôҲû�У�\n");
		return 1;
	}
	return 1;
}


