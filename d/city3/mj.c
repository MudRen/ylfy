// Room: /chengdu/mj.c
// oooc: 1998/06/24 

inherit ROOM;

void create()
{
        set("short", "���");
	set("long", @LONG
��������ӣ��м����������ջ�������
LONG
	);

	set("exits", ([
                "west" : __DIR__"nanjie1",
	]));

        set("objects", ([
             __DIR__"npc/poorman" : 1,
        ]));

	setup();
}

