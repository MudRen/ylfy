// Room: /d/city2/di_an1.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "�ذ��Ŷ����");
	set("long", @LONG
����һ����������Ĵ��������ͨ���ذ��š�����ͨ����������
�ϱ߾��Ƕ����ˣ�һ���˶��������Ƕ�ȥ��
LONG
	);
	set("outdoors", "city2");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"di_an2",
  "south" : __DIR__"dongchangdamen",
  "east" : __DIR__"wangfu3",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/d/city/npc/drunk" : 1,
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
