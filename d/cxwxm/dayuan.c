// Room: /d/cxwxm/dayuan.c
// marry 8,14
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",HIC"��Ժ"NOR);
        set("long", 
"�����ǳ��������ŵĴ�Ժ����һ��ĺ�լ��Ժû̫���\n"
"���𣬴���ʯ�ĵذ壬��֪���ĺ�שǽ�������������ڴ�ɨ\n"
"Ժ�ڵ���Ҷ����Ժ�����ϱ����г��ڣ����ڶ��Ϸ��������\n"
"һ����԰��\n\n"
);
        set("outdoors", "cxwxm");
        set("exits", ([ /* sizeof() == 5 */
  "south" : __DIR__"xiuxishi",
  "southeast" : __DIR__"huayuan",
  "east" : __DIR__"houmen",
  "north" : __DIR__"dating",
  "west" : __DIR__"changlang3",
]));
        set("objects",([
                "/d/cxwxm/npc/puren":4,
        ]));

        setup();
        replace_program(ROOM);
}

