//bye 
// /d/city3/shandao2.c
inherit ROOM;

void create()
{
        set("short", "山道");
	set("long", @LONG
这是一条崎岖不平的山道，人迹罕至，听说这里不是很太平。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "southdown" : __DIR__"shandao1",
                "northup" : __DIR__"shandao3",
				"east" : "/d/cxwxm/tianye",
	]));
        set("objects", ([
                __DIR__"npc/tufei2" : 1,
            ]));

	setup();
	replace_program(ROOM);
}



