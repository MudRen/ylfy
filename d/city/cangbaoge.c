// Room: /city/dangpu.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�ر���");
	set("long", @LONG
	����һ���������ּ�Ʒ������̵꣬һ����߸ߵĹ�̨���������ǰ����̨
�ϰ���һ������(paizi)����̨�������ϰ壬һ˫�������۾��������´������㡣
LONG
	);
	set("no_fight", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi": @TEXT
    ��ʯ�����԰�δ�󶨵�װ�������װ���󶨣���֮���ID��
    �߼��Ż�������������30����30���ϵ�װ��������ʧ��֮��װ������ʧ
    ������������������Ѱ󶨵�װ�����������δ��״̬	
TEXT
	]) );
	set("objects", ([
		__DIR__"npc/shenmiren" : 1,
	]));
	set("exits", ([
		"down" : __DIR__"dangpu",
	]));
	setup();
	replace_program(ROOM);
}
