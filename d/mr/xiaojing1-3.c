#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","С��");
         set("long",@long
һ�����������ö���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ
��׺�����С�������ʯ���ϣ�ž�žવķ�������������������С������
�졣
long);
         set("outdoors","mr");
         set("exits",([
             "west" : __DIR__"c15-4",
             "east" : __DIR__"xiaojing1-4",
]));
        setup();
        replace_program(ROOM);
}
