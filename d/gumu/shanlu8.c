// shanlu8.c By csy 98/12

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", YEL"ɽ·"NOR);
    set("long", @LONG
�˴���һ�����ɽ·����������������������Ω�������ȵף����Է��ۣ�
��ɽ�żţ�΢��������ãã����ֻ��һ�˶��ѡ���������ԶԶ�غ�����һ
���߶����ͱڡ�
LONG
        );

    set("exits", ([ 
                "northup"  : __DIR__"qiaobi",
                "southeast"  : __DIR__"shanlu7",        
    ]));

    set("outdoors", "��Ĺ");

    setup();
}

