// Room: /d/wudie/dyt.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "蝶翼堂");
        set("long", @LONG
这里是一处平地，是琼雅蝶练剑的地方，因为彩碟快要死的时候都
会飞到这里来，死后就留下它那翅膀。微风吹过，片片彩碟的翅膀随风
起舞，琼雅蝶就是在这里练成了旷世绝学---蝶翼剑法。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"pjt",
  "south" : __DIR__"cdt",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
