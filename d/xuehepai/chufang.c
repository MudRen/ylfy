//canting               龙门血河派--餐厅

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
           set("short","饭厅");
	set("long", @LONG
这里是血河派的饭厅。从青云阁进来，一股香气扑鼻而来，屋里摆着
几条长桌，长凳。平时弟子三五成群来此进餐，边吃边聊派内的闲事以及
江湖上的恩恩怨怨。如果饿了，不妨向厨师点菜(serve)。
LONG);
	set("valid_startroom",1);
	set("exits", ([
        	"west" : __DIR__"qingyunge",
                  "north" : __DIR__"wuqifang",
	]));
	set("no_fight", 1);
	set("area", "龙门");
	setup();
}

void init()
{
	add_action("do_serve","serve");
}

int do_serve()
{
	object ob, food, water;
	ob = this_player();
        food=new(__DIR__"obj/niqiu");
        water=new(__DIR__"obj/longjing");

        if( (present("niqiu", ob)) && (present("longjing cha", ob)) )
	{
               message_vision(HIC "厨师冲着$N大叫着：“先吃完了再要。”\n" NOR, ob);
		return 1;
	}
	else
	{
                if ( (present("niqiu", ob)) )
		{
                        message_vision(HIC "厨师将一壶龙井茶放在$N面前，嘴里嘟囔着：“有吃的还要！”。\n" NOR, ob);
		        water->move(ob);
			return 1;
		};
                if ( (present("longjing cha", ob)) )
		{
                        message_vision(HIC "厨师将一碟干煸泥鳅放在$N面前，嘴里嘟囔着：“有喝的还要！”。\n" NOR, ob);
		        food->move(ob);
			return 1;
		}
		else
		{
                        message_vision(HIC "厨师将一碟干煸泥鳅、一壶龙井茶放在$N面前。\n" NOR, ob);
		        food->move(ob);
        		water->move(ob);
			return 1;
		}

	}
}
