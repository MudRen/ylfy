// Room: /d/wudie/shanlu5.c
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
  "northeast" : __DIR__"shanlu6",
  "southup" : __DIR__"shanlu4",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
