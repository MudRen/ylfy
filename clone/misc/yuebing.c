// /clone/misc/gift.c	
// 注意：礼物发放Add的调用格式务必使用 add(string prop, mixed data, 1)

#include <ansi.h>
#define GIFT_NAME "月饼"

inherit ITEM;

void create()
{
	set_name(HIY + GIFT_NAME + NOR, ({"yue bing","bing"}));
	set_weight(200);
	if ( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "块");
		set("long", HIM"一块月饼，看起来似乎香甜可口，让人忍不住想拿起来咬一口。"NOR);
		set("value", 0);
		set("no_give", 1);
		set("no_get", 1);
		set("no_put", 1);
		set("no_drop", 1);
		set("no_sell", 1);
	}
	setup();
}

void init()
{
	add_action("do_chai", "eat");
}

int do_chai(string arg)
{
	object me;
	int i;

	me = this_player();
	
	if ( !id(arg) ) return notify_fail("你要吃什么？\n");
	if ( me->query("07_中秋") )                	
	{
		tell_object(me, HIY "你拿起月饼轻轻咬了口，不禁眉头一皱怎么味道怪怪的....，仔细一看原来是橡胶做的，你狠狠地把月饼扔了出去....\n"NOR);	
		destruct(this_object());
		return 1;
	}
	
	tell_object(me,HIG "你拿起月饼轻轻地咬了口，但觉得味道甜美无比，忍不住一口全吃了下去。\n" NOR);
	for ( i=0; i<10; i++ )
	{
		me->add("combat_exp", 5000000, 1);
	}
	// 删除上次派礼物生成的参数，增加本次参数，确保每位玩家只能用一次。
	me->delete("中秋",1);              	
	me->set("07_中秋", 1);              	
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{ 
	destruct(this_object());
}