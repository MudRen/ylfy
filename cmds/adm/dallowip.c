//xpasswd.c
// ported to CCTX by JackyBoy@CuteRabbits Studio 1999/4/1

#include <login.h>;
inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object ob,link_ob;
	ob=find_player(arg);
	if(!ob)
	{
        ob = new(LOGIN_OB);
        ob->set("id",arg);
        if( !ob->restore() )
        	return notify_fail("û�������ҡ�\n");
        else
		{                                    
ob->delete("allow_ip");	
           ob->save();
           destruct(ob);
           return 1;
		}
	}
	link_ob=ob->query_temp("link_ob");
	if(link_ob)
	{
link_ob->delete("allow_ip");	
		link_ob->save();
		tell_object(me, "���" + ob->query("id") + "("+ob->query("name")
+ "�ĵ�½ip�Ѿ�ɾ����\n");	
		return 1;
	}
	else
		return notify_fail("�����޷������޸ġ�\n");
	return 1;
}


int help(object me)
{
        write(@HELP
ָ���ʽ : xpasswd ID ������

���ָ������޸���ҵ����룬�����ʹ�á�	

HELP
    );
    return 1;
}
