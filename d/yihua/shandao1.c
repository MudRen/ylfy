// Room: /yihua/shandao1.c
// rtm 2000/03/04 

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
	����һ���������������ʻ���ɽ���������졣����Ӱ��
�����������������صĸо����ڻ���֮����ϡ�ɼ��۷������ȥ,��
������ȥֻ��������һ���ߴ�Ĺ�����ϡ�ɼ���
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"southdown" : __DIR__"shandao",
		"northup" : __DIR__"shandao2",
	]));

	setup();
	replace_program(ROOM);
}

