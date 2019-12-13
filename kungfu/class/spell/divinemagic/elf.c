// �ػ�����.�þ����һֱ�������,ֱ�����������������.

#include <ansi.h>

inherit SSERVER;
int do_execration(object me,object target,int i);
int do_hit(object me,object target,int skill);
int set_elf_skill(object me,object elf,int skill);

int cast(object me, object target)
{


	int  skill;
	string msg;
	skill=me->query_skill("divinemagic",1);
	if(skill>=200)
		return notify_fail("��ǿ���ħ���������Ա����Լ�������,������Ҫ�������ػ���.\n");
	if(me->query_temp("execration"))
		return notify_fail("���������䡣\n");
	if(me->query_temp("execration"))
		return notify_fail("���������䡣\n");
	if((int)me->query("mana") < 100 )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 50 )
		return notify_fail("��ľ���û�а취��Ч���У�\n");

	if(objectp(me->query_temp("cast_elf"))) return notify_fail("�����ľ����Ѿ������ٻ�������\n");
	me->add("mana", -100);
	me->receive_damage("sen", 50);

	msg = ""+me->name()+"�������ﲻ֪����˵Щʲ�ᡣ\n";
        message("vision",msg, environment(me), ({me}));
	tell_object(me,"�����Ժ��������ػ�ʥ���ħ������,����������......\n");
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
	   	 	msg=HIC"�����ľ���\n"NOR;
	    		break;
		case 2:
	    		msg=HIC"�����ҵ�����\n"NOR;
	    		break;
        	case 3:
            		msg=HIC"��������Զ�ŵĵ���Լ\n"NOR;
            		break;
		case 4:
			msg=HIC"�ػ��������\n"NOR;
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
	object elf,room;
	if(!objectp(me)) return 1;
	me->delete_temp("execration");
	
	if(random(100)<1)
	{
		msg="$N���ػ�ʥ��ʧ����\n";	
		message_vision(msg,me);
		return 1;
	}
	else
	{
		msg="$N���ػ�ʥ�������������,һֻ���������$N���\n";
		message_vision(msg,me);
		if(me->is_fighting())
			me->start_busy(me->query_busy()+3);
		elf=new("/daemon/class/divine/elf");
		if(!elf)
		{
			tell_object(me,"�����ļ�������,��֪ͨ��ʦ\n");
			return 1;
		}
		elf->set("owner",me);
		me->set_temp("cast_elf",elf);
		room=environment(me);
		elf->move(room);
		elf->set_leader(me);
		elf->invocation(me);
		set_elf_skill(me,elf,skill);
		
	}
	return 1;
}

int set_elf_skill(object me,object elf,int skill)
{
	elf->set_skill("unarmed",skill);
	elf->set_skill("parry",skill);
	elf->set_skill("dodge",skill);
	elf->set_temp("apply/armor",10+random(40));
	elf->set_temp("apply/damage",10+random(70));
	elf->set("combat_exp",skill*10000>1000000?skill*10000:1000000);
}

