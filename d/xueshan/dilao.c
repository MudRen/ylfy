//      dilao.c ����
//      Designed by secret (����)
//      97/04/09
inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG
����һ����������ʪ���η���
LONG
        );
        set("exits",([
                "westup" : __DIR__"houyuan",
        ]));
        setup();
        replace_program(ROOM);
}
