#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","С��");
         set("long",@long
һ�����������ö���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ
��׺�����С�������ʯ���ϣ�ž�žવķ������������������濴ȥ��һ
Ƭ�����֣�������һ��Сˮ�أ�������һ�����ȡ�
long);
set("outdoors","mr");
         set("exits",([
             "east" : __DIR__"shuichi",
             "north" : __DIR__"liulin2",
             "west" : __DIR__"xiaojing6",
          "south" : __DIR__"c14",
]));
        setup();
        replace_program(ROOM);
}
