// Room: /d/wudang/shanmen.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "�䵱ɽ��");
    set("long", @LONG
�����ǰ��һ����ľ��ï�ĸ�ɽ������ɽ������������Լ�ɼ���һ��ʯ
����ɽ�����죬���ż�������͡�ʯ����д�š��䵱ɽ���������֣�ԭ����
���������������䵱ɽ��
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guest" : 1,
]));
    set("outdoors", "wudang");
    set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"wdroad8",
  "westup" : __DIR__"shijie11",
]));
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
