#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","С��");
         set("long", @long
������һ��Բ��С�ţ�С�ŵ�������һ�����ȣ���������������������
�е��˶���æ���Լ������顣
long);
         set("exits", ([
             "north" : __DIR__"c16-3",
             "south" : __DIR__"c16-4",
]));
         setup();
         replace_program(ROOM);
}
