// Room: /d/wudie/shanlu26.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "ɽ��С·");
        set("long", @LONG
����������������ͷ�����Ƽ�ɽ�塣
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"shanlu27",
  "southdown" : __DIR__"shanlu25",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
