// Room: /yihua/shandao.c
// rtm 2000/03/04 

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
	����һ���������������ʻ���ɽ���������졣����
Ӱ�������������������صĸо����ڻ���֮����ϡ�ɼ��۷��
����ȥ,��������ȥֻ��������һ���ߴ�Ĺ�����ϡ�ɼ���
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" :"/d/xiaoyao/hubian",
		"northup" : __DIR__"shandao1",
	]));

	setup();
	replace_program(ROOM);
}

