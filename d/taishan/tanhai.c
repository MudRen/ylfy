// Room: /d/taishan/.c
// Date: CSWORD 96/03/25
inherit ROOM;
#include "/clone/item/liuxing.h"
void create()
{
    set("short", "̽��ʯ");
    set("long", @LONG
����һ���ɽ�����ͻ���ľ�ʯ����Լ�����࣬��ֱָ������
��ʯ��������ƾ������Ұ�������������о��ߵ�ɫ���ˣ���ͨ��һ��
�������ʵ����̽��ʯ��
LONG
    );
    set("exits", ([
        "westdown" : __DIR__"riguan",
        "east" : __DIR__"dongtian",
    ]));
    set("outdoors", "taishan");
    setup();
    //replace_program(ROOM);
}
