// Room: /d/emei/shangu.c ������ ɽ�ȿ�

inherit ROOM;

void create()
{
	set("short", "ɽ�ȿ�");
	set("long", @LONG
������һ����ľ�ͷ����·��Ȼ���ʣ�̧ͷ��ȥ��ֻ��ǰ�治Զ����
һ��ɽ�ȣ�����ï�ܣ��ٲݴ������ڹȿڶ��洦��һ�����ã���ʱ������
����ľ����ô�����
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                 "east" : __DIR__"qianfoan",
		 "south" : __DIR__"jiudaoguai1",
                 "northdown":__DIR__"yixiantian",
	]));

        set("objects", ([ 
                "/d/emei/npc/qiaofu" : 1,
            ]));

	setup();
}



