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
             "west" :__DIR__"c13-2",
             "east" : __DIR__"yunjinlou",
             "north" : __DIR__"c13",
]));
         setup();
         replace_program(ROOM);
}

