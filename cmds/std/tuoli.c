// tdd.c

#include <ansi.h>	
inherit F_CLEAN_UP;	
int main(object me, string arg)	
{
	if (!me->query("party/id"))
		return notify_fail("��Ŀǰû�м����κΰ���\n");	
	
	//if ( me->query("party/zhanglao") )
		//return notify_fail("��Ŀǰ�ڰ��ڵ���Ҫְ������˽���˰\n");	
	
	message("channel:chat", HIY"�����ɾ��顿"+HIM"��"+me->query("name")+"������"+me->query("party/name")+HIM"��,�Ӵ���"+me->query("party/name")+HIM"��û���κθ�ϵ��\n"NOR,users() );
	me->delete("party");
	me->delete("bh_rank");

	if(me->query("party/zhu"))
		me->delete("party/quanzhi");
	
	return 1;	
}
