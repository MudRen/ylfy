// Room: /d/gaibang/undertree.c
// Date: Haa 96/03/22
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "��������");
	set("long", @LONG
���ǻ�ɽ�������µ�Сɽ���������������õģ������˸������
����ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ����
LONG
	);
	set("exits", ([
		"out" : "/d/huashan/sheshen",
		"northeast":__DIR__"hsandao2",
	]));
/*
	set("objects",([
		CLASS_D("gaibang") + "/li-sh" : 1,
	]));
*/
	setup();
	replace_program(ROOM);
}


