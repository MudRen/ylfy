// This is a room made by roommaker.

inherit ROOM;

void create()
{
    set("short", HIY"园中小路"NOR);
    set("long", ""HIW"你顺着小路慢慢的走着，发现玫瑰园里的花开放的异常\n"
"鲜艳，令人有一种心旷神怡的感觉，不禁贪婪的深呼吸了几\n"
"口这里清新的空气。"NOR"\n");
        set("exits", ([
                "east" : __DIR__"rose1",
                "west" : __DIR__"rose3",
            ]));
     set("no_fight",1);
    setup();
    replace_program(ROOM);
}
