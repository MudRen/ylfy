// Room: /d/dali/duan1.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��21�գ�����ʱ�䣺17ʱ28��57�롣

inherit ROOM;

void create()
{
	set("short", "����ֵ�");
	set("long", @LONG
��ǰ��һ����ֱ�Ĵ�֣�������ʯƽ�̣���Ϊ����ǰ����һ��
�󸮵ڣ�����ǰ������죬���Ϸֱ�����ǡ����ϡ��������������֣�
������д���ǡ�������������
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xbdajie1",
  "east" : __DIR__"duan2",
]));

	setup();
}

