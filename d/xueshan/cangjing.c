//      cangjingge.c �ؾ���
//      Designed by secret (����)
//      97/04/09
inherit ROOM;
void create()
{
        set("short","�ؾ���");
        set("long",@LONG
������ѩɽ�µĲؾ�֮����
LONG
        );
        set("exits",([
                "southeast" : __DIR__"dating",
        ]));
        setup();
        replace_program(ROOM);
}
