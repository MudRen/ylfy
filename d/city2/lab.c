// Room: /d/city2/lab.c
inherit ROOM;
void create()
{
	set("short", "ʵ����");
	set("long", @LONG
����ƻ�ͨ����ÿ�춼�г����ڰ�ҹ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
"up" : __DIR__"tian_anm",	
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
