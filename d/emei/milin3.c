// Room: /d/emei/milin3.c ������ ����3

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
                "west"  : __DIR__"basipan3",
                "up" : __DIR__"shanpo",
	]));

	setup();
	replace_program(ROOM);
}



