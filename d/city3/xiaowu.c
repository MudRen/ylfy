// Room: /d/city3/xiaowu.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
һ�����ܿյ�����ʲ�����Ҳû�еĿշ��䡣ֻ�ڷ����м����
һ�����ӣ������ϰ����˵��ԵĹ��ߡ�
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zhubaodian",
]));

        set("objects", ([ 
  __DIR__"npc/xie" : 1,
]));

	setup();
	replace_program(ROOM);
}
