// Room: /chengdu/cdqz.c
// oooc: 1998/06/25 

inherit ROOM;

void create()
{
	set("short", "Ǯׯ");
	set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض�
�зֵꡣ�����е���Ʊ�����ǳ��ã�ͨ��ȫ������˵�����Ǯ��
��������к����ԨԴ����å����һ�㶼���������鷳��������
������һֱ�ܺá�
LONG
	);

	set("exits", ([
                "south" : __DIR__"xijie1",
	]));

	set("objects", ([
                __DIR__"npc/qian1" : 1
	]));

	setup();
	replace_program(ROOM);
}

