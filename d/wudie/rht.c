// Room: /d/wudie/rht.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "�ﻨ��");
        set("long", @LONG
���ǵ���ɽׯ�Ļ�԰�����и��ֻ��ܣ�԰�����лƻ��ſ���������
�ɣ����ܲ�㣬�����˱ǡ�԰���ܵ�Χǽ������������ǽ������ĵ����
����ϡ����Ʒ����ʱ��֪�Ӻδ����˺����ڻ���Ϸˣ��
LONG
);
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"ydt",
  "west" : __DIR__"pjt",
]));
        set("sleep_room", "1");

        setup();
        replace_program(ROOM);
}
