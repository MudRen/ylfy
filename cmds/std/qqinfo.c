
#include <ansi.h>
inherit F_CLEAN_UP;
#include <liebiao.h>

int main(object me,string arg)
{
	object obj;
	string str;
	if(!arg)
		obj=me;
	if(arg&&sscanf(arg,"set %s",arg))
	{
	        arg=replace_string(arg,"\"","");
	        arg=replace_string(arg,"'","");
	        arg=replace_string(arg,"\\","");
		me->set("qqinfo",arg);
		write(ALERT("你的个人信息已经设置成功!\n"));
		return 1;
	}
	if(arg&&!objectp(obj))
		obj = find_player(arg);
	if(me->query("xieyi/zmud")) return notify_fail(HIY"你的客户端不支持Tomud协议，无法查询对方信息!"NOR);
	if(!objectp(obj)) return notify_fail(ALERT("无法查询对方信息。"));
	if(obj->query_temp("temp_loaded")) return notify_fail(ALERT("无法查询对方信息。"));
	if(stringp(str=obj->query("qqinfo")))
	{
		write(TMI("qqinfo"+((obj==me)?"0":"1")+" "+str));
		return 1;
	}
	write(TMI("qqinfo"+((obj==me)?"0":"1")+""));
	return 1;
}
