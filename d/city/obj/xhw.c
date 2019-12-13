// xhw.c 消化丸
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("消化丸", ({"xiaohuawan", "wan"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一粒不大起眼的消化丸。\n");
                set("unit", "粒");
                set("value", 200);
                set("food_remaining", 1);
                set("food_supply", -100);
        }
}
void init()
{
          add_action("do_eat","eat");
}
int do_eat(string arg)
{
	if( !( environment())->is_character() ) return 0;
	if( !this_object()->id(arg) ) return notify_fail("你要吃什么？\n");
	if( this_player()->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if( (int)this_player()->query("food") < (int)this_player()->max_food_capacity() )
		return notify_fail("你现在不需要"+this_object()->name()+"。\n");
		message_vision("$N将" + name() + "吃得干干净净。\n", this_player());
	this_player()->set("food", 0);
			destruct(this_object());
		return 1;
}
int query_autoload() { return 1; }