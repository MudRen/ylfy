//      houmen.c ����
//      Designed by secret (����)
//      97/04/09
inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG
����ѩɽ�µĺ��š�
LONG
        );
        set("exits",([
                "south" : __DIR__"houyuan",
        ]));
        setup();
        replace_program(ROOM);
}


