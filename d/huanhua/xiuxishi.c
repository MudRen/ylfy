// room: xiuxishi.c
// By Marz

inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
        ���Ǽ�������᷿������������ֻ���м����һ����ʰ
����������Ĵ󴲣����ž�������˯����
LONG
        );

        set("exits", ([
          "south" : __DIR__"changlang",
                ]));

        set("sleep_room", 1);
        set("no_fight", 1);

        set("coor/x",120);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",120);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",120);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",120);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
}


