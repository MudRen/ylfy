// Room: /chengdu/shimiao.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "�Ѿ���");
	set("long", @LONG
�Ѿ������д�������һ���֡�֮�ƣ�ʼ����������ꡣֻ��
���ڵ��������ͥԺ�����ľ���졣��������ҷ���������
�������е�����������ʿ���������޺��ȣ�������ü��Ŀ��
LONG
	);

	set("exits", ([
                "south" : __DIR__"dongjie2",
                "north" : __DIR__"shimiao2",
	]));
        set("objects", ([
             __DIR__"npc/zike" : 1,
             __DIR__"npc/xiaoheshang1" : 1,
        ]));


	setup();
}

