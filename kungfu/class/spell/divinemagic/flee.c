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
	if(!skill||skill<=50)
		return notify_fail("��û��ѧ�����ʹ�ã�\n");
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

	msg = ""+me->name()+"�������ﲻ֪����˵Щʲ�ᡣ\n";
        message("vision",msg, environment(me), ({me}));
	tell_object(me,"�㿪ʼʩչ�ƶ���Ը......\n");
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
	   	 	msg=HIC"��ҫ��ҹ�յ��ǳ�,��ָ���ҵ���˷�֮·;\n"NOR;
	    		break;
		case 2:
	    		msg=HIC"�Ժ�ҹ֮��,����֮��������,�簡������һ�̰ɣ�\n"NOR;
	    		break;
        	case 3:
            		msg=HIC"�ƶ���Ը\n"NOR;
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
	int num;//��Χ���˵���Ŀ
	me->delete_temp("execration");
	num="/std/magic"->check_enemy_beside(me);//���me����Χ��û�е���.����Խ��,���ܵĻ����ԽС,������С��80%
	//���������magic�ļ̳��ļ�����
	num*=5;
	//num�����ֵ��20,��Сֵ��0
	//tell_object(me,"num is "+num+"\n");
	if(random(100)<num)
	{
		msg="$Nʩչ�ƶ���Ըʧ����\n";	
		message_vision(msg,me);
		return 1;
	}
	else
	{
		msg="$N��ʼʩչ�ƶ���Ը.....����һ�������ʧ��\n";
		message_vision(msg,me);
		me->remove_all_enemy();
		"/cmds/std/go"->do_flee(me);
		msg="$N�������л�������......\n";
		message_vision(msg,me);
		return 1;
	}
	return 1;
}


