// Room: chufang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ƣ��������ڣ���ζ�˱Ƕ�������ǽ��һ�����ɳ���
��̨��֧��ʮ���ڴ��������һ�ڷ����Ϸ������˴���������
���£��ֳ�ľ���ڽ��衣�����շ��ĵ�ʿ�⣬��λ��ͯæ������
��н������¯�����ܡ�һλ�����ʿ�����شߴ��š�
LONG
	);

	set("exits", ([
		"south" : __DIR__"shitang",
		"northwest" : __DIR__"chufang2",
	]));

//	set("objects",([
//		__DIR__"npc/shaofan-seng" : 2,
//	]));
	setup();
	replace_program(ROOM);
}



