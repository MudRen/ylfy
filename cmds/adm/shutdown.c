// shutdown.c
#include <net/daemons.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string wiz_status;
    object *user, link_ob;
    int i;
    if( me != this_player(1) )
		return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(boss)" && wiz_status != "(admin)" )
		return notify_fail("ֻ�� (admin) ���ϵ���ʦ������������" + MUD_NAME + "\n");
    
	write_file("/log/static/LASTCRASH", geteuid(me) + " shutdown Ϧ������ " + ctime(time()) + "\n");
    message( "system", "��Ϸ�������������Ժ�һ������ login ��\n", users() );
    
	user = children(USER_OB);
    for(i=0; i<sizeof(user); i++)
	{
		if( !environment(user[i]) )
			continue;
        user[i]->save();

        link_ob = user[i]->query_temp("link_ob");
        if( objectp(link_ob) )
			link_ob->save();
		auto_save_item(user[i]);
    }
    if( find_object(DNS_MASTER) )
		DNS_MASTER->send_shutdown();
	NATURE_D->auto_shutdown(1);
	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: shutdown
 
������������Ϸ��
 
HELP
);
        return 1;
}
 
