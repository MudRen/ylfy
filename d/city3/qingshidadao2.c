// Room: /chengdu/qingshidadao2.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ�������ʯ���г����������͵���ݣ���
·����������������ż��ô�׳����������·��ʱ����Щ����
��ʿ����ȥȥ����ʱ����װ�кܶ����ӵĴ󳵾�������������
�����ǳɶ���
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "west" : __DIR__"qingshidadao3",
                "east" : __DIR__"qingshidadao1",
	]));

	setup();
	replace_program(ROOM);
}

