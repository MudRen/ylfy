// Room: /d/city3/wenzai/houyuan.c
// This is a room made by roommaker. write by zhm/silversand.

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�����Ǹ����ĺ�Ժ���������죬֪�������ϲ�ͣ�ؽ��ţ��и�
������������ɨ�ŵ��档
LONG
);
	set("outdoors", "city3");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/atu" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"wuchang",
  "north" : __DIR__"zoulang4",
]));

	setup();
	replace_program(ROOM);
}
