// Room: /d/new/liangong2.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǽ������������ĵط����м���������������ר�����µ�����
���м����ֱֳ���,�ڻ������,���鶯������������ڵ��ϵ�������
����������
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"beidajie1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tong-ren" : 1,
]));
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}
