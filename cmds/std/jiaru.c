// team.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	if(!arg || !objectp(obj = present(arg, environment(me))))
	{
return notify_fail("��Ҫ��˭����İ��ɣ�\n");	
	}
	if (obj->query("party/id"))
	{
		return notify_fail("���Ѿ�����һ�������ˣ�����뻻������˳�ԭ����!\n");
	}
if (!me->query("party/zhu") && !me->query("party/zhanglao"))    	
	{
return notify_fail("�㲢��һ��֮��,Ҳ���ǰ��ڳ��ϡ�\n");	
	}
	if (me->query_temp("askfor_join")==obj->query("id"))
	{
		return notify_fail("��������"+obj->query("name")+"�Ļش�\n");
	}
	if (obj->query_temp("askfor_join")==me->query("id"))
	{
		obj->set("party/id",me->query("party/id"));
		obj->set("party/name",me->query("party/name"));
		obj->delete_temp("askfor_join");
		tell_room(environment(me),"��ϲ"+obj->query("name")+"�ɹ�����"+me->query("name")+"��"+me->query("party/name")+"�\n");
//   CHANNEL_D->do_channel(me, "chat","��ϲ"+obj->query("name")+"�ɹ�����"+me->query("name")+"��"+me->query("partyname")+"��!\n");       
message("channel:chat", HIY"�����ɾ��顿"+HIM"��"+obj->query("name")+"����"+me->query("name")+"Ħ�£�Ч����"+me->query("party/name")+"�\n"NOR,users());              	

	}
	else 
	{
		if (me->query_temp("askfor_join") && me->query_temp("askfor_join")!=obj->query("id"))
		{
			tell_object(me,"������˼���Ĵ���!\n");
		}
		me->set_temp("askfor_join",obj->query("id"));
		tell_room(environment(me),me->query("name")+"����"+obj->query("name")+"�����Լ���"+me->query("party/name")+"�\n");
	}
	return 1;
}

int help(object me)
{
	write( @HELP
jiaru id

��������������Ӻ�����ͬһ��������������İ��ɡ�	
ע�������Ϊ�ð��ɵİ�����
HELP
   );
   return 1;
}
