// Room: /d/emei/rongshulin2.c ������


inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һ������С·���Դ�����ּ��׺����������û��ݣ��������µ�·����
���˹����Ͼ����컨Ӱ�ȣ�ÿ����������֮ʱ����ɫ�����������Ĵ�����ʱ
��Ʈ���ּ䣬�����˺���һ�㡣���������������续��
LONG
	);

	set("exits", ([
                 "west":__DIR__"rongshulin1",
                 "north":__DIR__"yanbohu",
	]));
        set("outdoors", "emei");
	setup();
}