inherit ROOM;
void create()
{
          set("short", "疯怪居");
        set("long", @LONG
疯怪居，通吃帮六怪之一疯怪南怀人的居所，?
疯怪由于做起事来疯疯癫癫，被其他五怪关在
疯怪居里不让他出去。
LONG
        );
        set("exits", ([
                  "east" : __DIR__"toujv",
        ]));
        set("objects", ([
        "/d/tongchi/npc/fengguai":1,
        ]));
        setup();
        replace_program(ROOM);
}

