// shanlu6.c By csy 98/12

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", YEL"ɽ·"NOR);
    set("long", @LONG
�˴���һ�����ɽ·����������������������Ω�������ȵף����Է��ۣ�
��ɽ�żţ�΢��������ãã����ֻ��һ�˶��ѡ��������ã�����һ����ɽ
��ǰ��
LONG
        );

    set("exits", ([ 
                "enter"  : __DIR__"shandong",
                "southdown"  : __DIR__"shanlu5",        
    ]));

    set("outdoors", "��Ĺ");

    setup();
}

