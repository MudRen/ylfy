// Room: /d/kunlun/dt.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "大厅");
	set("long", @LONG
这里是何太冲议事、授徒的地方。厅上挂着一块写着「紫气东来」匾额。
厅中很宽敞，却没什么摆设，靠墙放着两把交椅，显得十分的简洁。
LONG
	);
    set("objects", ([ 
        CLASS_D("kunlun")+"/hetaichong"  : 1,
    ]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bwc",
  "north" : __DIR__"kjt",
]));

	setup();
	replace_program(ROOM);
}
