// Room: /d/city3/shudao3.c
// This is a room made by roommaker. write by zhm/silversand.

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ�������е����ɽ������Χ�����ͱڣ�һ��С�ľͻ����ȥ��ʬ���޴棬
ǰ����Լ����һ����������ܿ쵽�ɶ����ˡ�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : __DIR__"yidao2",
		"west" : __DIR__"shudao2",
		"south" : "/d/xuantian/pomiao",
		]));

	setup();
	replace_program(ROOM);
}
