#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long", @long
����һ�����ȣ����滭�Ž��������Ĺ��ʻ�����ɫ���������ɫ������
�ߣ�ʹ���㲻�ɵöԽ������������Ĵ��쾪̾���ѡ��ڳ������棬Ѿ�ߡ�
�Ҷ���������ȥ����æ���Լ������飬������һ������������ǳ��ȵ�
���졣
long);
         set("exits", ([
             "west" : __DIR__"keting",
             "east" : __DIR__"guifang",
             "north" : __DIR__"c14-3",
             "south" : __DIR__"c14-5",
]));
         setup();
  //     replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        mapping fam;
        fam = (mapping)me->query("family");

 if (dir == "east" && objectp(present("ya huan", environment(me))))
                return notify_fail("���˷Ը�û����Ҫ�����鲻Ҫ����С����Ϣ��\n");

                  return ::valid_leave(me, dir);
}
