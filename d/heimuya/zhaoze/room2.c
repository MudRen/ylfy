
inherit ROOM;
void create()
{
	set("short", "С��");
	set("long", @LONG
������һ���������ּ�С���ϣ���������ɭɭ�����֡�һ����紵��
����, ����ɳɳ������, ���㲻��������
LONG
	);
	set("outdoors", "room2");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room3",
  "east" : __DIR__"room1",
]));

	setup();
	replace_program(ROOM);
}
