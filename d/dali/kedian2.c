// Room: /city/kedian2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�͵��¥");
	set("long", @LONG
�������ڿ͵��¥�������ϣ����������ӿͷ��ﲻʱ�غ����Ĵ�
������һ��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ�����������¥�µ���
�񴦸���Ǯ������˯����
LONG
	);

	set("exits", ([
		"down" : __DIR__"kezhan",
		"enter" : __DIR__"kedian3",
	]));

	setup();
}

