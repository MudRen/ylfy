// Room: /d/cxwxm/houmen.c
// marry 8,14
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"����"NOR);
        set("long", 
"���Ѿ��Ǳ��ŵĺ����ˣ�������һƬ�������ƵĴ�ɽ�������\n"
"Զ������ԼԼ������������ʹ����ֵ���ȥ����������\n\n"
);

        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"cxwx2",
  "west" : __DIR__"dayuan",
]));

        setup();
        replace_program(ROOM);
}
