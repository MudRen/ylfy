
inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
������һ���������ּ�С���ϣ���������ɭɭ�����֡�һ����紵��
����, ����ɳɳ������, ���㲻��������
LONG
);
	set("outdoors", "room16");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room13",
  "southwest" : __DIR__"room14",
  "west" : __DIR__"xiaodou",
  "northeast" : "/d/city3/shudao1",
]));

	setup();
	replace_program(ROOM);
}
