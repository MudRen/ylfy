// Room: /chengdu/guandao1.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "�ٵ�");
	set("long", @LONG
������ͨ��ɶ��Ĺٵ������ڴ��⿿���ɶ��ǣ�����������
�˲���������Ŀ��ˡ����������ꡢ������С�����������ӡ���
�ֲ��ѡ���·���Ե��������ҡ�ڲ�����������ǳɶ������š�
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "east" : __DIR__"westchengmen",
                "west" : __DIR__"guandao2",
                "south" : __DIR__"liangting",
	]));

	setup();
	replace_program(ROOM);
}

