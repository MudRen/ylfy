// Room: /d/cxwxm/cxwx.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"����ǰ"NOR);
        set("long",
"��̧ͷһ����ֻ�������Ϲ���һ�����ң���Ի��"+HIG"�����������š�"NOR+"����ǰ\n"
"վ�ŵ�������������΢Ц���⿴���㡣\n\n"
);
        set("outdoors","cxwxm");
        set("exits", ([ /* sizeof() == 1 */
              "east" : __DIR__ "damen.c",
              "south" : __DIR__ "tianye",
        ]));
        set("objects",([
                "/d/cxwxm/npc/dizi":2,
        ]));

        setup();
        replace_program(ROOM);
}
