#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long", @long
����һ�����ȣ����滭�Ž��������Ĺ��ʻ�����ɫ���������ɫ������
�ߣ�ʹ���㲻�ɵöԽ������������Ĵ��쾪̾���ѡ��ڳ������棬Ѿ�ߡ�
�Ҷ���������ȥ����æ���Լ������飬������һ�㵡����������������
��������Ͷ����ǳ��ȵ����졣
long);
         set("exits", ([
             "south" : __DIR__"c15-2",
	     "west" : __DIR__"xiangfang2",
             "north" : __DIR__"c15-0",
             "east" : __DIR__"c15-3",
]));
         setup();
         replace_program(ROOM);
}
