#include <ansi.h>
inherit ROOM;
void create()
{
         set("short","�ص�");
         set("long",@long
�������س�ʪ��ǽ����һ����ѡ�
long);
         set("exits",([
             "south" : __DIR__"ytyuan",
             "north" : __DIR__"hhyuan",
]));
         setup();
         replace_program(ROOM);
}
