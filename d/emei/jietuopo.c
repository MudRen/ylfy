// Room: /d/emei/jietuopo.c ������ ������


inherit ROOM;




void create()
{
	set("short", "������");
	set("long", @LONG
������һ������СϿ�ȣ����߳�����ï�ܵ�ֲ����̵����֡����޵�
���ܡ�����������ż�������Կ����м�ֻ���������ּ������ȥ���峿��
������͸�������������ϼε�㣬������ǧ��
LONG
	);

	set("exits", ([
                 "southup":__DIR__"chunyangd1",
                 "northdown":__DIR__"liangfengqiao",
                 "east":__DIR__"rongshulin1",
	]));
        set("objects",([
	 "/d/emei/npc/songshu" : 1,
        ]));

        set("outdoors", "emei");
	setup();
	replace_program(ROOM);
}



