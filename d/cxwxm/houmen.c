// Room: /d/cxwxm/houmen.c
// marry 8,14
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"后门"NOR);
        set("long", 
"这已经是本门的后门了，门外是一片高耸入云的大山。东面的\n"
"远处隐隐约约传来喊叫声，使你奇怪的想去看看究竟。\n\n"
);

        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"cxwx2",
  "west" : __DIR__"dayuan",
]));

        setup();
        replace_program(ROOM);
}
