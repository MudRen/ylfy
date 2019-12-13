// describe.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string *txt;
	
	if ( !arg || arg=="?" || arg=="/?")	return help(me);
	
	txt = explode(arg, "\n");
	if ( !wizardp(me) )
	{
		if ( sizeof(txt) > 30 )	return notify_fail("�뽫�����Լ���������������ʮ�����ڡ�\n");
		if ( strlen(arg) > 300 ) return notify_fail("�뽫�����Լ����������������ٸ��ַ����ڡ�\n"); 
	}
	if ( arg=="none" ) me->delete("long");
	else 
	{
		arg = implode(txt, "\n") + "\n";
		arg = trans_color(arg, 2);
		me->set("long", arg + NOR);
	}
	
	write("Ok.\n");
	return 1;
}
int help(object me)
{
	write(@TEXT
ָ���ʽ��describe <����>
���ָ�������趨�������� look ָ���ʱ�������������ͨ������
����������һ��ʱ������ to describe �ķ�ʽ�����롣
TEXT
	);
	return 1;
}
