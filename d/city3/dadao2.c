// Room: /chengdu/dadao2.c
// oooc: 1998/06/27 

inherit ROOM;

void create()
{
        set("short", "���");
	set("long", @LONG
������ͨ��ɶ��Ĺٵ������ڴ��⿿���ɶ��ǣ�����������
�˲���������Ŀ��ˡ����������ꡢ������С�����������ӡ���
�ֲ��ѡ���·���Ե��������ҡ�ڲ�����������ǳɶ��ı��š�
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "south" : __DIR__"dadao5",
                "north" : __DIR__"dao",
	]));

	setup();
	replace_program(ROOM);
}

