
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", BLU "����"NOR);
    set("long", @LONG
���Ų��ߵ�����ֻ����ľ�Դ䣬ɽ����ѡ������Ƕ��͵�ʯ�ڣ�
��������һ��С·��֪ͨ������ȥ��
LONG
    );

    set("outdoors", "shengu");

    set("exits", ([
        "enter" : __DIR__"shandong",
        "north" : __DIR__"qiaobi",
 
    ]));

    setup();
    replace_program(ROOM);
}
