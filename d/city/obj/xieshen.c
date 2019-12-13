//wuchangdan.c
#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIR"邪神丹"NOR, ({"xieshen dan", "dan"}));
	if ( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "颗");
		set("long", "这是一颗深红色，似乎可以用来提高邪气，小心使用哦！\n");
		set("value", 10000000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if ( !objectp(me) ) return 0;
	if ( !id(arg) ) return notify_fail("你要吃什么？\n");
	if ( me->query("shen") < -2100000000 )
		message_vision(HIY"$N吃下一颗邪神丹半天没有反应，似乎没有起到任何作用。\n"NOR, me);
	else 
	{
		me->add("shen", -500000);
		message_vision(HIR"$N吃下一颗邪神丹，脸上邪气更重！\n"NOR,me);
	}
	destruct(this_object());
	return 1;
}

