//      zoulang1.c ����
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
                "down" : __DIR__"cedian1",
                "west" : __DIR__"dating",
                "westup" : __DIR__"zoulang3",
        ]));
        setup();
        replace_program(ROOM);
}
