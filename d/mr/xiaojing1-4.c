#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","С��");
         set("long",@long
һ�����������ö���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ
��׺�����С�������ʯ���ϣ�ž�žવķ�������������������һ��С�ء�
long);
         set("outdoors","mr");
         set("exits",([
             "east" : __DIR__"fenmu",
             "west" : __DIR__"xiaojing1-3",
]));
        setup();
        replace_program(ROOM);
}
