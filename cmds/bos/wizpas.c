//wizpas
//上次写的既然丢了，一个指令居然写了两遍，郁闷 

#include <login.h>;
inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object ob,link_ob;
	string id,wizpas;
	if(!arg||sscanf(arg,"%s %s",id,wizpas)!=2)
		return notify_fail("用法:wizpas ID 巫师登陆效验码！\n");
	ob=find_player(id);
	if(!ob)
	{
        ob = new(LOGIN_OB);
        ob->set("id",id);
        if( !ob->restore() )
        	return notify_fail("没有这个玩家。\n");
        else
		{                                    
           ob->set("wizpasswd",crypt(wizpas,0));
           tell_object(me, "设置巫师" + ob->query("name") + "("+ob->query("id")
                + ")的登陆效验码为："+wizpas+"。\n");
           log_file( "/cmds/loginpas", sprintf("%s %s(%s)设置%s(%s)的巫师登陆效验码\n",
                ctime(time()), me->query("name"), me->query("id"),
                ob->query("name"), ob->query("id")));
           ob->save();
           destruct(ob);
           return 1;
		}
	}
	link_ob=ob->query_temp("link_ob");
	if(link_ob)
	{
		link_ob->set("wizpasswd",crypt(wizpas,0));
		link_ob->save();
		tell_object(me, "设置巫师" + ob->query("name") + "("+ob->query("id")
			+ "的登陆效验码为："+wizpas+"。\n");
		return 1;
	}
	else
		return notify_fail("错误。无法进行修改。\n");
	return 1;
}


int help(object me)
{
        write(@HELP
指令格式 : wizpas ID 巫师登陆效验码

这个指令可以设置、修改巫师的登陆效验码。

HELP
    );
    return 1;
}