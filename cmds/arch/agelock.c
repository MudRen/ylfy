// agelock.c	
inherit F_CLEAN_UP;
int main(object me, string arg)
{
int age;
	if( me!=this_player(1) ) return 0;
	if( !arg || arg=="" )
return notify_fail("ָ���ʽ��agelock ������������\n");       	
if( sscanf(arg, "%d", age)!=1 ) age = 0;
write("��ȡ�������ߵ���������\n");
	seteuid(getuid());
if( LOGIN_D->set_agelock(age) ) {	
write("Ŀǰ������Ϸ���������Ϊ"+age+"\n");
		write("Ok.\n");
		return 1;
	} else
return notify_fail("���������趨ʧ�ܡ�\n");	
}
int help (object me)
{
        write(@HELP
ָ���ʽ: agelock ����  	
 
����ĳ���������µ�ʹ���߽�����Ϸ��	
 
HELP
);
        return 1;
}
 
