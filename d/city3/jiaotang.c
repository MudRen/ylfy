// Room: /chengdu/jiaotang.c
// oooc: 1998/6/28

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ����Ӣ���˿��Ľ��á�������ɲ���Զ�����������й�
��ʱ�����������������ʦ�������ɼ���ʷ�൱�ƾá����ڽ���
������ݣ����Խ�����Ҳû�����ˡ�ǰ����һ��Ү�����ѵĵ���
���������վ��һ����ʦ��������Ц�������㡣
LONG
	);

	set("exits", ([
                "northeast" : __DIR__"xiaojie3",
	]));

	set("objects", ([
		__DIR__"npc/chuanjiaoshi" :1 
	]));

	setup();
	replace_program(ROOM);
}

