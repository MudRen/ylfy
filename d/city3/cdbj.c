// Room: /chengdu/cdbj.c
// oooc: 1998/06/24

inherit ROOM;

void create()
{
        set("short", "�����ھ�");
	set("long", @LONG
��ǰ���������ʯʨ�ӣ��ļ俪�Ĵ���ţ������Ǵ�������
�߹ҡ���ʱ�м�����ʦ�����������ſ��Ǽ��������Ż�����ʦ����
������ȥ�����࣬�ֵ��º���Щ��������ӣ����������ǿ���ң�
���顺�����ھ֡��ĸ����֡��������Զ�������ĳɶ������ھ��ˡ�
LONG
	);

	set("exits", ([
                "east" : __DIR__"beijie2",
	]));

        set("objects", ([
            __DIR__"npc/biaotou" : 2,
        ]));

	setup();
	replace_program(ROOM);
}

