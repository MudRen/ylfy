// team.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	if(!arg || !objectp(obj = present(arg, environment(me))))
	{
		return notify_fail("��Ҫ����˭�İ��ɣ�\n");
	}
	if (me->query("party/id"))
	{
		return notify_fail("���Ѿ�����һ�������ˣ�����뻻������˳�ԭ����!\n");
	}
if (!obj->query("party/zhu") && !obj->query("party/zhanglao"))  	
	{
return notify_fail("������һ��֮��,Ҳ�����ǰ��ɳ��ϡ�\n");	
	}
	if (me->query_temp("askfor_join")==obj->query("id"))
	{
		return notify_fail("��������"+obj->query("name")+"�Ļش�\n");
	}
	if (obj->query_temp("askfor_join")==me->query("id"))
	{
		me->set("party/id",obj->query("party/id"));
		me->set("party/name",obj->query("party/name"));
		obj->delete_temp("askfor_join");
		tell_room(environment(me),"��ϲ"+me->query("name")+"�ɹ�����"+obj->query("name")+"��"+obj->query("party/name")+"��!\n");
//   CHANNEL_D->do_channel(obj,"chat","��ϲ"+me->query("name")+"�ɹ�����"+obj->query("name")+"��"+obj->query("partyname")+"��!\n");     	
message("chat", HIY"�����ɾ��顿"+HIM"��"+me->query("name")+"����"+obj->query("name")+"Ħ�£�Ч����"+obj->query("party/name")+"�\n"NOR,users());              	
	}
	else 
	{
		if (me->query_temp("askfor_join") && me->query_temp("askfor_join")!=obj->query("id"))
		{
			tell_object(me,"�������ԭ�ȵĴ���!\n");
		}
		me->set_temp("askfor_join",obj->query("id"));
		tell_room(environment(me),me->query("name")+"�������"+obj->query("name")+"��"+obj->query("party/name")+"�\n");
	}
	return 1;
}

int help(object me)
{
	write( @HELP
join id
����������������������ͬһ���������ҵİ��ɡ�
ע������ұ���Ϊ�ð��ɵİ�����
HELP
   );
   return 1;
}
