// say.c by macrohard 2000

#include <ansi.h>

inherit F_CLEAN_UP;
void delete_busy();
int main(object me, string arg)
{
	if (!arg)
	{
		if(me->is_busy() && me->query_temp("say_busy"))
		{
			if(!me->is_ghost() && userp(me))
				me->add("jing",-5);

			write("����������̫�죬 һ��С��ҧ������ͷ!\n");
			return 1;
		}
		
		if( time()-me->query_temp("say1")<1 && !wizardp(me) )
		{
			me->start_busy(4);
			me->set_temp("say_busy",1);
			remove_call_out("delete_busy");
			call_out("delete_busy",4);
			
			if(!me->is_ghost() && userp(me))
				me->add("jing",-5);
			
			write("�𼱣�����˵!\n");
			return 1;
		}
		
		write("���������ﲻ֪����˵Щʲô��\n");
		message("sound", me->name() + "�������ﲻ֪����˵Щʲô��\n",environment(me), me);
		me->set_temp("say1",time());
		return 1;
	}
	
	if(me->is_busy() && me->query_temp("say_busy"))
	{
		if(!me->is_ghost() && userp(me))
			me->add("jing",-5);
		
		write("��˵��̫�죬һ��С��ҧ������ͷ!\n");
		return 1;
	}
	
	if( time()-me->query_temp("say1")<1 && !wizardp(me) )
	{
		me->start_busy(4);
		me->set_temp("say_busy",1);
		remove_call_out("delete_busy");
		call_out("delete_busy",4);
		
		if(!me->is_ghost() && userp(me))
			me->add("jing",-5);
		
		write("�𼱣��л��úý���\n");
		return 1;
	}
	
	if( (int)me->query("qi") < (int)me->query("max_qi") / 5 )
	{
		arg = replace_string(arg, " ", " ... ") + " ...";
	}
	
	write( CYN "��˵����" + arg + "\n" NOR);
	message("sound", CYN + me->name() + "˵����" +  arg + "\n" NOR,environment(me), me);
	if ( playerp(me)) me->set_temp("say1",time());
        
	// The mudlib interface of say
	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

void delete_busy()
{
	object ob;

	if(!ob)
		return 0;

	if(ob->query_temp("say_busy"))
		ob->delete_temp("say_busy");
}

int help (object me)
{
	write(@HELP
ָ���ʽ: say <ѶϢ>
 
˵�������и�����ͬһ��������˶���������˵�Ļ���
 
ע: ��ָ����� ' ȡ��.
 
HELP
	);
	return 1;
}
