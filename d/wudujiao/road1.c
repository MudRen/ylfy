// by mayue

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ�����ϵĻ��������������һƬƬ�����͵�ˮ��
�����е���ͯ������������������������������˶���������
����ͷ�󺹵ĴҴҸ�·���ƺ���������������������԰��⡣
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"zuixianlou",
		"south" : __DIR__"road2",
//		"west" : __DIR__"wumiao",
		"north" : "/d/taishan/yidao",
	]));
 
	setup();
	replace_program(ROOM);
}

