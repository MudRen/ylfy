// /d/emei/taolin.c ������ ����
// create by host dec,20 1997
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���߽�һƬ���֣����Ͻ����˷ۺ�Ĺ�ʵ������һƬ���������ߡ�����
��֦�����ң�̤�������ϸ�ݣ��������������ڿ����е������㣬��������
��Ƣ����������
LONG
	);
        set("outdoors", "emei");
	set("exits", ([ 
		"south" : __DIR__"liba",
                "north" : __DIR__"yunvfeng",
		]));
	set("objects", ([ 
	]));

	setup();
}
