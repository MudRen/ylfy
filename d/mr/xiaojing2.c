#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","С��");
         set("long",@long
һ�����������ö���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ
��׺�����С�������ʯ���ϣ�ž�žવķ���������������������ȥ����
��ӡ�
long);
         set("ourdoors","mr");
         set("exits",([
             "east" : __DIR__"xiaojing1",
             "northwest" : __DIR__"tingyuju",
]));
        setup();
        replace_program(ROOM);
}
