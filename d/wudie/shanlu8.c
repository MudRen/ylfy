// Room: /d/wudie/shanlu8.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "ɽ��С·");
        set("long", @LONG
С·�����̺��٣���Χ��ɫ�����������˼��ɾ���
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shanlu7",
  "northup" : __DIR__"shanlu9",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
