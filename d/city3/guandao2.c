// Room: /chengdu/guandao2.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "�ٵ�");
	set("long", @LONG
������ͨ��ɶ��Ĺٵ������ڴ��⿿���ɶ��ǣ�����������
�˲���������Ŀ��ˡ����������ꡢ������С�����������ӡ���
�ֲ��ѡ���·���Ե��������ҡ�ڲ�����
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "east" : __DIR__"guandao1",
                "northwest" : __DIR__"shandao1",
	]));

	setup();
	replace_program(ROOM);
}

