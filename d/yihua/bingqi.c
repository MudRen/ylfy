inherit ROOM;

void create()
{
	set("short", "�껨��");
	set("long", @LONG
�������ƻ����ı����������ܷ��⼸�������ܣ��������ƻ�����
����ƽʱ�����õĽ���
LONG
	);
	set("exits", ([
		"west" : __DIR__"changlang",
	]));
	set("objects", ([
		"/clone/weapon/changjian.c" : 5]));

	set("no_fight", 1);
	
	setup();
	replace_program(ROOM);
}