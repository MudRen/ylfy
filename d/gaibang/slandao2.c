// Room: /d/gaibang/slandao2.c
// Date: Haa 96/03/22
#include <room.h>
inherit ROOM;


void create()
{
	set("short", "����");
	set("long", @LONG
����ؤ�� �������ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ� 
LONG
	);
	set("exits", ([
			"northeast" : __DIR__"undersl",
			"southwest" : __DIR__"slandao1",
	]));
	set("objects",([
		"/clone/food/jitui" : 3,
		"/clone/food/jiudai" : 1,
	]));
	setup();
	replace_program(ROOM);
}

