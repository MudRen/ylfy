
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
		return notify_fail("��Ҫ�Ѱ���֮λ���ø�˭��\n");

	if (!obj->query("party/id") || obj->query("party/id")!=me->query("party/id"))
		return notify_fail("���������ĳ�Ա!\n");

	if (!me->query("party/zhu"))
		return notify_fail("�㲢��һ��֮������ʲôȥ���ã�\n");
	
	if (!obj->query("party/zhanglao"))
		return notify_fail("��ֻ�ܰѰ���֮λ���ø����ϡ�\n");
	
	if (obj == me)
		return notify_fail("��Ȼ�㻹��������ΰ���ְ֮�����ֺα����ã�\n");
	
	obj->delete("party/zhanglao");
	obj->set("party/zhu",1);
	obj->set("bh_rank",HIC"����"NOR);
	obj->set("party/quanzhi",me->query("party/quanzhi"));
	me->delete("party/zhu");
	me->set("party/zhanglao",1);
	me->set("bh_rank",HIR"����"NOR);
	me->delete("party/quanzhi");
	
	tell_object(me,"�㽫����֮λ���ø�"+obj->query("name")+"("+obj->query("id")+")�ˡ�\n");
	tell_object(obj,me->query("name")+"("+me->query("id")+")������֮λ���ø����ˡ�\n");
	message("channel:chat", HIY"�����ɾ��顿"+HIM"��"+me->query("name")+"��λ���ͣ���"+me->query("party/name")+"����֮λ���ø�"+obj->query("name")+"��\n"NOR,users());     	

	return 1;
}

int help(object me)
{
	write( @HELP
rangwei id
		��������������Ѱ���֮λ���ø����ڳ��ϡ�
		ע�������Ϊ�ð��ɵİ������Ҹó�Ա�������ߡ�
HELP
   );
   return 1;
}
