// Room: /city/dangpu.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
	����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������ǰ����̨
�ϰ���һ������(paizi)����̨���������ϰ壬һ˫�������۾��������´������㡣
LONG
	);
	set("no_fight", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi": @TEXT
    �����̲����ۺ�ͯ�����ۣ���ӭ�ݹˣ����Ա��ܡ����Ŀ���������
����(list)������(buy)����ѯ�ѵ䵱����(check)������(value)���䵱(pawn)�����(redeem)��
����(sell)���ֻ�������Բ鿴������Ʒ����(look_item ��ƷӢ����,ͬ����Ʒ�������)��	
TEXT
	]) );
	set("objects", ([
		__DIR__"npc/tang" : 1,
		//__DIR__"npc/qian" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"nandajie1",
		"up" : __DIR__"cangbaoge",
	]));
	setup();
	replace_program(ROOM);
}
