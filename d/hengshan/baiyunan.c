// baiyunan.c

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
������Ǻ�ɽ�ɰ����֡����ڹ�����¹�������������һ�����ţ�
�ı���Ȼ����ɽ�����𽭺���û�뵽���־�Ȼ����һ����˹��
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"south"  : __DIR__"square",
		"north"  : __DIR__"changlang",
		"west"   : __DIR__"byawest",
		"east"   : __DIR__"byaeast",
	]));
	
	set("objects", ([
		__DIR__"npc/xian" : 1,
		__DIR__"npc/lin" : 1,
	//"/quest/menpai/newmp/shi5" : 1,
	//"/d/biwu/champion_hengshan" : 1,
	]));
	set("valid_startroom", 1);
	set("coor/x", 40);
	set("coor/y", 3210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
	"/clone/board/hengshan_b"->foo();
}

