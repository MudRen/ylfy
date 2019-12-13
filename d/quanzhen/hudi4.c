//hudi4.c

inherit ROOM;

void create()
{
	set("short", "小湖底 ");
	set("long", @LONG
这里是小湖湖底，四周黑忽忽的，头顶上只能看见一点亮光，身边的水流
似乎更加湍急了。脚下似乎有一点亮光，也不知是些什么。周围一片死寂，似
乎暗藏着层层杀机。
LONG
	);
	set("exits", ([
		"up" : __DIR__"",	
		"down" : __DIR__"",
		"east" : __DIR__"",
		"north" : __DIR__"",
		"south" : __DIR__"",
	]));
	setup();
	replace_program(ROOM);
}
