#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","�᷿");
         set ("long",@long
����һ���᷿, ��������, ֻ��һ�Ŵ�, һ��������һ�����ӡ�
long);
         set("no_fight", 1);
         set("sleep_room", 1);
         set("exits",([
             "west" : __DIR__"houting",
             "east" : __DIR__"c15-1",
             "north" : __DIR__"shufang",
]));
         setup();
         replace_program(ROOM);
}
