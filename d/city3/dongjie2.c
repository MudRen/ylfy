// Room: /chengdu/dongjie2.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "�����");
	set("long", @LONG
����ߵ��⣬�����������������������������ƺ���������
�����ˡ���ľ��֮������˳��������ȥ��������ǰһ���ϸߵ���
�ţ����������������֡��Ѿ��¡��������ϱ߿�ȥ��ֻ����һ
��С�֡�
LONG
	);

	set("exits", ([
                "west" : __DIR__"dongjie1",
                "north" : __DIR__"shimiao",
                "east" : __DIR__"dongjie3",
                "south" : __DIR__"xiaojie",
	]));
        set("objects", ([
            __DIR__"npc/seng-ren" : 1,
        ]));


	setup();
	replace_program(ROOM);
}

