// Room: /d/emei/baoguosi.c ������ ����1

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ����ʯ�̳ɵ�С�����������۵�ͨ��ǰ�������������ܵ����֡�
�����˼�������Ω�����ߵ��·������ľ������΢�紵����Ҷ����������
���������˳���Ϊ֮һ�ӣ����Ǿ��ѵ��������ڡ�
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"baoguosi",
                "south":__DIR__"fuhusi1",
	]));
        set("outdoors", "emei");

	setup();
}
