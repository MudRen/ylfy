#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long", @long
����һ�����ȣ����滭�Ž��������Ĺ��ʻ�����ɫ���������ɫ������
�ߣ�ʹ���㲻�ɵöԽ������������Ĵ��쾪̾���ѡ��ڳ������棬Ѿ�ߡ�
�Ҷ���������ȥ����æ���Լ������顣�����ǳ��ȵ����죬�����Ǿ�����
long);
         set("exits", ([
             "west" : __DIR__"c16-4",
             "east" : __DIR__"c15-6",
             "north" : __DIR__"jingyinge",
]));
         setup();
         replace_program(ROOM);
}
