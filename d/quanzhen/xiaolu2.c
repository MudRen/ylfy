// xiaolu2.c �ּ�С��

inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long", @LONG
������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�������Ҷ
��������������������Ķ�����
LONG
	);

	set("exits", ([
		"northup" : __DIR__"houshan",
		"south" : __DIR__"xiaolu1",
	]));
	
	set("outdoors", "quanzhen");

	setup();
	replace_program(ROOM);
}

