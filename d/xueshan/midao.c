//      midao.c �ܵ�
//      Designed by secret (����)
//      97/04/09
inherit ROOM;
void create()
{
        set("short","�ܵ�");
        set("long",@LONG
    ����һ����խ�İ�����
LONG
        );
        set("exits",([
                "north" : __DIR__"mishi",
                "east" : __DIR__"neidian",
        ]));
        setup();
        replace_program(ROOM);
}
