inherit ROOM;
void create()
{
          set("short", "卧室");
        set("long", @LONG
通吃帮帮主杨小邪的卧室，房内的布置很平常，
墙角放着一张大床。
LONG
        );
        set("exits", ([
                   "east" : __DIR__"xiefj",
        ]));
        set("objects", ([
        ]));
        set("sleep_room", "1");
        setup();
        replace_program(ROOM);
}
