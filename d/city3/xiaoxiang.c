// Room: /chengdu/xiaoxiang.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "С��");
	set("long", @LONG
������һ�������С���֪��ͨ��������ﲻʱ����
���ؾ����߹�����Ҳ����������Ǵ��������
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "south" : __DIR__"xijie",
                "north" : __DIR__"xiaoxiang1",
	]));

	setup();
	replace_program(ROOM);
}

