// by Amis 2006-9-23 20:18

#include <ansi.h>

void init()
{
		add_action("block_cmd","beg",1);
		add_action("block_cmd","steal",1);
		add_action("block_cmd","sleep",1);
		
		add_action("do_go","go");
		add_action("do_dig","digging",1);
		
		//this_player()->set_temp("marks/守卫", 1);

}



int block_cmd()
{
		object ob = this_object();
		if ( ob->query("定做/liuxing") ){
		write("由于刚出现过流星，附近有不少村民围观，你还是收敛点吧！\n");
    return 1;
  	}
}

int do_dig()
{
		object obj,ob = this_object(),me = this_player();
		
		if ( !ob->query("定做/liuxing") )
		return 0;	

    if ( !(present("tie qiao", me)) && !(present("tie chan", me)))
        return notify_fail(YEL"\n没有工具你挖得动吗？！\n"NOR);

    if( me->is_busy() || me->is_fighting() ) 
        return notify_fail("你正忙着呢！\n");     
        
		if ( me->query("jing") < 150 )
		return notify_fail("你实在太累了，歇歇吧！\n");	
		
		if ( me->query("jing") < 200 && random(2)==1 )
		return notify_fail("你实在太累了，歇歇吧！\n");
			
		message_vision("$N抡起铁锹，开始一阵猛敲乱砸。\n", me);		
				
		if ( random(999)==1 && random(me->query("kar")) > 32 )//获得醉月玄晶

		{
				obj=new("/clone/item/zuiyue-xuanjing");
				obj->move(me);
				message_vision(HIC"$N正挖间忽然碰到一个异常坚硬的物体，刨出来一看，赫然是一大块"+obj->query("name")+"！\n"NOR, me);
				write(HIG"你竟然发现了极其难得一见的材料，简直欣喜若狂，兴奋无比！\n"NOR);		
				return 1;
		}
		
		if ( random(200)==1 && random(me->query("kar")) > 29 )//获得火龙宝石
		{
				obj=new("/clone/gem/gem");
				obj->move(me);
				message_vision("$N的榔头忽然被一物碰出点点火星，刨出来一看，竟然是块"+obj->query("name")+"！\n", me);
				return 1;
		}
		
		if ( random(10)==1 && me->query("kar") > 1 )//获得寒玉精铁
		{
				obj=new("/clone/map/obj/hanyu-jingtie");
				obj->move(me);
				message_vision("$N的榔头忽然被一物碰出点点火星，刨出来一看，竟然是块"+obj->query("name")+"！\n", me);
				return 1;
		}
		if ( random(100)==1 && random(me->query("kar")) > 29 )//获得龙纹赤金
		{
				obj=new("/clone/map/obj/longwen-chijin");
				obj->move(me);
				message_vision("$N的榔头忽然被一物碰出点点火星，刨出来一看，竟然是块"+obj->query("name")+"！\n", me);
				return 1;
		}
		if ( random(50)==1 && random(me->query("kar")) > 25 )//获得万年玄冰(假)
		{
				obj=new("/clone/map/obj/jingang-shi");
				obj->move(me);
				message_vision("$N的榔头忽然被一物碰出点点火星，刨出来一看，竟然是块"+obj->query("name")+"！\n", me);
				return 1;
		}

		me->receive_damage("jing", 50 + random(50) );
    me->start_busy(5);
		return 1;
}

