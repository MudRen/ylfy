// reboot.c
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string wiz_status;
	object npc;
	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
    if( wiz_status != "(boss)" && wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("ֻ�� (arch) ���ϵ���ʦ������������" + MUD_NAME + "\n");
	seteuid(getuid());
	npc = new("/clone/npc/demogorgon");
	npc->move("/d/wizard/meeting");
	npc->start_shutdown();
	write_file("/log/static/LASTCRASH", geteuid(me) + " rebootϦ�������� " + ctime(time()) + "\n");
	write("Ok��\n");
	return 1;
}
int help (object me)
{
        write(@HELP
ָ���ʽ: reboot
 
��ʱʮ�������������Ϸ��
 
HELP
);
        return 1;
}
 
