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
	if(!skill||skill<=10)
		return notify_fail("��û��ѧ�����ʹ�ã�\n");
	if(me->query_temp("execration"))
		return notify_fail("���������䡣\n");
	if(me->query_temp("execration"))
		return notify_fail("���������䡣\n");
	if((int)me->query("mana") < 50 )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("��ľ���û�а취��Ч���У�\n");

	if(target&&target!=me)
		return notify_fail("�������޷�����������\n");
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
	   	 	msg=HIC"��ؼ���ʥ�ľ���\n"NOR;
	    		break;
		case 2:
	    		msg=HIC"ӵ��ĸ�ԵĴ����Ϣ\n"NOR;
	    		break;
        	case 3:
            		msg=HIC"�����Ȱ��Ĺػ�,�Ⱦ��Ұ�\n"NOR;
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
		me->receive_curing("kee", 100 + (int)me->query_skill("magic")/2 );
		me->add("kee", 100 + (int)me->query_skill("magic")/2 );
		if( (int)me->query("kee") > (int)me->query("eff_kee") ) 
			me->set("kee", (int)me->query("eff_kee"));
		msg="����������������������,��о��ö���\n";
		message_vision(msg,me);
		
		return 1;
	}
	return 1;
}
