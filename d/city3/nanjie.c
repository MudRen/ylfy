// Room: /chengdu/nanjie.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "�ϴ��");
	set("long", @LONG
�������ϴ�ֵ����϶ˣ���·����������֦��Ҷï����ͩ��
·�汻��ɨ�øɸɾ��������������Ķ���Щ���º͹�Ա��ż����
��������ƽ����ա������и��������µ�ʯ���š�
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "north" : __DIR__"nanjie2",
                "south" : __DIR__"southchengmen",
                "east" : __DIR__"gongqiao",
                "southwest" : __DIR__"cai",

	]));
        set("objects", ([
            __DIR__"npc/qigai" : 2,
        ]));

	setup();
	replace_program(ROOM);
}

