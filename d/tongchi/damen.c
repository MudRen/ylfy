inherit ROOM;
#include "/clone/item/liuxing.h"
void create()
{
        set("short", "ͨ�԰����");
        set("long", @LONG
�����������������ͨ�԰�߽�һ����ǽΪ��ɫ����ʯ���ɣ�����
ͭ�ţ������ߣ��Ŷ���¥����������֡�ͨ�԰������Ȼ������
LONG
        );
        set("exits", ([
                 "north" : __DIR__"tingyuan",
                 "south" : __DIR__"shandao4",
        ]));
        set("objects", ([
        ]));
        setup();
        replace_program(ROOM);
}
