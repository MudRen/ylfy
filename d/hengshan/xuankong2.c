// xuankong2.c

inherit ROOM;

void create()
{
	set("short", "悬空寺南楼");
	set("long", @LONG
这里是悬空寺的南门楼，也是南碑亭。悬空寺于陡崖上凿石穴插悬
梁为基，楼宇间栈桥相连。全寺面东座西，南北危楼对望，断崖分断，
很是艰险。
LONG
	);
	set("exits", ([
		"north"   : __DIR__"zhanqiao",
		"southup" : __DIR__"zhandao",
			"enter"   : __DIR__"xuankong3",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 3160);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

