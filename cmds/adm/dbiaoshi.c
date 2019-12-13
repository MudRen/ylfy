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
        	return notify_fail("没有这个玩家。\n");
        else
		{                                    
           ob->delete("biaoshiold");
           ob->save();
           destruct(ob);
           return 1;
		}
	}
	link_ob=ob->query_temp("link_ob");
	if(link_ob)
	{
		link_ob->delete("biaoshiold");
		link_ob->save();
		tell_object(me, "玩家" + ob->query("id") + "("+ob->query("name")
			+ "的身标已经删除。\n");
		return 1;
	}
	else
		return notify_fail("错误。无法进行修改。\n");
	return 1;
}


int help(object me)
{
        write(@HELP
指令格式 : xpasswd ID 新密码

这个指令可以修改玩家的密码，请谨慎使用。

HELP
    );
    return 1;
}