// Room: /d/shaolin/wuchang1.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "���䳡");
    set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡�
��ǧ��Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����䳡�м�
�����Ų���ľ�ˡ�ʮ����ɮ��������ϰ���ա�������һ����ɮ����
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"zoulang2",
  "north" : __DIR__"zoulang6",
  "west" : __DIR__"banruo5",
  "east" : __DIR__"wuchang",
]));
    set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mu-ren" : 4,
]));
    set("no_clean_up", 0);
    set("outdoors", "shaolin");
    setup();
    replace_program(ROOM);
}
