//xiaolu3.c  

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ּ�С��");
        set("long", @LONG
������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�������Ҷ
��������������������Ķ�����
LONG
        );

        set("exits", ([
                "west" : __DIR__"yunjiyuan",
                "east" : __DIR__"xiaolu1",
        ]));

	setup();
	replace_program(ROOM);
     
}

