// Room: /d/city3/shudao1.c
// This is a room made by roommaker. write by zhm/silversand.

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ�������е����ɽ������Χ�����ͱڣ�һ��С�ľͻ����ȥ��ʬ���޴棬
�ѹ��׻�˵�����֮�ѣ����������족���������Ѿ�����������츮֮���Ľ���֮
���ˡ�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"shudao2",
  "southwest" : "/d/heimuya/zhaoze/room16",
]));

	setup();
	replace_program(ROOM);
}
