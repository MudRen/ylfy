// Room: /d/emei/lingyunti.c ������ ������


inherit ROOM;


void create()
{
	set("short", "������");
	set("long", @LONG
������һ����ֱ��ɽ��ʯ�����˹����һ�����ݣ���ʵɽ���Ѿ��ܸߡ�
�����ĸ��Ʋ��ϻ�����ʯ������������·�ϣ�ǰ���ʯ���Ѿ�ģ�����塣
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
		"northdown" : __DIR__"xixiangchi",
		"southup" : __DIR__"leidongping",
	]));

	set("objects",([
	]));

	setup();
}
