// Room: /chengdu/xiaoxiang1.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "С��");
	set("long", @LONG
������һ�������С���֪��ͨ��������ﲻʱ�б�
�صľ���·��������������Ǵ���һ�¡�
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "south" : __DIR__"xiaoxiang",
                "northeast" : __DIR__"caotang",
	]));
        set("objects", ([
            __DIR__"npc/shusheng" : 2,
        ]));

	setup();
	replace_program(ROOM);
}

