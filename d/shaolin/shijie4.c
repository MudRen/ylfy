// Room: /d/nanyang/shijie4.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "ʯ��");
    set("long", @LONG
ˮ��Խ��Խ��ɽ�������ŨŨ��ˮ����ʯ���ϣ����ѵ�ɽ
϶�У�������һ����ϸϸ��Ȫˮ�����һ�ɳα̵�СϪ����ɽ��
������ȥ����Χ���⵴���������������������ɾ���
LONG
    );
    set("no_clean_up", 0);
    set("outdoors", "shaolin");
    set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"shijie3",
  "northup" : __DIR__"shijie5",
]));
    setup();
    replace_program(ROOM);
}
