#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long", @long
����һ�����ȣ����滭�Ž��������Ĺ��ʻ�����ɫ���������ɫ������
�ߣ�ʹ���㲻�ɵöԽ������������Ĵ��쾪̾���ѡ��ڳ������棬Ѿ�ߡ�
�Ҷ���������ȥ����æ���Լ������顣�����ǳ��ȵ����죬����������ի��
long);
         set("exits", ([
             "east" : __DIR__"c15-4",
             "west" : __DIR__"c15-6",
             "north" : __DIR__"shangyuezhai",
]));
         setup();
         replace_program(ROOM);
}