// Room: /chengdu/wuguan_cd.c
// oooc: 1998/06/25 

inherit ROOM;

void create()
{
        set("short", "�������");
	set("long", @LONG
������Զ�������ġ�������ݡ���
LONG
	);

	set("exits", ([
                "north" : __DIR__"dongjie1",
	]));

	setup();
	replace_program(ROOM);
}

