// Room: /d/wudie/wdt.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "舞蝶堂");
        set("long", @LONG
走进来一看，这哪是什么彩色的云，原来是漫天在飞的彩蝶，红
的，黑的，黄的......什么颜色都有。园中有一石碑，碑上刻着一首诗：
        山青绿水花满地，舞蝶群群伴君行。
            遥视彩云落人间，确见花蝶满园香。
LONG
);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yadie" : 1,
]));
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"pxt",
  "north" : __DIR__"pjt",
  "east" : __DIR__"ydt",
  "west" : __DIR__"cdt",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
