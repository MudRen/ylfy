// Room: /d/wudie/shanlu30.c
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
  "southwest" : __DIR__"shanlu29",
  "north" : __DIR__"shanlu31",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
