// Room: /d/gaibang/undersl.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "�ݽǱ�");
	set("long", @LONG
�������Ǽҳ�����ľ������档�����������õģ������˸�����
�����ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "up" : "/d/nanyang/chufang2",
  "southwest" : __DIR__"slandao2",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/kungfu/class/gaibang/he-bj" : 1,
]));
	setup();
	replace_program(ROOM);
}
