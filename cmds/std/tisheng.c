// team.c

#include <ansi.h>

inherit F_CLEAN_UP;
object find_player(string target)
{
      int i;
        object *objs;
        objs=users();
        for (i=0;i<sizeof(objs);i++)
                if (objs[i]->query("id")==target && interactive(objs[i]) && environment(objs[i]))
                        return objs[i];
        return 0;
}

int main(object me, string arg)
{
	object obj;
	
	if(!arg || !obj = find_player(arg))
	{
		return notify_fail("��Ҫ��˭�����ϣ�\n");	
	}
	
	if (!me->query("party/zhu"))
	{
		return notify_fail("�㲢��һ��֮����\n");
	}
	
	if (!obj->query("party/id") || obj->query("party/id")!=me->query("party/id"))
	{
		return notify_fail("���������ĳ�Ա!\n");
	}

	if (obj == me)
		return notify_fail("����һ��֮��������ְ֮���ǽ������������ΰɡ�\n");

	if (obj->query("party/zhanglao"))
		return notify_fail("��Ŀǰ����ְ����֮λ��û��Ҫ�������ˡ�\n");
	
	/*if(me->query("party/quanzhi") >= 5)
	{
		return notify_fail("�����Ѿ�����λ�����ˣ�\n");
	}*/
                me->add("party/quanzhi",1);
                obj->set("party/zhanglao",1);	
                obj->set("bh_rank",HIR"����"NOR);
       tell_object(me,"�㽫"+obj->query("name")+"("+obj->query("id")+")����Ϊ���г��ϣ�\n");	
tell_object(obj,me->query("name")+"("+me->query("id")+")��������Ϊ"+me->query("party/name")+"�ﳤ�ϣ�\n");	
//   CHANNEL_D->do_channel(me, "chat",obj->query("name")+"("+obj->query("id")+")������Ϊ"+me->query("partyname")+"�ﳤ��!\n");       	
message("channel:chat", HIY"�����ɾ��顿"+HIM"��"+obj->query("name")+"���Ĺ�����Ϊ"+me->query("party/name")+"�����º����͡�����Ϊ����ְ֮��\n"NOR,users());       	

	return 1;
}

int help(object me)
{
	write( @HELP
tisheng id	

����������������������ĳ����ԱΪ���г��ϡ�	
ע�������Ϊ�ð��ɵİ������Ҹó�Ա�������ߡ�
HELP
   );
   return 1;
}
