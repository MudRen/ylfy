// Room: /d/wudie/shanlu2.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "ɽ��С·");
        set("long", @LONG
С·�����̺��٣���Χ��ɫ�����������˼��ɾ���
LONG
);
        set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"shanlu",
  "northwest" : __DIR__"shanlu3",
    "southdown" : __DIR__"shanlu1",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
