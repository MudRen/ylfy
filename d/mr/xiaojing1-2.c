#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","С��");
         set("long",@long
һ�����������ö���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ
��׺�����С�������ʯ���ϣ�ž�žવķ��������������������������
������ר�ŽӴ���Ľ�ݵĸ�·Ӣ�ۺ��ܡ�
�졣
long);
         set("outdoors","mr");
         set("exits",([
             "north" : __DIR__"yanziwu",
             "south" : __DIR__"dating",
]));
        setup();
        replace_program(ROOM);
}
