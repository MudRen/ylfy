// Room: /d/nanyang/shijie3.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "ʯ��");
    set("long", @LONG
ʯ���������ƺ���ÿ�����Щ�����µ�ɽ���������������
�����Ϊһˬ��Զ����������ˮ�������н�Զ��ɽ���Ϲ���
�˺��ܵ����ܣ��������ҡ߮��
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
  "/d/shaolin/npc/xiao-hai" : 1,
]));
    set("no_clean_up", 0);
    set("outdoors", "shaolin");
    set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shijie2",
  "westup" : __DIR__"shijie4",
]));
    setup();
    replace_program(ROOM);
}
