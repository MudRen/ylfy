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
		return notify_fail("你要从你的帮派中开除谁？\n");

	if (!obj->query("party/id") || obj->query("party/id")!=me->query("party/id"))
		return notify_fail("他并非你帮的成员!\n");
	
	if (obj->query("party/zhu"))
		return notify_fail("他是一帮之主,你无权开除他。\n");
	
	if (!me->query("party/zhu") && !me->query("party/zhanglao"))
		return notify_fail("你并非一帮之主,也不像是帮内长老。\n");

	if(obj->query("party/zhanglao") && !me->query("party/zhu"))
		return notify_fail("你无权开除身为长老之职的他\n");
	
	obj->delete("party");
	obj->delete("bh_rank");

	if(obj->query("party/zhanglao"))
		me->add("party/quanzhi",-1);

	if(me->query("party/quanzhi") <= 0)
		me->delete("party/quanzhi");
	
	tell_object(me,"你将"+obj->query("name")+"("+obj->query("id")+")从你的帮中开除了！\n");
	tell_object(obj,me->query("name")+"("+me->query("id")+")将你从"+me->query("party/name")+"帮中开除了！\n");
	message("chat", HIY"【帮派精灵】"+HIM"："+obj->query("name")+"因故开除帮籍,从此与"+me->query("party/name")+"帮没有任何干系!\n"NOR,users());     	

	return 1;
}

int help(object me)
{
	write( @HELP
quzhu id

	这个命令可以让你开除你帮中的成员。
注：你必须为该帮派的帮主。且该成员必须在线。
HELP
   );
   return 1;
}
