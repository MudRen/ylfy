// cuiping2.c

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
�����ڴ���ɽ���ϣ���ľ���죬�Ѽ����ա�ɽ�־��ף�����������
�ã�һ�г��׾���ϴ����ɽ���о�������ɽ��ɫ��
LONG
	);
	set("exits", ([
		"eastup"   : __DIR__"xuankong1",
		"eastdown" : __DIR__"cuiping1",
	]));
	set("objects", ([
		"quest/skills2/wakuang/kuang/kuangmai" : 1,
	])); 
	    set_temp("wayao1",2);
	set("outdoors", "hengshan");
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 3180);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

