// Room: /d/cxwxm/feifeng3.c
// marry 8,14
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"��԰"NOR);
        set("long", 
"�����Ƿɷ�����С��԰�����������˰�ɫ�����򻨣�������ϸ\n"
"��Ҳ������ͬ�������˼�����˶���������ϲ���������صİ�����\n"
"�ռ��������������������ȥ�м���С�����ƺ����ڲɻ���\n\n"
);
        set("outdoors","cxwxm");
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"feifeng2",
]));
        set("objects",([
                "/d/cxwxm/npc/yahuan":2,
        ]));


        setup();
        replace_program(ROOM);
}
