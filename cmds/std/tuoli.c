// tdd.c

#include <ansi.h>	
inherit F_CLEAN_UP;	
int main(object me, string arg)	
{
	if (!me->query("party/id"))
		return notify_fail("你目前没有加入任何帮派\n");	
	
	//if ( me->query("party/zhanglao") )
		//return notify_fail("你目前在帮内当任要职，不能私自退帮。\n");	
	
	message("channel:chat", HIY"【帮派精灵】"+HIM"："+me->query("name")+"脱离了"+me->query("party/name")+HIM"帮,从此与"+me->query("party/name")+HIM"帮没有任何干系！\n"NOR,users() );
	me->delete("party");
	me->delete("bh_rank");

	if(me->query("party/zhu"))
		me->delete("party/quanzhi");
	
	return 1;	
}
