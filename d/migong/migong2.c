#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
		����һ���˼�������ɽ�ȣ�Զ����Լ�ܿ������͵�ɽ�£�һ��
		��ȥ���ܶ���ãã���������ұ���һ������С��ֱ���ֺ�֮�С�
LONG );
	set("exits",
		([
		//"west" : "/d/automap/1499.c",
		"east" : __DIR__"migong3",
		]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
