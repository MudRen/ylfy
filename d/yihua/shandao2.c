// Room: /yihua/shandao1.c
// rtm 2000/03/04 

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ������ˮ���̳ɵĿ����,ÿ�鶼�ǳ�Լ�˳ߣ���Լ����
���������룬�����ɶ��칤�������������де�õ��ԣ���ʱ���Կ���
һ��ֻҰ�ñı�������Ծ��������������ȥ��һ���޴�Ĺ���ΡȻ
������
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"southdown" : __DIR__"shandao1",
		"northup" : __DIR__"juebi",
	]));

	setup();
	replace_program(ROOM);
}

