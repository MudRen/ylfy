//wuchangdan.c
#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIG"正气丸"NOR, ({"zhengqi wan", "wan"}));
	if ( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "颗");
		set("long", "这是一颗碧绿色药丸，似乎可以用来提高正神，小心使用哦！\n");
		set("value", 10000000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if ( !objectp(me) ) return 0;
	if ( !id(arg) ) return notify_fail("你要吃什么？\n");
	if ( me->query("shen") > 2100000000 )
		message_vision(HIY"$N吃下一颗正气丸半天没有反应，似乎没有起到任何作用。\n"NOR, me);
	else 
	{
		me->add("shen", 500000);
		message_vision(HIG"$N吃下一颗正气丸，顿觉侠义之气更见浓厚！\n"NOR,me);
	}
	destruct(this_object());
	return 1;
}

