#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long", @long
����һ�����ȣ����滭�Ž��������Ĺ��ʻ�����ɫ���������ɫ������
�ߣ�ʹ���㲻�ɵöԽ������������Ĵ��쾪̾���ѡ��ڳ������棬Ѿ�ߡ�
�Ҷ���������ȥ����æ���Լ������飬�����ǳ��ȵ����죬�����ǿ�����
������Ǻ�Ժ��
long);
         set("exits", ([
             "west" : __DIR__"houyuan",
             "south" : __DIR__"keting",
          "north" : __DIR__"c14",
             "east" : __DIR__"c14-3",
]));
         setup();
         replace_program(ROOM);
}
