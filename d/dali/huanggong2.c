// Room: /d/dali/huanggong2.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺21ʱ27��26�롣

inherit ROOM;

void create()
{
	set("short", "[1;33m������[2;37;0m");
	set("long", @LONG
�����Ǵ��ǰ�������š�������ȥ���������컧������������
�ݶ�����ͭ�ߣ������������֮״��Ρ��׳������ҫ��Ŀ����������
������������Ѳ�ӡ�
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"huanggong1",
  "north" : __DIR__"huanggong3",
]));

	setup();
}

