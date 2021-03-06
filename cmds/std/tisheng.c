// team.c

#include <ansi.h>

inherit F_CLEAN_UP;
object find_player(string target)
{
      int i;
        object *objs;
        objs=users();
        for (i=0;i<sizeof(objs);i++)
                if (objs[i]->query("id")==target && interactive(objs[i]) && environment(objs[i]))
                        return objs[i];
        return 0;
}

int main(object me, string arg)
{
	object obj;
	
	if(!arg || !obj = find_player(arg))
	{
		return notify_fail("你要提谁做长老？\n");	
	}
	
	if (!me->query("party/zhu"))
	{
		return notify_fail("你并非一帮之主。\n");
	}
	
	if (!obj->query("party/id") || obj->query("party/id")!=me->query("party/id"))
	{
		return notify_fail("他并非你帮的成员!\n");
	}

	if (obj == me)
		return notify_fail("你乃一帮之主，长老之职还是交由他人来当任吧。\n");

	if (obj->query("party/zhanglao"))
		return notify_fail("他目前正任职长老之位，没必要再提升了。\n");
	
	/*if(me->query("party/quanzhi") >= 5)
	{
		return notify_fail("帮内已经有五位长老了！\n");
	}*/
                me->add("party/quanzhi",1);
                obj->set("party/zhanglao",1);	
                obj->set("bh_rank",HIR"长老"NOR);
       tell_object(me,"你将"+obj->query("name")+"("+obj->query("id")+")提升为帮中长老！\n");	
tell_object(obj,me->query("name")+"("+me->query("id")+")将你提升为"+me->query("party/name")+"帮长老！\n");	
//   CHANNEL_D->do_channel(me, "chat",obj->query("name")+"("+obj->query("id")+")被提升为"+me->query("partyname")+"帮长老!\n");       	
message("channel:chat", HIY"【帮派精灵】"+HIM"："+obj->query("name")+"忠心耿耿，为"+me->query("party/name")+"帮立下汗马功劳、晋升为长老之职！\n"NOR,users());       	

	return 1;
}

int help(object me)
{
	write( @HELP
tisheng id	

这个命令可以让你提升帮内某个成员为帮中长老。	
注：你必须为该帮派的帮主。且该成员必须在线。
HELP
   );
   return 1;
}
