// Room: /d/gaibang/undertree.c
// Date: Haa 96/03/22

inherit ROOM;

void create()
{
       set("short", "�ѷ���");
	set("long", @LONG
�߽�����㷢�������Ȼ���ж��졣
LONG
	);

	set("exits", ([
                "south":__DIR__"/d/tianlongsi/dadao1",
	]));

	setup();
	replace_program(ROOM);
}
