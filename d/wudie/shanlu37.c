// Room: /d/wudie/shanlu37.c
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
  "northwest" : __DIR__"shanlu38",
  "south" : __DIR__"shanlu36",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
