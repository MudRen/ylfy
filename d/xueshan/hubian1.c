//      hubian1.c ����С·
//      Designed by secret (����)
//      97/04/09
inherit ROOM;
void create()
{
        set("short","����С·");
        set("long",@LONG
����ʥ���ߵ�С·��
LONG
        );
        set("outdoors","xueshan");
        set("exits",([
                "east" : __DIR__"hubian2",
                "west" : __DIR__"shenghu",
        ]));
        setup();
        replace_program(ROOM);
}
