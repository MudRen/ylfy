// ask.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <ansi.h>
inherit F_CLEAN_UP;
string *msg_dunno = ({
	"$n摇摇头，说道：没听说过。\n",
	"$n睁大眼睛望着$N，显然不知道$P在说什么。\n",
	"$n耸了耸肩，很抱歉地说：无可奉告。\n",
	"$n说道：嗯....这我可不清楚，你最好问问别人吧。\n",
	"很显然，$n根本不想回答$P的问题。\n",
	"$n想了一会儿，说道：对不起，你问的事我实在没有印象。\n",
	"$n睁大眼睛望着$N，这么简单的问题也要问吗？\n",
});
int main(object me, string arg)
{
	mapping ask_msgs;
	string dest, topic, msg, *asks;
	object ob;
	int ask;
	seteuid(getuid());
	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("你要问谁什么事？\n");
	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("这里没有这个人。\n");
	//if ( me->is_busy() ) return notify_fail("你上一个动作还没有完成。\n");
	if( !ob->is_character() ) {
		message_vision("$N对着$n自言自语....\n", me, ob);
		return 1;
	}
	if( !ob->query("can_speak") ) {
		message_vision("$N向$n打听有关『" + topic + "』的消息，但是$p显然听不懂人话。\n", me, ob);
		return 1;
	}
	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);
	if( userp(ob) ) return 1;
	if( !living(ob) ) {
		message_vision("但是很显然的，$n现在的状况没有办法给$N任何答覆。\n",
			me, ob);
		return 1;
	}
	//me->start_busy(random(3));
	// 列出所有可询问的信息
	ask = 0;
	if ( mapp(ask_msgs=ob->query("inquiry")) 
		&& sizeof(ask_msgs) > 0 
		&& topic == "all" )
	{
		asks = keys(ask_msgs);
		if ( sizeof(asks) > 0 )
		{
			msg = HIW"你可以向 "HIG+ob->name(1)+HIW" 打听的小道消息共有 "HIR+sizeof(asks)+HIW" 条，具体如下：\n"HIY;
			for ( int i=0; i<sizeof(asks); i++ )
			{
				msg += "第"+chinese_number(i+1)+"条："HIG+asks[i]+"\n"HIY;
			}
			tell_object(me, msg);
			ask = 1;
		}
	}
	if( msg = ob->query("inquiry/" + topic) ) 
	{
		if( stringp(msg) ) 
		{
			message_vision( CYN "$N说道：" + msg + "\n" NOR, ob);
			return 1;
		}
	} 
	else if ( !ask )
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
	return 1;
}
int help(object me)
{
   write( @HELP
指令格式: ask <someone> about <something>
这个指令在解谜时很重要, 通常必须藉由此一指令才能
获得进一步的资讯。
HELP
   );
   return 1;
}
