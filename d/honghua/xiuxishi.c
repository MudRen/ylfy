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
      "north" : __DIR__"zoulang2",
                ]));

        set("sleep_room", 1);
        set("no_fight", 1);

        set("coor/x",-150);
    set("coor/y",90);
    set("coor/z",20);
    set("coor/x",-150);
    set("coor/y",90);
    set("coor/z",20);
    set("coor/x",-150);
    set("coor/y",90);
    set("coor/z",20);
    set("coor/x",-150);
    set("coor/y",90);
    set("coor/z",20);
    setup();
}