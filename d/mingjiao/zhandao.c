// Room: zhandao.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short",HIR"ջ��"NOR);
        set("long", @LONG
��ò���������ջ�����㷢����һȺ����������Ц��������
����˵����С�ֵܣ���ӭ����ӭ����ӭ���������̣�������Ǿ�
�ǡ��и�ͬ������ͬ�������ֵ��ˣ���������������̵�ɽ��
�ˡ�
LONG
        );
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/shuobude" : 1,
  __DIR__"npc/mingjiaodizi" : 4,
]));
        set("no_out",1);
        set("outdoors", "none");
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shanlu1",
  "south" : __DIR__"shanmen",
]));

        setup();
}

int valid_leave(object me, string dir)
{
        if ( me->query("id")=="mingjiao xunluo" && dir == "south" )
                return 0;
        return ::valid_leave(me, dir);
}
