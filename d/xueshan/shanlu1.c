//      shanlu1.c ɽ·
//      Designed by secret (����)
//      97/04/09
inherit ROOM;
void create()
{
        set("short","ɽ·");
        set("long",@LONG
    ����һ����ɽ��С·��
LONG
        );
        set("outdoors","xueshan");
        set("exits",([
                "westup" : __DIR__"shanlu2",
                "southdown" : __DIR__"shanjiao",
        ]));
        setup();
        replace_program(ROOM);
}
