// Room: /d/kunlun/ssy.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "��ʥ��");
	set("long", @LONG
���ﳤ���˼����������й������죬����ɭɭ����ѩ��������ֱ��������
�Լ�����������Դ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wft",
]));
	set("outdoors", "ssy");

	setup();
	replace_program(ROOM);
}
