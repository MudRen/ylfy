// Room: /d/emei/shanmen.c ������ ɽ��
// create by host dec,12

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "ɽ��");
    set("long", @LONG
�����Ƕ��ҵ�ɽ���£�����ɽ������������Լ�ɼ���һ��ʯ����ɽ��
���죬���ż�������͡�һ���޴���Ʒ������ʯ���м䣬�Ʒ���������
������Ŀ�������������֣������ҡ���
LONG
    );

    set("exits", ([
        "north":__DIR__"shanlu3",
        "southup": __DIR__"baoguosi",
    ]));

    set("outdoors", "emei");
    set("objects",([
    ]));
    setup();
}