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
���������ǳ��ȵ����졣
long);
         set("exits", ([
             "south" : __DIR__"c15-1",
              "east" : __DIR__"fanting1",
             "west" : __DIR__"shufang",
]));
         setup();
 //        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if (dir == "east" && me->query("family/family_name") != "����Ľ��"
        && objectp(present("guan jia", environment(me))))
                return notify_fail("�ܼҺȵ�������Ľ��ɽׯ��Ҫ�Ҵ�����\n");

        return ::valid_leave(me, dir);
}