#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", YEL"�Ҷ�"NOR);
	set("long", YEL @LONG
    ��Χ���ǻƺ�ɫ����ʯ���о����Ѿ��ڵ��º���ĵط��ˡ� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong05",
		"west" : __DIR__"dong32",
                	]));
                set("objects", ([
               __DIR__"npc/lev" : 1,
              __DIR__"npc/lev" : 1,
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}