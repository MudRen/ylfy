// Room: /d/wudie/shanlu31.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "ɽ��С·");
        set("long", @LONG
ԶԶ�����Ѿ����Կ���ɽ�������ɽׯ��ɽׯ�������ơ�
��������Χ����ɽׯ��Χ����������ң���ɼ����ɾ���
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shanlu32",
  "south" : __DIR__"shanlu30",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
