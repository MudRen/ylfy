// cuiping1.c

inherit ROOM;

void create()
{
	set("short", "翠屏山道");
	set("long", @LONG
你爬在翠屏山道上，石阶陡峭，近在目前。回头外望，恒山重峦叠
嶂，林木幽深，倍感静谧。
LONG
	);
	set("exits", ([
		"westup"  : __DIR__"cuiping2",
		"down"    : __DIR__"cuipinggu2",
	]));
	set("objects", ([
		"quest/skills2/wakuang/kuang/kuangmai" : 1,
	])); 
	    set_temp("wayao1",2);
	set("outdoors", "hengshan");
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 3180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

