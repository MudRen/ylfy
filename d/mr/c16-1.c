#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long", @long
����һ�����ȣ����滭�Ž��������Ĺ��ʻ�����ɫ���������ɫ������
�ߣ�ʹ���㲻�ɵöԽ������������Ĵ��쾪̾���ѡ��ڳ������棬Ѿ�ߡ�
�Ҷ���������ȥ����æ���Լ������飬������һ�㵡�������ȶ�������
��������������ǳ��ȵ����졣
long);
         set("exits", ([
             "south" : __DIR__"c16-2",
	     "east" : __DIR__"xiangfang3",
             "north" : __DIR__"c16-0",
             "west" : __DIR__"c16-3",
]));
         setup();
         replace_program(ROOM);
}
