#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long", @long
����һ�����ȣ����滭�Ž��������Ĺ��ʻ�����ɫ���������ɫ������
�ߣ�ʹ���㲻�ɵöԽ������������Ĵ��쾪̾���ѡ��ڳ������棬Ѿ�ߡ�
�Ҷ���������ȥ����æ���Լ������飬������һ���᷿�������ǳ��ȵ�
���졣
long);
         set("exits", ([
             "east" : __DIR__"xiangfang1",
             "north" : __DIR__"c13-1",
             "south" : __DIR__"c13-3",
]));
         set("objects",([
             __DIR__"npc/youcao" : 1,
]));
         setup();
         replace_program(ROOM);
}

