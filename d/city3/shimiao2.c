// Room: /chengdu/shimiao2.c
// oooc: 1998/06/26 

inherit ROOM;

void create()
{
        set("short", "���۱���");
	set("long", @LONG
������ΰׯ�ϵĴ��۱�������������������Ĵ��գ��м�
��������������Ľ��񣬵����������ƣ�����������Ů���������
ͷ��������һ�����ţ��������ݡ���������Ե�䣬��Ǯ�Ʋ�ʩ�á�
LONG
	);

	set("exits", ([
                "south" : __DIR__"shimiao",
	]));
        set("objects", ([
             __DIR__"npc/yuanseng" : 1,
             __DIR__"obj/box1" : 1,
        ]));
        setup();
}

