// Room: /d/chengdu/xiaojie.c
// oooc 1998/06/21 

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ����ʯ���̳ɵ�С�֣�·��ǳ��ɾ���������Ϊÿ����
�������й��˰������ɨһ�顣�����ϱ߿�,�����õĻ���������
��Լ��������ͤ��һ�ǡ�
LONG
	);
        set("outdoor","chengdu",);

	set("exits", ([
                "north" : __DIR__"dongjie2",
                "southeast":__DIR__"xiaojie1",
	]));

	setup();
	replace_program(ROOM);
}

