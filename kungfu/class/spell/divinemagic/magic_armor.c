// magic_armor ħ����

#include <ansi.h>
inherit SSERVER;
int do_hit(object me,int skill);
int do_execration(object me,int i);

int cast(object me,object target)
{
	string msg;
	int  skill;
    	
	if(me->query_temp("execration"))
		return notify_fail("���������䡣\n");
        skill=me->query_skill("magic");
        if(!skill||skill<60)
	    return notify_fail("��û����������ħ����\n");

	if(me->query_temp("magic_armor"))
		return notify_fail("���Ѿ�������ħ������......\n");
	if(me->query("mana")<=50)
		return notify_fail("ħ������Ҫ50�㷨�����ܺ���������\n");
	me->add("mana",-50);

	msg = ""+me->name()+"�������ﲻ֪����˵Щʲ�ᡣ\n";
    	message("vision",msg, environment(me), ({me}));
	tell_object(me,"�㿪ʼ����ħ���ܵ�����......\n");
	me->set_temp("execration",1);
	call_out("do_execration",1,me,1);
	return 1;
}


int do_execration(object me,int i)
{
	string msg;
	int skill;
	switch(i)
	{
		case 1:
	    		msg=HIC"��ʥ��������.\n"NOR;
	    		break;
		case 2:
	    		msg=HIC"����Ϊ��֮��\n"NOR;
	    		break;
        	case 3:
            		msg=HIC"�ػ����������ͽ\n"NOR;
			break;
		default: 
			break;
	}
	tell_object(me,msg);
        i++;
        if(i<4&&i>=0)  call_out("do_execration",1,me,i);
	else 
	{
  		skill=me->query_skill("magic",1);
        	if(!skill) return 1;
        	call_out("do_hit",1,me,skill);
	    	return 1;
    	}
	return 1;
}



int do_hit(object me,int skill)
{
	string msg;
	me->delete_temp("execration");
	me->set_temp("magic_armor",2);// ������2��ϵͳ�ļ�/feature/damage.c�й�}
    	msg="$N����ħ����......\n";
    	message_vision(msg,me);
    	if(me->is_fighting()&&userp(me))
    	me->start_busy(me->query_busy()+2);

}

