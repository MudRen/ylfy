
inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
һ���������·��Զ���ƺ��������䡣
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
"northwest": "/d/quanzhou/nanhu1",	
		"south": __DIR__"road1.c",
	]) );

	setup();
	replace_program(ROOM);
}

