// Room: /d/city/duchang3.c
#include <room.h>
inherit ROOM;
string look_sign(object me);
void create()
{
        set("short", "赌场");
	set("long", @LONG
你现在正站在赌场里，靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
                "east"          : __DIR__"duchang", 
	 ]) );
        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
	set("objects", ([
        __DIR__"npc/judge" : 1,
        ]) );
 
        setup();
}
string look_sign(object me)
{
        return "赌：胜者赢双。\n";
}
