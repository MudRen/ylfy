// Room: shanmen.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short","����ɽ��");
        set("long", @LONG
��������̵�ɽ�ţ����ɫ�����������Ӵ����������ǰ��
����������һ���ɫ���ң������š���������������ĺ�������
��ɫ���֣��������ϡ����������̵��ӵ��ڶ࣬��˵����ɽ��Ҳ
��һλ�������������ӵܾ轨�ġ�
LONG
        );
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/mingjiaodizi" : 4,
  __DIR__"npc/xuda" : 1,
]));
        set("outdoors", "none");
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zhandao",
  "south" : __DIR__"shanlu2",
]));

        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

         if ((!myfam || myfam["family_name"] != "����") && dir == "north" &&
                objectp(present("xu da", environment(me))))
           return notify_fail("���ȵ����㲻�����̵��ӣ��������ڡ�\n");
                
        return ::valid_leave(me, dir);
}
