// Room: /d/wudie/shanlu.c
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
  "northeast" : __DIR__"shanlu2",
         "southeast" : "/d/hainan/underhill2",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
