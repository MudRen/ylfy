// whisper.c

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string dest, msg;
	object ob;
	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("��Ҫ��˭����Щʲô��\n");
	ob = present(dest, environment(me));
	if( !ob || !ob->is_character() )
		return notify_fail("��Ҫ��˭���\n");
	if (ob==me)	return notify_fail("��������������������ѵ��쵽�Լ��Ķ��ߣ���һ����ι��\n");
	if (userp(ob) && !interactive(ob))	return notify_fail("û����"+ob->name()+"����������˵ʲôҲ�ǰ�˵��\n");
	write( BOLD "����" + ob->name() + "�Ķ�������˵����" + msg + "\n" NOR);
	tell_room( environment(me), me->name() + "��" + ob->name()
		+ "����С����˵��Щ����\n", ({ me, ob }) );
	if( !userp(ob) ) ob->relay_whisper(me, msg);
	else
		tell_object( ob, BOLD + me->name() + "����Ķ�������˵����" + msg + "\n" NOR);
	return 1;
}
int help(object me)
{
	write( @TEXT
ָ���ʽ��whisper <ĳ��> <ѶϢ>
���ָ�����������ͬһ�����е��˶������ NPC ���ڡ�
TEXT
	);
	return 1;
}
