// Room: /d/quanzhou/nanmen.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
#include "/clone/item/liuxing.h"
void create()
{
    set("short", "Ȫ������");
    set("long", @LONG
�������Ϸ���һ��Ȫ�ݵ����š���������һƬ��Ұ��
LONG
    );
    set("outdoors", "quanzhou");
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zhongxin",
  "south" : __DIR__"huangye",
]));
    setup();
    replace_program(ROOM);
}
