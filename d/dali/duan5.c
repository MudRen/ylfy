// Room: /d/dali/duan5.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺20ʱ44��9�롣

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�����������ĳ���ͨ�������ĺ�Ժ���������������ɽ�����
�Ĳ軨ͼ������̬���죬�������档
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"duan4",
  "southeast" : __DIR__"duan6",
]));

	setup();
}

