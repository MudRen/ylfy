// Room: /d/emei/bailongdong.c ������ ������
// create by host dec,20 1997

inherit ROOM;


void create()
{
	set("short", "������");
	set("long", @LONG
��������˵�ǡ����ߴ����еİ�������������֮������һ��������Ҷ���
�����������ۣ�ʯ���أ��ٿ�����һ���������Ѷ��У�����һ����������
�����ľ�ͷ��Խ��������ȥ��������ĳ�ʪ��ϢԽ��Խ�ء����ﱱ��������
�֣�������������
LONG
	);

	set("exits", ([
                 "southup" : __DIR__"shierpan1",
		"west" : __DIR__"gudelin",
                "northeast" : __DIR__"qingyinge",
	]));


	set("objects",([
	]));
	setup();
}
