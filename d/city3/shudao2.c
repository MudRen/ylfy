// Room: /d/city3/shudao2.c
// This is a room made by roommaker. write by zhm/silversand.

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ�������е����ɽ������Χ�����ͱڣ�һ��С�ľͻ����ȥ��ʬ���޴棬
�ѹ��׻�˵�����֮�ѣ����������족���㲻�ò�С�������ǰ����
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shudao3",
  "southeast" : __DIR__"shudao1",
]));

	setup();
	replace_program(ROOM);
}
