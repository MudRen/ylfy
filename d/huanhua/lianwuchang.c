//lianwuchang.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
����佻����ɵ����䳡��佻�����ÿ�����������������书����ʱ����
��ˮҲ���Ե�������ָ�������ӵܣ�����ÿ�����ﶼ����ͷ��ӵ������
�Ƿ���������Ϊ׳�ۡ�
LONG
	);

	set("exits", ([
		"south" :__DIR__"changlang3",
		]));
	set("objects", ([
    "/d/huashan/npc/tong-ren" : 1,	
	]));

	set("outdoors", "mingjiao");
	set("coor/x",100);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",100);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",100);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",100);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
