// Room: /city2/dangpu.c
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������ǰ��
��̨�ϰ���һ������(paizi)����̨�����ż��ϰ壬һ˫�������۾�����
���´������㡣
LONG
	);
	set("no_fight", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi": @TEXT
    �����̲����ۺ�ͯ�����ۣ���ӭ�ݹˣ����Ա��ܡ����Ŀ���������
����(list)������(buy)������(value)���䵱(pawn)�����(redeem)����
��(sell)���ֻ�������Բ鿴������Ʒ����(look_item ��ƷӢ����,ͬ����Ʒ�������)��
TEXT
	]) );
	set("objects", ([
		"/d/city2/npc/jia" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"nandaj1",
	]));
	setup();
	replace_program(ROOM);
}
