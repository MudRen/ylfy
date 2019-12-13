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
		return notify_fail("��Ҫ����İ����п���˭��\n");

	if (!obj->query("party/id") || obj->query("party/id")!=me->query("party/id"))
		return notify_fail("���������ĳ�Ա!\n");
	
	if (obj->query("party/zhu"))
		return notify_fail("����һ��֮��,����Ȩ��������\n");
	
	if (!me->query("party/zhu") && !me->query("party/zhanglao"))
		return notify_fail("�㲢��һ��֮��,Ҳ�����ǰ��ڳ��ϡ�\n");

	if(obj->query("party/zhanglao") && !me->query("party/zhu"))
		return notify_fail("����Ȩ������Ϊ����ְ֮����\n");
	
	obj->delete("party");
	obj->delete("bh_rank");

	if(obj->query("party/zhanglao"))
		me->add("party/quanzhi",-1);

	if(me->query("party/quanzhi") <= 0)
		me->delete("party/quanzhi");
	
	tell_object(me,"�㽫"+obj->query("name")+"("+obj->query("id")+")����İ��п����ˣ�\n");
	tell_object(obj,me->query("name")+"("+me->query("id")+")�����"+me->query("party/name")+"���п����ˣ�\n");
	message("chat", HIY"�����ɾ��顿"+HIM"��"+obj->query("name")+"��ʿ����Ｎ,�Ӵ���"+me->query("party/name")+"��û���κθ�ϵ!\n"NOR,users());     	

	return 1;
}

int help(object me)
{
	write( @HELP
quzhu id

	�������������㿪������еĳ�Ա��
ע�������Ϊ�ð��ɵİ������Ҹó�Ա�������ߡ�
HELP
   );
   return 1;
}
