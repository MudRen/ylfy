// Room: /d/wudie/shanlu40.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "ɽ·��ͷ");
        set("long", @LONG
ǰ���������ɾ��ˡ����޵��ɾ�������ǰ�����ƺ����������š�
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shanlu39",
  "northup" : __DIR__"jm",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
