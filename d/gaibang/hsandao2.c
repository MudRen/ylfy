// Room: /d/gaibang/wdandao2.c
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
			"southwest" : __DIR__"underhs",
			"northeast" : __DIR__"hsandao1",
	]));
	set("objects",([
		"/clone/food/jitui" : 3,
		"/clone/food/jiudai" : 1,
	]));
	setup();
	replace_program(ROOM);
}

