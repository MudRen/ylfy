//      zoulang2.c ����
//      Designed by secret (����)
//      97/04/09
inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG
    ������ѩɽ���ڵ����ȡ�
LONG
        );
        set("exits",([
                "down" : __DIR__"cedian2",
                "east" : __DIR__"dating",
                "eastup" : __DIR__"zoulang3",
        ]));
        setup();
        replace_program(ROOM);
}
