// Room: /d/cxwxm/changlang.c
// marry 8,14

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"����"NOR);
        set("long",
"����һ���ǳ������ĳ��ȣ����Ӻ��������û���ĺ������Ƴɣ�����\n"
"����������Ƕ��������ͼ�����ذ�����������Ȼ�Ĵ���ʯ�̳ɡ���������\n"
"�����˷·������ڹ�֮͢�С�\n\n"
);
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"changlang3",
  "west" : __DIR__"changlang",
]));

        setup();
        replace_program(ROOM);
}

