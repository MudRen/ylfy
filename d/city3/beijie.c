// Room: /chengdu/beijie.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "�����");
	set("long", @LONG
��������˫�˺ϱ�����ͩʮ��һ�꣬�������룬��ʯ�̾͵�
·���ɨ�øɸɾ����������Ǹ��鱦�̣����������������µ���
������
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "south" : __DIR__"beijie1",
                "east" : __DIR__"zhubaopu",
                "west" : __DIR__"wuchi",
                "north" : __DIR__"northchengmen",

	]));
        set("objects", ([
            "/d/huashan/npc/haoke" : 1,
        ]));

	setup();
	replace_program(ROOM);
}

