// shanlu10.c By csy 98/12

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", YEL"ɽ·"NOR);
    set("long", @LONG
������������ȣ�����ɽ��������嶥��������֮�У���֪��ͷ�� ����
���¡�ǰ��羰���ģ�ֻ�����ʵ��̫�գ�ɽʯ��������׵�����Ԩ������
���ײ������ˡ�
LONG
     );

    set("exits", ([ 
                "westdown"  : __DIR__"shanlu9",
                "eastup"  : __DIR__"duanchang",                         
    ]));

    set("outdoors", "��Ĺ");

    setup();
}

