// Room: /d/dali/huanggong13.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺21ʱ27��26�롣

inherit ROOM;

void create()
{
	set("short", "[1;33m������[2;37;0m");
	set("long", @LONG
�������Ǳ����۵��޹����ڵأ����������ʹ���������գ���
����װ��Ů������ʰ���䡣������������Ǽ���С��Ǿ���
�ʵ���Ϣ�ĵط��ˡ�
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"huanggong11",
  "southdown" : __DIR__"huanggong15",
  "west" : __DIR__"huanggong14",
]));

	setup();
}

