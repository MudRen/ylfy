// Room: /d/city/xidajie1.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
	����һ����������ʯ��ֵ���������ͷ���졣��������������ڣ�����
ϡ�٣������ĵغ������塣������һ�����ֵĹ㳡���ϱ��Ǳ�Ӫ�����߾��������ˡ�
LONG
	);
	set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xidajie2",
  "north" : __DIR__"yamen",
  "south" : __DIR__"bingyindamen",
  "east" : __DIR__"guangchang",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/drunk" : 1,
]));
	setup();
	replace_program(ROOM);
}
