// Room: /d/wudie/shanlu38.c
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
  "northwest" : __DIR__"shanlu39",
  "southeast" : __DIR__"shanlu37",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
