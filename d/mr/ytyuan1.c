#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","ӣ��԰");
         set("long",@long
����һƬӣ��԰�����Ͽ�����ӣ�һ���
long);
         set("exits",([
	"east" : __DIR__"ytyuan2",
             "south" : __DIR__"huandong",
]));
        setup();
        replace_program(ROOM);
}
