//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
��˵�����,����������,�����ڿ϶����������.
LONG
        );

        set("exits", ([
                "eastup" : __DIR__"shanlu3",
                "westdown" : __DIR__"shanlu5",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


