// wdroad9.c 黄土路
// by Xiang

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
	你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。
西南方有一条小路通往四川峨嵋境内。
LONG
	);
        set("outdoors", "emei");

	set("exits", ([
                "southwest": "/d/emei/shanlu1",
                "north": "/d/wudang/wdroad8",
"southeast": "/d/henshan/hsroad8",	
	]));
	setup();
	replace_program(ROOM);
}

