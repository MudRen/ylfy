#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","������");
         set("long",@long
����һƬ���̵������֣�һƬ���̵���ɫ����������ȥ֦Ҷïʢ�����ϼ�
ֻС�����������Ľи���ͣ����������΢������ڶ���
long);
         set("exits",([
             "west" : __DIR__"liulin",
             "east" : __DIR__"liulin2",
             "north" : __DIR__"liulin3",
             "south" : __DIR__"xiaojing6",
]));

         setup();
         replace_program(ROOM);
}
