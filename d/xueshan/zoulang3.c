//      zoulang3.c ����
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
                "north" : __DIR__"neidian",
                "eastdown" : __DIR__"zoulang1",
                "westdown" : __DIR__"zoulang2",
        ]));
        setup();
        replace_program(ROOM);
}
