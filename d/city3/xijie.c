// Room: /chengdu/xijie.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "�����");
	set("long", @LONG
���������ֵ����ƻ��ӣ����Ʈ������������αȵĵ��̣�
����һЩС̯С����·�������⣬ż���йٱ��жӾ���������һ
��С�������������Щ�¹ڳ����Ķ����ˣ��ϱ��и����̡���
�������ǳ��ǵ�·��
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "east" : __DIR__"xijie1",
                "north" : __DIR__"xiaoxiang",
                "south" : __DIR__"cddangpu",
                "west" : __DIR__"westchengmen",
	]));

	setup();
	replace_program(ROOM);
}

