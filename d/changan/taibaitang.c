// This is a room made by wsl.
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "̫����");
    set("long", @LONG
�������ǵġ�ʫ�ɡ����
LONG
    );
    set("exits", ([
         "south" :__DIR__"ca6",
         "east" :__DIR__"ca7",
    ]));
    create_door("south", "����", "north", DOOR_CLOSED);
    setup();
}
