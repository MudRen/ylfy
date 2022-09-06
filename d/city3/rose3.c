// This is a room made by roommaker.

inherit ROOM;

void create()
{
    set("short", MAG"园中小院"NOR);
    set("long", ""MAG"你走着走着发现自己已经身处在玫瑰丛中，一座很别致\n"
"的小木屋出现在你的眼前，木屋的旁边有一圈篱笆，由于玫\n"
"瑰花开的异常艳丽，所以你并没有怎么注意到它的存在。篱\n"
"笆旁有一口小井。"NOR"\n");
       set("resource/water", 1);
        set("exits", ([
                "east" : __DIR__"rose2",
                "west" : __DIR__"rose4",
            ]));
     set("no_fight",1);
    setup();
    replace_program(ROOM);
}

