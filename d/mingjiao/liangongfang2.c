// Room: liangongfang2.c

inherit ROOM;

void create()
{
        set("short", "练功房");
        set("long", @LONG
这是一间摆设简单的练功房，地上凌乱地扔了许多草蒲团，几个
教中弟子正在这里打坐、吐纳，为避免影响他人练功，从没人在这里
交谈，静静地只能听到些细微的呼吸声。

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiuxishi",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

