// Room: /d/chengdu/xiaojie.c
// oooc 1998/06/21 

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ����ʯ���̳ɵ�С�֣�·��ǳ��ɾ���������Ϊÿ����
�������й��˰������ɨһ�顣�����ϱ߿�,�����õĻ���������
��Լ��������ͤ��һ�ǡ������и����ӵꡣ
LONG
	);
        set("outdoor","chengdu",);

	set("exits", ([
                "south" : __DIR__"xiaojie2",
                "northwest":__DIR__"xiaojie",
                "east" : __DIR__"zongzidian",
	]));

	setup();
	replace_program(ROOM);
}

