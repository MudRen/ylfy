//      houyuan.c ��Ժ
//      Designed by secret (����)
//      97/04/09
inherit ROOM;
void create()
{
        set("short","��Ժ");
        set("long",@LONG
������ѩɽ�µĺ�Ժ���ϱ������䳡�������Ǻ��š�
LONG
        );
        set("outdoors","xueshan");
        set("exits",([
                "eastdown" : __DIR__"dilao",
                "north" : __DIR__"houmen",
                "south" : __DIR__"chang",
        ]));
        setup();
        replace_program(ROOM);
}

