// Room: /d/taishan/.c
// Date: CSWORD 96/03/25
inherit ROOM;
#include "/clone/item/liuxing.h"
void create()
{
    set("short", "���˷�");
    set("long", @LONG
����λ����ʶ���������ĵط�����״����һ�����͵����ˡ�
�����лƻ�������·��ΪΣ�գ������ڽ�·��д�ϡ��س��ҡ���
�����������߱���᷶��ı����š�
LONG
    );
    set("exits", ([
        "east" : __DIR__"yuhuang",
        "northup" : __DIR__"beitian",
    ]));
    set("objects",([
        __DIR__"npc/wei-shi1" : 2,
		__DIR__"npc/yuqingzi" : 1,
    ]));
    set("outdoors", "taishan");
    setup();
    replace_program(ROOM);
}
