//bye enter

inherit ROOM;

void create()
{
        set("short", "ɽ��");
	set("long", @LONG
����һ����᫲�ƽ��ɽ�����˼���������˵���ﲻ�Ǻ�̫ƽ��
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "southeast" : __DIR__"guandao2",
                "northup" : __DIR__"shandao2",
	]));
        set("objects", ([
                __DIR__"npc/tufei2" : 2,
            ]));

	setup();
	replace_program(ROOM);
}

