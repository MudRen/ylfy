// Room: /d/wudang/fuzhen5.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ǹ������㣬��ǽ��һ����ܣ������˵��̵ĵ伮����һЩ��
���ؼ����������䵱�صأ��䵱���Ӳ������ڡ�
LONG
);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/daodejing" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"fuzhen4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
