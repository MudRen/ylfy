// Room: /t/wanjiegu/riverside1.c

inherit ROOM;

void create()
{
        set("short", "江边小路");
        set("long", @LONG
这是澜沧江边的一条小路，江水滔滔，从下面奔腾而过，江面
上不时传来艄公的号子声，与江风的呼啸声形成一曲动人的交响乐
LONG
        );
        set("outdoors", "wanjiegu");
set("exits", ([ /* sizeof() == 2 */	
            "northup" : __DIR__"riverside2",
"southeast" : "/d/wanjiegu/road3",	
        ]));
        set("objects", ([
            __DIR__"npc/duck" : 2,
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
