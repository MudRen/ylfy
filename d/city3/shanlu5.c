//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
���Թ�������,����������ס��ǿ�ҵ�����,��֪�˵�
�����쳣�����ķ�.�������߾�������---�ɶ���.
LONG
        );

        set("exits", ([
                "eastup" : __DIR__"shanlu4",
                "west" : __DIR__"guandao4",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


