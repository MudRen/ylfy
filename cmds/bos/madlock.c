// wizlock.c
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	if( me!=this_player(1) )
		return 0;

	if( wiz_level(me) < wiz_level("(boss)") )
		return 0;

	if( LOGIN_D->get_madlock() == 1 )
		return notify_fail("ʱ�����ǹرյġ�\n");
	
	if( LOGIN_D->set_madlock(1) )
	{
		message("chat", HIG"��"+HBRED+HIY"��Ϸ����"NOR+HIG"��"+HIW"����������.....��ʱ���ѱ���ʱ��ա�\n"NOR,users() );
		return 1;
	}
	else
		return notify_fail("ʱ�շ��ʧ�ܡ�\n");
}

int help (object me)
{
        write(@HELP
ָ���ʽ: madlock
 
����ʹ���߼���������Ϸ��
 
HELP
);
        return 1;
}
 
