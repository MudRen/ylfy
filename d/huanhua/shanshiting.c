//shanshiting.c

inherit ROOM;

void create()
{
	set("short", "��ʳ��");
	set("long", @LONG
�㿴�������Ѿ���������������佻����ӣ�Χ�Ű����������š�һ��
�ϳ��ӹ���������ӭ�˹�����ָ��ָ�����������ʣ�µ�Ψһһ��ȳ
���ȵ�С�������εض��������ʼ硣
LONG
	);

	set("exits", ([
               "north" : __DIR__"changlang2",
		]));
	set("objects", ([
		  "/clone/food/baozi" : 3,
	]));

	set("coor/x",110);
	set("coor/y",-60);
	set("coor/z",0);
	set("coor/x",110);
	set("coor/y",-60);
	set("coor/z",0);
	set("coor/x",110);
	set("coor/y",-60);
	set("coor/z",0);
	set("coor/x",110);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
