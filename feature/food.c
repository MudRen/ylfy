// food.c

#include <dbase.h>
#include <name.h>

void init()
{
	if ( this_player() == environment() )
	{
		add_action("do_eat", "eat");
		if ( !query("decay") ) 
		{
			set("decay", 1);
			call_out("decay", 280);
		}
	}
}



void decay()
{
	object me = this_object(), ob = environment();
        if (!me || !ob) return;
	switch(add("decay", 1)) {
		case 2:
			set_temp("apply/long", ({ query("long") + "可是看起来不是很新鲜。\n" }));
			tell_object(ob, me->name()+"的颜色有些不对了。\n");
			break;
		case 3:
			set_temp("apply/long", ({ query("long") + "可是正在散发出一股难闻的味道。\n" }));
			tell_object(ob, me->name()+"散发出一股难闻的味道。\n");
			break;
		case 4:
			set_temp("apply/long", ({ query("long") + "可是有些腐烂了。\n" }));
			tell_object(ob, me->name()+"有些腐烂了，发出刺鼻的味道。\n");
			break;
		default:
			tell_object(ob, me->name()+"整个腐烂掉了。\n");
			destruct(this_object());
			return;
	}
	call_out("decay", 150);
}
int do_eat(string arg)
{
if( !this_object()->id(arg) ) return 0;
if( this_player()->is_busy() )
return notify_fail("你上一个动作还没有完成。\n");
if( !query("food_remaining") )
return notify_fail( name() + "已经没什么好吃的了。\n");
if( (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() ){
write("你已经吃太饱了，再也塞不下任何东西了。\n");
return 1;
}
this_player()->add("food", query("food_supply"));
if( this_player()->is_fighting() ) this_player()->start_busy(2);
// This allows customization of drinking effect.
if( query("eat_func") ) return 1;
set("value", 0);
add("food_remaining", -1);
if( !query("food_remaining") ) {
message_vision("$N将剩下的" + name() + "吃得干干净净。\n", this_player());
if( !this_object()->finish_eat() ){
remove_action("do_eat","eat");
destruct(this_object());
} 
} else 
message_vision("$N拿起" + name() + "咬了几口。\n", this_player());
return 1;
}
