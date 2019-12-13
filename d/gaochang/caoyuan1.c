
inherit ROOM;
void create()
{
	set("short", "草原");
	set("long", @LONG
这是一片无边无际的草原，半人高的青草随风而动，正如江湖中的你，随著
江湖之中汹涌的波涛，四处飘摇。你想到江湖中的无奈,不禁沧然泪下。 
LONG
	);
	set("no_new_clean_up", 0);
	set("outdoors", "caoyuan");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room44",
  "south" : __DIR__"caoyuan2",
]));

	setup();
	replace_program(ROOM);
}
