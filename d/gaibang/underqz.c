// Room: /d/gaibang/undertree.c
// Date: Haa 96/03/22
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "��ǹ����");
	set("long", @LONG
����Ȫ����ǹ���µ�С���������������õģ������˸��������
��ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ����
LONG
	);
	set("exits", ([
		"out" : "/d/quanzhou/tieqiang",
		"northeast":__DIR__"qzandao2",
	]));
/*
	set("objects",([
		CLASS_D("gaibang") + "/li-sh" : 1,
	]));
*/
	setup();
	replace_program(ROOM);
}


