// Room: /d/wudie/shanlu1.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "ɽ��С·");
        set("long", @LONG
С·�����̺��٣���Χ��ɫ�����������˼��ɾ���
LONG
);
        set("no_clean_up", 0);
     set("exits", ([ /* sizeof() == 3 */
"northup" : __DIR__"shanlu2",
]));

        setup();
        replace_program(ROOM);
}
