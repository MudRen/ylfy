// Room: /d/city/shangchang.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "机制商场");
	set("long", @LONG
这里是夕阳再现组织机制测试建设中心,由"鬼斧"鲁班策划兴建.很多江湖朋友	
都来这购买帮派地盘以求能更好地巩固自己的势力.	
LONG
);
//   set("no_fight",1);	
	set("exits", ([ /* sizeof() == 1 */
		"south" : "/d/city/ximen",
]));
set("objects", ([
	__DIR__"npc/luban" : 1,
]));

	setup();
	replace_program(ROOM);
}
