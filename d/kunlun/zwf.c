// Room: /d/kunlun/zwf.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
������������Ա���һСͤ������Щʯ��ʯ�ʹ���������Ϣ����Ϊ����
ɽ��·�գ����������ɱ����˸�Сͤ������Ϣ��
LONG
	);
	set("outdoors", "zwf");
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"klt",
  "north" : __DIR__"wft",
]));

	setup();
	replace_program(ROOM);
}
