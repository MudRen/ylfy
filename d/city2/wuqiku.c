
inherit ROOM;
void create()
{
	set("short", "武器库");
	set("long", @LONG
这里是武器库，架上摆满了各种武器,任由武士门挑选。
LONG
	);
	set("exits", ([
		"east" : __DIR__"kang2",
	]));
	set("objects", ([
		"/clone/weapon/zhujian" : 2,
		"/clone/weapon/zhubang" : 2,
		"/clone/weapon/changbian" : 1,
		"/clone/weapon/duanjian" : 1,
		"/clone/weapon/gangdao" : 1,
		"/clone/weapon/fuchen" : 1,
	]));
	
	setup();
	replace_program(ROOM);
}
