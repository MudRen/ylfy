//dating.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������佻����ɽӴ�һ�����ý�������ĵط������ź�ľ̫ʦ�κ�С��
�����ϱ����ߣ������м���Сͯ���ֶ�������ʱ�����˲���ˮ��
LONG
	);

	set("exits", ([
		"east" : __DIR__"guanyuge",
		"west" : __DIR__"xiangfang",
		]));
	set("objects", ([
		  __DIR__"npc/ma" : 1,
	]));


	set("coor/x",60);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
//      replace_program(ROOM);
        "/clone/board/huanhua_b"->foo();
}
