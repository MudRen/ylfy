// Room: /d/chengdu/fengyuting.c
// oooc 1998/06/28 

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
��վ��ͤ�����ͤ������ɵ��죬������һ�֡�ɽ��������
��¥���ĸо����������ǲ���˷��Ľֵ���������������������
��ɽ´�������де�������¶����һ�Ƿ���Զ������������ׯ��
�������������̨һƬ������
LONG
	);

	set("exits", ([
                "westdown" : __DIR__"xiaojie3",
	]));
        set("objects", ([
            __DIR__"npc/youke" : 2,
        ]));


	setup();
	replace_program(ROOM);
}

