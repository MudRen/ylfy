inherit ITEM;
#include <ansi.h>
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
    set_name(HIR "断肠花" NOR, ({"hua","duanchang"}));
        set("unit", "朵");
    set("long", "这是一朵断肠花,通体通红,鲜嫩欲滴,美丽异常。\n");
        set("no_get", "你根本不敢近前.\n");
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))  return notify_fail("你要吃什么？\n");
    message_vision(RED"$N想也不想,一口把"+this_object()->name()+RED+"吞了!\n" NOR,this_player());
    if(random(2)==0)
        this_player()->unconcious();
    else
        this_player()->die();
       this_object()->move(VOID_OB);
    destruct(this_object());
    return 1;
}
int query_autoload() { return 1; }