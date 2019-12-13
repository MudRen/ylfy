// Room: /d/chengdu/xiaojie2.c
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
                "north" : __DIR__"xiaojie1",
                "east" : __DIR__"xiaojie3",
	]));
        set("objects", ([
            __DIR__"npc/kid" : 1,
            __DIR__"npc/liumang" : 1,
        ]));

	setup();
	replace_program(ROOM);
}

