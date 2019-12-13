// unknow.c 未名仙丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "仙丹" NOR, ({ "dex dan", "dan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗园园的火红仙丹，不知道有什么用处。\n");
set("value", 1000000000);	
set("no_sell",1);
		set("unit", "颗");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
object me = this_player();		
object ob;		

        if (! id(arg))
                return notify_fail("你要吃什么？\n");
if( !objectp(ob = present(arg, me)) )
return notify_fail("什么?\n");			

        me = this_player();
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
        if (me->query("gift/unknowdan") >= 5)
        {
                message_vision("$N摇摇晃晃的，突然“啪嗒”一下子摔了个跟头。\n", me);
                tell_object(me, "你觉得吃完以后头重脚轻的。\n");
        } else
        if (random(5) == 0)
        {
                tell_object(me, "不过你觉得好像没什么作用。\n");
        } else
        {
tell_object(me, HIM "霎时间你觉得腿骨欲裂，一时疼痛难忍，几乎晕了过去。\n" NOR);	
                me->add("dex", 1);
me->unconcious();                  	
        }

        me->add("gift/unknowdan", 1);
destruct(this_object());   	
	return 1;
}
