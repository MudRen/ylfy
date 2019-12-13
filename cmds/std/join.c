// team.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	if(!arg || !objectp(obj = present(arg, environment(me))))
	{
		return notify_fail("你要加入谁的帮派？\n");
	}
	if (me->query("party/id"))
	{
		return notify_fail("你已经入了一个帮派了，如果想换帮，请先退出原帮派!\n");
	}
if (!obj->query("party/zhu") && !obj->query("party/zhanglao"))  	
	{
return notify_fail("他并非一帮之主,也不像是帮派长老。\n");	
	}
	if (me->query_temp("askfor_join")==obj->query("id"))
	{
		return notify_fail("你正等着"+obj->query("name")+"的回答！\n");
	}
	if (obj->query_temp("askfor_join")==me->query("id"))
	{
		me->set("party/id",obj->query("party/id"));
		me->set("party/name",obj->query("party/name"));
		obj->delete_temp("askfor_join");
		tell_room(environment(me),"恭喜"+me->query("name")+"成功加入"+obj->query("name")+"的"+obj->query("party/name")+"帮!\n");
//   CHANNEL_D->do_channel(obj,"chat","恭喜"+me->query("name")+"成功加入"+obj->query("name")+"的"+obj->query("partyname")+"帮!\n");     	
message("chat", HIY"【帮派精灵】"+HIM"："+me->query("name")+"加入"+obj->query("name")+"摩下，效忠于"+obj->query("party/name")+"帮。\n"NOR,users());              	
	}
	else 
	{
		if (me->query_temp("askfor_join") && me->query_temp("askfor_join")!=obj->query("id"))
		{
			tell_object(me,"你放弃了原先的打算!\n");
		}
		me->set_temp("askfor_join",obj->query("id"));
		tell_room(environment(me),me->query("name")+"申请加入"+obj->query("name")+"的"+obj->query("party/name")+"帮！\n");
	}
	return 1;
}

int help(object me)
{
	write( @HELP
join id
这个命令可以让你加入和你在同一个房间的玩家的帮派。
注：该玩家必须为该帮派的帮主。
HELP
   );
   return 1;
}
