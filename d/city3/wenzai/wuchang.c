// Room: /d/city3/wenzai/wuchang.c
// This is a room made by roommaker. write by zhm/silversand.

inherit ROOM;

void create()
{
	set("short", "�¼����䳡");
	set("long", @LONG
�������¼Һ�Ժ��һ����Ժ�������ܷ�����������õĵ��ߣ��ƺ����¼�
�����䳡����ȴû����������
LONG
);
	set("objects", ([ /* sizeof() == 1 */
  "/d/shaolin/npc/mu-ren" : 3,
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"houyuan",
]));

	setup();
	replace_program(ROOM);
}
