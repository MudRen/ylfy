inherit ROOM;
void create()
{
          set("short", "偷怪居");
        set("long", @LONG
偷怪居,通吃帮六怪之一梁空空的住处，偷怪最喜欢偷东西，
因此他很少在房里，整天都在外面偷自偷那，皇宫是他最常去的
地方。
LONG
        );
        set("exits", ([
                 "south" : __DIR__"jiujv",
                 "west" : __DIR__"fengjv",
        ]));
        set("objects", ([
        "/d/tongchi/npc/touguai":1,
        ]));
        setup();
        replace_program(ROOM);
}
