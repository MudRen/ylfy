// dao1.c ����·
// by oooc

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
������һ����������Ļ���·�ϣ���������ɭɭ�����֡���˵
���������˳�û�����ɾ�����
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "southwest" : __DIR__"dao",
	]));
        set("objects", ([
            __DIR__"npc/tufei2" : 1,
        ]));

	setup();
	replace_program(ROOM);
}

