inherit ROOM;
void create()
{
          set("short", "休息室");
        set("long", @LONG
休息室，通吃帮的弟子门练功累了就可以来这里休息。房里零乱的
放着几张床。
LONG
        );
        set("exits", ([
                   "east" : __DIR__"tianjin",
        ]));
        set("objects", ([
        ]));
        set("sleep_room", "1");
        set("no_fight", "1");
        setup();
        replace_program(ROOM);
}
