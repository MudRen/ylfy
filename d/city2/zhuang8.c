#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "����");
    set("long", @LONG
���������������ȡ��Ĵ��ڳ�����.
LONG
    );
    set("exits", ([
		"north" : "/d/city2/zhuang9",
		"south" : "/d/city2/zhuang5",
    ]));
    set("objects", ([
		"/d/city2/npc/dizi": 1,
    ]));
    set("outdoors", "city2");
    setup();
   replace_program(ROOM); 
}
