// Room: /d/huashan/bingqifang.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
    �����ǻ�ɽ�ɵı����������ܷ��⼸�������ܣ������ǻ�ɽ�ɸ�
����ƽʱ�����õ��񽣡�
LONG
);
	set("objects", ([ /* sizeof() == 1 */
          "/clone/weapon/zhujian" : 4,
]));
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"square",
  "east" : __DIR__"liangong1",
]));
	set("no_fight", 1);

	setup();
	replace_program(ROOM);
}
