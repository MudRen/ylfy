// Room: /city/xidajie2.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
	������������ϣ��е�����Ľ���Ҫ�ȱ𴦵ĸɾ������ࡣ�����Ϊ����
���š���Ӫ���ܱ�����Ե�ʣ������Ƕ�ϲ��ס��������߾����ĵ�û�м�������
��������������ͨ�����⡣�ϱ���һ���ھ֣�������һ�������ûʵĴ�լԺ��
LONG
	);
        set("outdoors", "city");
	set("exits", ([
		"east" : __DIR__"xidajie1",
		"south" : __DIR__"biaoju",
		"west" : __DIR__"ximen",
		"north" : __DIR__"caizhu",
	]));
        set("objects", ([
                "/d/npc/duanyanqing": 1,
	]));
	setup();
	replace_program(ROOM);
}
