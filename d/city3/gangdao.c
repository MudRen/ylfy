// Room: /chengdu/gangdao.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "�ٵ�");
	set("long", @LONG
������ͨ��ɶ��Ĺٵ������ڴ��⿿���ɶ��ǣ�����������
�˲���������Ŀ��ˡ����������ꡢ������С�����������ӡ���
�ֲ��ѡ���·���Ե��������ҡ�ڲ�����������ǳɶ��Ķ��š�
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "west" : __DIR__"eastchengmen",
                "east" : __DIR__"qingshidadao4",
	]));
        set("objects", ([
            __DIR__"npc/xiaofan" : 1,
        ]));

	setup();
	replace_program(ROOM);
}

