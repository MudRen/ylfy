// xiaolu2.c �ּ�С��
// by Xiang
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "�ּ�С��");
    set("long", @LONG
������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�������Ҷ
��������������������Ķ����������ƺ���һ����ª��СԺ��
LONG
    );
    set("exits", ([
        "north" : __DIR__"xiaoyuan",
        "south" : __DIR__"xiaolu1",
    ]));
    create_door("north", "����", "south", DOOR_CLOSED);
    setup();
}
