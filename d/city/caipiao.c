// Room: /city/duchang.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "福彩投注中心");
	set("long", @LONG
这里是泥潭彩票投注站。一夕成财，机会尽把你手！各位江湖豪杰来...来...来，来博上一把，机会难得，失不再来，说不定您就是这期的幸运者..... 0_0。
LONG
	);
set("no_fight",1);
	set("exits", ([
            "up" : __DIR__"duchang",      	
	]));
set("objects", ([
           "/clone/misc/caipiao_ban" : 1,
        ]));
	setup();
}
