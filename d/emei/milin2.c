// Room: /d/emei/milin2.c ������ ����2


inherit ROOM;




void create()
{
	set("short", "����");
	set("long", @LONG
����һ����ʯ�̳ɵ�С�����������۵�ͨ��ǰ�������������ܵ����֡�
�����˼�������Ω�����ߵ��·������ľ������΢�紵����Ҷ����������
���������˳���Ϊ֮һ�ӣ����Ǿ��ѵ��������ڡ�
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "east"  : __DIR__"fuhusi1",
                "south" : __DIR__"liangfengqiao",
	]));

	setup();
	replace_program(ROOM);
}



