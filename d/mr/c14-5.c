#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long", @long
����һ�����ȣ����滭�Ž��������Ĺ��ʻ�����ɫ���������ɫ������
�ߣ�ʹ���㲻�ɵöԽ������������Ĵ��쾪̾���ѡ��ڳ������棬Ѿ�ߡ�
�Ҷ���������ȥ����æ���Լ������飬�������ӻ��ң������ǳ��ȵ����졣
long);
         set("exits", ([
             "west" : __DIR__"zahuoshi",
             "north" : __DIR__"c14-4",
]));
	set("objects",([
	   __DIR__"npc/xiaotong" : 1,
	   __DIR__"npc/murong-bo" : 1,
]));
         setup();
         replace_program(ROOM);
}
