#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","С��");
         set("long",@long
һ�����������ö���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ
��׺�����С�������ʯ���ϣ�ž�žવķ�������������������ȥ������
С�������졣
long);
         set("ourdoors","mr");
         set("exits",([
             "east" : __DIR__"xiaoshe",
             "west" : __DIR__"xiaojing2",
]));
        setup();
        replace_program(ROOM);
}
