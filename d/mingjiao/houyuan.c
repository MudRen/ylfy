// Room: houyuan.c

inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǹ�Ժ�ӣ�Ժ�л��ܰ��㸡�����������᷿�Ĵ�����
͸���ƻ�֮�⣬������˸���ѣ��ƺ�����Ӱ�ζ������������
�Ӵ��߹���
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"xiaoting",
  "west" : __DIR__"xxiangfang",
  "north" : __DIR__"beixiangfang.c",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
        replace_program(ROOM);
}

