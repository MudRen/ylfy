// Room: /d/hainan/haibian.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ǰ����һ���޼ʵĴ�,����Ƕ��ͱ�����ʯ��.��Զ���ĺ�ˮ
��,һ���ʯ�ر�����עĿ,�������'���ĺ���'����.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shatan",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yuwen.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
