// Room: /d/chengdu/niangjiuwo.c
// oooc: 1998/6/28

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����ʽ�ķ����м䡣�������������һ���ܴ�ܴ��
ľͰ��Լ�ж��˶�ߡ���ľͰ�����棬վ�ż�������������Ĵ󺺣�
������������ڷ����ĳ�ľͰ�����š���ǰ��վ��һ�����ϵ����
�ںͼ���С����ü����ȥ��˵Ц�š�
LONG
	);

	set("exits", ([
                "northwest" : __DIR__"xiaojie3",
	]));

	set("objects", ([
		__DIR__"npc/wangerniang" : 1,
		__DIR__"npc/xiaohuozi" : 3,
	]));

	setup();
	replace_program(ROOM);
}

