inherit ROOM;
void create()
{
          set("short", "庭院");
        set("long", @LONG
通吃帮外观及为宏伟，但进到里面却又是另一番景象。庭院，四周自有竹
篱笆，也许日久失修，篱笆有的已倒塌，有的已盘满山藤茅草。一副古陋样。
LONG
        );
        set("exits", ([
                   "south" : __DIR__"damen",
                     "north" : __DIR__"road",
                     "west" : __DIR__"xiaomaowu",
         ]));
        set("objects", ([
       __DIR__"npc/asan" : 1,
       __DIR__"npc/asi" : 1,
        ]));
        set("outdoors", "city");
        setup();
        replace_program(ROOM);
}
