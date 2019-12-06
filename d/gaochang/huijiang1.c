// Room: /d/xingxiu/xxroad7.c
inherit ROOM;
void create()
{
        set("short", "帕米尔高原");
        set("long", @LONG
翻过天山顶峰, 便来到帕米尔高原。真是天外有天, 你仿佛来到另一个
世界。这儿冰雪消融，春意盎然。从那雪峰直垂下来的溪涧里，长满了野果
树。山风习习，空气清凉如水。山花烂漫, 几里地外也能闻到馥郁的花香。
北边一悬崖 (ya ) 挡住了你的视线。
LONG
        );
        set("exits", ([
            "southdown" : __DIR__"huijiang2",
        ]));
        set("objects", ([
                __DIR__"npc/huilang"  : 1,
        ]) );
        set ("item_desc", ([
                "ya" : "想爬崖? 别做梦了。\n"
        ])  ) ;
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
        replace_program(ROOM);
}
