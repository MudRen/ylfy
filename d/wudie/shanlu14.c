// Room: /d/wudie/shanlu14.c
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
  "southdown" : __DIR__"shanlu13",
  "northup" : __DIR__"shanlu15",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
