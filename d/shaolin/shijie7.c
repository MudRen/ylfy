// Room: /d/nanyang/shijie7.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "ʯ��");
    set("long", @LONG
ʯ�������������죬�ٲ��ڽ���Խ��ԽС��ˮ��Ҳ����Զȥ
��λ���Żһ�ɫɮ�µ�ɮ�˲����������������ɽ��ʱ��Ų���
�ȣ������Ǹ�����ӡ�����Զ�����ƺ����Կ���ʯ��һ�ǡ�
LONG
    );
    set("no_clean_up", 0);
    set("outdoors", "shaolin");
    set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shijie6",
  "east" : __DIR__"shanmen",
]));
    setup();
    replace_program(ROOM);
}
