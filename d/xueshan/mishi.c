//      mishi.c ����
//      Designed by secret (����)
//      97/04/09
inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG
    ����һ��С���䡣
LONG
        );
        set("exits",([
                "south" : __DIR__"midao",
                "down" : "/d/city/guangchang" ,
        ]));
        setup();
        replace_program(ROOM);
}
