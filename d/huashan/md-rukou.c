// /d/huashan/md-rukou.c
// Hop 05/15/97
#include <room.h>
inherit ROOM;
void create()
{ 
    set("short","ɽ��");
    set("long", @LONG
������ɽ������ڡ�ɽ���������һ�ţ�������ֲ��嶫��������ֻ
�ú���Ϲ���ˡ�
LONG
    );
    set("exits", ([
        "north" : __DIR__"siguoya",
        "south" : __DIR__"midong",
    ]));             
    setup();
    replace_program(ROOM);
}
