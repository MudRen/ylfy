// Room: /d/wudie/shanlu9.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "ɽ��С·");
        set("long", @LONG
ɽ��С·����ͨ�ģ�ȸ������ò����ڡ�
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"shanlu10",
  "southdown" : __DIR__"shanlu8",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
