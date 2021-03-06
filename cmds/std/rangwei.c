
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
		return notify_fail("你要把帮主之位禅让给谁？\n");

	if (!obj->query("party/id") || obj->query("party/id")!=me->query("party/id"))
		return notify_fail("他并非你帮的成员!\n");

	if (!me->query("party/zhu"))
		return notify_fail("你并非一帮之主，拿什么去禅让？\n");
	
	if (!obj->query("party/zhanglao"))
		return notify_fail("你只能把帮主之位禅让给长老。\n");
	
	if (obj == me)
		return notify_fail("既然你还想继续当任帮主之职，那又何必禅让？\n");
	
	obj->delete("party/zhanglao");
	obj->set("party/zhu",1);
	obj->set("bh_rank",HIC"帮主"NOR);
	obj->set("party/quanzhi",me->query("party/quanzhi"));
	me->delete("party/zhu");
	me->set("party/zhanglao",1);
	me->set("bh_rank",HIR"长老"NOR);
	me->delete("party/quanzhi");
	
	tell_object(me,"你将帮主之位禅让给"+obj->query("name")+"("+obj->query("id")+")了。\n");
	tell_object(obj,me->query("name")+"("+me->query("id")+")将帮主之位禅让给你了。\n");
	message("channel:chat", HIY"【帮派精灵】"+HIM"："+me->query("name")+"退位让贤，将"+me->query("party/name")+"帮主之位禅让给"+obj->query("name")+"。\n"NOR,users());     	

	return 1;
}

int help(object me)
{
	write( @HELP
rangwei id
		这个命令可以让你把帮主之位禅让给帮内长老。
		注：你必须为该帮派的帮主。且该成员必须在线。
HELP
   );
   return 1;
}
