#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
    set("short", "灌木丛");
    set("long", @LONG
  这是一片茂密的灌木丛，到处长满荆棘，树木把阳光都遮挡住了，
完全分不清东南西北，密林深处不时传来野兽低沉的吼叫声。
LONG);
    set("exits", ([
	    "north" :"/d/migong/senlin/senlin500",
		"east" : "/d/migong/senlin1/senlin300",
		"south" : "/d/migong/migong1.c",
		]));
	set("no_clean_up", 0);
	setup();
}
